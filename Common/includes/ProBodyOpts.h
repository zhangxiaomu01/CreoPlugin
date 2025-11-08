#ifndef PROBODYOPTSH
#define PROBODYOPTSH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

   Generic Body options branch

1. Element tree:
========================

   PRO_E_BODY
     |
     |--PRO_E_BODY_USE
     |
     |--PRO_E_BODY_SELECT


\*****************************************************************************/

/*****************************************************************************\

2. Elements table:
============================================================

------------------------------------------------------------------------------
Element Id                       Element Name               Data Type
------------------------------------------------------------------------------
PRO_E_BODY                       Body options               Compound
PRO_E_BODY_USE                   Body use option            PRO_VALUE_TYPE_INT
PRO_E_BODY_SELECT                Selected body reference    PRO_VALUE_TYPE_SELECTION

\*****************************************************************************/

/*****************************************************************************\

-------------------------------------------------------------------------------
3. Elements explained
-------------------------------------------------------------------------------
| Element Id                  | Comment                                       |
-------------------------------------------------------------------------------
| PRO_E_BODY                  | Compound element                              |
|.............................|...............................................|
| PRO_E_BODY_USE              | Mandatory                                     |
|                             |                                               |
|                             | Valid values:                                 |
|                             |   PRO_BODY_USE_NEW                            |
|                             |   Feature stores it's geometry in new body    |
|                             |   PRO_BODY_USE_ALL                            |
|                             |   Feature cuts from all existing bodies       |
|                             |   PRO_BODY_USE_SELECTED                       |
|                             |   Feature adds/removes it's geometry to/from  |
|                             |   selected body/ies.                          |
|                             |                                               |
|.............................|...............................................|
| PRO_E_BODY_SELECT           | Reference to selected body(ies)               |
|                             | Mandatory if PRO_E_BODY_USE is set to         | 
|                             | PRO_BODY_USE_SELECTED                         |
|                             | Ignored otherwise                             |

|                             |                                               |
|.............................|...............................................|

\*****************************************************************************/
/*****************************************************************************/


/* PRO_E_BODY_USE */

typedef enum pro_body_use_opts
{
  PRO_BODY_USE_NEW = 0,
  PRO_BODY_USE_ALL = 1,
  PRO_BODY_USE_SELECTED = 2
} ProBodyUseOpts;


/*****************************************************************************/
/*****************************************************************************\

   Note 1.  For Surface features PRO_E_BODY element should be not visible


\*****************************************************************************/

PRO_END_C_DECLS

#endif

