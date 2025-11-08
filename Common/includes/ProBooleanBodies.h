#ifndef PRO_BOOLEANBODIES_H
#define PRO_BOOLEANBODIES_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
	 |
         |--PRO_E_FEATURE_TYPE
         |
	 |--PRO_E_STD_FEATURE_NAME
	 |
	 |--PRO_E_BOOLEAN_TYPE
	 |
	 |--PRO_E_TARGET_BODY
	 |
	 |--PRO_E_TOOL_BODIES
	 |
	 |--PRO_E_KEEP_TOOLS
         |
         |--PRO_E_IS_SMT_CUT
         |
         |--PRO_E_SMT_CUT_NORMAL_DIR

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                Element Name       Data Type                 Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE         Feature Type       PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME     Feature name       PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_BOOLEAN_TYPE         Operation type     PRO_VALUE_TYPE_INT        Note-3 (ProBooleanbodiesTypeOption)
PRO_E_TARGET_BODY          Modified bodies    PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_TOOL_BODIES          Modifying bodies   PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_KEEP_TOOLS           Keep body          PRO_VALUE_TYPE_INT        Note-6 (ProBooleanbodiesKeepBodyOption)
PRO_E_IS_SMT_CUT           Normal Smt Cut     PRO_VALUE_TYPE_INT        Note-7
PRO_E_SMT_CUT_NORMAL_DIR   Normal Direction   PRO_VALUE_TYPE_INT        Note-8 (ProSmtCutNormDir)

===============================================================================

(3) Notes
   Note-1 : PRO_FEAT_BOOLEANBODIES

   Note-2 : Combine boolean body feature name.
			Default value depends on the operation type:
			Body Merge , Body Intersect or Body Subtract.
		
   Note-3 : boolean operation type options: Body Merge ( MERGE_BOOL_TYPE ),
			Body Intersect ( INTERSECT_BOOL_TYPE ),
			Body Subtract ( SUBTRACT_BOOL_TYPE ).

   Note-4 : References to modified body/bodies.
			valid selection refernce is from type PRO_BODY only.
			This is a mandatory element, could be filled with single body
			(MERGE_BOOL_TYPE or INTERSECT_BOOL_TYPE) or multiple bodies
			(SUBTRACT_BOOL_TYPE).
			In case of multiple bodies, please use ProElementReferencesSet().

   Note-5 : References to modifying body/bodies.
			valid selection refernce is from type PRO_BODY only.
			This is a mandatory element, could be filled with single body
			(SUBTRACT_BOOL_TYPE) or multiple bodies
			(MERGE_BOOL_TYPE or INTERSECT_BOOL_TYPE).

   Note-6 : Keep body options: available only when the boolean type is 
            SUBTRACT_BOOL_TYPE.
            KEEP_TOOL_NO (default) will delete the modifying bodies, 
            KEEP_TOOL_YES will keep the modifying body.

   Note-7 : This element is applicable only in sheetmetal parts.
            Controls cut type, SMT or SOLID.  PRO_B_TRUE for SMT cut type.

   Note-8 : This element is applicable only in sheetmetal parts.
            SMT Cut geometry driving surface.
            This element can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to
            Driven Surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to
            Offset Surface.  ProSmtCutNormDir.


==============================================================================*/


/* ==================== */
/* Type options of combine boolean body: */
/* ==================== */

typedef enum
{
	PRO_MERGE_BOOL_TYPE = 1,
	PRO_INTERSECT_BOOL_TYPE = 2,
	PRO_SUBTRACT_BOOL_TYPE = 3
} ProBooleanbodiesTypeOption;

/* ===================== */
/* Keep body for combine boolean body: */
/* ===================== */

typedef enum
{
	PRO_KEEP_TOOL_NO = 0,
	PRO_KEEP_TOOL_YES = 1
} ProBooleanbodiesKeepBodyOption;



PRO_END_C_DECLS
#endif /* PRO_BOOLEANBODIES_H */
