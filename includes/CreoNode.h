#pragma once

#include <memory>
#include <string>

#include "ProObjects.h"

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
		std::shared_ptr<CreoNode> parentNode, CreoNodeType type);

private:
	std::wstring m_name;
	ProFeature m_feature;
	ProMdl m_creoModel;
	CreoNodeType m_type;
	std::shared_ptr<CreoNode> m_parent;
};
