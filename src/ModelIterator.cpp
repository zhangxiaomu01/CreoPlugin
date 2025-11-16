#include "pch.h"
#include "ModelIterator.h"

#include "ProObjects.h"
#include "ProMdl.h"
#include "ProUtil.h"
#include <ProView.h>

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

ProError ModelIterator::RefitToModel(std::string& path)
{
	ProError status = PRO_TK_NO_CHANGE;
	if (path.empty()) {
		return status;
	}
	std::string PartIndexStr = path.substr(path.size() - 1);


	ProMdl    model;
	ProView   p_view;
	ProLine* view_names, * alt_names;
	ProName   w_fname;
	char      vname[PRO_NAME_SIZE], aname[PRO_NAME_SIZE];
	char      fname[] = "view_names.txt";
	int       num_views, i;
	FILE* fp;
	ProMatrix	matrix;

	//status = ProMdlCurrentGet(&model);

	auto creoModel = m_rootNode->GetCreoNodeAtIndex(0);
	model = creoModel->GetSolid();
	//if (status != PRO_TK_NO_ERROR)
	//	return status;

	status = ProViewNamesGet(model, &view_names, &alt_names, &num_views);

	if (status != PRO_TK_NO_ERROR)
	{
		return status;
	}
	else if (num_views <= 0)
	{
		return status;
	}


	if (num_views > 0)
	{
		for (i = 0; i < num_views; i++)
		{
			ProWstringToString(vname, view_names[i]);
			ProWstringToString(aname, alt_names[i]);

			status = ProViewNameToView(model, view_names[i], &p_view);

			status = ProViewRetrieve(model, view_names[i], &p_view);

			status = ProViewMatrixGet(model, p_view, matrix);

			status = ProViewRefit(model, p_view);
		}
		ProStringToWstring(w_fname, fname);
		ProInfoWindowDisplay(w_fname, NULL, NULL);
	}

	ProArrayFree((ProArray*)&view_names);
	ProArrayFree((ProArray*)&alt_names);


	//auto creoModel = m_rootNode->GetCreoNodeAtIndex(0);
	//if (model != nullptr) {
	//	ProMdl solidNode = creoModel->GetSolid();

	//	ProMdl currentModel;
	//	//status = ProMdlCurrentGet(&currentModel);

	//	auto& compPath = creoModel->GetProAsmcompPath();
	//	status = ProAsmcomppathMdlGet(&compPath, &currentModel);

	//	status = ProViewRefit(currentModel, nullptr);
	//}

	return status;
}
