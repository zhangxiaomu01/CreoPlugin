#ifndef PRO_APPRNSTATEH
#define PRO_APPRNSTATEH


#include <ProModelitem.h>
PRO_BEGIN_C_DECLS

typedef struct _ProApprnstateData *ProApprnstateData;  /* opaque handle for 
                                                          appearance state data */

extern ProError ProApprnstateNameGet (ProApprnstate apprn, wchar_t **r_name);

/*
   Purpose: To get the name of an appearance state

   Input Arguments:
      apprn - Handle to the appearance state.

   Output Arguments:
      r_name - Returns pointer to wchar string with the name of the apperarnce
               state; the caller must release the string using ProWstringFree()

   Return Values:
      PRO_TK_NO_ERROR   - The name of the appearance state was successfully 
                          found.
      PRO_TK_BAD_INPUTS - There was an error finding the name of the appearance
                          state.
*/

extern ProError ProSolidApprnstateVisit (ProSolid                 p_solid,
                                         ProModelitemFilterAction filter,
                                         ProModelitemVisitAction  action,
                                         ProAppData               app_data);
/*
   Purpose:     Visits all the appearance states in the specified solid.
   
   Input Arguments:
      p_solid           - The solid handle.
      visit_action      - The visiting function. If it returns anything other
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all items are
                          visited using the action function.
      app_data          - The application data passed to the filter
                          and visiting functions.
   
   Output Arguments:
      None
   
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the appearance
                           states.
      PRO_TK_E_NOT_FOUND - Either no appearance state exist, or they were all
                           filtered out by the filter function.
      Other              - Any other value is the value returned by the action
                           function (visiting stopped).
*/

extern ProError ProApprnstateIsActive(ProApprnstate apprn, ProBool* r_is_active);
/*
   Purpose: To determine if a given appearance state is the active one

   Input Arguments:
      apprn - Handle to the appearance state.

   Output Arguments:
      r_is_default - PRO_B_TRUE if the appearance state is the active one,
                     PRO_B_FALSE otherwise.

   Return Values:
      PRO_TK_NO_ERROR   - Appearance state is a valid handle.
      PRO_TK_BAD_INPUTS - There was an error evaluating the appearance state.
*/

PRO_END_C_DECLS

#endif /* PRO_APPRNSTATE_H */
