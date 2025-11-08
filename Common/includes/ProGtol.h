

#ifndef PROGTOL_H
#define PROGTOL_H

#include <ProSelection.h>
#include <ProAnnotationElem.h>

PRO_BEGIN_C_DECLS

typedef struct gtol_dialog_info   *ProGtoldata;
typedef struct progtol_datum_ref  *ProGtoldatumref;
typedef struct pro_gtol_attach    *ProGtolAttach;
typedef struct progtol_leader     *ProGtolleader;

typedef enum
{
   PROGTOLSTATUS_MODEL_REF_ENT   =  0,
   PROGTOLSTATUS_PLACEMENT       =  1,
   PROGTOLSTATUS_INVALID_REF_ENT =  2,
   PROGTOLSTATUS_REF_DTM_NEEDED  =  3,
   PROGTOLSTATUS_ONE_REF_DTM     =  4,
   PROGTOLSTATUS_NONCOLL_AXIS    =  5,
   PROGTOLSTATUS_NONCOLL_SURF    =  6,
   PROGTOLSTATUS_NONPERP_SURF    =  7,
   PROGTOLSTATUS_NONPERP_ENT     =  8,
   PROGTOLSTATUS_NONPAR_ENT      =  9,
   PROGTOLSTATUS_ENT_DTM_NOT_ANG = 10,
   PROGTOLSTATUS_NO_REF_ENT      = 11,
   PROGTOLSTATUS_COMPLETE        = 12,
   PROGTOLSTATUS_NO_REF_GEOM     = 13
} ProGtoldataStatus;

typedef enum
{
   PROGTOLTYPE_UNKNOWN          =  0,
   PROGTOLTYPE_STRAIGHTNESS     =  1,
   PROGTOLTYPE_FLATNESS         =  2,
   PROGTOLTYPE_CIRCULAR         =  3,
   PROGTOLTYPE_CYLINDRICAL      =  4,
   PROGTOLTYPE_LINE             = 11,
   PROGTOLTYPE_SURFACE          = 12,
   PROGTOLTYPE_ANGULAR          = 21,
   PROGTOLTYPE_PERPENDICULAR    = 22,
   PROGTOLTYPE_PARALLEL         = 23,
   PROGTOLTYPE_POSITION         = 31,
   PROGTOLTYPE_CONCENTRICITY    = 32,
   PROGTOLTYPE_SYMMETRY         = 35,
   PROGTOLTYPE_CIRCULAR_RUNOUT  = 41,
   PROGTOLTYPE_TOTAL_RUNOUT     = 42
} ProGtolType;

typedef enum
{
   PROGTOLMATCOND_UNKNOWN     = 0,
   PROGTOLMATCOND_LMC         = 1,
   PROGTOLMATCOND_MMC         = 2,
   PROGTOLMATCOND_RFS         = 3,
   PROGTOLMATCOND_DEFAULT_RFS = 4,
   PROGTOLMATCOND_LMC_R       = 5,
   PROGTOLMATCOND_MMC_R       = 6
} ProGtolMaterialCond;

typedef enum
{
   PROGTOLRTYPE_NONE   = -1, /* Only available in drawings */
   PROGTOLRTYPE_EDGE   = 1,
   PROGTOLRTYPE_AXIS   = 2,
   PROGTOLRTYPE_SURF   = 3,
   PROGTOLRTYPE_FEAT   = 4,
   PROGTOLRTYPE_DATUM  = 5,  /* Datum plane or axis */
   PROGTOLRTYPE_ENTITY = 6   /* NOT IMPLEMENTED */
} ProGtolRefItemType;

typedef enum
{
   PROGTOLPTYPE_DATUM,
   PROGTOLPTYPE_DIMENSION,
   PROGTOLPTYPE_DIM_RELATED,
   PROGTOLPTYPE_FREENOTE,
   PROGTOLPTYPE_LEADERS,
   PROGTOLPTYPE_TANLEADER,
   PROGTOLPTYPE_NORMLEADER,
   PROGTOLPTYPE_GTOL
} ProGtolPlacementType;


typedef enum
{
   PROLEADERTYPE_ARROWHEAD   =  1,
   PROLEADERTYPE_DOT         =  2,
   PROLEADERTYPE_FILLEDDOT   =  3,
   PROLEADERTYPE_NOARROW     =  4,
   PROLEADERTYPE_CROSS       =  5,
   PROLEADERTYPE_SLASH       =  6,
   PROLEADERTYPE_INTEGRAL    =  7,
   PROLEADERTYPE_BOX         =  8,
   PROLEADERTYPE_FILLEDBOX   =  9,
   PROLEADERTYPE_DOUBLEARROW = 10,
   PROLEADERTYPE_CROSS_N_ARROW = 13,
   PROLEADERTYPE_TARGET      = 14, 
   PROLEADERTYPE_LEFTHALF    = 15,
   PROLEADERTYPE_RIGHTHALF   = 16, 
   PROLEADERTYPE_TRIANGLE    = 18,
   PROLEADERTYPE_AUTOMATIC   = 19
} ProLeaderType;

