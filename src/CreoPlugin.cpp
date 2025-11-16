
#include "pch.h"
#include "framework.h"

/*--------------------------------------------------------------------*\
Pro/Toolkit includes
\*--------------------------------------------------------------------*/
#include <ProToolkit.h>
#include <Pro2dEntdef.h>
#include <ProANSI.h>
#include <ProAnalysis.h>
#include <ProAnimate.h>
#include <ProArray.h>
#include <ProAsmcomp.h>
#include <ProAsmcomppath.h>
#include <ProAssembly.h>
#include <ProAutodrill.h>
#include <ProAxis.h>
#include <ProCabling.h>
#include <ProCavitylayout.h>
#include <ProCavlayrule.h>
#include <ProChamfer.h>
#include <ProClCmd.h>
#include <ProClcmdElem.h>
#include <ProCollect.h>
#include <ProColor.h>
#include <ProComm.h>
#include <ProConst.h>
#include <ProContour.h>
#include <ProContourdata.h>
#include <ProCopyGeom.h>
#include <ProCore.h>
#include <ProCsys.h>
#include <ProCsysdata.h>
#include <ProCurve.h>
#include <ProCurvedata.h>
#include <ProDatumdata.h>
#include <ProDimension.h>
#include <ProDisplist.h>
#include <ProDrawing.h>
#include <ProDtlattach.h>
#include <ProDtlentity.h>
#include <ProDtlgroup.h>
#include <ProDtlitem.h>
#include <ProDtlnote.h>
#include <ProDtlsymdef.h>
#include <ProDtlsyminst.h>
#include <ProDtmAxis.h>
#include <ProDtmCrv.h>
#include <ProDtmCrvSketch.h>
#include <ProDtmCsys.h>
#include <ProDtmPln.h>
#include <ProDtmPnt.h>
#include <ProDwgtable.h>
#include <ProEdge.h>
#include <ProEdgedata.h>
#include <ProElemId.h>
#include <ProElement.h>
#include <ProElempath.h>
#include <ProExpldstate.h>
#include <ProExtdata.h>
#include <ProExtobj.h>
#include <ProExtobjCB.h>
#include <ProExtobjDisp.h>
#include <ProExtobjRef.h>
#include <ProExtobjSel.h>
#include <ProExtrude.h>
#include <ProFaminstance.h>
#include <ProFamtable.h>
#include <ProFeatForm.h>
#include <ProFeatIntr.h>
#include <ProFeatType.h>
#include <ProFeature.h>
#include <ProFemMesh.h>
#include <ProFemObjects.h>
#include <ProFlatSrf.h>
#include <ProForeignCurve.h>
#include <ProGeomitem.h>
#include <ProGeomitemdata.h>
#include <ProGraphic.h>
#include <ProGroup.h>
#include <ProGtol.h>
#include <ProHardware.h>
#include <ProHole.h>
#include <ProImm.h>
#include <ProImportfeat.h>
#include <ProIntf3Dexport.h>
#include <ProIntfData.h>
#include <ProIntfimport.h>
#include <ProItemerr.h>
#include <ProJlink.h>
#include <ProLayer.h>
#include <ProMaterial.h>
#include <ProMdl.h>
#include <ProMdlChk.h>
#include <ProMenu.h>
#include <ProMenuBar.h>
#include <ProMessage.h>
#include <ProMfg.h>
#include <ProMfgdb.h>
#include <ProMfgoper.h>
#include <ProModFeat.h>
#include <ProMode.h>
#include <ProModelitem.h>
#include <ProMoldbase.h>
#include <ProNcseq.h>
#include <ProNcseqElem.h>
#include <ProNote.h>
#include <ProNotify.h>
#include <ProObjects.h>
#include <ProParameter.h>
#include <ProParamval.h>
#include <ProPart.h>
#include <ProPattern.h>
#include <ProPecktable.h>
#include <ProPiping.h>
#include <ProPoint.h>
#include <ProPrint.h>
#include <ProProcstep.h>
#include <ProQuilt.h>
#include <ProQuiltdata.h>
#include <ProRefInfo.h>
#include <ProRelSet.h>
#include <ProReplace.h>
#include <ProRevolve.h>
#include <ProRib.h>
#include <ProRmdt.h>
#include <ProRule.h>
#include <ProScope.h>
#include <ProSecConstr.h>
#include <ProSecdim.h>
#include <ProSecdimType.h>
#include <ProSecerror.h>
#include <ProSection.h>
#include <ProSelection.h>
#include <ProSheetmetal.h>
#include <ProShrinkwrap.h>
#include <ProSimprep.h>
#include <ProSimprepdata.h>
#include <ProSizeConst.h>
#include <ProSkeleton.h>
#include <ProSolid.h>
#include <ProStdSection.h>
#include <ProSurface.h>
#include <ProSurfacedata.h>
#include <ProSweep.h>
#include <ProTool.h>
#include <ProToolElem.h>
#include <ProToolinput.h>
#include <ProToolkitDll.h>
#include <ProUI.h>
#include <ProUICascadebutton.h>
#include <ProUICheckbutton.h>
#include <ProUICmd.h>
#include <ProUIDialog.h>
#include <ProUIInputpanel.h>
#include <ProUILabel.h>
#include <ProUILayout.h>
#include <ProUIList.h>
#include <ProUIMenubar.h>
#include <ProUIMenupane.h>
#include <ProUIMessage.h>
#include <ProUIOptionmenu.h>
#include <ProUIProgressbar.h>
#include <ProUIPushbutton.h>
#include <ProUIRadiogroup.h>
#include <ProUISlider.h>
#include <ProUISpinbox.h>
#include <ProUITab.h>
#include <ProUITable.h>
#include <ProUITextarea.h>
#include <ProUIThumbwheel.h>
#include <ProUdf.h>
#include <ProUtil.h>
#include <ProUvStat.h>
#include <ProValue.h>
#include <ProVerstamp.h>
#include <ProView.h>
#include <ProWcell.h>
#include <ProWchar.h>
#include <ProWeld.h>
#include <ProWindows.h>
#include <ProWorkspace.h>
#include <ProWstring.h>
#include <ProXsec.h>
#include <ProTKRunTime.h>

