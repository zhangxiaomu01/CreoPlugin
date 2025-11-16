#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ProObjects.h"
#include "ProSurface.h"
#include "CommonDataType.h"

enum class CreoNodeType {
	CAssembly,
	CPart,
	CBody,
	CQuilt,
	Annotation
};


class CreoNode {
public:
	CreoNode(std::wstring& name,
		ProFeature feature, ProMdl creoModel, 
		CreoNode* parentNode, CreoNodeType type);

	CreoNode(NDSInt32 localIndex,
		ProFeature feature, ProMdl creoModel,
		CreoNode* parentNode, CreoNodeType type, 
		ProAsmcomppath& compPath);

	CreoNode(NDSInt32 localIndex,
		ProQuilt& quilt, ProMdl creoModel,
		CreoNode* parentNode, CreoNodeType type,
		ProAsmcomppath& compPath);

	ProError ParseNode();

	ProError ParseChildren();

	std::shared_ptr<CreoNode> Create(NDSInt32 index, ProFeature& feature);

	std::shared_ptr<CreoNode> CreateBodyNode(NDSInt32 index, ProFeature& feature);

	std::shared_ptr<CreoNode> CreateQuiltNode(NDSInt32 index, ProQuilt& quilt);

	ProError ParseNodeMaterials();

	std::string GetNodePath();

	ProMdl& GetSolid();

	ProFeature& GetFeature();

	ProAsmcomppath& GetProAsmcompPath();

	CreoNode* GetCreoNodeAtIndex(NDSInt32 index);

private:
	static ProError NDSProCOmponentVisitAction(ProFeature* p_feature, ProError status, ProAppData app_data);

	static ProError NDSProComponentFilterAction(ProFeature* p_feature, ProAppData app_data);

	std::wstring m_name;
	std::string m_nodePath;
	ProAsmcomppath m_cmpPath{};
	NDSInt32 m_localIndex;
	bool m_isSketch;

	ProFeature m_feature;
	ProQuilt m_quilt;
	ProMdl m_creoModel;
	CreoNodeType m_type;
	CreoNode* m_parent;
	std::vector<std::shared_ptr<CreoNode>> m_children; // Only valid for Assembly / Part node.

	std::vector<ProSurface> m_surfaces; // Only valid for Body / Quilt node.
	std::vector<ProSurfaceAppearanceProps> m_surfaceProperties;
};