typedef enum
{
   PROGTOLREFTYPE_NONE      = 0,
   PROGTOLREFTYPE_PRIMARY   = 1,
   PROGTOLREFTYPE_SECONDARY = 2,
   PROGTOLREFTYPE_TERTIARY  = 3
} ProGtolReferenceType;

typedef enum
{
   PROGTOLPROJZONE_NONE       = 0,
   PROGTOLPROJZONE_BELOWGTOL  = 1,
   PROGTOLPROJZONE_INSIDEGTOL = 2
} ProGtolProjzone;

/* PROGTOLPROF_BILATERAL_IDX = 0 and PROGTOLPROF_UNILATERAL_IDX = 1 in order
 * to handle legacy code. */
typedef enum
{
   PROGTOLPROF_BILATERAL_IDX = 0,
   PROGTOLPROF_UNILATERAL_IDX = 1,
   PROGTOLPROF_UNEQUAL_IDX = 2
} ProGtolProfBoundIndex;

typedef enum
{
  PRO_TEXT_HRZJUST_DEFAULT,
  PRO_TEXT_HRZJUST_LEFT,
  PRO_TEXT_HRZJUST_CENTER,
  PRO_TEXT_HRZJUST_RIGHT
} ProTextHrzJustification;

typedef enum
{
	PRO_GTOL_SYMBOL_DIAMETER,
	PRO_GTOL_SYMBOL_FREE_STATE,	
	PRO_GTOL_SYMBOL_STAT_TOL,
	PRO_GTOL_SYMBOL_TANGENT_PLANE,   

	/* Material condition symbols */
	PRO_GTOL_SYMBOL_LMC,
	PRO_GTOL_SYMBOL_MMC,
	PRO_GTOL_SYMBOL_RFS,
	PRO_GTOL_SYMBOL_DEFAULT_RFS,
	PRO_GTOL_SYMBOL_LMC_R,
	PRO_GTOL_SYMBOL_MMC_R,

  /* Indicator Symbol */
    PRO_INDICATOR_SYMBOL_ANGULARITY,
    PRO_INDICATOR_SYMBOL_PERPENDICULARITY,
    PRO_INDICATOR_SYMBOL_PARALLELISM,
    PRO_INDICATOR_SYMBOL_SYMMETRY,
    PRO_INDICATOR_SYMBOL_RUNOUT,
    PRO_GTOL_SYMBOL_TRANSLATION

    /* Add new C4 sumbols */
} ProGtolSymbol;

typedef enum
{
	PRO_INDICATOR_DIRECTION_FEAT,
	PRO_INDICATOR_COLLECTION_PLANE,	
	PRO_INDICATOR_INTERSECTION_PLANE,
	PRO_INDICATOR_ORIENTATION_PLANE

} ProGtolIndicatorType;

typedef enum
{
  PRO_GTOL_SYNTAX_VALIDITY_CHECK

} ProGtolValidityCheckType;

typedef enum
{
  PRO_FONT_ASME,
  PRO_FONT_ISO,
  PRO_FONT_LEGACY,
  PRO_FONT_STROKED_ASME,
  PRO_FONT_STROKED_ISO

}ProSymbolFont;

typedef enum
{
  PRO_GTOL_ENVELOPE_DEFAULT,
  PRO_GTOL_ENVELOPE_SKIP_OUTSIDE_TEXT

}ProGtolEnvelopeFlag;













extern ProError ProGtolDelete(
   ProGtol *gtol);

/*
   Purpose:   Deletes a gtol from its owning Creo Parametric model.

   Input Arguments:
      gtol     - The gtol

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_CANT_WRITE     - Could not delete the given item because
                              it has read-only access.
      PRO_TK_E_NOT_FOUND
*/

extern ProError ProGtolRightTextGet (ProGtol *gtol, wchar_t **p_text);

/*
Purpose: Retrieves the text of the specified geometrical tolerance.

Input Arguments:
  gtol - Pointer to the geometrical tolerance.

Output Arguments:
  p_text   - The string added to the right of the geometric tolerance.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS  - The input argument is invalid.
  PRO_TK_E_NOT_FOUND - There is no additional text for this geometric tolerance.
*/

extern ProError ProGtolRightTextSet (ProGtol *gtol, wchar_t *text);

/*
Purpose: Sets the text of the specified geometric tolerance.

Input Arguments:
  gtol - Pointer to the geometrical tolerance.
  text - The string added to the right of the geometric tolerance.

Output Arguments:
  None

Return Values:
  PRO_TK_NO_ERROR   - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS - One or more input argument is invalid.
  PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
  PRO_TK_CANT_WRITE - Could not modify the given item because
                      it has read-only access.
*/

extern ProError ProGtolDtlnoteGet (ProGtol    *solid_model_gtol,
                                   ProDrawing  drawing,
                                   ProDtlnote *dtl_note);
/*
Purpose: Return the detail note that represents a shown geometric tolerance.

Input Arguments:
  solid_model_gtol - The geometric tolerance handle.
  drawing          - The drawing where the note is displayed.

Output Arguments:
  dtl_note    - The drawing detail note that displays the model note.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The solid model is not contained in the drawing.
  PRO_TK_E_NOT_FOUND - The geometric tolerance is not displayed in the drawing
                       as a note.
*/




































