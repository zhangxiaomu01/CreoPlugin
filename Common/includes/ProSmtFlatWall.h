#ifndef PROSMTFLATWALL_H
#define PROSMTFLATWALL_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Flat Wall feature
*/



#include <ProToolkit.h>
#include <ProSmtFlangeWall.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_SMT_WALL_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_FLAT_WALL_ATT_EDGE
     |
     |--PRO_E_SMT_FLAT_WALL_ANGLE
     |    |
     |    |--PRO_E_SMT_FLAT_WALL_ANGLE_TYPE
     |    |
     |    |--PRO_E_SMT_FLAT_WALL_ANGLE_VAL
     |    |
     |    |--PRO_E_SMT_FLAT_WALL_ANGLE_FLIP
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_SMT_FILLETS
     |    |
     |    |--PRO_E_SMT_FILLETS_USE_RAD
     |    |
     |    |--PRO_E_SMT_FILLETS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLETS_VALUE
     |
     |--PRO_E_SMT_WALL_HEIGHT
     |    |
     |    |----PRO_E_SMT_WALL_HEIGHT_TYPE
     |    |
     |    |----PRO_E_SMT_WALL_HEIGHT_VALUE
     |
     |--PRO_E_SMT_BEND_RELIEF
     |    |
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE1
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_WIDTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_LENGTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_LENGTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_ANGLE
     |    |
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE2
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_WIDTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_LENGTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_LENGTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_ANGLE
     |
     |--PRO_E_SMT_WALL_THICKNESS_FLIP
     |
     |--PRO_E_SMT_CORNERS_ARR
     |    |
     |    |--PRO_E_SMT_CORNER
     |    |    |  
     |    |    |--PRO_E_WALL_CORNER_TREATMENT
     |    |    |  
     |    |    |--PRO_E_SMT_EDGE_RIP
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_TYPE
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_ADD_GAP
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_CLOSE_CORNER
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_DIM_1
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_1_TYPE
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_1_VAL
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_DIM_2
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_2_TYPE
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_2_VAL
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_FLIP
     |
     |--PRO_E_SMT_CORNER_RELIEF
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_TYPE
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL
     |
     |
     |-- PRO_E_SMT_MTR_CUTS
     |     |
     |     |--PRO_E_SMT_MTR_CUTS_ADD
     |     |
     |     |--PRO_E_SMT_THREE_BEND_CRNR_RELIEF_TYPE
     |     |
     |     |--PRO_E_SMT_MITER_CUT_GROOVE_TYPE
     |     |
     |     |--PRO_E_SMT_MTR_CUTS_WIDTH_VAL
     |     |
     |     |--PRO_E_SMT_MTR_CUTS_OFFSET_VAL
     |
     |  
     |--PRO_E_SMT_DEV_LEN_CALCULATION
     |    |
     |    |--PRO_E_SMT_DEV_LEN_SOURCE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR
     |    |    |  
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_BEND_TABLE

************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_TYPE               Wall Type             PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_FLAT_WALL_ATT_EDGE      Attachment Edges      PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_FLAT_WALL_ANGLE         Bend Angle            Compound
PRO_E_SMT_FLAT_WALL_ANGLE_TYPE    Angle Type            PRO_VALUE_TYPE_INT
PRO_E_SMT_FLAT_WALL_ANGLE_VAL     Angle Value           PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_FLAT_WALL_ANGLE_FLIP    Angle Flip            PRO_VALUE_TYPE_INT
PRO_E_STD_SECTION                 Wall Section          see: ProStdSection.h 
PRO_E_SMT_FILLETS                 Fillets               Compound
PRO_E_SMT_FILLETS_USE_RAD         Use Radius            PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_SIDE            Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE           Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_WALL_HEIGHT             Wall Height           Compound
PRO_E_SMT_WALL_HEIGHT_TYPE        Height Type           PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_HEIGHT_VALUE       Height Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_RELIEF             Bend Relief           Compound
PRO_E_SMT_BEND_RELIEF_SIDE1       Side 1 Relief         Compound
PRO_E_SMT_BEND_RELIEF_SIDE2       Side 2 Relief         Compound
PRO_E_BEND_RELIEF_TYPE            Relief Type           PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Relief Width          PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Relief Depth type     PRO_VALUE_TYPE_INT
							See Note 1.
