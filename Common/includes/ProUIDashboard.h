#ifndef PROUIDASHBOARD_H_
#define PROUIDASHBOARD_H_
 


#include <ProANSI.h>

PRO_BEGIN_C_DECLS

#include <ProToolkit.h>
#include <ProUI.h>
#include <ProSizeConst.h>

/****************************************************************************/
/*                             Dashboard TK Handles                         */
/****************************************************************************/

typedef void* ProUIDashboardShowOptions;
typedef void* ProUIDashboardPageOptions;

typedef void* ProUIDashboard;
typedef void* ProUIDashboardPage;


/****************************************************************************/
/*                           Dashboard TK Event Handlers                    */
/****************************************************************************/

typedef enum tpdf_ProUIDashboardEventType
{
  PRO_UI_DASHBOARD_CREATE   = 0,  /* Called on Dashboard create             */

  PRO_UI_DASHBOARD_HIDE     = 1,  /* Called on Dashboard hide. For example  */
                                  /* when another Dashboard is pushed       */

  PRO_UI_DASHBOARD_SHOW     = 2,  /* Called on Dashboard show               */

  PRO_UI_DASHBOARD_DESTROY  = 3,  /* Called on Dashboard exit               */

  PRO_UI_DASHBOARD_DISMISS  = 4,  /* Called on Dashboard close action       */
                                  /* PRO_TK_NO_ERROR = dashboard dismiss    */
                                  /* any other status means keep the        */
                                  /* dashboard active                       */
                                  
  PRO_UI_DASHBOARD_EXIT     = 5,  /* Called on switching from 
                                     current Dashboard Ribbon Page 
                                     to different Ribbon Page.*/
                                              
  PRO_UI_DASHBOARD_ENTER    = 6,  /* Called on switching to 
                                     Dashboard Ribbon Page from 
                                     different Ribbon Page.*/

  PRO_UI_DASHBOARD_MAX_CB
} ProUIDashboardEventType;

typedef enum tpdf_ProUIDashboardPageEventType
{
  PRO_UI_DASHBOARD_PAGE_CREATE   = 0, /* Called on Page create              */

  PRO_UI_DASHBOARD_PAGE_SHOW     = 1, /* Called on Page show                */

  PRO_UI_DASHBOARD_PAGE_HIDE     = 2, /* Called on page hide                */

  PRO_UI_DASHBOARD_PAGE_DESTROY  = 3, /* Called on page destroy             */

  PRO_UI_DASHBOARD_PAGE_MAX_CB
} ProUIDashboardPageEventType;

typedef ProError (*ProUIDashboardCallbackFunction) 
				(ProUIDashboard dashboard,
			         ProUIDashboardEventType event_type,
				 ProAppData appdata);
/*
    Purpose: This the function prototype for a callback invoked upon a 
             dashboard event.

    Input Arguments:
        dashboard - The dashboard handle.
        event_type - The event type that invoked this notification.
        appdata - Application data that was stored to be passed to this 
                  function.

    Output Arguments:
        none

    Return Values:
	PRO_TK_NO_ERROR - For a call of type PRO_UI_DASHBOARD_DISMISS only,
				indicates that the dismissal can proceed.  Otherwise ignored.
	Any other value - For a call of type PRO_UI_DASHBOARD_DISMISS only,
				indicates that the dismissal may not proceed.  Otherwise ignored.

*/

typedef ProError (*ProUIDashboardpageCallbackFunction)
				 (ProUIDashboardPage page,
				  ProUIDashboardPageEventType event_type,
			 	  ProAppData appdata);
/*
    Purpose: This is the function prototype for a callback function that will 
             be called upon a designated event in  a dashboard page.

    Input Arguments:
        page - Handle to the dashboard page.
        event_type - The type of event that invoked this callback.
        appdata - Application data that was stored to be passed to this 
                  function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.

*/

/****************************************************************************/
/*          Dashboard TK Standard Layout Default Buttons          */
/****************************************************************************/