#include "../thirdParty/logger/EasyLog.hpp"
#include "DispObjectRenderer.h"
#include "ModelIterator.h"

/*--------------------------------------------------------------------*\
Application includes
\*--------------------------------------------------------------------*/
#include <time.h>

/*--------------------------------------------------------------------*\
Application global/external data
\*--------------------------------------------------------------------*/
static wchar_t  MSGFIL[] = { 'm','s','g','_','u','s','e','r','.','t','x','t','\0' };
static char revcode[PRO_LINE_SIZE];

/* Declare function */
ProError UserZoomAtSelPoint();

int	 ProDispObjectSelectEntitySet(ProType*, ProType);

// Function to create display object on selected surface
ProError PTTestDispObjectSurf()
{
    DispObjectRenderer dispObjectRenderer;
    NDSMatrix meshMatrix;
    meshMatrix.matrix[0] = 100.0;
    meshMatrix.matrix[5] = 100.0;
    meshMatrix.matrix[10] = 100.0;

    ProError status = PRO_TK_NO_ERROR;
    //for (int ii = 0; ii < 2; ++ii) {
    //    meshMatrix.matrix[13] = -250.0 * ii;
    //    status = dispObjectRenderer.RenderTestBox(meshMatrix);
    //}

    for (int ii = 0; ii < 2; ++ii) {
        meshMatrix.matrix[14] = -40.0 * ii;
        status = dispObjectRenderer.RenderTestRectLine(meshMatrix);
    }

	return status;
}

ProError CollectObjectInfo() {
    ProError status = PRO_TK_NO_ERROR;

    ModelIterator modelIterator;
    modelIterator.CollectModelNode();

    std::string path = "0_0";
    status = modelIterator.RefitToModel(path);

    return status;
}

static uiCmdAccessState TestAccessDefault(uiCmdAccessMode access_mode)
{
    return (ACCESS_AVAILABLE);
}


