#include "pch.h"

#include "CreoNode.h"

CreoNode::CreoNode(ProFeature feature, ProMdl creoModel, CreoNodeType type)
	: m_feature(feature), m_creoModel(creoModel), m_type(type)
{
}