extern ProError ProGtolleaderAlloc(
   ProLeaderType type,
   ProSelection attachment,
   ProGtolleader *leader);

/*
   Purpose:    Allocates and defines a gtol leader structure.

   Input Arguments:
      type        - The type which determinates the leader appearance
      attachment  - The item to which the leader is attached

   Output Arguments:
      leader      - The allocated gtol leader structure

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
*/

extern ProError ProGtolleaderFree(
   ProGtolleader *leader);

/*
   Purpose:    Frees a gtol leader structure.

   Input Arguments:
      leader      - Pointer to the leader structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolleadersFree(
   ProGtolleader **leaders);

/*
   Purpose:    Frees an array of gtol leader structures.

   Input Arguments:
      leaders     - Pointer to the leader structure array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolleaderGet(
   ProGtolleader leader,
   ProLeaderType *type,
   ProSelection *attachment);

/*
   Purpose:    Provides the information contained in a gtol leader structure.

   Input Arguments:
      leader      - The leader structure

   Output Arguments:
      type        - The type which determinates the leader appearance
      attachment  - The item to which the leader is attached

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGeomitemGtolrefSet(
   ProGeomitem  *geomitem,
   ProDimension *in_dim);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumSet
   Purpose:    <B><P>Note: This function is deprecated.  Use 
               ProGeomitemSetdatumSet() instead. </P></B>
    
               Sets a datum plane or axis to be a gtol reference.

   Input Arguments:
      geomitem    - The datum plane or axis
      in_dim      - Identifies the dimension for an "In dim" tolerance;
                    set to NULL if the gtol is "Free".

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGeomitemGtolrefClear(
   ProGeomitem *geomitem);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumClear
   Purpose:    <B><P>Note: This function is deprecated.  Use 
              ProGeomitemSetdatumClear() instead. </P></B>
    
   Clears a datum plane or axis so it is no longer a gtol reference.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_CANT_WRITE     - Could not delete the given item because
                              it has read-only access.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGeomitemIsGtolref(
   ProGeomitem *geomitem,
   ProBoolean  *ref_datum,
   ProBoolean  *is_in_dim,
   ProDimension *in_dim);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumGet
   Purpose:    <B><P>Note: This function is deprecated.  Use 
              ProGeomitemSetdatumGet() instead. </P></B>
    
   Shows whether a datum plane or axis is a gtol reference.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      ref_datum  - TRUE is the datum is a gtol reference
      is_in_dim  - TRUE if the datum is "In dim", FALSE if "Free"
      in_dim     - If is_in_dim==TRUE, the dimension

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/



typedef enum
{
   PROGTOLUNITAREASTYLE_X    = 0, /* /7X7 */
   PROGTOLUNITAREASTYLE_BOX  = 1, /* /[box]7 */
   PROGTOLUNITAREASTYLE_DIA  = 2  /* /[diameter]7 */
} ProGtolUnitareaStyle;

typedef enum 
{
   PRO_GTOLREF_IN_DIM,
   PRO_GTOLREF_IN_GTOL,
   PRO_GTOLREF_IN_GEOM,
   PRO_GTOLREF_FREE
} ProGtolsetdatumRefType;

typedef struct
{
   ProGtolsetdatumRefType type;
   union 
   {
     ProDimension dim;
     ProGtol gtol;
     ProSelection geom;
   } ref;
}ProGtolsetdatumValue;



extern ProError ProGeomitemSetdatumSet(
   ProGeomitem  *geomitem,
   ProGtolsetdatumValue* value);

/*
   Purpose:    Sets a datum plane or axis to be a Set Datum.  
               This function supersedes ProGeomitemGtolrefSet.

   Input Arguments:
      geomitem    - The datum plane or axis
      value  - The type and reference object for the "Set Datum" to apply.  
               Pass NULL to make it a "Free" Set Datum.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_WRITE     - Could not modify the given item because
                              it has read-only access.
*/
extern ProError ProGeomitemSetdatumClear(
   ProGeomitem *geomitem);

/*
   Purpose:    Removes the Set Datum status of a datum plane or axis.  
               This function supersedes ProGeomitemGtolrefClear.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      	none

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGeomitemSetdatumGet(
   ProGeomitem *geomitem,
   ProBoolean  *set,
   ProGtolsetdatumValue* value);

/*
   Purpose:    Shows whether a datum plane or axis is a Set Datum.  
               This function supersedes ProGeomitemIsGtolref.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      set - TRUE is the datum is a Set Datum.
      value  - The type and reference object for the "Set Datum" to apply.  
               If type of ProGtolsetdatumValue is PRO_GTOLREF_IN_GEOM, 
               the caller should free the memory for value.ref.geom 
               by using ProSelectionFree(). 
      
   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolTextstyleSet (ProGtol* gtol,
                                     ProTextStyle text_style);
/*
	DEPRECATED: Creo 1
    SUCCESSORS: ProAnnotationTextstyleSet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleSet() instead.</P> 
	      Assigns the text style assigned to a geometric tolerance.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The gtol.
        text_style - The text style. Free this using ProTextStyleFree().

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text style cannot be varied.
        PRO_TK_CANT_WRITE - Could not modify the given item because
                            it has read-only access.
*/

