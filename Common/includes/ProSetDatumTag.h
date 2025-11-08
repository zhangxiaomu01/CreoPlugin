#ifndef PROSETDATUMTAG_H_
#define PROSETDATUMTAG_H_


#include <ProToolkit.h>
#include <ProSelection.h>
#include <ProNote.h>


PRO_BEGIN_C_DECLS



typedef struct pro_model_item ProSetDatumTag;

typedef enum pro_dtm_feat_addl_text_pos
{
  PRO_DTM_FEAT_ADDL_TEXT_RIGHT,
  PRO_DTM_FEAT_ADDL_TEXT_BOTTOM,
  PRO_DTM_FEAT_ADDL_TEXT_LEFT,
  PRO_DTM_FEAT_ADDL_TEXT_TOP,
  PRO_DTM_FEAT_ADDL_TEXT_DEFAULT
}ProDtmFeatAddlTextPos;


extern ProError ProGeomitemSetdatumtagGet (ProGeomitem* item,
                                           ProSetDatumTag* set_datum_tag);
/*
    Purpose: Obtains the set datum tag referring to this geometry item, if it
             exists.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        item - The geometry item.

    Output Arguments:
        set_datum_tag - The set datum tag annotation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - There is no set datum tag annotation  for the
                             given geometry.

*/

extern ProError ProSetdatumtagPlaneGet (ProSetDatumTag* tag,
                                        ProAnnotationPlane* plane);
/*
    Purpose: Obtains the annotation plane for a set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag annotation.

    Output Arguments:
        plane - The annotation plane.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagAttachmentGet (ProSetDatumTag* tag,
                                             ProSelection* attachment);
/*
    Purpose: Obtains the item to which the set datum tag is attached
             (dimension, gtol, or geometry).

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        attachment - The attachment. (Caller should free memory of
                     *attachment by using ProSelectionFree().)

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The set datum tag attachment is to the datum
                             itself.
    See Also:
        ProSetdatumtagPlacementGet()

*/

extern ProError ProSetdatumtagPlacementGet (ProSetDatumTag* tag,
                                            ProModelitem* attach_item);
/*
    Purpose: Obtains the item (type,id,owner only) to which the set datum tag
             is attached (dimension, gtol, or geometry).
             This function is useful in cases where it is not possible to
             construct the selection.
             For example , Solid owned DFS attached to solid owned dimension
             created in drawing.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        attach_item - The attachment item.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProSetdatumtagAttachmentGet()

*/

extern ProError ProSetdatumtagReferenceGet (ProSetDatumTag* tag,
                                            ProGeomitem* reference);
/*
    Purpose: Obtains the geometry item used as the set datum.
             <P><B>Note:</B>This API works for SDTA not for DFS after Creo 4.0</P>

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        reference - The geometry of the set datum.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NOT_VALID  - The input argument is a DFS and not SDTA.

*/

extern ProError ProSetdatumtagReferencesAdd( ProSetDatumTag         *dfs, 
                                             ProAnnotationReference *refs );
/*
   Purpose:   Add DFS semantic references

   Input Arguments:
      dfs   - valid DFS.
      refs  - ProArray of DFS references.
              Only 1 reference from type PRO_ANNOT_REF_SRF_COLLECTION is allowed.
   Output Arguments:


   Return Values:
      PRO_TK_NO_ERROR          - The function completed successfully.
      PRO_TK_BAD_INPUTS        - The input argument is invalid.
      PRO_TK_MAX_LIMIT_REACHED - More than 1 references from type PRO_ANNOT_REF_SRF_COLLECTION.
      PRO_TK_CANT_MODIFY       - Refercnce from type PRO_ANNOT_REF_SRF_COLLECTION already exist.
*/

extern ProError ProSetdatumtagReferencesGet( ProSetDatumTag          *dfs,
                                             ProAnnotationReference **refs );
