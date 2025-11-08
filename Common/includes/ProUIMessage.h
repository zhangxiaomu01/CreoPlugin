
#ifndef PROUIMESSAGE_H
#define PROUIMESSAGE_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

typedef enum pro_ui_message_button
{
  PRO_UI_MESSAGE_ABORT     = 0,      /* Abort from the appln */
  PRO_UI_MESSAGE_RETRY     = 1,      /* Retry the step */
  PRO_UI_MESSAGE_IGNORE    = 2,      /* Ignore the event */
  PRO_UI_MESSAGE_CONFIRM   = 3,      /* Confirm the event */
  PRO_UI_MESSAGE_YES       = 4,      /* confirm the event */
  PRO_UI_MESSAGE_NO        = 5,      /* disagree */
  PRO_UI_MESSAGE_OK        = 6,      /* acknowldge */
  PRO_UI_MESSAGE_CANCEL    = 7       /* disacknowledge */
} ProUIMessageButton;

extern ProError ProUIMessageDialogDisplay(
    ProUIMessageType type,
    wchar_t *title,
    wchar_t *msg_txt,
    ProUIMessageButton *buttons,
    ProUIMessageButton def_button,
    ProUIMessageButton *user_choice);
/*
   Purpose:     Displays the UI Message Dialog
 
   Input Arguments:
      type              - The type of the message
      title             - The text to display as the dialog title
      msg_txt           - The message text to be displayed in the dialog
                          Note, to display '&' pass '&&' instead.
      buttons           - A ProArray of possible button identifiers 
      def_button        - The identifier of the default button
 
   Output Arguments:
      user_choice       - The identifier of the button that the user pressed
                          to dismiss the dialog
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully loaded and displayed
				the dialog
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogCreate(
    const char *name,
    ProUIMessageType type
);
/*
   Purpose:     Initialize a message dialog
                Note: This API intended is for transient and balloon message
                      dialogs. For regular message dialogs use
                      ProUIMessageDialogDisplay.

   Input Arguments:
      name              - Name of the dialog
      type              - The type of the message

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog initialized successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogShow(const char *name);
/*
   Purpose:     Display a message dialog

   Input Arguments:
      name              - Name of the dialog

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogTitleSet(
    const char *name,
    const wchar_t *title
);
/*
   Purpose:     Set the title of a message dialog

   Input Arguments:
      name              - Name of the dialog
      title             - Text to be displayed in the title

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogMessageSet(
    const char *name,
    const wchar_t *message
);
/*
   Purpose:     Set the message of the dialog

   Input Arguments:
      name              - Name of the dialog
      message           - Text to be displayed in the message

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogTransientSet(const char *name);
/*
   Purpose:     Make a message dialog transient

   Input Arguments:
      name              - Name of the dialog

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogDurationSet(
    const char *name,
    int duration
);
/*
   Purpose:     Set the duration of a transient dialog (default: 5 seconds)

   Input Arguments:
      name              - Name of the dialog
      duration          - Duration of the dialog in milliseconds

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMessagedialogBalloonSet(
    const char *name,
    const char *target_dialog,
    const char *target_component
);
/*
   Purpose:     Make a message dialog balloon

   Input Arguments:
      name              - Name of the dialog
      target_dialog     - Dialog on which the balloon is displayed
      target_component  - Component pointed by the balloon

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - Dialog displayed successfully
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

PRO_END_C_DECLS
 
#endif  /* PROUIMESSAGE_H */