extern ProError ProGtolTextstyleGet (ProGtol* gtol,
                                     ProTextStyle* text_style);
/*
	DEPRECATED: Creo 1
    SUCCESSORS: ProAnnotationTextstyleGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleGet() instead.</P> 
	      Obtains the text style assigned to a geometric tolerance.

    Licensing Requirement:
          TOOLKIT for 3D Drawings
    
    Input Arguments:
        gtol - The gtol.
    
    Output Arguments:
        text_style - The text style.  Free this using ProTextStyleFree().
    
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProGtolElbowlengthGet (ProGtol* gtol,
                                       double* elbow_length,
                                       ProVector elbow_direction);
/*
    Purpose: Obtains the elbow properties of the geometric tolerance.
<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The gtol.

    Output Arguments:
        elbow_length - The elbow length, in model units.
        elbow_direction - The elbow direction, in the model's coordinate
                          system.  This is the
                          direction from the gtol text to the gtol leaders.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not use leaders.
        PRO_TK_INVALID_TYPE - This gtol was created in a release before 
                              Wildfire 2.0. Because of this, its internal 
                              structure is different and the elbow length 
                              cannot be obtained by this function.
*/

extern ProError ProGtolLineEnvelopeGet (ProGtol* note,
                                        int line_number,
                                        ProLineEnvelope envelope);
/*
    Purpose: Get the envelope of a line in a specified geometric tolerance.
<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The gtol.
        line_number - The line number of the gtol.

    Output Arguments:
        envelope - The envelope surrounding the text line, in the model's
                   coordinate system.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The indicated line does not exist.
*/





typedef enum
{
   PRO_GTOLVALTYPE_VALUE               = 1,  /* ProGtoldataValueSet */
   PRO_GTOLVALTYPE_COMPOSITE           = 2,  /* ProGtoldataCompositeSet */
   PRO_GTOLVALTYPE_ZONE_HEIGHT         = 3,  /* ProGtoldataProjZoneSet */
   PRO_GTOLVALTYPE_PERUNIT             = 4,  /* ProGtoldataPerUnitSet */
   PRO_GTOLVALTYPE_UNIT_AREA_OR_LENGTH = 5,  /* ProGtoldataPerUnitSet */
   PRO_GTOLVALTYPE_DISPOSITION         = 6   /* ProGtoldataDispositionValSet */
} ProGtolValueType;



typedef enum 
{
PRO_GTOLTEXT_ON_RIGHT,
PRO_GTOLTEXT_ON_TOP,
PRO_GTOLTEXT_ON_BOTTOM,
PRO_GTOLTEXT_ON_LEFT
} ProGtolTextType;

extern ProError ProGtolTopTextGet (ProGtol* gtol, wchar_t** above_text);
/*
    Purpose: Obtains the text added to the top of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        above_text - The text added to the top of the geometric tolerance.  If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text on top.

*/

extern ProError ProGtolTopTextSet (ProGtol* gtol, wchar_t* above_text);
/*
    Purpose: Assigns the text added to the top of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        above_text - The text added to the top of the geometric tolerance.  If 
                   the text should extend over multiple lines, the input string 
                   should contain '\n' characters indicating the line breaks.  
                   Note that the top text cannot extend beyond the length of 
                   the gtol control frame, and so the function may 
                   automatically insert line breaks into the text when doing 
                   this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the top text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolBottomTextGet (ProGtol* gtol, wchar_t** below_text);
/*
    Purpose: Obtains the text added to the bottom of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        below_text - The text added to the bottom of the geometric tolerance. If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text on bottom.

*/

extern ProError ProGtolBottomTextSet (ProGtol* gtol, wchar_t* below_text);
/*
    Purpose: Assigns the text added to the bottom of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        below_text - The text added to the bottom of the geometric tolerance. If 
                   the text should extend over multiple lines, the input string 
                   should contain '\n' characters indicating the line breaks.  
                   Note that the bottom text cannot extend beyond the length of 
                   the gtol control frame, and so the function may 
                   automatically insert line breaks into the text when doing 
                   this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the bottom text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolLeftTextGet (ProGtol* gtol, wchar_t** left_text);
/*
    Purpose: Obtains the text added to the left of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        left_text - The text added to the left of the geometric tolerance. If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text to left.

*/

extern ProError ProGtolLeftTextSet (ProGtol* gtol, wchar_t* left_text);
/*
    Purpose: Assigns the text added to the left of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        left_text - The text added to the left of the geometric tolerance. If 
                  the text should extend over multiple lines, the input string 
                  should contain '\n' characters indicating the line breaks.  
                  Note that the left text cannot extend beyond the length of 
                  the gtol control frame, and so the function may 
                  automatically insert line breaks into the text when doing 
                  this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the left text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolAddlTextBoxedSet (ProGtol* gtol, ProGtolTextType text_type, ProBoolean is_boxed);
/*
    Purpose: Set Boxed to Additional text to a geometric tolerance with particular ProGtolTextType.
              Note that only Top and Bottom ProGtolTextType can have Boxed.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
            gtol - The geometric tolerance.
            text_type - The instance of additional text to access.
            is_boxed - Set boxed to the additional text. Pass PRO_B_TRUE to set the Boxed.
    
    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
            PRO_TK_CANT_WRITE - Cannot modify the gtol because it is read-only.

*/

