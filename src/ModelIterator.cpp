#include "pch.h"
#include "ModelIterator.h"

#include "ProObjects.h"
#include "ProMdl.h"

ModelIterator::ModelIterator()
{
	m_creoModel = nullptr;
}

ModelIterator::~ModelIterator()
{

}

ProError ModelIterator::CollectModelNode()
{
	ProError status = PRO_TK_NO_ERROR;

	// Get main model
	status = ProMdlCurrentGet(&m_creoModel);

	ProMdlType rootNodeType;
	status = ProMdlTypeGet(m_creoModel, &rootNodeType);

	ProName rootNodeName;
	status = ProMdlNameGet(m_creoModel, rootNodeName);

	if (status != PRO_TK_NO_ERROR) {
		return status;
	}

	CreoNodeType type = CreoNodeType::CAssembly;
	if (rootNodeType == PRO_MDL_PART) {
		type = CreoNodeType::CPart;
	}

	std::wstring nodeName = rootNodeName;

	ProFeature rootFeature;
	rootFeature.id = -1;
	rootFeature.type = PRO_TYPE_UNUSED;
	rootFeature.owner = m_creoModel;
	
	m_rootNode = std::shared_ptr<CreoNode>(new CreoNode(nodeName, rootFeature, m_creoModel, nullptr, type));
	m_rootNode->ParseNode();

	return status;
}
