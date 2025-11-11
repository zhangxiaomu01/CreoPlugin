#pragma once

#include <vector>

#include "CommonDataType.h"
#include "ProToolkit.h"
#include "ProDispObject.h"

struct DispObjectRenderStates {
	ProDispObject m_dispObject = NULL;
	NDSInt32* m_dispObjectList = NULL;
	NDSInt32 m_featureId = 118;
};

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

	ProError RenderTestBox(NDSMatrix& meshTransform);

	ProError RenderTestRectLine();

private:

	//ProDispObject surfDisp_obj = NULL;
	ProDispObject curveDisp_obj = NULL;
	NDSInt32* dispobj_keylist1 = NULL;
	//NDSInt32* dispobj_keylist2 = NULL;
	NDSInt32 m_dispObjectWindowId = -1;
	NDSInt32 m_featureCount = 0;


	std::vector<DispObjectRenderStates> m_renderStates;

};
