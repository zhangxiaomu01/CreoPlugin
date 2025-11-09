#include "pch.h"
#include "DispObjectRenderer.h"

#include "ProMdl.h"
#include "ProMenu.h"
#include "ProUtil.h"
#include "ProColor.h"
#include "ProGraphic.h"
#include "ProArray.h"
#include "ProAsmcomp.h"
#include "ProCsys.h"
#include "ProTKRunTime.h"
#include "ProUIMessage.h"
#include "ProWindows.h"
#include "ProCurve.h"
#include "ProModelitem.h"

DispObjectRenderer::~DispObjectRenderer()
{
	ProError status = PRO_TK_NO_ERROR;
	if (curveDisp_obj != NULL)  // Delete existing display object
	{
		status = ProDispObjectDetach(m_dispObjectWindowId, dispobj_keylist1);

		status = ProDispObjectDelete(&curveDisp_obj);

		status = ProArrayFree((ProArray*)&dispobj_keylist1);

		curveDisp_obj = NULL;
	}

	if (surfDisp_obj != NULL) {
		status = ProDispObjectDetach(m_dispObjectWindowId, dispobj_keylist2);

		status = ProDispObjectDelete(&surfDisp_obj);

		status = ProArrayFree((ProArray*)&dispobj_keylist2);

		surfDisp_obj = NULL;
	}
}

