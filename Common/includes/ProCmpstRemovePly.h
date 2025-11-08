#ifndef PROCMPSTREMOVE_PLY_H
#define PROCMPSTREMOVE_PLY_H

/*
   Creo Parametric TOOLKIT declarations related to removePly feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************
 Feature element tree :

 PRO_E_FEATURE_TREE
	 |
	 |--PRO_E_FEATURE_TYPE
	 |--PRO_E_REMOVE_PLY_TYPE
	 |--PRO_E_STD_FEATURE_NAME
	 |--PRO_E_REMOVE_PLY_REF


Feature elements table
------------------------------------------------------------------------
Element Id                  Element Name         Data Type
------------------------------------------------------------------------
PRO_E_FEATURE_TYPE         Feature Type       PRO_VALUE_TYPE_INT        Note-1
PRO_E_REMOVE_PLY_TYPE      Type               PRO_VALUE_TYPE_INT        Note-2
PRO_E_STD_FEATURE_NAME     featname           PRO_VALUE_TYPE_WSTRING              
PRO_E_REMOVE_PLY_REF       ply_ref            ProArray of ProReference

 Notes
	Note-1 : PRO_FEAT_REMOVE_PLY
    Note-2 : ProRemovePlyType

*****************************************************************************/

typedef enum pro_remove_ply_type
{
	PRO_REMOVE_PLY_UNDEFINE = -1,
	PRO_REMOVE_PLY_REMOVE   = 0,   
	PRO_REMOVE_PLY_KEEP     = 1 
} ProRemovePlyType;

PRO_END_C_DECLS

#endif