extern ProError ProGtolAddlTextBoxedGet (ProGtol* gtol, ProGtolTextType text_type, ProBoolean* is_boxed);
/*
    Purpose: Get if Additional text to a geometric tolerance with particular ProGtolTextType is Boxed.
              Note that only Top and Bottom ProGtolTextType can have Boxed.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
            gtol - The geometric tolerance.
            text_type - The instance of additional text to access.

    Output Arguments:
            is_boxed - PRO_B_TRUE if Additional text to a gtol with particular ProGtolTextType is Boxed.

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
            PRO_TK_E_NOT_FOUND - The gtol does not have text on particular ProGtolTextType.

*/

extern ProError ProGtolPrefixGet (ProGtol* gtol, wchar_t** prefix);
/*
    Purpose: Obtains the prefix text for the geometric tolerance.
    
    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        prefix - The prefix text.  Free this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not contain prefix text.

*/

extern ProError ProGtolPrefixSet (ProGtol* gtol, wchar_t* prefix);
/*
    Purpose: Assigns the prefix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        prefix - The prefix text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol prefix cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the text because the gtol is read-only.

*/

extern ProError ProGtolSuffixGet (ProGtol* gtol, wchar_t** suffix);
/*
    Purpose: Obtains the suffix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        suffix - The suffix text.  Free this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not contain suffix text.

*/

extern ProError ProGtolSuffixSet (ProGtol* gtol, wchar_t* suffix);
/*
    Purpose: Assigns the suffix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        suffix - The suffix text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol suffix cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the text because the gtol is read-only.

*/

extern ProError ProGtoltextTextstyleGet (ProGtol* gtol, 
                                         ProGtolTextType text_type, 
					 ProTextStyle* text_style);
/*
    Purpose: Gets the text style for the additional text applied to a geometric
             tolerance.

    Licensing Requirement:	
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The geometric tolerance.
        text_type - The instance of additional text to access.

    Output Arguments:
        text_style - The text style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have the additional text
                             specified.

*/

extern ProError ProGtoltextTextstyleSet (ProGtol* gtol, 
                                         ProGtolTextType text_type, 
					 ProTextStyle text_style);
/*
    Purpose: Sets the text style for the additional text applied to a geometric
             tolerance.  Note that not all text style properties are supported 
             for gtol additional text; unsupported properties are ignored by 
             this function.

    Licensing Requirement:	
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The geometric tolerance.
        text_type - The instance of additional text to access.
        text_style - The text style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text style cannot be varied.
        PRO_TK_CANT_WRITE - Cannot modify the gtol because it is read-only.

*/

extern ProError ProGtolRightTextEnvelopeGet (ProGtol* note,

                                        ProLineEnvelope envelope);

/*
    Purpose: Get the envelope of the right text in a specified geometric tolerance.

<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The gtol.

    Output Arguments:
        envelope - The envelope surrounding the right text, in the model's
                   coordinate system.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

	



extern ProError ProGtolTopTextHorizJustificationSet (
   ProGtol* gtol, ProTextHrzJustification justification);
/*
   Purpose:    Sets horizontal justification for additional gtol text at the top

   Input Arguments:
      gtol              - The gtol
      justification - Applied justification

   Output Arguments:
      none

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolTopTextHorizJustificationGet (
   ProGtol* gtol, ProTextHrzJustification *justification);
/*
   Purpose:    Gets horizontal justification for additional gtol text at the top

   Input Arguments:
      gtol              - The gtol

   Output Arguments:
      justification - Justification to apply. 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolBottomTextHorizJustificationSet (
   ProGtol* gtol, ProTextHrzJustification justification);
/*
   Purpose:    Sets horizontal justification for additional gtol text at the bottom

   Input Arguments:
      gtol              - The gtol
      justification - Applied justification

   Output Arguments:
      none

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolBottomTextHorizJustificationGet (
   ProGtol* gtol, ProTextHrzJustification *justification);
/*
   Purpose:    Gets horizontal justification for additional gtol text at the bottom

   Input Arguments:
      gtol              - The gtol

   Output Arguments:
      justification - Justification to apply. 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProMdlGtolCreate (ProMdl owner_mdl, ProGtolType type, ProGtolAttach gtol_attach, wchar_t* value_str, ProGtol *gtol);
/*
   Purpose:   Creates new Gtol with specified placement and value string

   Input Arguments:
     owner_mdl  - Owner of the gtol.
	   type       - type of gtol.
	   gtol_attach  - placement which includes attachment references and annotation plane.
	   value_str  - value string.

   Output Arguments:
		 gtol - newly created gtol.

   Return Values:
     PRO_TK_NO_ERROR      - The function completed successfully.
     PRO_TK_BAD_CONTEXT	  - Specified placement reference are invalid.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - Gtol could not be created.
     PRO_TK_UNSUPPORTED   - owner_mdl is not drawing for creating 
                            make dim or offset type gtol.
*/