ProError DispObjectRenderer::RenderDispObjectCurve()
{
	ProError status = PRO_TK_NO_ERROR;
	ProMdl model = NULL;
	ProMatrix transform = { { 1.0, 0.0, 0.0, 0.0},
							  { 0.0, 1.0, 0.0, 0.0},
							  { 0.0, 0.0, 1.0, 0.0},
							  { 0.0, 0.0, 0.0, 1.0} };
	float normal[3] = { 0.0,   0.0, 1.0 };
	int* strip_size;
	ProTriVertex** strip_arr = NULL;
	ProTriVertex* strip = NULL;
	ProSelection* p_sel;
	int i = -1, n_sel = -1, count_pnt = -1, j, offsetVal = 1;
	ProMdl owner;
	ProModelitem modelitem;
	ProCurve curve;
	Pro3dPnt* p_points;
	ProSurfaceAppearanceProps surf_appear;
	ProTriVertex tempTriVertex;
	float x_offset = 0.0, y_offset = 0.0, z_offset = 0.0;
	double curveLen = 0.0, tolerance = 0.0;
	ProMdlType topMdlType;
	ProAsmcomppath pCompPath;
	int* cIdTablel, feat_id = 117;
	ProBoolean isCompPath = PRO_B_FALSE;
	ProModelitem sAsmComp;
	int disobj_winId;
	ProUIMessageButton* buttons;
	ProUIMessageButton result = PRO_UI_MESSAGE_NO;

	if (curveDisp_obj != NULL) // If Display object exist then ask user to keep it or replace witn new one
	{
		ProArrayAlloc(2, sizeof(ProUIMessageButton), 1, (ProArray*)&buttons);
		buttons[0] = PRO_UI_MESSAGE_YES;
		buttons[1] = PRO_UI_MESSAGE_NO;

		status = ProUIMessageDialogDisplay(PROUIMESSAGE_QUESTION, L"Delete existing curve display object",
			L"Code creates only one curve display object at a time. Do you want to delete existing curve display object?",
			buttons, buttons[1], &result);

		status = ProArrayFree((ProArray*)&buttons);

		if (result == PRO_UI_MESSAGE_NO)
			return (PRO_TK_NO_ERROR);
	}

	//Select curve to created display object
	status = ProSelect((char*)"curve", 1, NULL, NULL, NULL, NULL, &p_sel,
		&n_sel);

	if (status != PRO_TK_NO_ERROR || n_sel < 1)
		return status;

	status = ProSelectionModelitemGet(p_sel[0], &modelitem);

	status = ProModelitemMdlGet(&modelitem, &owner);

	status = ProCurveInit((ProSolid)owner, modelitem.id, &curve);

	status = ProCurveLengthEval(curve, &curveLen);
	offsetVal = curveLen / 2;

	// If curve length is small (less than 10), then maximum distance between 
	// the tessellation is reduced otherwise it will be 1.0 
	if (offsetVal < 5)
		tolerance = offsetVal / 10.0;
	else
		tolerance = 1.0;

	status = ProCurveTessellationGet(curve, tolerance, &p_points, &count_pnt);

	// Memory allocation for strip arrays
	status = ProArrayAlloc(1, sizeof(ProTriVertex*), 1, (ProArray*)&strip_arr);

	// Memory allocation for first strip array
	status = ProArrayAlloc(0, sizeof(ProTriVertex), 1, (ProArray*)&(strip_arr[0]));

	// Memory allocation for strip size
	status = ProArrayAlloc(1, sizeof(int), 1, (ProArray*)&strip_size);

	// checking for curve plane
	if (count_pnt < 3)
	{
		if (p_points[0][2] == p_points[1][2])
			z_offset = offsetVal;

		else if (p_points[0][1] == p_points[1][1])
			y_offset = offsetVal;

		else if (p_points[0][0] == p_points[1][0])
			x_offset = offsetVal;

		else
			z_offset = offsetVal;
	}

	else if (count_pnt >= 3)
	{
		// Checking Z coord of 3 points (of 1st, middle and last point on curve)
		if ((p_points[0][2] == p_points[count_pnt / 2][2]) && (p_points[0][2] == p_points[count_pnt - 1][2]))
			z_offset = offsetVal;

		// Checking z coord of Y points (of 1st, middle and last point on curve)
		else if ((p_points[0][1] == p_points[count_pnt / 2][1]) && (p_points[0][1] == p_points[count_pnt - 1][1]))
			y_offset = offsetVal;

		// Checking X coord of 3 points (of 1st, middle and last point on curve)
		else if ((p_points[0][0] == p_points[count_pnt / 2][0]) && (p_points[0][0] == p_points[count_pnt - 1][0]))
			x_offset = offsetVal;

		else
			z_offset = offsetVal;
	}

	for (i = 0; i < count_pnt; i++)
	{
		tempTriVertex.pnt[0] = p_points[i][0];
		tempTriVertex.pnt[1] = p_points[i][1];
		tempTriVertex.pnt[2] = p_points[i][2];

		tempTriVertex.norm[0] = 0.0;
		tempTriVertex.norm[1] = 0.0;
		tempTriVertex.norm[2] = 1.0;

		// Adding curve point for dispobj
		status = ProArrayObjectAdd((ProArray*)&(strip_arr[0]), PRO_VALUE_UNUSED, 1, &tempTriVertex);

		// Following code is taking offset curve points at offsetVal distance which is 
		// in normal direction to curve plane
		tempTriVertex.pnt[0] = p_points[i][0] + x_offset;
		tempTriVertex.pnt[1] = p_points[i][1] + y_offset;
		tempTriVertex.pnt[2] = p_points[i][2] + z_offset;

		// Adding offset curve point for dispobj
		status = ProArrayObjectAdd((ProArray*)&(strip_arr[0]), PRO_VALUE_UNUSED, 1, &tempTriVertex);
	}

	strip_size[0] = count_pnt * 2;

	status = ProMdlCurrentGet(&model);

	disobj_winId = 0;
	status = ProMdlWindowGet(model, &disobj_winId);
	if (status == PRO_TK_NO_ERROR) {
		m_dispObjectWindowId = disobj_winId;
	}

	if (result == PRO_UI_MESSAGE_YES)  // Delete existing display object
	{
		status = ProDispObjectDetach(disobj_winId, dispobj_keylist1);

		status = ProDispObjectDelete(&curveDisp_obj);

		status = ProArrayFree((ProArray*)&dispobj_keylist1);

		curveDisp_obj = NULL;
	}

	status = ProDispObjectCreate(L"test_curvedisp_obj", PRO_DISP_OBJECT_TWO_SIDED,
		1, strip_size, strip_arr, &curveDisp_obj);

	// Setting appearance porperties for display object
	surf_appear.ambient = 0.5;
	surf_appear.shininess = 0.2;
	surf_appear.highlite = 0.1;
	surf_appear.color_rgb[0] = 0.0;
	surf_appear.color_rgb[1] = 0.0;
	surf_appear.color_rgb[2] = 1.0;
	surf_appear.transparency = 0.3;
	surf_appear.diffuse = 0.80;
	surf_appear.highlight_color[0] = 0.10;
	surf_appear.highlight_color[1] = 0.20;
	surf_appear.highlight_color[2] = 0.60;
	surf_appear.reflection = 0.000000;

	status = ProMdlTypeGet(model, &topMdlType);

	// For top model assembly, checking for selected entities component path
	if (topMdlType == PRO_MDL_ASSEMBLY)
	{
		status = ProSelectionAsmcomppathGet(p_sel[0], &pCompPath);

		if (pCompPath.table_num > 0)
		{
			int arrayCount;

			sAsmComp.type = PRO_FEATURE;
			sAsmComp.id = pCompPath.comp_id_table[pCompPath.table_num - 1];
			sAsmComp.owner = owner;

			status = ProArrayAlloc(0, sizeof(int), 1, (ProArray*)&cIdTablel);

			for (arrayCount = 0; arrayCount < pCompPath.table_num; arrayCount++)
			{
				status = ProArrayObjectAdd((ProArray*)&cIdTablel,
					PRO_VALUE_UNUSED, 1, &pCompPath.comp_id_table[arrayCount]);
			}
			isCompPath = PRO_B_TRUE;
		}
		else
			isCompPath = PRO_B_FALSE;
	}

	if (status == PRO_TK_NO_ERROR)
	{
		// Attach display object 
		status = ProDispObjectAttach((int)disobj_winId, curveDisp_obj, (isCompPath == PRO_B_TRUE ? cIdTablel : NULL), feat_id, transform);

		surf_appear.color_rgb[0] = 0.0;
		surf_appear.color_rgb[1] = 0.0;
		surf_appear.color_rgb[2] = 1.0;

		status = ProArrayAlloc(0, sizeof(int), 1, (ProArray*)&dispobj_keylist1);

		if (isCompPath == PRO_B_TRUE)
		{
			int arrayCount = -1, ii = -1;

			status = ProArraySizeGet(cIdTablel, &arrayCount);

			for (ii = 0; ii < arrayCount; ii++)
			{
				status = ProArrayObjectAdd((ProArray*)&dispobj_keylist1,
					PRO_VALUE_UNUSED, 1, &cIdTablel[ii]);
			}
		}

		status = ProArrayObjectAdd((ProArray*)&dispobj_keylist1,
			PRO_VALUE_UNUSED, 1, &feat_id);

		// Set appearance properties to display object 
		status = ProDispObjectSetSurfaceAppearanceProps((int)disobj_winId, dispobj_keylist1, surf_appear);
	}

	/* Call repaint */
	status = ProWindowRepaint(disobj_winId);

	status = ProArrayFree((ProArray*)&(strip_arr[0]));

	status = ProArrayFree((ProArray*)&strip_arr);

	status = ProArrayFree((ProArray*)&strip_size);

	if (isCompPath == PRO_B_TRUE)
	{
		status = ProArrayFree((ProArray*)&cIdTablel);
	}

	return status;
}

