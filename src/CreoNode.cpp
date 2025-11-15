#include "pch.h"

#include "CreoNode.h"

CreoNode::CreoNode(
	std::wstring& name,
	ProFeature feature, 
	ProMdl creoModel, 
	std::shared_ptr<CreoNode> parentNode, 
	CreoNodeType type)
	: m_name(name),
	m_feature(feature), 
	m_creoModel(creoModel), 
	m_type(type),
	m_parent(parentNode)
{

}
