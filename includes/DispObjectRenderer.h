#pragma once

#include "ProToolkit.h"
#include "ProDispObject.h"

class DispObjectRenderer {
public:
	DispObjectRenderer() = default;

	~DispObjectRenderer();

	ProError RenderDispObjectCurve();

	ProError RenderDispObjectMesh();

private:

	ProDispObject surfDisp_obj = NULL;
	ProDispObject curveDisp_obj = NULL;
	int* dispobj_keylist1 = NULL, * dispobj_keylist2 = NULL;
	int m_dispObjectWindowId = -1;
};