ProError DispObjectRenderer::RenderDispObjectMesh()
{
	ProError status = PRO_TK_NO_ERROR;
	ProMdl model = NULL;
	ProMatrix transform = { { 1.0, 0.0, 0.0, 0.0},
							  { 0.0, 1.0, 0.0, 0.0},
							  { 0.0, 0.0, 1.0, 0.0},
							  { 0.0, 30.0, 0.0, 1.0} };
	float spiralSurfPtsRem, normal[3] = { 0.0,   0.0, 1.0 };
	int* strip_size, spiralSurfPts, reminderVal, facetCount;
	ProTriVertex** strip_arr = NULL;
	ProSurfaceAppearanceProps surf_appear;
	ProMatrix CompMatrix;
	ProSelection* p_sel;
	int i = -1, n_sel = -1, j;
	ProMdl owner;
	ProModelitem modelitem;
	ProCurve curve;
	Pro3dPnt* p_points;
	ProSurface pSurface;
	ProTessellation surfTessellation;
	Pro3dPnt* surfVertices;
	ProVector* surfNormals;
	ProSurfaceTessellationInput inputData;
	ProTriVertex tempTriVertex;
	ProTriangle* pFacets;
	ProMdlType topMdlType;
	ProAsmcomppath pCompPath;
	int* cIdTablel;
	ProBoolean isCompPath = PRO_B_FALSE;
	ProModelitem sAsmComp;
	ProCsys csys;
	ProGeomitemdata* pCsysDataPtr;
	int disobj_winId;
	ProUIMessageButton* buttons2;
	int feat_id = 118;
	ProUIMessageButton result = PRO_UI_MESSAGE_NO;

	if (surfDisp_obj != NULL) // If Display object exist then ask user to keep it or replace witn new one
	{
		ProArrayAlloc(2, sizeof(ProUIMessageButton), 1, (ProArray*)&buttons2);
		buttons2[0] = PRO_UI_MESSAGE_YES;
		buttons2[1] = PRO_UI_MESSAGE_NO;

		status = ProUIMessageDialogDisplay(PROUIMESSAGE_QUESTION, L"Delete existing surface display object",
			L"Code creates only one surface display object at a time. Do you want to delete existing surface display object?",
			buttons2, buttons2[1], &result);

		status = ProArrayFree((ProArray*)&buttons2);

		if (result == PRO_UI_MESSAGE_NO)
			return (PRO_TK_NO_ERROR);
	}

	//Select surface to created display object
	status = ProSelect((char*)"surface", 1, NULL, NULL, NULL, NULL, &p_sel,
		&n_sel);

	if (status != PRO_TK_NO_ERROR || n_sel < 1)
		return status;

	status = ProSelectionModelitemGet(p_sel[0], &modelitem);

	status = ProModelitemMdlGet(&modelitem, &owner);

	if (modelitem.type == PRO_SURFACE)
	{
		status = ProSurfaceInit((ProSolid)owner, modelitem.id, &pSurface);

		status = ProSurfacetessellationinputAlloc(&inputData);

		status = ProSurfacetessellationinputChordheightSet(inputData, PRO_SRFTESS_CHORD_HT_DEFAULT);

		status = ProSurfacetessellationinputAnglecontrolSet(inputData, 1);

		status = ProSurfacetessellationinputStepsizeSet(inputData, 1);

		status = ProSurfacetessellationinputUvprojectionSet(inputData, PRO_SRFTESS_DEFAULT_PROJECTION, NULL);

		// Getting surface tessellation data
		status = ProSurfaceTessellationGet(pSurface, inputData, &surfTessellation);

		status = ProTessellationVerticesGet(surfTessellation, &surfVertices);

		status = ProTessellationNormalsGet(surfTessellation, &surfNormals);

		// Getting facets from surface tessellation
		status = ProTessellationFacetsGet(surfTessellation, &pFacets);

		status = ProArraySizeGet(pFacets, &facetCount);
	}
	else
		return PRO_TK_BAD_INPUTS;

	status = ProArrayAlloc(facetCount, sizeof(ProTriVertex*), 1, (ProArray*)&strip_arr);

	// Each facet is added as a seperate strip so, number of strip arrays (ie strips)
	// is equal to number of facets
	for (i = 0; i < facetCount; i++)
	{
		status = ProArrayAlloc(0, sizeof(ProTriVertex), 1, (ProArray*)&(strip_arr[i]));
	}

	status = ProArrayAlloc(facetCount, sizeof(int), 1, (ProArray*)&strip_size);

	for (i = 0; i < facetCount; i++)
	{
		strip_size[i] = 3;

		for (j = 0; j < 3; j++)
		{
			tempTriVertex.pnt[0] = surfVertices[pFacets[i][j]][0];
			tempTriVertex.pnt[1] = surfVertices[pFacets[i][j]][1];
			tempTriVertex.pnt[2] = surfVertices[pFacets[i][j]][2];

			tempTriVertex.norm[0] = surfNormals[pFacets[i][j]][0];
			tempTriVertex.norm[1] = surfNormals[pFacets[i][j]][1];
			tempTriVertex.norm[2] = surfNormals[pFacets[i][j]][2];

			status = ProArrayObjectAdd((ProArray*)&(strip_arr[i]), PRO_VALUE_UNUSED, 1, &tempTriVertex);
		}
	}

	status = ProMdlCurrentGet(&model);
	if (status != PRO_TK_NO_ERROR)
		return status;

	disobj_winId = 0;
	status = ProMdlWindowGet(model, &disobj_winId);
	if (status == PRO_TK_NO_ERROR) {
		m_dispObjectWindowId = disobj_winId;
	}

	if (result == PRO_UI_MESSAGE_YES)  // Deletes existing display object
	{
		status = ProDispObjectDetach(disobj_winId, dispobj_keylist2);

		status = ProDispObjectDelete(&surfDisp_obj);

		status = ProArrayFree((ProArray*)&dispobj_keylist2);

		surfDisp_obj = NULL;
	}

	// Creates new display object
	status = ProDispObjectCreate(L"test_disp_obj", PRO_DISP_OBJECT_TWO_SIDED, facetCount, strip_size,
		strip_arr, &surfDisp_obj);

	// setting appearance porperties for display object
	surf_appear.ambient = 0.5;
	surf_appear.shininess = 0.2;
	surf_appear.highlite = 0.1;
	surf_appear.color_rgb[0] = 0.0;
	surf_appear.color_rgb[1] = 0.0;
	surf_appear.color_rgb[2] = 1.0;
	surf_appear.transparency = 0.5;
	surf_appear.diffuse = 0.80;
	surf_appear.highlight_color[0] = 0.10;
	surf_appear.highlight_color[1] = 0.20;
	surf_appear.highlight_color[2] = 0.60;
	surf_appear.reflection = 0.000000;

	if (status == PRO_TK_NO_ERROR)
	{
		status = ProMdlTypeGet(model, &topMdlType);

		if (topMdlType == PRO_MDL_ASSEMBLY)
		{
			// Getting component path
			status = ProSelectionAsmcomppathGet(p_sel[0], &pCompPath);

			if (pCompPath.table_num > 0)
			{
				int arrayCount;

				sAsmComp.type = PRO_FEATURE;
				sAsmComp.id = pCompPath.comp_id_table[pCompPath.table_num - 1];
				sAsmComp.owner = owner;

				status = ProArrayAlloc(0, sizeof(int), 1, (ProArray*)&cIdTablel);

				// Getting component ID table
				for (arrayCount = 0; arrayCount < pCompPath.table_num; arrayCount++)
				{
					status = ProArrayObjectAdd((ProArray*)&cIdTablel,
						PRO_VALUE_UNUSED, 1, &pCompPath.comp_id_table[arrayCount]);
				}
				isCompPath = PRO_B_TRUE;
			}
			else
				isCompPath = PRO_B_FALSE;
		}

		// Attaching display object
		status = ProDispObjectAttach((int)disobj_winId, surfDisp_obj, (isCompPath == PRO_B_TRUE ? cIdTablel : NULL), feat_id, transform);

		surf_appear.color_rgb[0] = 0.0;
		surf_appear.color_rgb[1] = 0.0;
		surf_appear.color_rgb[2] = 1.0;

		status = ProArrayAlloc(0, sizeof(int), 1, (ProArray*)&dispobj_keylist2);

		if (isCompPath == PRO_B_TRUE)
		{
			int arrayCount = -1, ii = -1;

			status = ProArraySizeGet(cIdTablel, &arrayCount);

			for (ii = 0; ii < arrayCount; ii++)
			{
				status = ProArrayObjectAdd((ProArray*)&dispobj_keylist2,
					PRO_VALUE_UNUSED, 1, &cIdTablel[ii]);
			}
		}

		status = ProArrayObjectAdd((ProArray*)&dispobj_keylist2,
			PRO_VALUE_UNUSED, 1, &feat_id);

		// Setting appearance properties on display object
		status = ProDispObjectSetSurfaceAppearanceProps((int)disobj_winId, dispobj_keylist2, surf_appear);
	}

	// Call repaint 
	status = ProWindowRepaint(disobj_winId);
	

	for (i = 0; i < facetCount; i++)
	{
		for (j = 0; j < 3; j++)
		{
			status = ProArrayFree((ProArray*)&(strip_arr[i]));
		}
	}

	status = ProArrayFree((ProArray*)&strip_arr);

	status = ProArrayFree((ProArray*)&strip_size);

	if (modelitem.type == PRO_SURFACE)
	{
		status = ProArrayFree((ProArray*)&surfVertices);

		status = ProArrayFree((ProArray*)&surfNormals);
	}

	if (isCompPath == PRO_B_TRUE)
	{
		status = ProArrayFree((ProArray*)&cIdTablel);
	}

	return PRO_TK_NO_ERROR;
}
