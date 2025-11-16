#include "pch.h"

#include "CreoNode.h"

#include "ProObjects.h"
#include "ProFeature.h"
#include "ProFeatType.h"
#include <ProLayer.h>
#include <ProSolid.h>
#include <ProSolidBody.h>
#include <ProQuilt.h>

CreoNode::CreoNode(
	std::wstring& name,
	ProFeature feature, 
	ProMdl creoModel, 
	CreoNode* parentNode,
	CreoNodeType type)
	: m_name(name),
	m_feature(feature), 
	m_creoModel(creoModel), 
	m_parent(parentNode),
	m_type(type)
{
	m_localIndex = 0;
	m_nodePath = "";
	m_isSketch = false;
}

CreoNode::CreoNode(
	NDSInt32 localIndex, 
	ProFeature feature, 
	ProMdl creoModel, 
	CreoNode* parentNode,
	CreoNodeType type,
	ProAsmcomppath& compPath)
	:m_feature(feature),
	m_creoModel(creoModel),
	m_parent(parentNode),
	m_type(type),
	m_cmpPath(std::move(compPath))
{
	m_localIndex = localIndex;
	m_nodePath = "";
	m_isSketch = false;
}

CreoNode::CreoNode(
	NDSInt32 localIndex, ProQuilt& quilt, ProMdl creoModel, CreoNode* parentNode, CreoNodeType type, ProAsmcomppath& compPath)
	:m_quilt(quilt),
	m_creoModel(creoModel),
	m_parent(parentNode),
	m_type(type),
	m_cmpPath(std::move(compPath))
{
	m_localIndex = localIndex;
	m_nodePath = "";
	m_isSketch = false;
}

static ProError NDSProSurfaceVisitAction(ProSurface p_surface, ProError status, ProAppData app_data)
{
	std::vector<ProSurface>* p_surfaces = (std::vector<ProSurface>*)app_data;
	p_surfaces->emplace_back(p_surface);
	return PRO_TK_NO_ERROR;
}

ProError CreoNode::ParseNode()
{
	ProError status = PRO_TK_NO_ERROR;
	// Parse base node info.
	if (m_parent == nullptr) { // Root
		m_localIndex = 0;
		m_nodePath += std::to_string(m_localIndex);

		m_cmpPath.table_num = 0;
		m_cmpPath.owner = (ProSolid)m_creoModel;
		m_cmpPath.comp_id_table[0] = -1;
	}
	else {
		// Add name
		ProName nodeName;
		status = ProMdlMdlnameGet(m_creoModel, nodeName);

		if (status != PRO_TK_NO_ERROR) {
			return status;
		}

		if (m_type == CreoNodeType::CAssembly || m_type == CreoNodeType::CPart) {
			m_name = nodeName;
		}
		else if (m_type == CreoNodeType::CBody) {
			m_name = nodeName;
			m_name = m_name + L":Body_" + std::to_wstring(m_localIndex);
		}
		else if (m_type == CreoNodeType::CQuilt) {
			m_name = nodeName;
			m_name = m_name + L":Quilt_" + std::to_wstring(m_localIndex);
		}
		

		std::string parentPath = m_parent->GetNodePath();
		m_nodePath = parentPath + "_" + std::to_string(m_localIndex);
	}

	if (m_type == CreoNodeType::CAssembly || m_type == CreoNodeType::CPart) {
		ParseChildren();
	}
	else if (m_type == CreoNodeType::CBody) {
		// Parse face
		status = ProSolidBodySurfaceVisit(&m_feature, NDSProSurfaceVisitAction, (ProAppData)&m_surfaces);

		if (status == PRO_TK_NO_ERROR) {
			status = ParseNodeMaterials();
		}
	}
	else if (m_type == CreoNodeType::CQuilt) {
		// Parse Quilt
	}

	return status;
}