typedef enum tpdf_ProUIDashboardStdLayoutButton
{
  PRO_UI_DASHBOARD_BUTTON_PAUSE_RESUME = (1 << 0),
  PRO_UI_DASHBOARD_BUTTON_PREVIEW = (1 << 1),
  PRO_UI_DASHBOARD_BUTTON_OK = (1 << 2),
  PRO_UI_DASHBOARD_BUTTON_CANCEL = (1 << 3)
}ProUIDashboardStdLayoutButton;

/****************************************************************************/
/*                  Dashboard TK Pause/Resume states                        */
/****************************************************************************/

typedef enum tpdf_ProUIDashboardPauseResumeButtonState
{
  ProUIDashboardButtonPauseState,
  ProUIDashboardButtonResumeState
}ProUIDashboardPauseResumeButtonState;

typedef char   ProUIDashboardButtonName[PRO_NAME_SIZE];
typedef char   ProUIDashboardButtonLabel[PRO_LINE_SIZE];
typedef char   ProUIDashboardButtonIcon[PRO_LINE_SIZE];
typedef char   ProUIDashboardButtonHelp[PRO_LINE_SIZE];

/****************************************************************************/
/*                       Dashboard TK Page states                           */
/****************************************************************************/

typedef enum tpdf_ProUIDashboardPageState
{
  PRO_UI_DASHBOARD_PAGE_DEFAULT_STATE = 0, 

  PRO_UI_DASHBOARD_PAGE_WARNING_STATE = 1,

  PRO_UI_DASHBOARD_PAGE_ERROR_STATE   = 2
  
}ProUIDashboardPageState;

/****************************************************************************/
/*                         Dashboard TK APIs                                */
/****************************************************************************/

LIB_UITOOLS_API  ProError ProUIDashboardpageoptionsAlloc (char*         page_name, 
						char*         resource_name,
						ProAppData    application_data,
					ProUIDashboardPageOptions* options);
/*
    Purpose: Allocates a handle representing a single page (or layout) that 
             will be shown in a dashboard.

    Input Arguments:
        page_name - The page name (must be unique).
        resource_name - Name of the resource file to use (whose top component 
                        must be a layout, not a dialog).  If NULL, an empty 
                        default layout is used.
        application_data - Application data stored for the page.

    Output Arguments:
        options - A handle representing a dashboard page.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageoptionsFree
				 (ProUIDashboardPageOptions options);
/*
    Purpose: Frees a handle representing a single page (or layout) that will be 
             shown in a dashboard.

    Input Arguments:
        options - A handle representing a dashboard page.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageoptionsNotificationSet
			 (ProUIDashboardPageOptions options,
			  ProUIDashboardpageCallbackFunction notification,
			  ProAppData appdata);
/*
    Purpose: Assigns a function to be called upon a certain event occurring in 
             the dashboard.

    Input Arguments:
        options - A handle representing a dashboard page.
        notification - The function to be called upon the designated event 
                       occurrence.
        appdata - Application data passed to the callback function upon 
                  invocation.   Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsAlloc
			 (ProUIDashboardPageOptions  main_page,
			  ProUIDashboardPageOptions* slideup_pages,
		          ProAppData                 appdata,
			  ProUIDashboardShowOptions* dashboard_options);
/*
    Purpose: Allocates a handle containing data used to build a dashboard.

    Input Arguments:
        main_page - The main page for the dashboard.
        slideup_pages - ProArray of handles representing slideup pages. 
                        Can be NULL.
        appdata - Application data to be stored with the dashboard.  Can be 
                  NULL.

    Output Arguments:
        dashboard_options - The handle to data used to build the dashboard.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsTitleSet(
                         ProUIDashboardShowOptions  dash_options,
                         const wchar_t*             title);
/*
    Purpose: Sets the dashboard title label.

    Input Arguments:
        dash_options - The handle to the data used to build the dashboard
        title - dashboard title to set.
    
    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsIconSet(
                            ProUIDashboardShowOptions  dash_options,
                            const char*                icon);
/*
    Purpose: Sets the dashboard icon.

    Input Arguments:
        dash_options - The handle to the data used to build the dashboard
        icon - dashboard icon to set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsHelpTextSet(
                            ProUIDashboardShowOptions  dash_options,
                            const wchar_t*             help_text);
/*
    Purpose: Sets the dashboard help text.

    Input Arguments:
        dash_options - The handle to the data used to build the dashboard
        help_text    - dashboard help text to set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsDefaultOpenSet(
                            ProUIDashboardShowOptions  dash_options,
                            const char*                page_name);
/*
Purpose: Sets the dashboard open by default page.

Input Arguments:
dash_options - The handle to the data used to build the dashboard
page_name    - The page name to be opened by default

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR - The function succeeded.
PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsFree 
			(ProUIDashboardShowOptions dashboard_options);
/*
    Purpose: Frees a handle containing data used to build a dashboard.

    Input Arguments:
        dashboard_options - The handle to data used to build the dashboard.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardshowoptionsNotificationSet
			 (ProUIDashboardShowOptions      options,
			  ProUIDashboardCallbackFunction notification,
			  ProAppData                     appdata);
/*
    Purpose: Assigns a callback function to called for the indicated event 
             occurrence in the dashboard.

    Input Arguments:
        options - A handle to data used to build a dashboard.
        notification - The notification function to be called for the given 
                       event.
        appdata - Application data to be passed to the callback function when 
                  it is invoked.  Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardShow (ProUIDashboardShowOptions options );
/*
    Purpose: Push a new dashboard UI into the dashboard stack mechanism.  The 
             dashboard will be shown in the message area of Creo Parametric.
	     This function creates an event loop - thus does not exit
	     until the dashboard is being dismissed.

    Input Arguments:
        options - Required data for building the dashboard.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded in displaying the dashboard,
	                  and was later dismissed by ProUIDashboardDestroy() or other UI events.
	PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUIDashboardDestroy()
*/