/*====================================================================*\
FUNCTION : user_initialize()
PURPOSE  : Pro/DEVELOP standard initialize - define menu button
\*====================================================================*/
extern "C" int user_initialize(
    int argc,
    char* argv[],
    char* version,
    char* build,
    wchar_t errbuf[80])
{

    char cbuff1[PRO_PATH_SIZE], cbuff2[PRO_PATH_SIZE];
    char astr1[PRO_LINE_SIZE];
    int i, menu_id;
    ProPath wbuff1, wbuff2;
    ProError status;
    uiCmdCmdId	cmd_id;

    ProUITranslationFilesEnable();

    initLogger("E:/Newdim/Project/Logs/mylogfile.log", ldebug);

    L_(linfo) << "Plugin initializing...";

    //L_(lwarning) << "Ops, variable x should be " << 5 << "; is " << 6;

    /*---------------------------------------------------------------------*\
        First confirm the size of wchar_t
    \*---------------------------------------------------------------------*/
    status = ProWcharSizeVerify(sizeof(wchar_t), &i);

    if (status != PRO_TK_NO_ERROR || (i != sizeof(wchar_t)))
    {
        ProTKSprintf(astr1, "ERROR wchar_t Incorrect size (%d). Should be: %d",
            sizeof(wchar_t), i);
        status = ProMessageDisplay(MSGFIL, "USER %0s", astr1);

        ProTKPrintf("%s\n", astr1);
        ProStringToWstring(errbuf, astr1);
        return(-1);
    }

    /*---------------------------------------------------------------------*\
        Add new button to the menu bar
    \*---------------------------------------------------------------------*/
    ProTKSprintf(revcode, "%s - %s", version, build);

    ProMessageDisplay(MSGFIL, "USER %0s", "");
    status = ProCmdActionAdd("-Install Test",
        (uiCmdCmdActFn)CollectObjectInfo,
        uiProe2ndImmediate, TestAccessDefault,
        PRO_B_TRUE, PRO_B_TRUE, &cmd_id);

    status = ProMenubarmenuPushbuttonAdd(
        "File", "-Install Test", "-Install Test Label", "Install Test Help",
        "File.psh_rename", PRO_B_TRUE, cmd_id, MSGFIL);

    /*---------------------------------------------------------------------*\
        New Button for URL in Embedded Browser
    \*---------------------------------------------------------------------*/

    status = ProCmdActionAdd("TOOLKIT Compilers",
        (uiCmdCmdActFn)PTTestDispObjectSurf,
        uiProe2ndImmediate, TestAccessDefault,
        PRO_B_TRUE, PRO_B_TRUE, &cmd_id);

    status = ProMenubarmenuPushbuttonAdd("Help",
        "TOOLKIT Compilers", "Creo Parametric TOOLKIT Compilers Label", "Creo Parametric TOOLKIT Compilers Help",
        NULL, PRO_B_TRUE, /* Always add at the bottom of the Help Menubar */
        cmd_id, MSGFIL);


    /*---------------------------------------------------------------------*\
        Print the protk.dat  info
    \*---------------------------------------------------------------------*/

    status = ProToolkitApplExecPathGet(wbuff1);

    status = ProToolkitApplTextPathGet(wbuff2);

    ProWstringToString(cbuff1, wbuff1);
    ProWstringToString(cbuff2, wbuff2);

    L_(linfo) << "Execute path: " << cbuff1;
    L_(linfo) << "App text path: " << cbuff2;

    endLogger();
    /* Upon success */
    return (0);

#if 0
    /* If unsuccessful, return non-zero.
     * You may store an error message in errbuf.
     * The return value and error message will be displayed to the user.
     * Pro/ENGINEER will call user_terminate() and shut down your application
     */
    ProStringToWstring(errbuf, "Sample error message");
    return(-1);
#endif
}

/*====================================================================*\
FUNCTION : user_terminate()
PURPOSE  : To handle any termination actions
\*====================================================================*/
extern "C" void user_terminate()
{

    ProTKPrintf("user_terminate\n");
}

