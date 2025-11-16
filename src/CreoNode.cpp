#include "pch.h"

#include "CreoNode.h"

#include "ProObjects.h"
#include "ProFeature.h"
#include "ProFeatType.h"
#include <ProLayer.h>
#include <ProSolid.h>
#include <ProSolidBody.h>

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
	else if (m_type == CreoNodeType::CBody || m_type == CreoNodeType::CQuilt) {
		// Parse face
	}

	return status;
}

ProError CreoNode::ParseChildren()
{
	ProError status = PRO_TK_NO_ERROR;
	if (m_type == CreoNodeType::CAssembly) { // Parse assembly
		std::vector<ProFeature> vComponents;
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