LIB_UITOOLS_API  ProError ProUIDashboardDestroy (ProUIDashboard dashboard_handle);
/*
    Purpose: Pop the dashboard from the dashboard stack mechanism.  The 
             dashboard UI will be destroyed.

    Input Arguments:
        dashboard_handle - The dashboard handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUIDashboardShow()
*/

LIB_UITOOLS_API  ProError ProUIDashboardUserdataGet (ProUIDashboard dashboard,
					   ProAppData* user_data);
/*
    Purpose: Obtains the application data stored with this dashboard upon 
             registration.

    Input Arguments:
        dashboard - The dashboard handle.

    Output Arguments:
        user_data - The applicaton data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardPageGet (ProUIDashboard dashboard, 
				       char*          name,
				       ProUIDashboardPage* page);
/*
    Purpose: Obtains the handle to a given page from the dashboard.

    Input Arguments:
        dashboard - The dashboard handle.
        name - The page name.  Pass NULL to get the handle to the main page.

    Output Arguments:
        page - The handle to the dashboard page.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_FOUND - The dashboard does not contain the given page.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageDevicenameGet (ProUIDashboardPage page,
						 char** device_name);
/*
    Purpose: Obtains the device name.  This name should be used in other 
             Creo Parametric TOOLKIT ProUI functions to access the components stored in the 
             dashboard page.

    Input Arguments:
        page - The handle to the dashboard page.

    Output Arguments:
        device_name - The device name.  Free this string using 
                      ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageUserdataGet (ProUIDashboardPage page,
					       ProAppData* user_data);
/*
    Purpose: Obtains the application stored with this dashboard page on 
             registration.

    Input Arguments:
        page - The handle to the dashboard page.

    Output Arguments:
        user_data - The application data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageClose (ProUIDashboardPage page);
/*
    Purpose: Closes the dashboard slide-up page.

    Input Arguments:
        page - The dashboard page handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The page is the main page and cannot be closed.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageOpen(ProUIDashboardPage page);

/*
    Purpose: Opens specified dashboard page

    Input Arguments:
        page  - The dashboard page handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - Failed to open the page.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageIsOpen(ProUIDashboardPage page, ProBoolean* is_open);

/*
    Purpose: Check if specified dashboard page is open

    Input Arguments:
        page  - The dashboard page handle.


    Output Arguments:
        is_open - PRO_B_TRUE if open

    Return Values:
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function faild.
*/