PRO_E_BEND_RELIEF_DEPTH                       Relief Depth value         PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_LENGTH_TYPE     Relief Length type    PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_LENGTH          Relief Length value   PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_ANGLE                       Relief Angle               PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_WALL_THICKNESS_FLIP                 Flip Thickness             PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_CALCULATION                 Developed Length           Compound
PRO_E_SMT_DEV_LEN_SOURCE                      Dev Length Source          PRO_VALUE_TYPE_INT 
PRO_E_SMT_DEV_LEN_Y_FACTOR                    Dev Length Y Factor        Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE              Y Factor Value             PRO_VALUE_TYPE_DOUBLE  
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE               Y Factor Type              PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE                  Dev Length Bend Table      PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS                            Miter Cuts                 Compound
PRO_E_SMT_MTR_CUTS_ADD                        Add Miter Cuts             PRO_VALUE_TYPE_INT
PRO_E_SMT_MITER_CUT_GROOVE_TYPE               Miter Cut Groove Type      PRO_VALUE_TYPE_INT
PRO_E_SMT_THREE_BEND_CRNR_RELIEF_TYPE         3-Bend CornerRelief Type   PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS_WIDTH_VAL                  Miter Cuts Width Val       PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_MTR_CUTS_OFFSET_VAL                 Miter Cuts Offset Val      PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNERS_ARR                         Corners                    Array
PRO_E_SMT_CORNER                              Corner                     Compound
PRO_E_SMT_EDGE_RIP                            Edge Rip                   Compound
PRO_E_SMT_EDGE_RIP_TYPE                       Edge Rip Type              PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_ADD_GAP                    Edge Rip Add Gap           PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER               Edge Rip Close Corner      PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_1                      Edge Rip Dim 1             Compound
PRO_E_SMT_EDGE_RIP_DIM_1_TYPE                 Edge Rip Dim 1 Type        PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_1_VAL                  Edge Rip Dim 1 Value       PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EDGE_RIP_DIM_2                      Edge Rip Dim 2             Compound
PRO_E_SMT_EDGE_RIP_DIM_2_TYPE                 Edge Rip Dim 2 Type        PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_2_VAL                  Edge Rip Dim 2 Value       PRO_VALUE_TYPE_DOUBLE
Note 1.
  The element PRO_E_BEND_RELIEF_DEPTH_TYPE has been added in Creo Parametric.
This element rules the visibility of the bend relief depth element
PRO_E_BEND_RELIEF_DEPTH. The old element PRO_E_BEND_RELIEF_DEPTH will be used
if PRO_E_BEND_RELIEF_DEPTH_TYPE is PRO_BEND_RLF_DEPTH_BLIND or
PRO_BEND_RLF_DEPTH_TYPE_PARAM and part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE
is "Blind". It is recommended to define PRO_E_BEND_RELIEF_DEPTH_TYPE explicitly
for all Creo Parametric TOOLKIT applications. Otherwise the element will be automatically
filled by the default value. The default value in Creo Parametric depends on
the part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE and the configuration option
smt_drive_tools_by_parameters Yes/No. If the value of the option is No,
then the default value will be the last bend relief type, as selected
by the user in the dashboard UI during creation of a new feature.
If the default value is not "Blind", Creo Parametric TOOLKIT applications prior to this
release will not use the element PRO_E_BEND_RELIEF_DEPTH.
To fix it, set PRO_E_BEND_RELIEF_DEPTH_TYPE to PRO_BEND_RLF_DEPTH_BLIND.

