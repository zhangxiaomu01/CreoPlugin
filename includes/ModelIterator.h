#pragma once

#include <memory>

#include "ProObjects.h"

#include "CreoNode.h"

class ModelIterator {
public:
	ModelIterator();
	~ModelIterator();

	ProError CollectModelNode();

private:
	std::shared_ptr<CreoNode> m_rootNode;

};