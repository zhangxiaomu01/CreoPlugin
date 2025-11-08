
 
#ifndef PROSMTEDITBEND_H
#define PROSMTEDITBEND_H

#include <ProToolkit.h>

PRO_BEGIN_C_DECLS


typedef enum
{
  PRO_ED_CONST_WALL_LENGTH        = 0,
  PRO_ED_CONST_LEG_LENGTH         = 1,
  PRO_ED_CONST_WALL_HEIGHT        = 2,
  PRO_ED_CONST_FLAT_LENGTH        = 3

} ProEditBendEditOpt;

typedef enum
{
  PRO_ED_BEND_RLF_SAME_TYPE       = 0,
  PRO_ED_BEND_RLF_RIP             = 1

} ProEditBendBndRlfOpt;

typedef enum
{
  PRO_ED_CRNR_RLF_SAME_TYPE       = 0,
  PRO_ED_CRNR_RLF_V_NOTCH         = 1

} ProEditBendCrnrRlfOpt;

typedef enum
{
  PRO_ED_CRNR_SEAM_SAME_TYPE      = 0,
  PRO_ED_CRNR_SEAM_OPEN           = 1

} ProEditBendCrnrSeamOpt;

typedef enum
{
  PRO_ED_NO_CRNR_SEAM_RND_CHMF      = 0,
  PRO_ED_CR_CRNR_SEAM_RND_CHMF      = 1

} ProEditBendCrRndChmfOpt;



PRO_END_C_DECLS
#endif
