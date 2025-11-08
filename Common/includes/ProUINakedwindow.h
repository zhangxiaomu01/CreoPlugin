

#ifndef __PROUINAKEDWINDOW_H__
#define __PROUINAKEDWINDOW_H__

#include <ProUI.h>

PRO_BEGIN_C_DECLS

extern ProError ProUINakedwindowHelptextSet (
    char                   *dialog, 
    char                   *component, 
    wchar_t                *value);

/*
    Purpose: Set the help text to display when the cursor is over the naked
             window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Help text to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowHelptextGet (
    char                   *dialog, 
    char                   *component, 
    wchar_t               **value);
/*
    Purpose: Get the help text that will be displayed when the cursor is over
                        the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Help text for the naked window. Free this using
                ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowShow (
    char   *dialog, 
    char   *component);
/*
    Purpose: Make the naked window visible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowHide (
    char   *dialog, 
    char   *component);
/*
    Purpose: Make the naked window invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsVisible (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: Determines if the naked window is visible or invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE if the naked window is visible. PRO_B_FALSE if the 
                naked window is invisible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowEnable (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the naked window and all its children to be sensitive to
             user input.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowDisable (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the naked window  and all its children
             to be insensitive to the user input.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsEnabled (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: Checks if the naked window is sensitive or insensitive to the user
                          input.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE if the naked window is sensitive. PRO_B_FALSE if the 
                naked window is insensitive.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowForegroundcolorSet (
    char                   *dialog, 
    char                   *component, 
    ProUIColor              value);
/*
    Purpose: Set the foreground color to a naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - The foreground color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowForegroundcolorGet (
    char                   *dialog, 
    char                   *component, 
    ProUIColor             *value);
/*
    Purpose: Get the foreground color to a naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - The foreground color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowBackgroundcolorSet (
    char                   *dialog, 
    char                   *component, 
    ProUIColor              value);
/*
    Purpose: Set the background color type to a naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - The background color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowBackgroundcolorGet (
    char                   *dialog, 
    char                   *component, 
    ProUIColor             *value);
/*
    Purpose: Get the background color type of a naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - The background color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProUINakedwindowNakeddisplayGet (
    char                   *dialog, 
    char                   *component, 
    ProAppData             *value);

/*

    Purpose: Returns the display pointer for the naked window.
             For UNIX this is the XWindows display pointer.
	     For Windows this value should not be used.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - The display status.              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedwindowGet (
    char                   *dialog, 
    char                   *component, 
    ProAppData             *value);
/*
    Purpose: Get the system window being used by the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Value passed to the function.
	        Under X Windows this is a window id (Window).
	        Under Microsoft Windows this is a window handle (HWND).

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedwidthSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set the NakedWindow width in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value -  The width in pixels              

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedwidthGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose:  Get the NakedWindow width in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - The width in pixels.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedheightSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set the NakedWindow height in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value -  The height in pixels.              

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedheightGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get the NakedWindow height in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value -  The height in pixels.              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedminwidthSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set the minimum NakedWindow width in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
	value -  The minimum width in pixels.

    Output Arguments:
        none              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedminwidthGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get the minimum NakedWindow width in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value -  The minimum width in pixels.              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedminheightSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set the minimum NakedWindow height in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
	value -  The minimum height in pixels.

    Output Arguments:
        none              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowNakedminheightGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get the minimum NakedWindow height in pixels. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
	
    Output Arguments:
        value -  The minimum height in pixels.              

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowDefaultbuttonactionSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set the default button action of the naked window. 
             This is a flag indicating whether a middle mouse 
	     button press in the NakedWindow should cause the 
	     default button of the Dialog in which the component 
	     is contained to be activated.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Value of the flag (PRO_B_TRUE or PRO_B_FALSE).              

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowDefaultbuttonactionGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Set the default button action of the naked window. 
             This is a flag indicating whether a middle mouse 
	     button press in the NakedWindow should cause the 
	     default button of the Dialog in which the component 
	     is contained to be activated.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
                     
    Output Arguments:
        value - Value of the flag (PRO_B_TRUE or PRO_B_FALSE).

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowAlwaysalloweventsSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*

    Purpose: Set whether user-input events should be processed
             when the NakedWindow is blocked. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Value of the flag (PRO_B_TRUE or PRO_B_FALSE).              

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowAlwaysalloweventsGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*

    Purpose: Get whether user-input events should be processed
             when the NakedWindow is blocked.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Value of the flag (PRO_B_TRUE or PRO_B_FALSE).            
        
    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowMappedSet (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the naked window to occupy space when invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowMappedUnset (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the naked window not to occupy space when invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsMapped (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: Checks if the naked window occupies any space when it is invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when naked window occupy space when it is invisible;
                PRO_B_FALSE when naked window does not occupy any space when it is
                invisible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowPopupmenuSet (
    char                   *dialog, 
    char                   *component, 
    char                   *value);
/*
    Purpose: Set the popup menu to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - The name of the popup menu.
     Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUINakedwindowPopupmenuGet (
    char                   *dialog, 
    char                   *component, 
    char                  **value);
/*
    Purpose: Get the popup menu for the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - The name of the popup menu. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowEnablePopupwheninsensitive (
    char   *dialog, 
    char   *component);
/*
    Purpose: Shows the popup menu when the naked window is insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowDisablePopupwheninsensitive (
    char   *dialog, 
    char   *component);
/*
    Purpose: Hides the popup menu when the naked window is insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsPopupwheninsensitiveEnabled (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: Checks the status (shown/hidden) of the popup menu when the naked window is
             insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when the popup menu is shown for the insensitive
                naked window; PRO_B_FALSE when the popup menu is hidden for the
                insensitive naked window.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowEnableAlwaysontop (
    char   *dialog, 
    char   *component);

/*

    Purpose:Make children that have always-on-top enabled be always
            placed above their siblings in the Z-order.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowDisableAlwaysontop (
    char   *dialog, 
    char   *component);
/*

    Purpose:Ignore childrens' always-on-top flag when arranging them.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowIsAlwaysontopEnabled (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);
/*

    Purpose:Check if the NakedWindow always places children with
            always-on-top behavior enabled to always be above their
            siblings in the Z-order when arranging them.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE if the NakedWindow always places
                children with always-on-top behavior enabled
                to always be above their siblings in the Z-order,
                PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUINakedwindowParentnameGet (
    char                   *dialog, 
    char                   *component, 
    char                  **value);
/*
     Purpose: Get the name of the parent to the naked window component.

     Input Arguments:
         dialog - The name of the dialog that contains the naked window.
         component - The name of the naked window component.

     Output Arguments:
         value - The name of the parent. Free this output using ProStringFree().
     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUINakedwindowAttachLeft (
    char   *dialog, 
    char   *component);
/*
    Purpose: To attach the naked window at left side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowUnattachLeft (
    char   *dialog, 
    char   *component);
/*
    Purpose: To not attach the naked window at left side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsAttachedLeft (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: To check if the naked window is attached at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when the naked window is attached at left side of the parent component.
                PRO_B_FALSE when the naked window is not attached at left side of the parent component.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowAttachRight (
    char   *dialog, 
    char   *component);
/*
    Purpose: To attach the naked window at right side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowUnattachRight (
    char   *dialog, 
    char   *component);
/*
    Purpose: To not attach the naked window at right side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowIsAttachedRight (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: To check if the naked window is attached at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when naked window is attached at right side of the parent component.
                PRO_B_FALSE when naked window is not attached at right side of the parent component.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowAttachTop (
    char   *dialog, 
    char   *component);
/*
    Purpose: To attach the naked window at top side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowUnattachTop (
    char   *dialog, 
    char   *component);
/*
    Purpose: To not attach the naked window at top side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUINakedwindowIsAttachedTop (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: To check if the naked window is attached at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when the naked window is attached at top side of the parent component.
                PRO_B_FALSE when the naked window is not attached at top side of the parent component.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowAttachBottom (
    char   *dialog, 
    char   *component);
/*
    Purpose: To attach the naked window at bottom side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowUnattachBottom (
    char   *dialog, 
    char   *component);
/*
    Purpose: To not attach the naked window at bottom side of the parent 
	     component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUINakedwindowIsAttachedBottom (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state);
/*
    Purpose: To check if the naked window is attached at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        state - PRO_B_TRUE when the naked window is attached at bottom side of the parent component.
                PRO_B_FALSE when the naked window is not attached at bottom side of the parent component.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLeftoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set left offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLeftoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get left offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowRightoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set right offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowRightoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get right offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTopoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set top offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTopoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get top offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowBottomoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);
/*
    Purpose: Set bottom offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowBottomoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);
/*
    Purpose: Get bottom offset to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowNakedwindowAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new naked window to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the naked window to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowNakedwindowRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a naked window from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowCheckbuttonAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new checkbutton to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the checkbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowDrawingareaAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new drawingarea to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the drawingarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowInputpanelAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new inputpanel to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the inputpanel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLabelAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new label to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLayoutAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new layout to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowListAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new list to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the list to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowOptionmenuAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new optionmenu to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the optionmenu to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowProgressbarAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new progressbar to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the progressbar to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowPushbuttonAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new pushbutton to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the pushbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowRadiogroupAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new radiogroup to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the radiogroup to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSliderAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new slider to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the slider to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSpinboxAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new spinbox to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the spinbox to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTabAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new tab to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the tab to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTableAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new table to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the table to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTextareaAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new textarea to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the textarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowThumbwheelAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new thumbwheel to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the thumbwheel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProUINakedwindowTreeAdd (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Add a new tree to the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the tree to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowCheckbuttonRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a checkbutton from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowDrawingareaRemove (
    char               *dialog, 
    char               *component, 
    char               *name);

/*
    Purpose: Remove a drawingarea from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the drawingarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowInputpanelRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a inputpanel from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLabelRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a label from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowLayoutRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a layout from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowListRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a list from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowOptionmenuRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a optionmenu from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowProgressbarRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a progressbar from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowPushbuttonRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a pushbutton from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowRadiogroupRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a radiogroup from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSliderRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a slider from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSpinboxRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a spinbox from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTabRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a tab from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTableRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a table from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTextareaRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a textarea from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowThumbwheelRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a thumbwheel from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowTreeRemove (
    char               *dialog, 
    char               *component, 
    char               *name);
/*
    Purpose: Remove a tree from the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowAnchorSet (
    char               *dialog, 
    char               *component, 
    int                 x, 
    int                 y, 
    ProUIAnchor         anchor);
/*
    Purpose: Sets the position of the tree with respect to a given anchor
              location. This function is applicable  only if the parent of
              the naked window is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the naked window used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);
/*
     Purpose: Set the size of the naked window. This field is used only
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        width - Width of the naked window.
        height - Height of the naked window.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowPositionSet (
    char               *dialog, 
    char               *component, 
    int                 x, 
    int                 y);
/*
     Purpose: Set the position to the naked window with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowPositionGet (
    char               *dialog, 
    char               *component, 
    int                *x, 
    int                *y);
/*
     Purpose: Get the position of the naked window with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowSizeGet (
    char               *dialog, 
    char               *component, 
    int                *width, 
    int                *height);
/*
     Purpose: Get the size of the naked window. This field is used only
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        width - Width of the naked window.
        height - Height of the naked window.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowCursorposGet (
    char               *dialog, 
    char               *component, 
    ProUIPoint         *position);
/*
    Purpose: Get the position of the cursor in the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.

    Output Arguments:
        position - Position of the cursor.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUINakedwindowCursorposSet (
    char               *dialog, 
    char               *component, 
    int                 x, 
    int                 y);
/*
    Purpose: Set the cursor at the given location in the naked window.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        x - X value.
        y - Y value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowResizeActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the function to be called when the naked window is resized.
             Note: the naked window contents are typically cleared after
             a resize.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        function - Function to be called when the naked window is resized.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowKeyActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);

/*

    Purpose: Set the action function to be called when a key has been
             pressed with the keyboard input focus on the naked window. 

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        function - Function to be called when a key is pressed with 
	           input focus on the naked window
        data - Action data to be passed to callback function. Can be NULL.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUINakedwindowFocusinActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the action function to be called when the naked window has got
             keyboard input focus.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        function -  Function to be called when naked window has got focus.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowFocusoutActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the action function to be called when the naked window has lost
             keyboard input focus.

    Input Arguments:
        dialog - The name of the dialog that contains the naked window.
        component - The name of the naked window component.
        function -  Function to be called when naked window has lost focus.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUINakedwindowDestroynotifyActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the function to be called when a component is about
             to be destroyed.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        function - Function to be called when a component is about
                   to be destroyed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUINakedwindowPremanagenotifyActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the function to be called when a component is about
             to be managed.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        function - Function to be called when a component is about
                   to be managed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUINakedwindowPostmanagenotifyActionSet (
    char           *dialog, 
    char           *component, 
    ProUIAction function, 
    ProAppData data);
/*
    Purpose: Set the function to be called when a component is about
             to be managed.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        function - Function to be called when a component is about
                   to be managed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

/* nvk STOP REPLACEMENTS HERE*/
extern ProError ProUIDialogNakedwindowAdd (
    char               *dialog,
    char               *name,
    ProUIGridopts      *grid);
