
#include "ProToolkit.h"

#include "ProMdl.h"
#include "ProMenu.h"
#include "ProMessage.h"
#include "ProNotify.h"
#include "ProObjects.h"
#include "ProUtil.h"
#include "ProTKRunTime.h"

static wchar_t msgfil[20];


/*===========================================================================*\
    The user_part_status() function reports the current part name and whether
    it has been modified since last saved.
\*===========================================================================*/
static void UserPartStatus()
{
    ProMessageDisplay(msgfil, "USER Current object: Tested!");
}


/*===========================================================================*\
    The UserCheckPart() function checks the validity of a part before
    saving it.
\*===========================================================================*/
ProError UserCheckPart(ProPath model_path)
{
    /*---------------------------------------------------------------------------*\
        user's checks go here
    \*---------------------------------------------------------------------------*/
    return(PRO_TK_NO_ERROR);
}

/*===========================================================================*\
    The function user_initialize() sets up the message file name,  the
    Pro/TOOLKIT menu buttons, and the notify options.
\*===========================================================================*/
extern "C" int user_initialize()
{
    int          menu_id;

    /*---------------------------------------------------------------------------*\
        Set up the message file name.
    \*---------------------------------------------------------------------------*/
    ProStringToWstring(msgfil, "usermsg.txt");
    /*---------------------------------------------------------------------------*\
        Set up the new button, "Status", on the PART menu.
    \*---------------------------------------------------------------------------*/
    ProMenuFileRegister("part", "part.mnu", &menu_id);
    ProMenuAuxfileRegister("part", "part.aux", &menu_id);
    ProMenubuttonActionSet("part", "Status",
        (ProMenubuttonAction)UserPartStatus, NULL, 0);
    /*---------------------------------------------------------------------------*\
        Set up the notify option to call the CHECK PART function before
        saving an object.
    \*---------------------------------------------------------------------------*/
    //ProNotificationSet(PRO_MODEL_SAVE_PRE, UserCheckPart);
    return (0);
}

/*---------------------------------------------------------------------------*\
    End the Pro/TOOLKIT application
\*---------------------------------------------------------------------------*/
extern "C" void user_terminate()
{
    ProTKPrintf("Pro/TOOLKIT application terminated successfully\n");
}
