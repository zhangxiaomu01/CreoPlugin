#ifndef PRO_SPLITBODY_H
#define PRO_SPLITBODY_H

/*
   Creo Parametric TOOLKIT declarations related to split body feature.
*/



#include <ProFeature.h>

PRO_BEGIN_C_DECLS


/*****************************************************************************

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SPLIT_BY_OPTION
     |   
	 |--PRO_E_SPLIT_BODY_TYPE
	 |
     |--PRO_E_SPLIT_BODY
     |    |--PRO_E_SPLIT_TARGET_BODY
     |    |--PRO_E_SPLIT_BODY_REF
     |    |--PRO_E_SPLIT_BODY_SLICE_OPT
     |    |--PRO_E_SPLIT_TOOL_EXTEND_OPT 
     |
     |--PRO_E_SPLIT_OUT
     |    |--PRO_E_SPLIT_VOL_SRFS


Feature elements table

----------------------------------------------------------------------------------------------------------
Element Id                   Element Name            Data Type                  Valid Values
----------------------------------------------------------------------------------------------------------

PRO_E_FEATURE_TYPE           Feature type            PRO_VALUE_TYPE_INT         PRO_FEAT_SPLIT_BODY
PRO_E_STD_FEATURE_NAME       Feature Name            PRO_VALUE_TYPE_WSTRING
PRO_E_SPLIT_BY_OPTION        Split by option         PRO_VALUE_TYPE_INT         ProSplitByType
PRO_E_SPLIT_BODY_TYPE        Operation               PRO_VALUE_TYPE_INT         ProSplitOperation
PRO_E_SPLIT_BODY             Split by object         Compound
PRO_E_SPLIT_TARGET_BODY      Target body             PRO_VALUE_TYPE_SELECTION
PRO_E_SPLIT_BODY_REF         Split By                PRO_VALUE_TYPE_SELECTION
PRO_E_SPLIT_BODY_SLICE_OPT   Slice direction         PRO_VALUE_TYPE_INT         ProSplitBodySliceOpt
PRO_E_SPLIT_TOOL_EXTEND_OPT  Extend splitting object PRO_VALUE_TYPE_INT         ProSplitBodyToolExtendOpt
PRO_E_SPLIT_OUT              Split by volume         Compound
PRO_E_SPLIT_VOL_SRFS         Surfaces                PRO_VALUE_TYPE_SELECTION

-----------------------------------------------------------------------------------------------------------
Note 1 : Using the split body feature a given body can be splitted 
         either by a splitting object or by volume. 
--------------------------------------------------------------------------------
Table 1: Mandatory elements for Split by object type of splitting.
------------------------------------------------------------------------------
|              | Element Id                      | Comment                   |
------------------------------------------------------------------------------
| Splitting    : PRO_E_SPLIT_BY_OPTION           : PRO_SPLIT_BY_SPLITTING_OBJ|
| Object                                           of type ProSplitByType    |
|              : PRO_E_SPLIT_TARGET_BODY         : Body to be split          |
|              : PRO_E_SPLIT_BODY_REF            : Splitting object          |
|              : PRO_E_SPLIT_BODY_SLICE_OPT      : Side 1 / Side 2 of type   |
|                                                  ProSplitBodySliceOpt      |
|              : PRO_E_SPLIT_TOOL_EXTEND_OPT     : Extend option of type     |
|                                                  ProSplitBodyToolExtendOpt |
|............................................................................|

--------------------------------------------------------------------------------
Table 2: Mandatory elements for Split by volume type of splitting.
------------------------------------------------------------------------------
|              | Element Id                      | Comment                   |
------------------------------------------------------------------------------
| Volume      : PRO_E_SPLIT_BY_OPTION            : PRO_SPLIT_BY_VOLUME       |
|                                                  of type ProSplitByType    |
|             : PRO_E_SPLIT_VOL_SRFS             : Surfaces and / or surface |
|                                                  regions                   |
|----------------------------------------------------------------------------|
*****************************************************************************/
/* PRO_E_SPLIT_BY_OPTION */
typedef enum pro_split_by_type
{
   PRO_SPLIT_BY_SPLITTING_OBJ = 1,
   PRO_SPLIT_BY_VOLUME        = 2
} ProSplitByType;

typedef enum pro_split_operation
{
	PRO_SPLIT_BODY = 1,
	PRO_TRIM_BODY = 2
} ProSplitOperation;

 /* PRO_E_SPLIT_BODY_SLICE_OPT */
 typedef enum pro_split_body_slice_opt
 {
   PRO_E_SPLIT_BODY_SLICE_FIRST_OPT  =  0,
   PRO_E_SPLIT_BODY_SLICE_SECOND_OPT =  1 
 } ProSplitBodySliceOpt;

 /* PRO_E_SPLIT_TOOL_EXTEND_OPT */
 typedef enum pro_split_body_tool_extend_opt
 {
   PRO_E_SPLIT_TOOL_EXTEND_OPT_NO   = 0,
   PRO_E_SPLIT_TOOL_EXTEND_OPT_YES  = 1
 } ProSplitBodyToolExtendOpt;

PRO_END_C_DECLS

#endif