/*
   Purpose:  Get DFS semantic references

   Input Arguments:
      dfs    - valid DFS.

   Output Arguments:
      refs   - ProArray of DFS references. Free it using ProAnnotationreferencearrayFree()

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProSetdatumtagReferenceDelete( ProSetDatumTag *dfs, 
                                               int             index );
/*
   Purpose:   Delete DFS semantic reference

   Input Arguments:
      dfs    - valid DFS.
   index     - Indices start from 0. Get existing references from 
               ProSetdatumtagReferencesGet()

   Output Arguments:

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/


extern ProError ProSetdatumtagTextstyleGet (ProSetDatumTag* tag,
                                            ProTextStyle* text_style);
/*
        DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use
              ProAnnotationTextstyleGet() instead.</P>
              Obtains the text style for the set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        text_style - The text style.  Free this using ProTextstyleFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagTextstyleSet (ProSetDatumTag* tag,
                                            ProTextStyle text_style);
/*
        DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleSet
    Purpose: <P><B>Note:</B> This function is deprecated. Use
              ProAnnotationTextstyleSet() instead.</P>
              Assigns the text style for the set datum tag.
            <P><B>Note:</B>Angle and Mirror properties cannot be set.
                They can be set only for Notes and Dimensions.</P>

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.
        text_style - The text style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProSetdatumtagPlaneSet (ProSetDatumTag* tag,
                                        ProAnnotationPlane* plane);
/*
    Purpose: Assigns the annotation plane for a set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag annotation.
        plane - The annotation plane.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagAttachmentSet (ProSetDatumTag* tag,
                                             ProSelection attachment);
/*
    Purpose: Assigns the item to which the set datum tag is attached.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.
        attachment - The attachment. Use NULL to attach the tag to its
              datum plane, or to the default position on its axis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef ProError (*ProSetdatumtagFilterAction) (ProSetDatumTag* set_datum_tag,
                                                ProAppData app_data);
/*
    Purpose: Filter action for visiting set datum tags.

    Input Arguments:
        set_datum_tag - The set datum tag.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Skip the visit action for this annotation.
        Any other value - Calll the vist action for this annotation.  This
                          status will be passed to the visit action.

*/

typedef ProError (*ProSetdatumtagVisitAction) (ProSetDatumTag* set_datum_tag,
                                               ProError error,
                                               ProAppData app_data);
/*
    Purpose: Visit action for visiting set datum tags.

    Input Arguments:
        set_datum_tag - The set datum tag.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSolidSetdatumtagVisit (ProSolid solid,
                                          ProSetdatumtagVisitAction action,
                                          ProSetdatumtagFilterAction filter,
                                          ProAppData app_data);
/*
    Purpose: Visits the set datum tag annotations in a solid model.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        solid - The part or assembly.
        action - The visit action
        filter - The filter action.  Can be NULL.
        app_data - Application data passed to the action functions.  Can be
                   NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No set datum tag annotations were found in the
                             model.
        Any other value - The value returned by the visit action to stop
                          visiting.

*/

extern ProError ProDrawingSetdatumtagVisit (ProDrawing drawing,
                                            ProSetdatumtagVisitAction action,
                                            ProSetdatumtagFilterAction filter,
                                            ProAppData app_data);
 /*
    Purpose: Visits the set datum tag annotations in a drawing.
     
        Licensing Requirement:
          TOOLKIT for 3D Drawings
     
    Input Arguments:
        drawing - The drawing.
        action - The visit action
        filter - The filter action.  Can be NULL.
        app_data - Application data passed to the action functions.  Can be
                   NULL.
     
    Output Arguments:
        none
     
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No set datum tag annotations were found in the
                             drawing.
        Any other value - The value returned by the visit action to stop
                           visiting.
     
     */



extern ProError ProMdlSetdatumtagCreate (ProMdl p_mdl, ProSelection attachment,
                                         ProAnnotationPlane* annotation_plane,
                                         wchar_t *label,
                                         ProSetDatumTag *r_dfs);
/*
    Purpose: Create a new datum feature symbol annotation. ProAnnotationShow()
    should be called after creating the annotation in order for the annotation
    to be displayed.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        p_mdl - solid or drawing.
        attachment - attachment reference.
        annotation_plane - The annotation plane. If the attachment is to a
                           dimension or gtol, can be NULL.
                           For drawing, annotation plane should be NULL.
        label - label of datum feature symbol

    Output Arguments:
        r_dfs - new datum feature symbol

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        
        PRO_TK_E_AMBIGUOUS - The annotation plane cannot be used in conjunction
                             with the properties of the
                             attachment.        

*/

