#pragma once

#include "ProObjects.h"

enum class CreoNodeType {
	CAssembly,
	CPart,
	CBody,
	CQuilt
};


class CreoNode {
public:
	CreoNode(ProFeature feature, ProMdl creoModel, CreoNodeType type);

private:
	ProFeature m_feature;
	ProMdl m_creoModel;
	CreoNodeType m_type;
};
