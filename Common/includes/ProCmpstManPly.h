#ifndef PROCMPST_MAN_PLY_H
#define PROCMPST_MAN_PLY_H

/*
   Creo Parametric TOOLKIT declarations related to cmpstManPly feature.
*/



#include <ProANSI.h>

PRO_BEGIN_C_DECLS

/***********************************************************************************************

 Feature element tree :
 ----------------------
 |--PRO_E_FEATURE_TYPE
 |--PRO_E_STD_FEATURE_NAME
 |
 |--PRO_E_CMPST_PLY_BASE_QUILT
 |
 |--PRO_E_CMPST_MAN_PLY_TYPE 
 |--PRO_E_AREA_BOUNDARY
 |  |--PRO_E_AREA_BOUNDARY_LOOPS
 |     |--PRO_E_AREA_BOUNDARY_LOOP
 |        |--PRO_E_STD_LOOP_COLLECTION_APPL
 |--PRO_E_DSGNTAREA_CREATION_FLIP
 |--PRO_E_CMPST_MAN_PLY_ZONES  
 |        
 |--PRO_E_CMPST_MAN_PLY_CMPND
 |  |--PRO_E_CMPST_MAN_PLY_MTRL
 |  |--PRO_E_CMPST_MAN_PLY_ORNT
 |  |--PRO_E_CMPST_MAN_PLY_DROP_OFF
 |  |--PRO_E_CMPST_MAN_PLY_NAME
 |  |--PRO_E_CMPST_MAN_PLY_SEQ
 |
 |--PRO_E_CMPST_PLY_ROSETTE


Feature elements table
-------------------------------------------------------------------------------------------------------
Element Id                     Element Name           Data Type                Valid Values
-------------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type           PRO_VALUE_TYPE_INT       PRO_FEAT_CMPST_MAN_PLY
PRO_E_STD_FEATURE_NAME	       featname	              PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_PLY_BASE_QUILT     CmpstPlyBaseQuiltStep  PRO_VALUE_TYPE_SELECTION The layup surface
PRO_E_CMPST_MAN_PLY_TYPE       Ply_type               ProCmpst_man_ply_type    Optional. Default value: 1. 
PRO_E_AREA_BOUNDARY            Boundary               compound
PRO_E_AREA_BOUNDARY_LOOPS      Loops                  ProArray of Loops
PRO_E_AREA_BOUNDARY_LOOP       Loop                   compound
PRO_E_STD_LOOP_COLLECTION_APPL Boundary chains        PRO_VALUE_TYPE_POINTER   See ProCrvcollection.h
PRO_E_DSGNTAREA_CREATION_FLIP  Creation Flip          PRO_VALUE_TYPE_INT       Optional. 0/1
PRO_E_CMPST_MAN_PLY_ZONES      Zones                  PRO_VALUE_TYPE_SELECTION PRO_QUILT of Laminate Zone feature
PRO_E_CMPST_MAN_PLY_CMPND      PlyCompound            compound
PRO_E_CMPST_MAN_PLY_MTRL       Material               PRO_VALUE_TYPE_INT       Material id
PRO_E_CMPST_MAN_PLY_ORNT       Orientation            PRO_VALUE_TYPE_DOUBLE    The valid range is -360.0 to +360.0
PRO_E_CMPST_MAN_PLY_DROP_OFF   Drop-Off               PRO_VALUE_TYPE_DOUBLE    The valid range is 0 to MAX_DIM_VALUE
PRO_E_CMPST_MAN_PLY_NAME       Name                   PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_MAN_PLY_SEQ        Sequence               PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_CMPST_PLY_ROSETTE        CmpstPlyRosetteStep    PRO_VALUE_TYPE_SELECTION PRO_SURFACE, PRO_QUILT
                                                                               PRO_CSYS, PRO_LOG_CSYS
******************************************************************************************************/

typedef enum
{
    PRO_CMPST_MAN_PLY_TYPE_OPT_MANUAL_PLY     = 1, // use PRO_E_AREA_BOUNDARY
    PRO_CMPST_MAN_PLY_TYPE_OPT_ZONE_BASED_PLY = 2, // use PRO_E_CMPST_MAN_PLY_ZONES
} ProCmpst_man_ply_type;

PRO_END_C_DECLS

#endif
