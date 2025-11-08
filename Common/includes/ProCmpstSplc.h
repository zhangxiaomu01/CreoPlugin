#ifndef PROCMPST_SPLC_H
#define PROCMPST_SPLC_H

/*
   Creo Parametric TOOLKIT declarations related to cmpstSplc feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************
 Feature element tree :
 ----------------------
 |--PRO_E_FEATURE_TYPE
 |--PRO_E_STD_FEATURE_NAME
 |--PRO_E_PLIES_REF
 |--PRO_E_STD_CURVE_COLLECTION_APPL
 |--PRO_E_CMPST_PLY_OVERLAP_OPT
 |--PRO_E_CMPST_PLY_OVERLAP_DIM
 |--PRO_E_CMPST_PLY_STG_OPT
 |--PRO_E_CMPST_PLY_STG_DIM
 |--PRO_E_CMPST_PLY_SPLC_FLIP


Feature elements table
--------------------------------------------------------------------------------
Element Id                  Element Name         Data Type         Valid Values
--------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE	Feature Type	PRO_VALUE_TYPE_INT	PRO_FEAT_CMPST_SPLC
PRO_E_STD_FEATURE_NAME	featname	DATATYPE
PRO_E_PLIES_REF	plies_coll	ProArray of ProReference
PRO_E_STD_CURVE_COLLECTION_APPL	chain_coll	ProCollection
PRO_E_CMPST_PLY_OVERLAP_OPT	cmpst_ply_overlap_opt	ProCmpst_splc_overlap
PRO_E_CMPST_PLY_OVERLAP_DIM	cmpst_ply_overlap_dim	double
PRO_E_CMPST_PLY_STG_OPT	cmpst_ply_stg_opt	ProCmpst_splc_stagger
PRO_E_CMPST_PLY_STG_DIM	cmpst_ply_stg_dim	double
PRO_E_CMPST_PLY_SPLC_FLIP	cmpst_ply_splc_flip	int



*****************************************************************************/



typedef enum
{
  PRO_CMPST_SPLC_OVERLAP_NO = 0,
  PRO_CMPST_SPLC_OVERLAP_YES = 1,
}ProCmpst_splc_overlap;

typedef enum
{
  PRO_CMPST_SPLC_STAGGER_NO = 0,
  PRO_CMPST_SPLC_STAGGER_YES = 1,
}ProCmpst_splc_stagger;



PRO_END_C_DECLS

#endif

