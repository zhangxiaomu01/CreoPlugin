#pragma once

#include <memory>

#include "ProObjects.h"

#include "CreoNode.h"

class ModelIterator {
public:
	ModelIterator();
	~ModelIterator();

	ProError CollectModelNode();

	ProError RefitToModel(std::string& path);

	ProError RefitToModelCustom(std::string& path);

	bool SaveScreenCaptureToPath(std::string fileName);

private:
	std::shared_ptr<CreoNode> m_rootNode;

	ProMdl m_creoModel;

	ProMatrix m_oldViewPanZoomMatrix;
	bool m_panZoomMatrixSet = false;
};