ProError CreoNode::ParseChildren()
{
	ProError status = PRO_TK_NO_ERROR;
	std::vector<ProFeature> vComponents;
	std::vector<ProQuilt> vQuilts;
	if (m_type == CreoNodeType::CAssembly) { // Parse assembly
		// Parse Quilt node
		status = ProAsmcomppathDispQuiltVisit(
			&m_cmpPath, (ProSolid)m_creoModel, nullptr,
			[](ProQuilt p_quilt, ProError status, ProAppData app_data)->ProError {
				std::vector<ProQuilt>* vQuilts = (std::vector<ProQuilt>*)app_data;
				vQuilts->emplace_back(p_quilt);
				return PRO_TK_CONTINUE;
			},
			(ProAppData)&vQuilts);
		if (!vQuilts.empty()) {
			// TODO: Add extra part node. For now, skip.
		}

		// Parse Part / Sub - assembly
		status = ProSolidFeatVisit(
			(ProSolid) m_creoModel,
			NDSProCOmponentVisitAction,
			NDSProComponentFilterAction,
			(ProAppData) & vComponents
		);
		if (status != PRO_TK_NO_ERROR) {
			return status;
		}

		for (int ii = 0; ii < vComponents.size(); ++ii) {
			auto childNode = Create(ii, vComponents[ii]);
			if (childNode == nullptr) {
				continue;
			}

			childNode->ParseNode();
			m_children.emplace_back(std::move(childNode));
		}


	}
	else if (m_type == CreoNodeType::CPart) {
		status = ProSolidFeatVisit(
			(ProSolid)m_creoModel,
			NDSProCOmponentVisitAction,
			NDSProComponentFilterAction,
			(ProAppData)&vComponents
		);
		vComponents.clear();

		// Quilt
		status = ProAsmcomppathDispQuiltVisit(
			&m_cmpPath, (ProSolid)m_creoModel, nullptr,
			[](ProQuilt p_quilt, ProError status, ProAppData app_data)->ProError {
				std::vector<ProQuilt>* vQuilts = (std::vector<ProQuilt>*)app_data;
				vQuilts->emplace_back(p_quilt);
				return PRO_TK_NO_ERROR;
			}, (ProAppData)&vQuilts);

		if (status == PRO_TK_NO_ERROR)
		{
			for (int ii = 0; ii < vQuilts.size(); ++ii)
			{
				auto childNode = CreateQuiltNode(ii, vQuilts[ii]);

				if (childNode == nullptr) {
					continue;
				}

				// TODO: This is not working!
				//ProGeomitem geomSurface;
				//status = ProQuiltToGeomitem((ProSolid)m_creoModel, vQuilts[ii], &geomSurface);
				//if (status == PRO_TK_NO_ERROR) {
				//	status = ProModelitemHide(&geomSurface);
				//}

				childNode->ParseNode();
				m_children.emplace_back(std::move(childNode));
			}
		}

		// Solid body
		int size = 0;
		ProSolidBody* bodies = nullptr;
		status = ProSolidBodiesCollect((ProSolid)m_creoModel, &bodies);
		if (status == PRO_TK_NO_ERROR)
		{
			status = ProArraySizeGet(bodies, &size);
			for (int ii = 0; ii < size; ++ii)
			{
				auto childNode = CreateBodyNode(ii, bodies[ii]);
				if (childNode == nullptr) {
					continue;
				}

				childNode->ParseNode();
				m_children.emplace_back(std::move(childNode));
			}
			ProArrayFree((ProArray*)&bodies);
		}

	}
	return status;
}

std::shared_ptr<CreoNode> CreoNode::Create(NDSInt32 index, ProFeature& feature)
{
	ProError status = PRO_TK_NO_ERROR;

	ProFeattype fType;
	status = ProFeatureTypeGet(&feature, &fType);
	if (fType != PRO_FEAT_COMPONENT) {
		return nullptr;
	}

	// Add comp path;
	ProMdl model = nullptr;
	status = ProAsmcompMdlGet(&feature, &model);
	if (model == nullptr)
		return nullptr;

	auto compPath = m_cmpPath;
	compPath.comp_id_table[compPath.table_num] = feature.id;
	++compPath.table_num;

	ProMdlType type;
	status = ProMdlTypeGet(model, &type);
	std::shared_ptr<CreoNode> childNode = nullptr;
	if (type == PRO_MDL_PART)
	{
		childNode = std::shared_ptr<CreoNode>(
			new CreoNode(index, feature, model, this, CreoNodeType::CPart, std::move(compPath)));
	}
	else if (type == PRO_MDL_ASSEMBLY)
	{
		childNode = std::shared_ptr<CreoNode>(
			new CreoNode(index, feature, model, this, CreoNodeType::CAssembly, std::move(compPath)));
	}

	return childNode;
}

std::shared_ptr<CreoNode> CreoNode::CreateBodyNode(NDSInt32 index, ProFeature& feature)
{
	ProError status = PRO_TK_NO_ERROR;

	if (feature.type != PRO_BODY) {
		return nullptr;
	}

	// Add comp path;
	auto compPath = m_cmpPath;
	compPath.comp_id_table[compPath.table_num] = feature.id;
	++compPath.table_num;

	// Body will have the same creoModel as Part.
	std::shared_ptr<CreoNode> childNode = std::shared_ptr<CreoNode>(
		new CreoNode(index, feature, m_creoModel, this, CreoNodeType::CBody, std::move(compPath)));

	return childNode;
}