LIB_UITOOLS_API  ProError ProUIDashboardpageTitleSet (ProUIDashboardPage page,
					    wchar_t*           title);
/*
    Purpose: Assigns the title string for the dashboard page.  This will be 
             shown as the button name for the slide-up panel.

    Input Arguments:
        page - The dashboard page handle.
        title - The title string.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageDashboardGet (ProUIDashboardPage page,
						ProUIDashboard*    dashboard);
/*
    Purpose: Obtains the dashboard that owns this page.

    Input Arguments:
        page - The dashboard page handle.

    Output Arguments:
        dashboard - The dashboard handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageNameGet (ProUIDashboardPage page,
					   char**             name);
/*
    Purpose: Obtains the name of the page.

    Input Arguments:
        page - The dashboard page handle.

    Output Arguments:
        name - The page name.  Free this string using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dashboard page is the main page and does not 
                             have a user-defined name.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageComponentnameGet (ProUIDashboardPage page,
						    char*    nominal_name,
						    char**   component_name);
/*
    Purpose: Obtains the real component name in the dashboard page.  This name 
             should be used in ProUI functions for accessing a component in the 
             dashboard.

    Input Arguments:
        page - The dashboard page handle.
        nominal_name - The nominal component name from the resource file used 
                       to generate this page.  To get the name of the top-most
		       layout for the page, pass "".
  

    Output Arguments:
        component_name - The true component name to use for this instance of 
                         the dashboard page.  Free this string using 
                         ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The component by this name was not found in the 
                             page.

*/

LIB_UITOOLS_API  ProError ProUIDashboardStdlayoutGet (ProUIDashboard dashboard,
					    char**         std_layout);
/*
    Purpose: Obtains the standard layout name typically used for placement of 
             OK and cancel buttons.

    Input Arguments:
        dashboard - The dashboard handle.

    Output Arguments:
        std_layout - The standard layout name.  Free this string using 
                     ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


LIB_UITOOLS_API  ProError ProUIDashboardBitmapSet (ProUIDashboard dash_hnd, char* image);
/*
    Purpose: Assigns the icon for the dashboard, which appears to the left of
             the slideup panel buttons.

    Input Arguments:
        dash_hnd - The dashboard handle.
        image - The name of the file (.GIF or .BIF) to use for the tool icon.
    
    Output Arguments:
        none
    
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageForegroundcolorSet (ProUIDashboardPage page, ProUIColor color);
/*
    Purpose: Assigns the text color for the button name that opens the slide-up panel.

    Input Arguments:
        page - The dashboard page handle.
        color - The color to use for the title text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDashboardStdlayoutDefaultBtnsAdd(
  ProUIDashboardPage page_handle,
  ProUIDashboardStdLayoutButton buttons
);
/*
  Purpose: Adds a new standard push buttons to the dashboard of Creo Parametric.
            This function affects the top-level Creo Parametric dashboard only.

  Input Arguments:
      pageHandler    - Handle to the dashboard page.
      buttons        - Bit mask to identify which buttons to add.

  Output Arguments:
      none

  Return Values:
      PRO_TK_NO_ERROR       - The function successfully added the buttons.
      PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
      PRO_TK_GENERAL_ERROR  - Failed to add one of the buttons.
*/

