#ifndef PROCMPST_DRAPE_H
#define PROCMPST_DRAPE_H

/*
   Creo Parametric TOOLKIT declarations related to cmpstDrape feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************

NOTE:
There must be only one Composite Drape feature in the single composite model.
If the feature already exists, ProFeatureWithoptionsCreate() API will abort and:
1. Return PRO_TK_GENERAL_ERROR value.
2. And record ProItemerror with PRO_TK_E_FOUND error into output p_errors argument.


 Feature element tree :
 ----------------------
 |--PRO_E_FEATURE_TYPE
 |--PRO_E_STD_FEATURE_NAME
 |--PRO_E_DRAPE_SETS
    |--PRO_E_DRAPE_SET
       |--PRO_E_DRAPE_PLY_REF
       |--PRO_E_DRAPE_SEED_PNT
       |--PRO_E_DRAPE_STEP_LENGTH
       |--PRO_E_DRAPE_ANGLE
       |--PRO_E_DRAPE_POLYLINE_ANG
       |--PRO_E_DRAPE_3D
       |--PRO_E_DRAPE_SLIT_CURVES (Reserved for future use. Not in use in Creo 10)
       |--PRO_E_DRAPE_REFINEMENT
    |--PRO_E_DRAPE_CURED_THICK
 

Feature elements table
------------------------------------------------------------------------
Element Id                  Element Name         Data Type
------------------------------------------------------------------------
PRO_E_FEATURE_TYPE       Feature Type           PRO_VALUE_TYPE_INT       PRO_FEAT_CMPST_DRAPE
PRO_E_STD_FEATURE_NAME   featname               PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_DRAPE_SETS         Sets                   ProArray                 See note 1 below.
PRO_E_DRAPE_SET          Set                    Compound                 See note 2 below.
PRO_E_DRAPE_PLY_REF      Ply reference          ProReference             See note 3 below.
PRO_E_DRAPE_SEED_PNT     Seed point             ProReference             See note 4 below.
PRO_E_DRAPE_STEP_LENGTH  Step length            double                   See note 5 below.
PRO_E_DRAPE_ANGLE        Draping angle          double                   See note 6 below.
PRO_E_DRAPE_POLYLINE_ANG Simplification angle   double                   See note 7 below.
PRO_E_DRAPE_3D           Drape in 3D space      ProDrapeIn3d             See note 8 below.
PRO_E_DRAPE_SLIT_CURVES  - Reserved for future use. Not in use in Creo 10
PRO_E_DRAPE_REFINEMENT   Refinement:            ProDrapeRefinement       See note 9 below.
PRO_E_DRAPE_CURED_THICK	Drape all plies using:	ProDrapeThicknessOpt     See note 10 below.


*****************************************************************************/

/* ========================== NOTES ===========================================

Note 1. PRO_E_DRAPE_SETS - Mandatory
  
   ProArray of any number of PRO_E_DRAPE_SET compound elements. This is array of 
   Draping simulation definitions.


Note 2. PRO_E_DRAPE_SET - Mandatory

   Compound element - holds definition (properties) of each individual Draping
   Simulation applied to a particular single ply.


Note 3. PRO_E_DRAPE_PLY_REF - Mandatory - Individual per each PRO_E_DRAPE_SET
 
   Defines a ply to perform a draping simulation on.

   Selection is a singal Composite Ply. Reference type PRO_CMPST_PLY_DEF.
   The same ply reference cannot be used in another Draping Simulation SET.
   

Note 4. PRO_E_DRAPE_SEED_PNT - Optional - Individual per each PRO_E_DRAPE_SET

   Defines a starting point of the Draping Simulation applied to the ply.
   Must lie on the ply defined in PRO_E_DRAPE_PLY_REF element and be located
   inside the boundary of the selected ply.

   Can be empty. In this case the system will calculate a default ply location point
   and save it in the feature as a Seed Point reference.

   Valid values:
   a) Datum Point (PRO_POINT) or
   b) Intent Point (PRO_LOG_PNT) or
   c) Ply Location point (PRO_CMPST_PLY_PNT), which is a UV location point
      on a surface of a composite ply.
   

Note 5. PRO_E_DRAPE_STEP_LENGTH - Mandatory - Individual per each PRO_E_DRAPE_SET
   
   It's the distance between adjacent drape points / fibers
   i.e. the resolution of the fishnet drape mesh. 

   Valid values: Linear dimensions : [model accuracy, 1e6]


Note 6. PRO_E_DRAPE_ANGLE - Mandatory - Individual per each PRO_E_DRAPE_SET

   It's the angle with respect to the material roll direction of the fixed warp
   and weft fibers (i.e. the orientation that the drape progresses). 

   Valid values: Angular dimensions: [-360 deg, 360 deg]


Note 7. PRO_E_DRAPE_POLYLINE_ANG - Mandatory - Individual per each PRO_E_DRAPE_SET

   It's polyline simplification angle  The angle between polyline segments
   below which the segments may be merged. 

   Valid values: Angular dimensions: [0 deg, 360 deg]


Note 8. PRO_E_DRAPE_3D - Mandatory - Individual per each PRO_E_DRAPE_SET

   The option to consider the plys height in the laminate stack when
   performing draping analysis.

   Valid values: Disabled/Enabled as listed in ProDrapeIn3d enum below

Note 9. PRO_E_DRAPE_REFINEMENT - Mandatory - Individual per each PRO_E_DRAPE_SET

   The option to consider the refinement for each set

   Valid values: Disabled/Enabled as listed in ProDrapeRefinement enum below


Note 10. PRO_E_DRAPE_CURED_THICK - global

   The option to consider the cured/uncured thickness.for all sets

   Valid values: Disabled/Enabled as listed in ProDrapeThicknessOpt enum below



*******************************************************************************/

/* Valid values for PRO_E_DRAPE_3D element */
typedef enum
{
    PRO_DRAPE_IN3D_DISABLED = 0,
    PRO_DRAPE_IN3D_ENABLED  = 1
}ProDrapeIn3d;

typedef enum
{

  PRO_DRAPE_OPTION_CURED_THICKNESS   = 0,
  PRO_DRAPE_OPTION_UNCURED_THICKNESS = 1

}ProDrapeThicknessOpt;

typedef enum
{
  PRO_DRAPE_REFINEMENT_DISABLED = 0,
  PRO_DRAPE_REFINEMENT_ENABLED  = 1

}ProDrapeRefinement;

PRO_END_C_DECLS

#endif