std::shared_ptr<CreoNode> CreoNode::CreateQuiltNode(NDSInt32 index, ProQuilt& quilt)
{
	ProError status = PRO_TK_NO_ERROR;

	NDSInt32 quiltId = -1;
	status = ProQuiltIdGet(quilt, &quiltId);

	auto compPath = m_cmpPath;
	compPath.comp_id_table[compPath.table_num] = quiltId;
	++compPath.table_num;

	std::shared_ptr<CreoNode> childNode = std::shared_ptr<CreoNode>(
		new CreoNode(index, quilt, m_creoModel, this, CreoNodeType::CQuilt, std::move(compPath)));

	return childNode;
}

ProError CreoNode::ParseNodeMaterials()
{
	if (m_type == CreoNodeType::CAssembly || m_type == CreoNodeType::CPart || m_surfaces.empty()) {
		return PRO_TK_NO_CHANGE;
	}

	ProError status = PRO_TK_NO_ERROR;

	ProMdl p_handle;
	status = ProMdlCurrentGet(&p_handle);

	for (int ii = 0; ii < m_surfaces.size(); ++ii) {
		auto& face = m_surfaces[ii];
		ProSurfaceAppearanceProps surfAppProps;
		ProGeomitem geomSurface;
		status = ProSurfaceToGeomitem((ProSolid)m_creoModel, face, &geomSurface);
		ProAsmitem item;
		item.item = geomSurface;
		item.path = m_cmpPath;
		item.item.owner = p_handle;
		if (m_parent == nullptr)
		{//���
			item.path.comp_id_table[0] = -1;
			item.path.owner = (ProSolid)p_handle;
			item.path.table_num = 0;
		}

		int SpecularColor = 0;
		int rgb = 0;
		int ambientColor = 0;
		double transparency = 0;
		int shininess = 8;
		double emissiveColor = 1;
		double diffuseColor = 0;

		status = ProSurfaceSideAppearancepropsGet((ProModelitem*)&geomSurface, 0, &surfAppProps);
		if (PRO_TK_NO_ERROR != status) {
			status = ProMdlVisibleSideAppearancepropsGet(&item, 0, &surfAppProps);
			if (PRO_TK_NO_ERROR != status)
			{
				status = ProSurfaceAppearanceDefaultPropsGet(PRO_DEF_APPEARANCE_SOLID, &surfAppProps);
			}
		}

		// Test code		
		if (ii == 86) {
			int x = 0;
			//ProSurfaceAppearanceProps newSurfAppProps = surfAppProps;
			//newSurfAppProps.color_rgb[0] = 1.0f;
			//newSurfAppProps.color_rgb[1] = 0.0f;
			//newSurfAppProps.color_rgb[2] = 0.0f;
			//status = ProSurfaceSideAppearancepropsGet((ProModelitem*) &geomSurface, 0, &surfAppProps);
			//status = ProSurfaceSideAppearancepropsGet((ProModelitem*)&geomSurface, 1, &surfAppProps);
			//status = ProSurfaceSideAppearancepropsSet((ProModelitem*)&geomSurface, 0, &newSurfAppProps);
		}
		//
		if (status != PRO_TK_NO_ERROR) {
			surfAppProps.diffuse = -1.0;
		}
		m_surfaceProperties.emplace_back(surfAppProps);
	}

	return status;
}

std::string CreoNode::GetNodePath()
{
	return m_nodePath;
}

ProError CreoNode::NDSProCOmponentVisitAction(ProFeature* p_feature, ProError status, ProAppData app_data)
{
	std::vector<ProFeature>* componentArray = (std::vector<ProFeature>*)app_data;
	if (componentArray) {
		componentArray->emplace_back(*p_feature);
	}
	return PRO_TK_NO_ERROR;
}

ProError CreoNode::NDSProComponentFilterAction(ProFeature* p_feature, ProAppData app_data)
{
	ProError status = PRO_TK_NO_ERROR;
	ProFeattype fType;

	status = ProFeatureTypeGet(p_feature, &fType);

	if (fType == PRO_FEAT_DATUM || fType == PRO_FEAT_CSYS) {
		status = ProModelitemHide(p_feature);
	}

	if (fType == PRO_FEAT_COMPONENT)
		return PRO_TK_NO_ERROR;

	return PRO_TK_CONTINUE;
}