extern ProError  ProGtolValueStringSet (ProGtol *gtol, wchar_t* value);
/*
   Purpose:   Set value string of gtol

   Input Arguments:
     gtol			  - valid gtol.
	   value      - value string.

   Output Arguments:
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolValueStringGet (ProGtol *gtol, wchar_t** value);
/*
   Purpose:   Get value string of gtol

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   value           - value string.Free it using ProWstringFree()
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_E_NOT_FOUND    - No value string found
*/

extern ProError  ProGtolAllOverSet(ProGtol *gtol, ProBoolean all_over);
/*
   Purpose:   Set all over option for profile gtol

   Input Arguments:
      gtol			 - valid gtol.
      all_over   - Pass PRO_B_TRUE to set all over else pass PRO_B_FASLE
	
   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR      - The function completed successfully.
	   PRO_TK_CANT_MODIFY   - This type of gtol does not support all over.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/

extern ProError  ProGtolAllOverGet(ProGtol *gtol, ProBoolean *all_over);
/*
   Purpose:   Get all over option for profile gtol

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   all_over        - PRO_B_TRUE if all over is set else PRO_B_FASLE
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
	   PRO_TK_INVALID_TYPE   - This type of gtol does not support all over.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolAllAroundSet(ProGtol *gtol, ProBoolean all_around);
/*
   Purpose:   Set all around option for profile gtol

   Input Arguments:
     gtol			   - valid gtol.	  
     all_around  - Pass PRO_B_TRUE to set all around else pass PRO_B_FASLE

   Output Arguments:	   
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
	   PRO_TK_CANT_MODIFY    - This type of gtol does not support all around.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolAllAroundGet(ProGtol *gtol, ProBoolean *all_around);
/*
   Purpose:   Get all around option for profile gtol

   Input Arguments:
     gtol			   - valid gtol.	  

   Output Arguments:
	   all_around  - PRO_B_TRUE if all around is set else PRO_B_FASLE
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_INVALID_TYPE   - This type of gtol does not support all around.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeGet (ProGtol *gtol, wchar_t*** values ,wchar_t*** primary ,wchar_t*** secondary ,wchar_t*** tertiary);
/*
   Purpose:   Get composite tolerance frame

   Input Arguments:
      gtol			 - valid gtol.	  

   Output Arguments:
		 values    -  NULL or ProArray() of value strings. Free it using ProWstringproarrayFree()
		 primary   -  NULL or ProArray() of primary strings. Free it using ProWstringproarrayFree()
		 secondary -  NULL or ProArray() of secondary strings. Free it using ProWstringproarrayFree()
		 tertiary  -  NULL or ProArray() of tertiary strings. Free it using ProWstringproarrayFree()

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeSet(ProGtol *gtol, int index ,wchar_t* value ,wchar_t* primary ,wchar_t*  secondary ,wchar_t* tertiary);
/*
   Purpose:   Set composite tolerance

   Input Arguments:
     gtol   - valid gtol.
	   index  - position.Indices starts from 0. Pass PRO_VALUE_UNUSED to insert at end.
     value     -  value string. If NULL, row corresponding to input index will be removed.
     primary   -  primary datum string.
     secondary -  secondary datum string.
     tertiary  -  tertiary datum string.
   
   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	
     PRO_TK_OUT_OF_RANGE   - invalid index
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolDatumReferencesSet (ProGtol *gtol, wchar_t* primary,wchar_t* secondary,wchar_t* tertiary);
/*
   Purpose:   Set datum references to gtol.

   Input Arguments:
     gtol			 - valid gtol.
     primary   - primary datum ref. Can be NULL
     secondary - secondary datum ref. Can be NULL
     tertiary  - tertiary datum ref. Can be NULL

   Output Arguments:
		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	 
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolDatumReferencesGet (ProGtol *gtol, wchar_t** primary,wchar_t** secondary,wchar_t** tertiary);
/*
   Purpose:   Get datum references to gtol.

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   primary -  primary datum ref. Can be NULL.  Free it using ProWstringFree()
	   secondary -  secondary datum ref. Can be NULL. Free it using ProWstringFree()
	   tertiary -  tertiary datum ref. Can be NULL. Free it using ProWstringFree()
		

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	 
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeShareRefSet(ProGtol *gtol,ProBoolean share);
/*
   Purpose:   Set Share datum references for composite frame

   Input Arguments:
     gtol		- valid gtol.	  
     share  - Pass PRO_B_TRUE to share else pass PRO_B_FALSE

   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeShareRefGet(ProGtol *gtol,ProBoolean *share);
/*
   Purpose:   Get Share datum references for composite frame

   Input Arguments:
     gtol - valid gtol.

   Output Arguments:
     share - share option.		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolTypeSet (ProGtol *gtol , ProGtolType type);
/*
   Purpose:   Set gtol type

   Input Arguments:
     gtol    - valid gtol.	
     type    - gtol type

   Output Arguments:      		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolTypeGet (ProGtol *gtol , ProGtolType *type);
/*
   Purpose:   Set gtol type

   Input Arguments:
     gtol    - valid gtol.

   Output Arguments:
     type    - gtol type

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolBoundaryDisplaySet(ProGtol *gtol, ProBoolean boundary);
/*
   Purpose:   Set display of Boundary modifier.

   Input Arguments:
     gtol			 - valid gtol.
     boundary  - Pass PRO_B_TRUE to display else pass PRO_B_FALSE

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_CANT_MODIFY    - This type of gtol cannot have boundary modifier
*/

