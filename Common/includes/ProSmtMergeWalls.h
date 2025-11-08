#ifndef PROSMTMERGEWALLS_H
#define PROSMTMERGEWALLS_H



/*
Creo Parametric TOOLKIT declarations related to SheetMetal Merge Walls feature
*/

#include <ProANSI.h>

PRO_BEGIN_C_DECLS

/* ****************************************************************************


Feature element tree :

PRO_E_FEATURE_TREE
|
|--PRO_E_FEATURE_TYPE
|
|--PRO_E_SMT_WALL_TYPE
|
|--PRO_E_STD_FEATURE_NAME
|
|--PRO_E_SMT_WALL_MERGE_BASE_REF
|    |
|    |--PRO_E_STD_SURF_COLLECTION_APPL
|         
|--PRO_E_SMT_WALL_MERGE_GEOM_REF
|    |
|    |--PRO_E_STD_SURF_COLLECTION_APPL
|    
|--PRO_E_STEP_MERGE_EDGE
|    
|--PRO_E_SMT_MERGE_KEEP_LINES
|
|--PRO_E_SMT_MERGE_KEEP_BEND_EDGES



===============================================================================
Element Id                         Element Name         Data Type
===============================================================================

PRO_E_FEATURE_TYPE                  Feature Type       PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_TYPE                 Wall Type          ProSmtWallWallType
PRO_E_STD_FEATURE_NAME              Feature Name       PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_WALL_MERGE_BASE_REF       Base Ref           Compound
PRO_E_STD_SURF_COLLECTION_APPL      Surface Collector  Surface Collection
PRO_E_SMT_WALL_MERGE_GEOM_REF       Geom Ref           Compound
PRO_E_STEP_MERGE_EDGE               Multi Collector    PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_MERGE_KEEP_LINES          Keep line Type     PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_MERGE_KEEP_BEND_EDGES     Keep Edges of Bends PRO_VALUE_TYPE_BOOLEAN
===============================================================================


===============================================================================
Element Id                           Valid Values
===============================================================================
PRO_E_FEATURE_TYPE                   PRO_FEAT_WALL
PRO_E_SMT_WALL_TYPE                  PRO_SMT_WALL_TYPE_MERGE
                                     (See ProSmtFlangeWall.h)
PRO_E_STD_SURF_COLLECTION_APPL       (see note 1) 
PRO_E_STEP_MERGE_EDGE                Edges (see note 2)
PRO_E_SMT_MERGE_KEEP_LINES           PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_MERGE_KEEP_BEND_EDGES      PRO_B_TRUE, PRO_B_FALSE
===============================================================================

-------------------------------------------------------------------------------
note 1.
One-by-One Surface collection  See ProSrfcollection.h and 
ProElementCollection*() API in ProElement.h

note 2.
PRO_E_STEP_MERGE_EDGE - Exclude edges that were included by the
merge of the surfaces.

-------------------------------------------------------------------------------

******************************************************************************/

PRO_END_C_DECLS


#endif /* PROSMTJOINWALLS_H */
