#ifndef PROCMPST_CORE_H
#define PROCMPST_CORE_H


/*
   Creo Parametric TOOLKIT declarations related to cmpstCore feature.
*/



#include <ProANSI.h>
#include <ProCmpstManPly.h>

PRO_BEGIN_C_DECLS

/***********************************************************************************************

 Feature element tree :
 ----------------------
 |--PRO_E_FEATURE_TYPE
 |--PRO_E_STD_FEATURE_NAME
 |--PRO_E_CMPST_PLY_BASE_QUILT
 |--PRO_E_CMPST_MAN_PLY_TYPE
 |--PRO_E_AREA_BOUNDARY
 |  |--PRO_E_AREA_BOUNDARY_LOOPS
 |     |--PRO_E_AREA_BOUNDARY_LOOP
 |        |--PRO_E_STD_LOOP_COLLECTION_APPL
 |
 |--PRO_E_DSGNTAREA_CREATION_FLIP
 |--PRO_E_CMPST_MAN_PLY_ZONES
 |--PRO_E_CMPST_MAN_PLY_CMPND
 |  |--PRO_E_CMPST_MAN_PLY_MTRL
 |  |--PRO_E_CMPST_MAN_PLY_ORNT
 |  |--PRO_E_CMPST_MAN_PLY_DROP_OFF
 |  |--PRO_E_CMPST_MAN_PLY_NAME
 |  |--PRO_E_CMPST_MAN_PLY_SEQ
 |
 |--PRO_E_CMPST_PLY_ROSETTE
 |--PRO_E_CMPST_CORE_SET_ARR
 |  |--PRO_E_CMPST_CORE_SET
 |     |--PRO_E_CMPST_CORE_D1
 |     |--PRO_E_CMPST_CORE_D2
 |     |--PRO_E_CMPST_CORE_HEIGHT
 |     |--PRO_E_STD_CURVE_COLLECTION_APPL

Feature elements table
-------------------------------------------------------------------------------------------------------
Element Id                      Element Name           Data Type                Valid Values
-------------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type           PRO_VALUE_TYPE_INT       PRO_FEAT_CMPST_CORE
PRO_E_STD_FEATURE_NAME          featname               PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_PLY_BASE_QUILT      CmpstPlyBaseQuiltStep  PRO_VALUE_TYPE_SELECTION The layup surface
PRO_E_CMPST_MAN_PLY_TYPE        Ply_type               ProCmpst_man_ply_type    Optional. Default value: 1.
PRO_E_AREA_BOUNDARY             Boundary               compound
PRO_E_AREA_BOUNDARY_LOOPS       Loops                  ProArray of Loops
PRO_E_AREA_BOUNDARY_LOOP        Loop                   compound
PRO_E_STD_LOOP_COLLECTION_APPL  Boundary chains        PRO_VALUE_TYPE_POINTER   See ProCrvcollection.h
PRO_E_DSGNTAREA_CREATION_FLIP   Creation Flip          PRO_VALUE_TYPE_INT       Optional. 0/1
PRO_E_CMPST_MAN_PLY_ZONES       Zones                  PRO_VALUE_TYPE_SELECTION PRO_QUILT of Laminate Zone feature
PRO_E_CMPST_MAN_PLY_CMPND       PlyCompound            compound
PRO_E_CMPST_MAN_PLY_MTRL        Material               PRO_VALUE_TYPE_INT       Material id
PRO_E_CMPST_MAN_PLY_ORNT        Orientation            PRO_VALUE_TYPE_DOUBLE    The valid range is -360.0 to +360.0
PRO_E_CMPST_MAN_PLY_DROP_OFF    Drop-Off               PRO_VALUE_TYPE_DOUBLE    The valid range is 0 to MAX_DIM_VALUE
PRO_E_CMPST_MAN_PLY_NAME        Name                   PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_MAN_PLY_SEQ         Sequence               PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_PLY_ROSETTE         CmpstPlyRosetteStep    PRO_VALUE_TYPE_SELECTION PRO_SURFACE, PRO_QUILT
                                                                                PRO_CSYS, PRO_LOG_CSYS
PRO_E_CMPST_CORE_SET_ARR        Taper Sets             ProArray of Sets         Optional
PRO_E_CMPST_CORE_SET            Taper Set              Compound                 Optional
PRO_E_CMPST_CORE_D1             D1                     PRO_VALUE_TYPE_DOUBLE    Optional. Positive numbers
PRO_E_CMPST_CORE_D2             D2                     PRO_VALUE_TYPE_DOUBLE    Optional. The valid range is 0 to 
                                                                                material thickness
PRO_E_STD_CURVE_COLLECTION_APPL Taper Chain            PRO_VALUE_TYPE_SELECTION Optional. See ProCrvcollection.h
******************************************************************************************************/


PRO_END_C_DECLS

#endif
