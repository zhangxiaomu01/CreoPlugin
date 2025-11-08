#ifndef PROCOMPOSITE_H
#define PROCOMPOSITE_H

#include <ProObjects.h>
#include <ProMdl.h>
#include <ProModelitem.h>
#include <ProColor.h>



PRO_BEGIN_C_DECLS

typedef enum tk_cmpst_mass_prop_opt
{
    PRO_CMPST_MP_LAYUP_BASED,
    PRO_CMPST_MP_PLIES_BASED
} ProCompositeMassPropertyOption;


extern ProError ProCompositeMassPropertyOptionGet(ProMdl composite_mdl, ProCompositeMassPropertyOption* opt);

/*

Purpose: Get mass property calculation option on composite solid.

    Input Arguments:
        composite_mdl - The composite model.

    Output Arguments:
        opt - option

    Return Values:
        PRO_TK_NO_ERROR - The function successfully returned the information.
        PRO_TK_BAD_INPUTS - The input argument is invalid.
        PRO_TK_INVALID_TYPE - Model is not a composite Model

*/

extern ProError ProCompositeMassPropertyOptionSet(ProMdl composite_mdl, ProCompositeMassPropertyOption opt);

/*

Purpose: Set mass property calculation option on composite solid.

    Input Arguments:
        composite_mdl - The composite model.
        opt           - option

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - The function successfully returned the information.
        PRO_TK_BAD_INPUTS   - The input argument is invalid.
        PRO_TK_INVALID_TYPE - Model is not a composite Model

*/

extern ProError ProCompositeMdlGet (ProFeature *p_feat_handle,
                                    ProMdl     *p_mdl_handle);
/*
   Purpose: Retrieves the composite model, given a composite feature.
   <b>Note</b>: After changing anything in this model application must regenerate top model (p_feat_handle->owner)
   using ProSolidRegenerate()

   Input Arguments:
      p_feat_handle     - The handle to the composite feature

   Output Arguments:
     p_mdl_handle       - The model handle to be initialized

   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid composite
                            feature with a valid composite model.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid composite 
                            feature.
      PRO_TK_BAD_CONTEXT  - The specified feature is a suppressed composite 
                            feature.
      PRO_TK_E_NOT_FOUND  - composite model is not a solid or 
                            is not in memory.
*/

extern ProError ProCompositeFeatureCreate (ProMdl     p_mdl_handle,
                                           ProFeature *p_feat_handle);
/*
   Purpose: creates empty composite feature.

   Input Arguments:
       p_mdl_handle  - The model handle. 

   Output Arguments:
       p_feat_handle  - The created composite feature. 

   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid model.
      PRO_TK_BAD_INPUTS   - The composite feature was created successfully.
*/


extern ProError ProMdlIsComposite (ProMdl  p_mdl_handle, 
                                   ProBoolean *p_is_composite);
/*
   Purpose: Check is model of kind Composite model

   Input Arguments:
       p_mdl_handle      - The model handle.

   Output Arguments:
     p_is_composite   -  This is PRO_B_TRUE if the model
                         is a Composite model; otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/


extern ProError ProRosetteDefaultSet(ProFeature *rosette);
/* 
  Purpose: Set specified rosette as default.

  Input Arguments:
      rosette             - The rosette feature
	  
  Output Arguments:
      none

  Return Values:
    PRO_TK_NO_ERROR       - The function successfully returned the information.
    PRO_TK_BAD_INPUTS     - The input argument is invalid.
    PRO_TK_INVALID_TYPE   - Feature is not rosette.
*/

extern ProError ProRosetteDefaultGet(ProMdl composite_mdl, ProFeature *rosette);
/*
  Purpose: Get specified rosette as default.

  Input Arguments:
      composite_mdl - The composite model.

  Output Arguments:
      rosette - Default rosette feature.

  Return Values:
    PRO_TK_NO_ERROR       - The function successfully returned the information.
    PRO_TK_BAD_INPUTS     - The input argument is invalid.
    PRO_TK_E_NOT_FOUND    - No rosette found or no default is set.
*/


extern ProError ProCompositePlyVisit (ProSolid                  composite,
                                      ProModelitemVisitAction   action, 
                                      ProModelitemFilterAction  filter,
                                      ProAppData                appdata);
/*
 Purpose:  Visits all the plies in the specified composite solid.

   Input Arguments:
      composite          - The composite solid handle.
      action             - The visiting function. If it returns anything other than PRO_TK_NO_ERROR, visiting stops.
      filter             - The filter function. If NULL, all features in the specified solid are visited using the action function.
      appdata            - The application data passed to the filter and action functions.

   Output Arguments:
      None

   Return Values:

      PRO_TK_NO_ERROR    - The function successfully visited all the plies.
      PRO_TK_E_NOT_FOUND - Either no ply exist, or they were all filtered  out by the filter function.
      Other              - Any other value is the value returned by the   action function (visiting stopped).
 
 */

extern ProError ProPlyColorGet(ProPly *ply, ProColor *color);

/*
Purpose: Get color of ply

   Input Arguments:
     ply - ply     

   Output Arguments:
     color - color

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned color.
      PRO_TK_BAD_INPUTS -  invalid ply
*/


extern ProError ProPlyFeatureGet(ProPly *ply, ProFeature *feat);
/*
Purpose: Get feature which created ply.

   Input Arguments:
     ply - ply     

   Output Arguments:
     feat -  feat

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned feature.
      PRO_TK_BAD_INPUTS -  invalid ply
 
*/

PRO_END_C_DECLS


#endif  /* PROCOMPOSITE_H */
