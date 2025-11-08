#ifndef PRO_SOLID_BODY_H
#define PRO_SOLID_BODY_H

#include	<ProToolkit.h>
#include	<ProObjects.h>
#include    <ProSolid.h> 


 PRO_BEGIN_C_DECLS 
 
typedef enum tk_body_state
{ 
   PRO_BODY_STATE_NONE  = -1
  ,PRO_BODY_STATE_MISSING = 0
  ,PRO_BODY_STATE_CONSUMED
  ,PRO_BODY_STATE_NO_CONTR_FEAT
  ,PRO_BODY_STATE_NO_GEOMETRY
  ,PRO_BODY_STATE_ACTIVE
} ProSolidBodyState;

extern ProError ProSolidBodyCreate (ProSolid      sld, 
                                    ProSolidBody *body);  
/*   
  Purpose: Create new body

  Input Arguments:
     sld - The solid owner.

  Output Arguments:
     body - Newly created body.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully initialized body.  
     PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
 */

extern ProError ProSolidBodiesCollect (ProSolid       sld, 
                                       ProSolidBody** bodies);  
/*   
  Purpose: Collect all bodies in the solid.

  Input Arguments:
     sld - visit bodies of this solid

  Output Arguments:
            bodies -  ProArray of ProSolidBody

  Return Values:
     PRO_TK_NO_ERROR   - API returned bodies.
     PRO_TK_BAD_INPUTS - NULL or invalid inputs . 
*/
extern ProError ProSolidDefaultBodyGet (ProSolid      sld, 
                                        ProSolidBody *default_body);  
/*   
  Purpose: Get default body in solid.

  Input Arguments:
     sld - solid

  Output Arguments:
     default_body-  default body

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.
     PRO_TK_GENERAL_ERROR - Function failed.
*/
extern ProError ProSolidDefaultBodySet (ProSolidBody *default_body);
/*
  Purpose: Set specified body as default.

  Input Arguments:
     default_body - set this body as default body

  Output Arguments:

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.
     PRO_TK_NO_CHANGE - Body is already default body.
     PRO_TK_GENERAL_ERROR - Function failed.             
*/

extern ProError ProSolidBodySurfaceVisit (ProSolidBody         *body, 
                                          ProSurfaceVisitAction visit_action,  
                                          ProAppData            app_data);  
/*   
  Purpose: Visits surface in a body

  Input Arguments:
     body - body
    visit_action - action function
    app_data - application data.

  Output Arguments:

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.
   PRO_TK_E_NOT_FOUND- There are no surfaces in specified body.      
 */
extern ProError ProSolidBodyDelete (ProSolidBody *body);
/*   
  Purpose: Delete body

  Input Arguments:
     body - the body

  Output Arguments:

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.
   PRO_TK_BAD_INPUTS- invalid inputs.     
 */

extern ProError ProSolidBodyStateGet (ProSolidBody      *body,
                                      ProSolidBodyState *state);  
/*   
  Purpose: Get state of the body

  Input Arguments:
     body - the body

  Output Arguments:
	ProSolidBodyState - body state

  Return Values:
    PRO_TK_NO_ERROR   - Function is successful.
   PRO_TK_BAD_INPUTS- invalid inputs.      
 */
extern ProError ProSolidBodyIsConstruction (ProSolidBody *body,
                                            ProBoolean   *is_constr);
/*
  Purpose: Checks if specified body is construction body.

  Input Arguments:
     body - body

  Output Arguments:
     is_constr- PRO_B_TRUE if body is construction body.

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.  
     PRO_TK_GENERAL_ERROR - Function failed.         
*/
extern ProError ProSolidBodyConstructionSet (ProSolidBody *constr_body);
/*
  Purpose: Set specified body as construction.

  Input Arguments:
     constr_body - set this body as construction body.

  Output Arguments:

  Return Values:
     PRO_TK_NO_ERROR   - Function is successful.
     PRO_TK_NO_CHANGE - Body is already construction body.
     PRO_TK_GENERAL_ERROR - Function failed.         
*/
extern ProError ProSolidBodyIsSheetmetal(ProSolidBody *body, ProBoolean  *is_smt);
/*
  Purpose: Checks if specified body is active sheetmetal body.

  Input Arguments:
	   body - body

  Output Arguments:
	   is_smt- PRO_B_TRUE if body is sheetmetal body.

  Return Values:
	   PRO_TK_NO_ERROR   - Function is successful.
	   PRO_TK_GENERAL_ERROR - Function failed.
*/

extern ProError ProSolidBodyOutlineGet(ProSolidBody *body, ProOutline body_outline);
/*
  Purpose: Retrieves the regeneration outline of a solid body, with respect to the
       base coordinate system orientation.

  Input Arguments:
	   body - The body whose outline is to be determined

  Output Arguments:
	   body_outline - The outline that defines the boundary box
                      of the body, in the orientation of the base
                      coordinate system

  Return Values:
	   PRO_TK_NO_ERROR   - Function is successful.
	   PRO_TK_E_NOT_FOUND - The solid body is empty
	   PRO_TK_GENERAL_ERROR - Function failed.
*/

extern ProError ProSolidBodyFeaturesGet (ProSolidBody  *body,
                                         ProFeature **features);
/*
   Purpose:     Lists all features associated with the specified body

   Input Arguments:
     body       - The body handle.

   Output Arguments:
      features   -  ProArray of features.  Free this using ProArrayFree().

   Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved features.
     PRO_TK_BAD_INPUTS - The input argument is invalid.
     PRO_TK_E_NOT_FOUND - No contributing features.
*/

extern ProError ProSolidBodyDensityGet (ProSolidBody *body, 
                                        double       *density);

/*
  Purpose:  Determines the density of the body.

  <p><b>NOTE: </b> This function returns density of material assigned to body.
  
  Input Arguments:  
      body - The body handle.

  Output Arguments:
      density - The body density (in the units of the model).  
                Density of material assigned to body.

  Return Values:
      PRO_TK_NO_ERROR - The function retrieved the density.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The part has not been assigned a density value.
*/

extern ProError ProSolidBodyMassPropertyGet ( ProSolidBody     *body,      
                                              ProName           csys_name,
                                              ProMassProperty  *mass_prop );
/*
   Purpose:  Calculates the mass properties of a body  in
             the specified coordinate system.

   Input Arguments:
      body - The handle to a part or an assembly.
      csys_name - The name of the coordinate system. If this is NULL, the
                  function uses the default coordinate system.

   Output Arguments:
      mass_prop - The mass property.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the 
                             information.
      PRO_TK_BAD_INPUTS    - The solid handle is invalid.
      PRO_TK_E_NOT_FOUND   - The specified coordinate system was not found.
      PRO_TK_GENREAL_ERROR - A general error occurred and the function
                             failed.

*/
extern ProError ProSolidBodyIsComposite(ProSolidBody* body, ProBoolean* is_cmpst);
/*
  Purpose: Checks if specified body is active composite body.

  Input Arguments:
       body - body

  Output Arguments:
       is_cmpst- PRO_B_TRUE if body is composite body.

  Return Values:
       PRO_TK_NO_ERROR   - Function is successful.
       PRO_TK_GENERAL_ERROR - Function failed.
*/

PRO_END_C_DECLS

#endif
