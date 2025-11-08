#ifndef PROBODYCOPYH
#define PROBODYCOPYH



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
      |-- PRO_E_BODY_COPY_REFS
===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
Element Id                     Element Name     Data Type                 Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type     PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME         Feature Name     PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_BODY_COPY_REFS           Bodies to copy   PRO_VALUE_TYPE_SELECTION  Note-3

===============================================================================

(3) Notes

   Note-1 : PRO_FEAT_BODY_COPY

   Note-2 : Body copy feature name.

   Note-3 : Mandatory: one or more selected bodies to copy. Only bodies from
            the same model are allowed.
            In case of multiple bodies, please use ProElementReferencesSet().

==============================================================================*/

PRO_END_C_DECLS

#endif