/*
    Purpose: Add a new naked window to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the naked window to be added.
	grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutNakedwindowAdd (
    char               *dialog,
    char               *component,
    char               *name,
    ProUIGridopts      *grid);
/*
    Purpose: Add a new naked window to the layout.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        name - Name of the naked window to be added.
	grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNakedwindowAdd (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Add a new naked window to the tree.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        name - Name of the naked window to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableNakedwindowAdd (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Add a new naked window to the table.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        name - Name of the naked window to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaNakedwindowAdd (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Add a new naked window to the drawing area.

    Input Arguments:
        dialog - Name of the dialog.
        component - The name of the naked window component.
        name - Name of the naked window to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogNakedwindowRemove (
    char               *dialog,
    char               *name);
/*
    Purpose: Remove the naked window from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutNakedwindowRemove (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Remove the naked window from the layout.

    Input Arguments:
        dialog - Name of the layout.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNakedwindowRemove (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Remove the naked window from the tree.

    Input Arguments:
        dialog - Name of the tree.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableNakedwindowRemove (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Remove the naked window from the table.

    Input Arguments:
        dialog - Name of the table.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaNakedwindowRemove (
    char               *dialog,
    char               *component,
    char               *name);
/*
    Purpose: Remove the naked window from the drawing area.

    Input Arguments:
        dialog - Name of the drawing area.
        component - The name of the naked window component.
        name - Name of the naked window to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS

#endif /* __PROUINAKEDWINDOW_H__ */