extern ProError ProGtolBoundaryDisplayGet(ProGtol *gtol, ProBoolean *boundary);
/*
   Purpose:   Get display of Boundary modifier.

   Input Arguments:
     gtol	- valid gtol.

   Output Arguments:
     boundary -  boundary option.

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_INVALID_TYPE   - This type of gtol cannot have boundary modifier
 */

extern ProError ProGtolUnilateralSet(ProGtol *gtol, ProBoolean unilateral_set, ProBoolean outside);
/*
   Purpose:   Set Unilateral modifier.

   Input Arguments:
     gtol			      - valid gtol.
     unilateral_set - PRO_B_TRUE to set Unilateral modifier 
                      PRO_B_FALSE to remove Unilateral modifier 
     outside        - Whether the tolerance refers to the outside of
                      the profile, if unilateral_set == PRO_B_TRUE

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_CANT_MODIFY    - This type of gtol cannot have unilateral modifier
*/

extern ProError ProGtolUnilateralGet(ProGtol *gtol, ProBoolean *unilateral_set, ProBoolean *outside);
/*
   Purpose:   Get Unilateral modifier.

   Input Arguments:
     gtol	- valid gtol.

   Output Arguments:
     unilateral_set -  unilateral modifier.
     outside        -  Whether the tolerance refers to the outside of
                       the profile, if unilateral_set == PRO_B_TRUE

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_INVALID_TYPE   - This type of gtol cannot have unilateral modifier
 */

extern ProError  ProGtolTopModelGet(ProGtol *gtol,ProMdl *top_mdl);
/*
   Purpose:   Get top model of gtol

   Input Arguments:
     gtol		 - valid gtol.	  	  

   Output Arguments:
     top_mdl		 - The model (part, assembly, or drawing) that  
                           defines the origin of ProSelection structures used
                           in setting up gtol references.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	  	  
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolElbowlengthSet (ProGtol* gtol, double elbow_length, ProVector elbow_direction);
/*
    Purpose: Set elbow to gtol.
<p><b>Note:</b>
    This function only supports leader type gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
      gtol            - The gtol.
		  elbow_length    - The elbow length, in model units.
		  elbow_direction - The elbow direction, in the model's coordinate
		                    system.  This is the direction from the gtol text 
                        to the gtol leaders.

    Output Arguments:       

    Return Values:
      PRO_TK_NO_ERROR     - The function succeeded.
      PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.        
      PRO_TK_INVALID_TYPE - The gtol does not use leaders.
*/

extern ProError  ProGtolSymbolStringGet (ProGtolSymbol symbol, ProSymbolFont font, wchar_t **value);
/*
   Purpose:   Get value string of gtol

   Input Arguments:
      symbol			 - Type of symbol 
	  font			     - Symbol font type

   Output Arguments:
	  value           - value string. Free it using ProWstringFree()
	
   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	  
      PRO_TK_BAD_INPUTS     - The input argument is invalid.	  
*/

extern ProError ProGtolReferencesAdd( ProGtol                    *gtol, 
                                      ProAnnotationReference     *refs );
/*
   Purpose:   Add gtol references

   Input Arguments:
      gtol  - valid gtol.
      refs  - ProArray of gtol references.
              Only 1 reference from type PRO_ANNOT_REF_SRF_COLLECTION is allowed.

   Output Arguments:      
      

   Return Values:
      PRO_TK_NO_ERROR          - The function completed successfully.
      PRO_TK_BAD_INPUTS        - The input argument is invalid.      
      PRO_TK_BAD_CONTEXT       - The gtol owner is drawing.
      PRO_TK_MAX_LIMIT_REACHED - More than 1 references from type PRO_ANNOT_REF_SRF_COLLECTION.
      PRO_TK_CANT_MODIFY       - Refercnce from type PRO_ANNOT_REF_SRF_COLLECTION already exist.
*/

extern ProError ProGtolReferencesGet( ProGtol                 *gtol, 
                                      ProAnnotationReference **p_refs );
/*
   Purpose:   Get gtol references

   Input Arguments:
     gtol        - valid gtol.
    
   Output Arguments:
     p_refs   - ProArray of gtol references. Free it using ProAnnotationreferencearrayFree()
    
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_BAD_CONTEXT    - The gtol owner is drawing.
		  
	See Also:
     ProAnnotationElementGet()
*/

extern ProError ProGtolReferenceDelete( ProGtol *gtol, 
                                        int      index_ref );
/*
   Purpose:   Delete gtol reference

   Input Arguments:
      gtol    - valid gtol. 
 index_ref    - Indices start from 0. Get existing references from ProGtolReferencesGet()

   Output Arguments:       

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
      PRO_TK_BAD_CONTEXT    - The gtol owner is drawing..
*/