extern ProError ProUIDashboardStdlayoutButtonAdd(
  ProUIDashboardPage page_handle,
  ProUIDashboardButtonName button_name,
  ProUIDashboardButtonLabel button_label,
  ProUIDashboardButtonHelp one_line_help,
  ProUIDashboardButtonIcon icon,
  ProFileName filename
);
/*
  Purpose: Adds a new push button to the dashboard of Creo Parametric.
           This function affects the top-level Creo Parametric dashboard only.
           This function is executed only once during a Creo Parametric
           session for each push button. Subsequent calls to this function
           for a previously loaded push button are ignored.
  Input Arguments:
     page_handle               - Handle to the dashboard page.
     buttonName                - The name of the push button (must be unique)
     button_label              - The label of the push button
     one_line_help             - The one-line help for the push button
     image                     - The image of the push button
     filename                  - The name of the message file that contains the
                                 label and help string

  Output Arguments: 
    None

  Return Values:
     PRO_TK_NO_ERROR           - The function successfully added the button.
     PRO_TK_BAD_INPUTS         - One or more input arguments was invalid.
     PRO_TK_GENERAL_ERROR      - The function failed to add the button.
     PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the
                               message file.
*/

extern ProError ProUIDashboardStdlayoutDefaultButtonNameGet(
  ProUIDashboardPage page_handle,
  ProUIDashboardStdLayoutButton button_id,
  char **button_name
);
/*
  Purpose: Get default button name.

  Input Arguments:
    page_handle            - Handle to the dashboard page.
    button_id              - Id of the button.

  Output Arguments:
    button_name -   The Button's name. Free this string using ProStringFree()

  Return Values:
    PRO_TK_NO_ERROR        - The function returned the name.
    PRO_TK_E_NOT_FOUND     - No standard button has this id.
    PRO_TK_BAD_INPUTS      - One or more input arguments was invalid.
*/

extern ProError ProUIDashboardPauseresumeButtonStateGet(
  ProUIDashboardPage page_handle,
  ProUIDashboardPauseResumeButtonState *state
);
/*
  Purpose: Get Pause\Resume button state.

  Input Arguments:
    page_handle            - Handle to the dashboard page.

  Output Arguments:
    state - the button's state, ProUIDashboardButtonPauseState if pause button is on,
                                ProUIDashboardButtonResumeState otherwise.

  Return Values:
    PRO_TK_NO_ERROR        - The function returned the current state.
    PRO_TK_BAD_INPUTS      - One or more input arguments was invalid.
    PRO_TK_E_NOT_FOUND     - Pause\Resume button does not exist.
*/

extern ProError ProUIDashboardPauseresumeButtonStateSet(
  ProUIDashboardPage page_handle,
  ProUIDashboardPauseResumeButtonState state
);
/*
  Purpose: Set Pause\Resume button state.

  Input Arguments:
    page_handle            - Handle to the dashboard page.
    state                  - the new button's state,
                              ProUIDashboardButtonPauseState for pause,
                              ProUIDashboardButtonResumeState otherwise.
  Output Arguments: 
    None

  Return Values:
    PRO_TK_NO_ERROR        - The function returned the current state.
    PRO_TK_BAD_INPUTS      - One or more input arguments was invalid.
    PRO_TK_E_NOT_FOUND     - Pause\Resume button does not exist.
*/

LIB_UITOOLS_API  ProError ProUIDashboardpageStateSet (ProUIDashboardPage page, 
                                                      ProUIDashboardPageState state);
/*
    Purpose: Modify the visibility of the button which opens the dashboard page
             according to the the page state.
             Affects the background and foreground of the button.

    Input Arguments:
        page  - The dashboard page handle.
        state - The state of the page.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - Failed to Modify the page button.

*/

LIB_UITOOLS_API  ProError ProUIDashboardpageVisibleSet (ProUIDashboardPage page, 
                                                        ProBoolean visible);
/*
    Purpose: Modify the visibility of the button which opens the dashboard page.

    Input Arguments:
    page    - The dashboard page handle.
    visible - The state of the page.

    Output Arguments:
    none

    Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
    PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
    PRO_TK_GENERAL_ERROR - Failed to Modify the page button.

*/

PRO_END_C_DECLS

#endif