/*=====================================================================*\
FUNCTION: UserZoomAtSelPoint
PURPOSE:  Zooms window in by factor of 2 at selected point on a solid model.
\*=====================================================================*/
ProError UserZoomAtSelPoint()
{
    int windowId = -1;
    ProError status = ProWindowCurrentGet(&windowId);
    if (windowId > 0) {
        status = ProWindowRefit(windowId);

        // ProViewRefit(); // Should be good engough!
    }

    return status;


    //ProError status;
    ProSelection* p_sel;
    int n_sel;
    ProAsmcomppath	comp_path;
    ProPoint3d p3d;
    ProMatrix	matrix, zoom_matrix;
    ProPoint3d t_point;
    ProFileName msgfile;
    ProModelitem item;
    ProMdl top_model;

    ProPoint3d scrpnt;
    int i, j, k;
    int window;
    double scale;

    /*--------------------------------------------------------------------*\
        The Pro/ENGINEER "virtual window".  Used to calculate the amount
        of pan needed to center the zoomed window on the chosen point.
    \*--------------------------------------------------------------------*/
    double window_outline[2][3] = { {0.0, 0.0, 0.0}, {1000.0, 843.75, 0.0} };

    ProStringToWstring(msgfile, "msg_uggraph.txt");

    /*-----------------------------------------------------------------*\
        Prompt the user to select the center of the zoom
    \*-----------------------------------------------------------------*/
    ProMessageDisplay(msgfile,
        "USER Select a location on a solid model for zoom ");

    status = ProSelect("prt_or_asm", 1, NULL, NULL, NULL, NULL,
        &p_sel, &n_sel);
    if (status != PRO_TK_NO_ERROR)
        return (status);

    /*-----------------------------------------------------------------*\
        Get the selected point
    \*-----------------------------------------------------------------*/
    ProSelectionPoint3dGet(p_sel[0], p3d);

    /*-----------------------------------------------------------------*\
        Get the assembly component path for the selected component
    \*-----------------------------------------------------------------*/
    status = ProSelectionAsmcomppathGet(p_sel[0], &comp_path);
    if (status == PRO_TK_NO_ERROR && comp_path.owner != NULL)
    {

        top_model = comp_path.owner;
        /*-----------------------------------------------------------------*\
            Get the coordinate transformation matrix for the component to
                the assembly
        \*-----------------------------------------------------------------*/
        ProAsmcomppathTrfGet(&comp_path, PRO_B_TRUE, matrix);

        /*-----------------------------------------------------------------*\
            Transform the selected point into the coordinate system of the
                top level assembly
        \*-----------------------------------------------------------------*/
        status = ProPntTrfEval(p3d, matrix, t_point);

    }
    else
    {

        /*-----------------------------------------------------------------*\
            If the selection is the top level component prepare the needed
            parameters for zooming
        \*-----------------------------------------------------------------*/
        ProSelectionModelitemGet(p_sel[0], &item);
        top_model = item.owner;
        memcpy(t_point, p3d, sizeof(ProPoint3d));
    }

    /*-----------------------------------------------------------------*\
        Get the view transformation matrix (from the current window)
    \*-----------------------------------------------------------------*/
    ProViewMatrixGet(top_model, NULL, matrix);

    /*-----------------------------------------------------------------*\
        Transform the solid model point to screen coordinates
    \*-----------------------------------------------------------------*/
    ProPntTrfEval(t_point, matrix, scrpnt);

    /*-----------------------------------------------------------------*\
        Get the window pan-zoom transformation matrix
    \*-----------------------------------------------------------------*/
    ProWindowCurrentMatrixGet(matrix);

    /*-----------------------------------------------------------------*\
        Zoom in on the created point
    \*-----------------------------------------------------------------*/
    for (j = 0; j < 4; j++)
    {
        for (k = 0; k < 4; k++)
            zoom_matrix[j][k] = 0.0;
    }

    /*-----------------------------------------------------------------*\
        Double the existing window scale
    \*-----------------------------------------------------------------*/
    scale = 2.0 * matrix[0][0];

    for (j = 0; j < 3; j++)
    {
        zoom_matrix[j][j] = scale;
        zoom_matrix[3][j] =
            (window_outline[1][j] - window_outline[0][j]) / 2.0 -
            scrpnt[j] * scale;
    }

    zoom_matrix[3][3] = 1.0;

    ProMdlWindowGet(top_model, &window);

    status = ProWindowPanZoomMatrixSet(window, zoom_matrix);

    /*-----------------------------------------------------------------*\
        Repaint the window
    \*-----------------------------------------------------------------*/
    ProWindowRepaint(window);

    return (status);
}
