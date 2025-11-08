#ifndef PRO_REMOVEBODY_H
#define PRO_REMOVEBODY_H



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
	 |--PRO_E_BODY_SELECT
	 |


===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                Element Name       Data Type                Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE         Feature Type       PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME     Feature name       PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_BODY_SELECT         Remove bodies      PRO_VALUE_TYPE_SELECTION   Note-3

===============================================================================

(3) Notes

   Note-1 : PRO_FEAT_REMOVEBODY

   Note-2 : Remove body feature name.
			Default value Remove body.

   Note-3 : References for bodies that will be removed.
			valid selection reference is from type PRO_BODY only.
			This is a mandatory element, could be filled with single body
			or multiple bodies.
			In case of multiple bodies, please use ProElementReferencesSet().


==============================================================================*/


PRO_END_C_DECLS
#endif /* PRO_REMOVEBODY_H */