================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_WALL
PRO_E_SMT_WALL_TYPE               ProSmtWallWallType
PRO_E_SMT_FLAT_WALL_ATT_EDGE      Edges   
PRO_E_SMT_FLAT_WALL_ANGLE_TYPE    ProBndAngleType
PRO_E_SMT_FLAT_WALL_ANGLE_FLIP    PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FILLETS_USE_RAD         PRO_B_TRUE, PRO_B_FALSE   
PRO_E_SMT_FILLETS_SIDE            ProSmdRadType
PRO_E_SMT_WALL_HEIGHT_TYPE        ProBendPosition
PRO_E_BEND_RELIEF_TYPE            ProBendRlfType
PRO_E_BEND_RELIEF_DEPTH_TYPE      ProBendRlfDepthType
PRO_E_BEND_RELIEF_LENGTH_TYPE     ProBendRlfLengthType(See ProSmtFlangeWall.h)
PRO_E_SMT_WALL_THICKNESS_FLIP     PRO_B_TRUE, PRO_B_FALSE     
PRO_E_SMT_DEV_LEN_SOURCE          ProDvlLenSrcType
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   ProDvlLenFactor
PRO_E_SMT_DEV_LEN_BEND_TABLE      int (bend table ID)
PRO_E_WALL_CORNER_TREATMENT       ProWallCornerTreatment
PRO_E_SMT_CORNER_RELIEF_TYPE      ProCornerRelType
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE ProSmdRelType
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE ProCornerRlfDepthType
PRO_E_SMT_MTR_CUTS_ADD            PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_MITER_CUT_GROOVE_TYPE   ProMiterCutType
PRO_E_SMT_THREE_BEND_CRNR_RELIEF_TYPE    ProThreeBendCornerType   
PRO_E_SMT_EDGE_RIP_TYPE           ProEdgeRipType
PRO_E_SMT_EDGE_RIP_ADD_GAP        PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_DIM_1_TYPE     ProEdgeRipDimType
PRO_E_SMT_EDGE_RIP_DIM_2_TYPE     ProEdgeRipDimType
PRO_E_SMT_EDGE_RIP_FLIP           PRO_B_TRUE, PRO_B_FALSE

Note2. Miter cuts.
  When PRO_E_SMT_THREE_BEND_CRNR_RELIEF_TYPE is set to PRO_THREE_B_CNR_TYPE_CLOSED
the walid options for PRO_E_SMT_MITER_CUT_GROOVE_TYPE are:
     PRO_MITER_CUT_NO_GAP, PRO_MITER_CUT_OBROUND.

 When PRO_E_SMT_THREE_BEND_CRNR_RELIEF_TYPE is set to  PRO_THREE_B_CNR_TYPE_TANGENT,
  PRO_THREE_B_CNR_TYPE_OPEN or PRO_THREE_B_CNR_TYPE_RIP,
the walid options for PRO_E_SMT_MITER_CUT_GROOVE_TYPE are:
     PRO_MITER_CUT_NO_GAP,  and PRO_MITER_CUT_THROUGH_ALL.

  If PRO_E_SMT_MITER_CUT_GROOVE_TYPE is set for  PRO_MITER_CUT_OBROUND,
both  PRO_E_SMT_MTR_CUTS_WIDTH_VAL and PRO_E_SMT_MTR_CUTS_OFFSET_VAL are used.
  If PRO_E_SMT_MITER_CUT_GROOVE_TYPE is set for  PRO_MITER_CUT_THROUGH_ALL,
only  PRO_E_SMT_MTR_CUTS_WIDTH_VAL is used.
  If PRO_E_SMT_MITER_CUT_GROOVE_TYPE is set for  PRO_MITER_CUT_NO_GAP,
neither is used.




================================================================================

************************************************************************/

typedef enum
{
  PRO_BND_ANGLE_NOT_DEFINED  = -1,
  PRO_BND_ANGLE_VALUE        =  0,
  PRO_BND_ANGLE_BY_PARAM     =  1,
  PRO_BND_ANGLE_FLAT         =  2

} ProBndAngleType;


typedef enum
{
  PRO_WALL_CORNER_SEAM = 1,
  PRO_WALL_CORNER_NO_SEAM = 2,
  PRO_WALL_CORNER_IGNORE = 3

} ProWallCornerTreatment;


typedef enum
{
  PRO_THREE_B_CNR_TYPE_NO = -1,
  PRO_THREE_B_CNR_TYPE_TANGENT = 0,
  PRO_THREE_B_CNR_TYPE_CLOSED = 1,
  PRO_THREE_B_CNR_TYPE_OPEN = 2,
  PRO_THREE_B_CNR_TYPE_RIP = 3

} ProThreeBendCornerType;

typedef enum
{
  PRO_MITER_CUT_UNDEFINED = -1,
  PRO_MITER_CUT_NO_GAP = 0,
  PRO_MITER_CUT_THROUGH_ALL    = 1,
  PRO_MITER_CUT_OBROUND   = 2

} ProMiterCutType;


PRO_END_C_DECLS

#endif
