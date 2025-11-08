#ifndef PRO_UNIFYSURF_H
#define PRO_UNIFYSURF_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_UNIFYSRF_TARGET
      |
      |-- PRO_E_UNIFYSRF_SRFS
      |
      |-- PRO_E_UNIFYSRF_UPD_SRF_REF_OPT
   
===============================================================================

(2) Feature elements table

-----------------------------------------------------------------------------------------------
Element Id                      Element Name      Data Type                Valid Values
-----------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type      PRO_VALUE_TYPE_INT       Note1
PRO_E_STD_FEATURE_NAME          Feature Name      PRO_VALUE_TYPE_WSTRING   Note2
PRO_E_UNIFYSRF_TARGET           Target Surface    PRO_VALUE_TYPE_SELECTION Note3 
PRO_E_UNIFYSRF_SRFS             Surfaces to unify PRO_VALUE_TYPE_SELECTION Note4
PRO_E_UNIFYSRF_UPD_SRF_REF_OPT  Options           PRO_VALUE_TYPE_BOOLEAN   Note5 
================================================================================================

(3) Notes

   Note1 : PRO_FEAT_UNIFYSRF

   Note2 : Surface Region feature name.
           Default value is "Unify_Surfaces".

   Note3 : The target surface can be any surface of a quilt or body, 
           that has at least one split-edge or non-refinable-edge

   Note4 : This is a set of surfaces, which will be unified into the target.

   Note5 : The "Update Surface References" option is related to surface 
           reference forwarding for the children.
           (PRO_B_TRUE : The consumed surface references will be forwarded.)

==============================================================================*/

PRO_END_C_DECLS

#endif /* PRO_UNIFYSURF_H */
