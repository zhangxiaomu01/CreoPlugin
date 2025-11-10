#pragma once

#include <vector>

#include "CommonDataType.h"
#include "ProToolkit.h"
#include "ProDispObject.h"

class DispObjectRenderer {
public:
	DispObjectRenderer() = default;

	~DispObjectRenderer();

	ProError RenderDispObjectCurve(
		std::vector<NDSFloat32>& vertices,
		std::vector<NDSUInt32>& indices,
		NDSMatrix& transformMatrix
	);

	ProError RenderDispObjectMesh(
		std::vector<NDSFloat32>& vertices,
		std::vector<NDSFloat32>& normals,
		std::vector<NDSUInt32>& indices,
		ModelTransfer::NDSMaterial* matrial,
		NDSMatrix& meshTransform
	);

	ProError RenderTestBox();

	ProError RenderTestRectLine();

private:

	ProDispObject surfDisp_obj = NULL;
	ProDispObject curveDisp_obj = NULL;
	int* dispobj_keylist1 = NULL, * dispobj_keylist2 = NULL;
	int m_dispObjectWindowId = -1;
};
