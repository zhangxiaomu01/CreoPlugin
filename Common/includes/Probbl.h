#ifndef PROBBL_H
#define PROBBL_H

#include <ProToolkit.h>



PRO_BEGIN_C_DECLS

/************************ CREO BBL ********************************
************************************************************************/

/*
              
           1----2nd direction----- 1 curve ---------+--------- 1
                                                    |           
           |                                        |          |
           |                                        |          |
                                                               
           1                                       i-th        n-th
                                                                
           c                                        c          c
           u                                        u          u
           r                                        r          r
           v                                        v          v
           e                                        e          e
                                                                
           |                                        |          |
                                                    |          | 
          1st                                       |          | 
                                                    |          |
           d                                        |          |
           i                                        |          |
           r                                        |          |
           e                                        |          |
           c                                        |          |
           t                                        |          |
           i                                        |          |
           o                                        |          |
           n                                        |          |
           |                                        |          |
           |                                        |          |
           +----2nd direction----- i-th curve ------+----------+
           |                                        |          |
           |                                        |          |
                                                    |           
           0 ---2nd direction------- n curve -------+--------- 1


*/
/************************************************************************

PRO_E_FEATURE_TREE
 |---PRO_E_FEATURE_TYPE
 |---PRO_E_FEATURE_FORM
 |---PRO_E_DTM_SRF_TYPE

 |---PRO_E_BNBLN_CURVES
 |    |---PRO_E_BNBLN_1DIR
 |    |    |---PRO_E_BNBLN_DIR_CURVES
 |    |    |    |---PRO_E_STD_CHAIN_HOLDER
 |    |    |    |    |---PRO_E_STD_CURVE_COLLECTION_APPL
 |    |    |---PRO_E_BBL_ADD_CLOSED
 |    |---PRO_E_BNBLN_2DIR
 |    |    |---PRO_E_BNBLN_DIR_CURVES
 |    |    |---PRO_E_BBL_ADD_CLOSED

 |---PRO_E_STD_FEATURE_NAME
 |---PRO_E_EXT_SURF_CUT_SOLID_TYPE

**************************************************************************/

/*
------------------------------------------------------------------------------
Element Id                        Element Name               Data Type
------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type                PRO_VALUE_TYPE_INT
PRO_E_FEATURE_FORM               Feature form                PRO_VALUE_TYPE_INT
PRO_E_DTM_SRF_TYPE               Datum surface type          PRO_VALUE_TYPE_INT

PRO_E_BNBLN_CURVES                                           PRO_ELEM_TYPE_COMPOUND
PRO_E_BNBLN_1DIR                 BBL curves in 1st direction PRO_ELEM_TYPE_COMPOUND
PRO_E_BNBLN_2DIR                 BBL curves in 2nd direction PRO_ELEM_TYPE_COMPOUND

PRO_E_BNBLN_DIR_CURVES           array of chain holders      PRO_ELEM_TYPE_ARRAY
PRO_E_STD_CHAIN_HOLDER                                       PRO_ELEM_TYPE_COMPOUND
PRO_E_STD_CURVE_COLLECTION_APPL  curves to path through      PRO_VALUE_TYPE_SELECTION
                                 curve can be composite
PRO_E_BBL_ADD_CLOSED             closes the surface in 1st   PRO_VALUE_TYPE_INT 
                                 or 2nd direction
PRO_E_STD_FEATURE_NAME                                       PRO_VALUE_TYPE_WSTRING
PRO_E_EXT_SURF_CUT_SOLID_TYPE                                PRO_VALUE_TYPE_INT

*/


/************************************************************************
 Requirments
-------------------------------------------------------------------------
    PRO_E_FEATURE_TYPE                  required
                                        type (see ProFeatType.h)
                                        valid value PRO_FEAT_DATUM_SURF
    PRO_E_FEATURE_FORM                  required
                                        valid value PRO_USE_SURFS
    PRO_E_DTM_SRF_TYPE                  required
                                        valid value PRO_E_DTM_SRF_TYPE_BND_BLEND

    PRO_E_STD_FEATURE_NAME              required
                                        Default given by application depending
                                        on feature type. Modifiable by user.

    PRO_E_BNBLN_CURVES                  required at least 1 direction
                                        PRO_E_BNBLN_1DIR or PRO_E_BNBLN_2DIR

    PRO_E_BNBLN_1DIR                    required at least 2 curves
                                        not required if PRO_E_BNBLN_2DIR is defined

    PRO_E_BNBLN_2DIR                    required at least 2 curves
                                        not required if PRO_E_BNBLN_1DIR is defined


    PRO_E_BNBLN_DIR_CURVES              required
    PRO_E_STD_CHAIN_HOLDER              required                 
    PRO_E_STD_CURVE_COLLECTION_APPL     required      
    PRO_E_BBL_ADD_CLOSED                not required 
                                        Default value PRO_B_FALSE
                                        Value PRO_B_TRUE is workable if there are at least 3 curves
    PRO_E_STD_FEATURE_NAME                                       
    PRO_E_EXT_SURF_CUT_SOLID_TYPE       required
                                        valid value PRO_FEAT_DATUM_SURF

-------------------------------------------------------------------------

***************************************************************************/

#define PRO_E_DTM_SRF_TYPE_BND_BLEND 11

/************************************************************************/

PRO_END_C_DECLS

#endif