extern ProError ProGtolIndicatorsSet (ProGtol *gtol, ProGtolIndicatorType *types, wchar_t **symbols, wchar_t **dfs);
/*
   Purpose:   Set indicators of gtol. Pass types, symbols and dfs as NULL to remove all indicators.

   Input Arguments:
    gtol     - valid gtol.
	  types    - ProArray() of indicator types. Maximum array size is 3.
	  symbols  - ProArray() of indicator symbols strings. Maximum array size is 3.
	  dfs			 - ProArray() of dfs strings. Maximum array size is 3.

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.	 
*/

extern ProError ProGtolIndicatorsGet (ProGtol *gtol, ProGtolIndicatorType **types, wchar_t ***symbols, wchar_t ***dfs);
/*
   Purpose:     Get indicators of gtol

   Input Arguments:
     gtol			- valid gtol.	  

   Output Arguments:
		 types    -  ProArray() of indicator types. Free it using ProArrayFree()
		 symbols  -  ProArray() of indicator symbols strings. Free it using ProWstringproarrayFree()
		 dfs      -  ProArray() of dfs strings. Free it using ProWstringproarrayFree()		 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_E_NOT_FOUND    - No indicators found for specified gtol
*/

extern ProError  ProGtolNameGet (ProGtol *gtol, wchar_t **p_name);
/*
   Purpose:   Get name of gtol

   Input Arguments:
     gtol   - valid gtol.

   Output Arguments:
     p_name - name string.Free it using ProWstringFree()

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_E_NOT_FOUND    - Gtol is not found in database.
*/

extern ProError ProGtolValidate (ProGtol *gtol, ProGtolValidityCheckType type, ProBoolean *is_valid_gtol);
/*
   Purpose:     Check whether the gtol is valid or not

   Input Arguments:
     gtol     - gtol.
     type     - type of validity check

   Output Arguments:
     is_valid_gtol - PRO_B_TRUE if GTol is valid, PRO_B_FALSE otherwise 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR  - The function encountered an error.
*/

extern ProError ProGtolDtlnotesCollect(ProGtol *solid_model_gtol, ProDrawing drawing, ProDtlnote **notes);
/*
Purpose: Return the detail notes that represent a geometric tolerance in a drawing.

Input Arguments:
  solid_model_gtol - The geometric tolerance handle.
  drawing          - The drawing where the note is displayed.

Output Arguments:
  notes    - ProArray of drawing notes that represent a model gtol.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the notes.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The solid model is not contained in the drawing.
  PRO_TK_E_NOT_FOUND - The geometric tolerance is not represented in the drawing
                       by any note.
*/

extern ProError ProGtolleaderZExtensionlineGet(ProGtol *gtol, ProGtolleader *leader, ProBoolean *is_zextension, ProPoint3d *line_end);
/*
Purpose: Gets Z-Extension line of gtol leader. This is required when gtol is moved to another plane and other cases. 

Input Arguments:
  gtol      - The geometric tolerance handle.
  leader    - gtol leader.

Output Arguments:
  is_zextension      - PRO_B_TRUE if gtol has Z-Extension.
  line_end           - end point of extension line.

Return Values:
  PRO_TK_NO_ERROR       - The function completed successfully.
  PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
*/

extern ProError ProGtolEnvelopeGetWithFlags (ProGtol         *gtol,
                                             ProDrawing       drawing,
                                             ProGtolEnvelopeFlag flags,
                                             ProLineEnvelope  envelope);
/*
  Purpose: Get the envelope of gtol.
  For getting coordinates of gtol displayed in solid and same gtol is displayed
  in drawing then drawing should not be active.

  Input Arguments:
    gtol     - gtol.
    drawing  - drawing. Pass only for solid gtol shown in drawing, otherwise
               pass NULL.
    flags    - Gtol Envelope Flag. Pass PRO_GTOL_ENVELOPE_SKIP_OUTSIDE_TEXT to
               get envelope without additional texts, otherwise pass
               PRO_GTOL_ENVELOPE_DEFAULT.

  Output Arguments:
    envelope - The envelope surrounding the gtol, in the model's coordinate
               system. For Flat to Screen Gtol, envelope will be in screen
               co-ordinates.
               For drawing it is in the screen coordinates.
               For additional texts, there won't be any padding.

  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments were invalid.
*/

extern ProError ProGtolEnvelopeGet (ProGtol         *gtol,
                                    ProDrawing       drawing,
                                    ProLineEnvelope  envelope);
/*
  Purpose: Get the envelope of gtol.
  For getting coordinates of gtol displayed in solid and same gtol is displayed
  in drawing then drawing should not be active.

  Input Arguments:
    gtol     - gtol.
    drawing  - drawing. Pass only for solid gtol shown in drawing, otherwise
               pass NULL.

  Output Arguments:
    envelope - The envelope surrounding the gtol, in the model's coordinate
               system. For Flat to Screen Gtol, envelope will be in screen
               co-ordinates.
               For drawing it is in the screen coordinates.
               For additional texts, there won't be any padding.

  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments were invalid.
*/

PRO_END_C_DECLS
#endif /* PROGTOL_H */
