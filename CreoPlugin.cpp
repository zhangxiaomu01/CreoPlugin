
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
ProError  ProTestInstallationCheck();
ProError  ProTestInstallationURLCheck();
static ProError ProTestStdCloseAction(char* dialog, char* component, ProAppData data);
ProError  ProTestDialogCreate(ProBoolean is_successful);

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
        (uiCmdCmdActFn)ProTestInstallationCheck,
        uiProe2ndImmediate, TestAccessDefault,
        PRO_B_TRUE, PRO_B_TRUE, &cmd_id);

    status = ProMenubarmenuPushbuttonAdd(
        "File", "-Install Test", "-Install Test Label", "Install Test Help",
        "File.psh_rename", PRO_B_TRUE, cmd_id, MSGFIL);

    /*---------------------------------------------------------------------*\
        New Button for URL in Embedded Browser
    \*---------------------------------------------------------------------*/

    status = ProCmdActionAdd("TOOLKIT Compilers",
        (uiCmdCmdActFn)ProTestInstallationURLCheck,
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
    ProTKPrintf("\n     Exec_path:  %s\n", cbuff1);
    ProTKPrintf("     Text_path:  %s\n\n", cbuff2);

    for (i = 0; i < argc; i++)
        ProTKPrintf("   argv[%d]: %s\n", i, argv[i]);

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

/*====================================================================*\
FUNCTION : ProTestInstallationCheck
PURPOSE  : Open a internationalized modal dialog with the test result
\*====================================================================*/
ProError  ProTestInstallationCheck()
{
    int 	window_id;
    ProError 	status;
    ProBoolean 	is_successful = PRO_B_FALSE;

    /* Call a sample Pro/TOOLKIT feature */
    status = ProWindowCurrentGet(&window_id);

    if (status == PRO_TK_NO_ERROR)
    {
        /* Set flag for a SUCCESS dialog */
        is_successful = PRO_B_TRUE;
    }
    else
    {
        /* Set flag for a FAILURE dialog */
        is_successful = PRO_B_FALSE;
    }

    /*---------------------------------------------------------------------*\
             Create and Display the dialog
    \*---------------------------------------------------------------------*/
    status = ProTestDialogCreate(is_successful);

    return (status);
}

/*====================================================================*\
FUNCTION : ProTestStdCloseAction
PURPOSE  : Close Action for Dialog
\*====================================================================*/
static ProError ProTestStdCloseAction(char* dialog, char* component, ProAppData data)
{
    ProError status;

    status = ProUIDialogExit(dialog, PRO_TK_NO_ERROR);
    return status;
}

/*====================================================================*\
FUNCTION : ProTestInstallationURLCheck
PURPOSE  : Open the URL for PTC Supports Web Page in Embedded Browser
\*====================================================================*/
ProError  ProTestInstallationURLCheck()
{
    int 	window_id;
    ProError 	status;
    ProComment 	url;

    /*---------------------------------------------------------------------*\
             Call a sample Pro/TOOLKIT feature
    \*---------------------------------------------------------------------*/
    status = ProWindowCurrentGet(&window_id);

    if (status == PRO_TK_NO_ERROR)
    {
        /*---------------------------------------------------------------------*\
                 Load a sample URL
        \*---------------------------------------------------------------------*/
        ProStringToWstring(url, "http://www.ptc.com/partners/hardware/current/support.htm");
        status = ProWindowURLShow(window_id, url);
    }

    return (status);
}

/*====================================================================*\
FUNCTION : ProTestDialogCreate
PURPOSE  : Common utility for creation of dialog
\*====================================================================*/
ProError  ProTestDialogCreate(ProBoolean  is_successful)
{
    ProMdl 	model;
    int 	dialog_status;
    ProError 	status;
    ProComment  message_wchar;
    ProComment  title_wchar;

    char* dialog = "pt_install_dialog";

    status = ProUIDialogCreate(dialog, dialog);

    status = ProUIDialogCloseActionSet(dialog,
        (ProUIAction)ProTestStdCloseAction, NULL);

    status = ProUIPushbuttonActivateActionSet(dialog, "CloseBtn",
        (ProUIAction)ProTestStdCloseAction, NULL);

    if (is_successful == PRO_B_TRUE)
    {
        status = ProMessageToBuffer(message_wchar, MSGFIL, "USER Succeeded");
    }
    else
    {
        status = ProMessageToBuffer(message_wchar, MSGFIL, "USER Failed");
    }

    status = ProUILabelTextSet(dialog, "Message", message_wchar);

    status = ProUIDialogActivate(dialog, &dialog_status);

    status = ProUIDialogDestroy(dialog);

    return (status);
}