extern ProError ProMdlSetdatumtagDelete (ProSetDatumTag* symbol);
/*
    Purpose: Delete a new datum feature symbol annotation.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        symbol - new datum feature symbol

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        
        PRO_TK_CANT_MODIFY - Cannot delete set datum tag.    

*/

extern ProError ProSetdatumtagLabelSet (ProSetDatumTag* dfs, wchar_t* lbl);
/*
    Purpose: Sets label to datum feature symbol annotation             

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
              lbl - label of datum feature symbol             

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagLabelGet (ProSetDatumTag* dfs, wchar_t** lbl);
/*
    Purpose: Get label of datum feature symbol annotation             

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.         

    Output Arguments:
        lbl - label of datum feature symbol. Free it using ProWstringFree()

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagAdditionalTextSet (ProSetDatumTag* dfs, wchar_t* lbl,
                                                 ProDtmFeatAddlTextPos  addlTextPos);
/*
    Purpose: Sets Additional text and Position to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        lbl - label of datum feature symbol.
		addlTextPos - position where the Additional text Appears. Default position is Right

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagAdditionalTextGet (ProSetDatumTag* dfs, wchar_t** lbl,
                                                 ProDtmFeatAddlTextPos*  addlTextPos);
/*
    Purpose: Gets Additional text and Position to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        
    Output Arguments:
       lbl - label of datum feature symbol. Free it using ProWstringFree()
       addlTextPos - position where the Additional text Appears.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagElbowSet (ProSetDatumTag* dfs, ProBoolean elbow);
/*
    Purpose: Sets or unset Elbow to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        elbow - leader - Pass PRO_B_TRUE to set Elbow display otherwise PRO_B_FALSE

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.     
        PRO_TK_CANT_MODIFY - datum feature symbol annotation can't be modified.

*/
extern ProError ProSetdatumtagElbowGet (ProSetDatumTag* dfs, ProBoolean* elbow);
/*
    Purpose: Outputs whether a specified datum feature symbol annotation Elbow is set. 

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        

    Output Arguments:
        elbow - PRO_B_TRUE if dfs has Elbow display otherwise PRO_B_FALSE

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_CANT_ACCESS - datum feature symbol annotation can't be accessed.

*/
extern ProError ProSetdatumtagASMEDisplayGet (ProSetDatumTag* dfs, ProBoolean *asme);
/*
    Purpose: Outputs whether a specified datum feature symbol annotation ASME is set.         

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.

    Output Arguments:
        asme - PRO_B_TRUE if symbol has ASME display otherwise PRO_B_FALSE

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.    
        PRO_TK_CANT_ACCESS - datum feature symbol annotation can't be accessed.

*/
extern ProError ProSetdatumtagASMEDisplaySet (ProSetDatumTag* dfs, ProBoolean asme);
/*
    Purpose: Set or unset ASME display of datum feature symbol annotation.            

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        asme - Pass PRO_B_TRUE to set ASME display otherwise PRO_B_FALSE

    Output Arguments:
        none
       
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_CANT_MODIFY - datum feature symbol annotation can't be modified.

*/
extern ProError ProSetdatumtagTextLocationGet (ProSetDatumTag* dfs,ProDrawing drw, Pro3dPnt pnt);
/*
    DEPRECATED: Since Creo 7
    SUCCESSORS: ProSetdatumtagTextPointGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use
              ProSetdatumtagTextPointGet() instead.</P>
              Gets text point of datum feature symbol.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - The set datum tag.
        drw - Pass drawing for dfs owned by solid and shown in drawing. Pass NULL otherwise. 

    Output Arguments:
        pnt - point

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProSetdatumtagTextPointGet()
*/

extern ProError ProDrawingSetDatumTagIsShown(ProSetDatumTag* set_datum_tag,
                                             ProDrawing drawing,
                                             ProView view,
                                             ProBoolean* is_shown);
