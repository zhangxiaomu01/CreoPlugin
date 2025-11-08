#ifndef PROSMTFLATTENFORM_H
#define PROSMTFLATTENFORM_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Flatten Form feature
*/



#include <ProToolkit.h>
#include <ProBodyOpts.h>

PRO_BEGIN_C_DECLS

/* ***************************************************************************

Feature element tree :

 PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_FLATTEN_REF_TYPE
     |
     |--PRO_E_STEP_SEL_FORM
     |
     |--PRO_E_SMT_FLATTEN_PROJ_CUTS
     |
     |--PRO_E_BODY
     |    |
     |    |--PRO_E_BODY_USE
     |    |
     |    |--PRO_E_BODY_SELECT



========================================================================================================
Element Id                     Element Name             Data Type                  Valid Values
========================================================================================================

PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT
                                                       See Note 1.
PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING

PRO_E_SMT_FLATTEN_REF_TYPE     Reference Select Type   PRO_VALUE_TYPE_INT           ProFlattenRefType

PRO_E_STEP_SEL_FORM            Form                    PRO_VALUE_TYPE_SELECTION
                                                       See Note 2.
PRO_E_SMT_FLATTEN_PROJ_CUTS    Project form cuts       PRO_VALUE_TYPE_BOOLEAN
PRO_E_BODY                       Body options        Compound See Note 3.
PRO_E_BODY_USE                   Body use option     PRO_VALUE_TYPE_INT
PRO_E_BODY_SELECT                Selected body ref   PRO_VALUE_TYPE_SELECTION
--------------------------------------------------------------------------------------------------------
Note 1.
 PRO_E_FEATURE_TYPE must be of PRO_FEAT_FLATTEN

--------------------------------------------------------------------------------------------------------
Note 2.
 Only valid when PRO_E_SMT_FLATTEN_REF_TYPE is PRO_FLATTEN_FORM_REFSEL
 Selection need to be an array of form features or surfaces to be flattened 
--------------------------------------------------------------------------------------------------------
Note 3.
 Only valid when PRO_E_SMT_FLATTEN_REF_TYPE is PRO_FLATTEN_FORM_ALLSEL
            PRO_E_BODY_USE must be PRO_BODY_USE_SELECTED.
            PRO_E_BODY_SELECTED must contain a single selected body
********************************************************************************************************/

typedef enum Pro_Flatten_Ref_Type
{
  PRO_FLATTEN_FORM_REFSEL = 0,
  PRO_FLATTEN_FORM_ALLSEL = 1
}ProFlattenRefType;


PRO_END_C_DECLS

#endif /* PROSMTFLATTENFORM_H */                    
