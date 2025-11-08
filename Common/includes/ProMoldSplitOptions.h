#ifndef PROMOLDSPLITOPTIONS_H
#define PROMOLDSPLITOPTIONS_H
/*
   Creo Parametric TOOLKIT declarations of mold split options.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS


typedef enum Pro_MoldSplitGeomOpt
{
  PRO_MOLD_GEOM_OPT_VOLUMES     = 1,
  PRO_MOLD_GEOM_OPT_CURVES      = 2

}  ProMoldSplitGeomOpt;

typedef enum Pro_MoldSplitVolNumOpt
{
  PRO_MOLD_SPLIT_VOL_OPT_MANY        =  0,
  PRO_MOLD_SPLIT_VOL_OPT_TWO         =  1,
  PRO_MOLD_SPLIT_VOL_OPT_ONE         =  2

}  ProMoldSplitVolNumOpt;


PRO_END_C_DECLS

#endif /*PROMOLDSPLITOPTIONS_H*/