/*
    Purpose:  Determines if an Set Datum Tag is shown in a particular view of a drawing.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        set_datum_tag  - The set datum tag.
        drawing        - The drawing that shows the annotation.
        view           - The drawing view.

    Output Arguments:
        is_shown      - PRO_B_TRUE if the set datum tag is shown,
                        PRO_B_FALSE if it is not shown in the target
                        view.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_BAD_CONTEXT - DFS cannot be shown in specified drawing view.
*/
extern ProError ProSetdatumtagAdditionalTextLocationGet(ProSetDatumTag* dfs,
                                                        ProDrawing drawing,
                                                        ProView view,
                                                        Pro3dPnt addl_pnt);
/*
    Purpose: Gets Additional text point of datum feature symbol.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - The set datum tag.
        drawing - Pass drawing for dfs owned by solid and shown in drawing. Pass NULL otherwise.
        view - Pass view if drw is not NULL. Pass NULL otherwise.

    Output Arguments:
        addl_pnt - point

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The set datum tag annotation is not found or 
                             it has no Additional Text.
*/
extern ProError ProDrawingSetdatumtagErase(ProDrawing drawing, ProView view, ProSetDatumTag* tag);
/*
    Purpose:  Sets an set datum tag to be erased from drawing view.  This changes the drawing
              database to not show the annotation until it is explicitly
              shown again.

    Input Arguments:
        drawing  - The drawing where dfs needs to be shown.
        view     - drawing view. Should NOT be NULL
        tag      - dfs

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_BAD_CONTEXT - DFS cannot be shown in specified drawing view.
        PRO_TK_NO_CHANGE   - The annotation is not shown in the target drawing view.
        PRO_TK_E_AMBIGUOUS - DFS is place on a serface in solid but the view of the
                             DFS is not passed.

    See Also:
        ProAnnotationShow()
        ProAnnotationIsShown()
        ProCombstateAnnotationErase()
        ProDrawingAnnotationErase()
*/

extern ProError ProSetdatumtagTextPointGet (ProSetDatumTag* dfs, ProDrawing drw, ProView view, Pro3dPnt pnt); 
/* 
    Purpose: Gets text point of datum feature symbol. 

    Licensing Requirement: 
          TOOLKIT for 3D Drawings

    Input Arguments: 
        dfs - The set datum tag. 
        drw - Pass drawing for dfs owned by solid and shown in drawing. Pass NULL otherwise. 
        view - View in which DFS is shown if drawing is not NULL. 

    Output Arguments: 
        pnt - point 

    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid. 
*/ 

extern ProError ProDrawingLegacySetdatumtagErase(ProDrawing drawing, ProView view, ProAsmcomppath *path, ProSetDatumTag* tag);
/*
    Purpose:  Sets an legacy set datum tag to be erased from drawing view.  This changes the drawing
              database to not show the annotation until it is explicitly
              shown again.
              <b>Note:</b> Only allowed for legacy Set Datum tag

    Input Arguments:
        drawing  - The drawing where legacy set datum tag needs to be shown.
        view     - drawing view. Should NOT be NULL
        path     - component path.
        tag      - legacy set datum tag

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_BAD_CONTEXT - Set datum tag cannot be shown in specified drawing view.
        PRO_TK_NO_CHANGE   - The annotation is not shown in the target drawing view.
        PRO_TK_INVALID_TYPE - not a legacy set datum tag.

*/

extern ProError ProDrawingLegacySetdatumtagIsShown(ProSetDatumTag *tag, ProDrawing drawing, ProView view, ProAsmcomppath* path, ProBoolean *is_shown);
/*
    Purpose:  Checks if legacy set datum tag is shown
              <b>Note:</b> Only allowed for legacy Set Datum tag

    Input Arguments:
        drawing  - The drawing where legacy set datum tag present.
        view     - drawing view. Should NOT be NULL
        path     - component path.
        tag      - legacy set datum tag

    Output Arguments:
        is_shown - PRO_B_TRUE if it is shwon

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_BAD_CONTEXT - Set datum tag cannot be shown in specified drawing view.
        PRO_TK_NO_CHANGE   - The annotation is not shown in the target drawing view.
        PRO_TK_INVALID_TYPE - not a legacy set datum tag.

*/

PRO_END_C_DECLS

#endif
