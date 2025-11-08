#ifndef PROXSEC_H
#define PROXSEC_H


 
 
#include	<ProToolkit.h>
#include	<ProObjects.h>
#include        <ProSolid.h> 
#include        <ProView.h>

typedef enum pro_xsec_cut
{
  PRO_XSEC_PLANAR = 0,
  PRO_XSEC_OFFSET = 1,
  PRO_XSEC_PATTERN = 2,
  PRO_XSEC_LAMINATE = 3

} ProXsecCut;

typedef enum pro_xsec_cut_obj
{
  PRO_XSECTYPE_MODEL		= 0,
  PRO_XSECTYPE_QUILTS		= 1,
  PRO_XSECTYPE_MODELQUILTS	= 2,
  PRO_XSECTYPE_ONEPART   	= 3
} ProXsecCutobj;

typedef struct pro_xsec
{
 ProName     xsec_name;
 ProSolid    solid_owner;
} ProXsec;

/* size of the name in ProXsecMdlname should be PRO_NAME_SIZE */
/* Used instead of ProXsec */
typedef struct pro_xsec_mdlname *ProXsecMdlname;

typedef struct pro_xsec_type
{
 ProXsecCut cutter;
 ProXsecCutobj cut_object;
} ProXsecType;

typedef struct geom* ProGeom;

/* Deprecated. Please use ProXsecGeometry */
typedef struct pro_xsec_geom
{
 int      memb_id_tab;
 int      quilt_id;
 ProGeom  geom_ptr; 
} ProXsecGeom;

/* Deprecated. Please use ProXSectionItem and ProXSectionItemDataGet*/
typedef struct pro_xsec_geometry
{
 int     *memb_id_tab;   /* ProArray of member id tab to the xsec owner part */
 int      quilt_id;      /* quilt id for xsec */
 ProGeom  geom_ptr;      /* geometry pointer for xsec */
} ProXsecGeometry;

typedef struct protk_xsection_item *ProXSectionItem;

/* Used for:
   Setting quilt id for offset xsec creation.
   Setting quilt xsec type for offset xsec creation.
*/
typedef struct protk_xsection_create_data *ProXSectionCreateData;

typedef struct pro_xsec_xhatch
{
 int        angle;
 double     spacing;
 double     offset; 
} ProXsecXhatch;

typedef struct pro_zone_reference 
{
 int  geom_id;       /* geom id for zone plane */
 int  oper;          /* operation: 0 - intersection, 1 - union */
 int *memb_id_tab;   /* member id tab to the plane owner part */
} ProZoneReference;

typedef struct pro_zone_reference_with_flip 
{
 int  geom_id;       /* geom id for zone plane */
 int  oper;          /* operation: 0 - intersection, 1 - union */
 int *memb_id_tab;   /* ProArray of member id tab to the plane owner part */
 int  flip;          /* 1 or -1 */
} ProZoneReferenceWithflip;

/* The items that could be exclude are components and bodies */
typedef enum pro_xsec_exclude_models
{
  PRO_XSEC_MODEL_EXCLUDE	= 0,
  PRO_XSEC_MODEL_INCLUDE	= 1
} ProXsecExcludeModels;

#define PRO_XHATCH 0
#define PRO_XSEC_EXCLUDED (1<<0)
#define PRO_XSEC_FILL     (1<<1)
#define PRO_XHATCH_ERASED (1<<2)

typedef struct pro_xsec_xhatch_pattern
{
 int        angle;
 double     spacing;
 double     offset;
 int        font; /* values are defined in  ProLinestyle */
 ProColor   color;
} ProXsecXhatchPattern;

#define PRO_NEW_HATCH_DASH_MAX  6
typedef struct pro_xsec_new_xhatch_pattern
{
  double     angle;
  double     x_origin;
  double     y_origin;
  double     delta_x;
  double     delta_y;
  double     dash[PRO_NEW_HATCH_DASH_MAX];
  int        num_dash;
  ProColor   color;
} ProXsecNewXhatchPattern;

typedef struct pro_xsec_xhatch_style
{
 int type; /* PRO_XHATCH | PRO_XSEC_EXCLUDED | PRO_XSEC_FILL | PRO_XHATCH_ERASED */
 ProXsecXhatchPattern *lines; /* This is ProArray; free it with ProArrayFree */
} ProXsecXhatchStyle;

typedef struct pro_xsec_new_xhatch_style
{
  int                   type; /* PRO_XHATCH | PRO_XSEC_EXCLUDED | 
                                 PRO_XSEC_FILL | PRO_XHATCH_ERASED */
                              /* PRO_XSEC_EXCLUDED type will be applied only in 
                                 drawing environment */
  ProXsecXhatchPattern    *old_lines; /* This is ProArray; 
                                         free it with ProArrayFree */
  ProXsecNewXhatchPattern *new_lines; /* This is ProArray; 
                                         free it with ProArrayFree */
} ProXsecNewXhatchStyle;


typedef enum pro_xsec_offset_side
{
  PRO_XSEC_OFFSET_BOTH_SIDES	= 0,
  PRO_XSEC_OFFSET_SIDE_1	= 1,
  PRO_XSEC_OFFSET_SIDE_2	= 2
} ProXsecOffsetSide;



PRO_BEGIN_C_DECLS

extern ProError ProXsecMdlnameAlloc( ProSolid solid_owner, ProMdlName xsec_name, 
                                     ProXsecMdlname *r_xsec );
/*
Purpose:     Allocates ProXsecMdlname handle.

Input Arguments:
  solid_owner - Owner of the Cross-section
  xsec_name   - The name to set in the Cross-section. Maximum name size should be 
                PRO_MDLNAME_SIZE.

Output Arguments:
  r_xsec - Cross-section handle

Return Values:
PRO_TK_NO_ERROR    - Data successfully retrieved.
PRO_TK_BAD_INPUTS  - Invalid xsec.
PRO_TK_LINE_TOO_LONG - xsec_name longer then PRO_NAME_SIZE.
*/

extern ProError ProXsecMdlnameFree( ProXsecMdlname *p_xsec );
/*
Purpose:     Frees ProXsecMdlname handle.

Input Arguments:
  p_xsec   - Cross-section handle

Output Arguments:
  None

Return Values:
PRO_TK_NO_ERROR    - Data successfully retrieved.
PRO_TK_BAD_INPUTS  - Invalid xsec.
*/

extern ProError ProXsecMdlnameNameGet(ProXsecMdlname xsec, ProMdlName xsec_name);
/*
Purpose:     Gives the name of the Cross-section

Input Arguments:
xsec   - Cross-section handle

Output Arguments:
xsec_name - The Cross-section name

Return Values:
PRO_TK_NO_ERROR    - Data successfully retrieved.
PRO_TK_BAD_INPUTS  - Invalid xsec.

*/

extern ProError ProXsecMdlnameNameSet(ProXsecMdlname xsec, ProMdlName xsec_name);
/*
Purpose:     Sets the name of the Cross-section. Xsec name should be restricetd to 
             PRO_NAME_SIZE.

Input Arguments:
  xsec      - Cross-section handle
  xsec_name - The name to set in the Cross-section. Maximum name size should be 
              PRO_NAME_SIZE.

Output Arguments:
  None

Return Values:
PRO_TK_NO_ERROR      - Data successfully set.
PRO_TK_BAD_INPUTS    - Invalid xsec or 
PRO_TK_LINE_TOO_LONG - xsec_name longer then PRO_NAME_SIZE.

*/

extern ProError ProXsecMdlnameSolidOwnerGet(ProXsecMdlname xsec, ProSolid *p_solid_owner);
/*
Purpose:     Gives the owner of the Cross-section

Input Arguments:
  xsec   - Cross-section handle

Output Arguments:
  p_solid_owner - Owner of the Cross-section

Return Values:
PRO_TK_NO_ERROR    - Data successfully retrieved.
PRO_TK_BAD_INPUTS  - Invalid xsec.

*/

extern ProError ProXsecMdlnameSolidOwnerSet(ProXsecMdlname xsec, ProSolid solid_owner);
/*
Purpose:     Sets the owner of the Cross-section

Input Arguments:
  xsec   - Cross-section handle
  solid_owner - Owner of the Cross-section

Output Arguments:
  None

Return Values:
PRO_TK_NO_ERROR    - Data successfully set.
PRO_TK_BAD_INPUTS  - Invalid xsec.

*/

typedef ProError (*ProSolidXsecVisitAction) (ProXsec       *xsec,
                                             ProAppData  caller_data);
/*
   Purpose:     Caller-supplied visit function performed when visiting 
                part or assembly cross-sections.

   Input Arguments:
      xsec        - Cross-section being visited
      caller_data - Caller supplied data

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - Continue visiting.
      Other              - Stop visiting, propagate this error up.
*/

extern ProError ProXsecPlanarCreate( ProSolid      solid_owner,
                                     ProName       xsec_name,
                                     int           plane_id,
                                     ProXsecCutobj type,
                                     int           quilt_id,
                                     ProXsec      *xsec );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProXsecPlanarWithoptionsCreate
   Purpose:  Create a cross section through a datum plane.
   <p><b>NOTE: </b>
   This function is deprecated. Please use ProXsecPlanarWithoptionsCreate instead.

   Input Arguments:
        solid_owner   - Solid in which the xsec is to be created.
        xsec_name     - Name of the cross section.
        plane_id      - ID of the plane through which the cross section is
                        created.  This plane must belong to the solid_owner.
        type          - Type of object being cut by the xsec.
        quilt_id      - ID of the quilt being cut if Xsec_type is quilt;  
                        -1 in all other cases. The quilt must belong to the
                        solid_owner.

  Output Arguments:
        xsec          - Handle to created cross section 

  Return Values:
        PRO_TK_NO_ERROR      - Cross section successfully created.
        PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
        PRO_TK_GENERAL_ERROR - Failed to create cross section.
*/
 
extern  ProError ProSolidXsecVisit( ProSolid                 solid,
                                    ProSolidXsecVisitAction  visit_action,
                                    ProAppData               caller_data );

/*  
Purpose:          Visit all cross-sections in the specified solid. This
                  function visits only "named" cross sections.

   Input Arguments:
      solid           - The solid handle
      visit_action    - The visiting function; visiting stops if this function
                        does not return PRO_TK_NO_ERROR.
      caller_data     - Application data passed to the visit function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Cross-sections successfully visited.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND - Model doesn't have cross-sections.
      Other           - Value returned by the action function;
                        visiting stops.
*/


 extern  ProError ProXsecTypeGet( ProXsec       *xsec,
				  ProXsecType   *p_type);
/* 
   Purpose:     Return type of the specified cross-section.

   Input Arguments:
      xsec  - Cross section handle

   Output Arguments:
      p_type  - Cross-section type; a structure with 2 fields: <br>
                <OL>
                <LI>Cutting object type (plane, ply, offset or pattern)<br>
                <LI>Type of the object being cut  (model, quilt, or
                   model_and_quilts)
                </OL>

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/


extern ProError ProXsecRename( ProXsec *xsec,
                               ProName  new_name );
/*
  Purpose:  Rename a cross-section.

  Input Arguments:
      xsec      - Cross section handle
      new_name  - New name for the cross section.  Note: the contents of 
                  this handle will be changed by the function.

  Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR  - Name successfully changed.
      PRO_TK_BAD_INPUTS - Invalid input parameter(s); rename aborted.
*/


extern ProError ProXsecRegenerate( ProXsec  *xsec );
/*
   Purpose:     Regenerate cross-section of a part or assembly.

   Input Arguments:
      xsec  - Cross section handle

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - Cross-section successfully regenerated.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      other              - Error encountered, cross-section not regenerated.
*/

extern ProError ProXsecDelete( ProXsec   *xsec );
/*
   Purpose:     Delete specified cross-section from a part or assembly.

   Input Arguments:
      xsec  - Cross section handle

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - Cross-section successfully deleted .
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXsecDisplay( ProXsec *xsec);
/*
   Purpose:     Display the specified cross section. Does NOT add the cross 
                section to the associated objects list. The display disappears 
                on the first screen redraw.

   Input Arguments:
      xsec              - Cross section handle

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - Cross-section successfully displayed.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXsecGeometryRetrieve( ProXsec      *xsec,
                                         ProXsecGeom  **geom_arr );
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProXsecGeometryCollect
   Purpose: Return the geometry of all cross-section components.
   <p><b>NOTE: </b>This function is deprecated. Please use ProXsecGeometryCollect instead.
      
   Input Arguments:
      xsec   - Cross-section handle


 Output Arguments:
      geom_arr - Array of component geometry structures (see ProXsecGeom)   

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecMassPropertyCompute( ProXsec  *xsec, 
                                            ProName  csys_name,
                                            ProMassProperty   *p_mass_prop);
/*
   Purpose:     Compute the mass properties of the cross-section in the 
                specified coordinate system.
<p>
                Note:
<p>             Not supported for offset or quilt cross-sections.
 
   Input Arguments:
      xsec  -      Cross-section 
      csys_name  - Name of reference coordinate system

   Output Arguments:
      p_mass_prop - The following results are returned for cross sections:
                  <table><tr>
                   <td><b>Value Returned</b></td> <td><b>Structure Field Used</b></td></tr>
                   <tr><td>area</td> <td>surface_area</td></tr>
                   <tr><td>center_of_gravity</td> <td>center_of_gravity[0] and
                                              center_of_gravity[1]</td></tr>
                    <tr><td>coor_sys_inertia</td> <td>coor_sys_inertia[0][0],
                                              coor_sys_inertia[0][1],
                                              coor_sys_inertia[1][0],
                                              coor_sys_inertia[1][1]</td></tr></table>

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully computed.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/


extern ProError ProXsecGeometryCollect( ProXsec      *xsec,
                                        ProView p_view,
                                         ProXsecGeometry  **r_geom_arr );
/*
   DEPRECATED: Since Creo 7
   SUCCESSORS: ProXSectionItemsCollect, ProXSectionItemDataGet
   Purpose:  Returns the geometry of non-empty cross-section components 
                (intersecting their sub-assemblies)
	<p><b>NOTE: </b>
   This function is deprecated. 
   Please use ProXSectionItemsCollect and ProXSectionItemDataGet instead to get geom from item.			

   Input Arguments:
      xsec   - Cross-section handle
      p_view -  View handle
                if not NULL, function returns only solid geometry (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, returns all non-empty components


 Output Arguments:
      r_geom_arr - Pointer to ProArray of component geometry structures (see ProXsecGeometry)   

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_E_NOT_FOUND  - Input cross-section is not a drawing view cross-section.
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.      
*/

LIB_COREUTILS_API  ProError ProXsecGeometryArrayFree ( ProXsecGeometry **p_geom_arr );
/*
    Purpose: Frees ProArray of cross-section data allocated by
             ProXsecGeometryCollect function.
 
    Input Arguments:
        p_geom_arr - The pointer to the ProArray of ProXsecGeometry
 
    Output Arguments:
        none
 
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - p_geom_arr is NULL.
 
    See Also:
        ProXsecGeometryCollect()
 
*/

LIB_COREUTILS_API  ProError ProXsecGeometryFree ( ProXsecGeometry *xsec_geom );
/*
    Purpose: Frees the cross-section data.
 
    Input Arguments:
        xsec_geom - The pointer to the ProXsecGeometry
 
    Output Arguments:
        none
 
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - xsec_geom is NULL.
 
*/

extern ProError ProXSectionItemsCollect( ProXsecMdlname    xsec,
										                     ProView           p_view, 
                                         ProXSectionItem **p_xsec_items );
/*
   Purpose: Returns array of ProXSectionItem. 
            An array item is created for each body. 
            If no bodies are created, contains one item for each component.

   Input Arguments:
    xsec     - Cross-section handle
    p_view   - View handle
               if not NULL, function returns only items containing solid geometry 
               (non-quilt and non-facetrep) components that intersect their non-hidden, 
               non-suppressed parts and are inside view borders;
               if NULL, returns all non-empty components.

   Output Arguments:
    p_xsec_items - ProArray of ProXSectionItem.

   Return Values:
    PRO_TK_NO_ERROR      - Data successfully retrieved.
    PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
    PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
    PRO_TK_E_NOT_FOUND   - p_view is drawing view and input cross-section is
                           not found in the view.

 See Also:
    ProXSectionItemDataGet, ProXSectionItemsArrFree, ProXSectionItemFree.
*/

extern ProError ProXSectionItemsArrFree( ProXSectionItem **p_xsec_items_arr );
/*
    Purpose: Frees ProArray of cross-section data allocated by
             ProXSectionItemsCollect function.
 
    Input Arguments:
        p_xsec_items_arr - The pointer to ProArray of ProXSectionItem
 
    Output Arguments:
        none
 
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - p_xsec_items_arr is NULL.
 
    See Also:
        ProXSectionItemsCollect()
*/

extern ProError ProXSectionItemFree( ProXSectionItem *p_xsec_item );
/*
    Purpose: Frees ProXSectionItem
 
    Input Arguments:
        p_xsec_item - The pointer to the ProXSectionItem
 
    Output Arguments:
        none
 
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS - p_xsec_item is NULL.
 
*/
extern ProError ProXSectionItemDataGet( ProXSectionItem  xsec_item, 
                                        ProAsmcomppath  *r_path,  
                                        ProType         *r_id_type, 
                                        int             *r_id, 
                                        ProGeom         *r_geom );
/*
   Purpose: Returns Data from xsec item handle.

   Input Arguments:
    xsec_item - Cross section body specific handle.

   Output Arguments:
    r_path    - path to the component being cut by cross-section.
    r_id_type - body or quilt type.
    r_id      - id of the body or the quilt being cut, or the exagerated ply
                if this is a ply section.
    r_geom    - Geometry created by Cross-section by cutting specific body or quilt.

   Return Values:
    PRO_TK_NO_ERROR      - Data successfully retrieved.
    PRO_TK_BAD_INPUTS    - Invalid input parameter(s).

 See Also:
    ProXSectionItemDataGet, ProXSectionItemsArrFree, ProXSectionItemFree.
*/

extern ProError ProXsecPlaneGet (ProXsec *xsec, ProGeom *pp_plane);

/*
    Purpose:     Return the plane of a given cross-section.
 
    Input Arguments:
       xsec   - Cross-section handle
 
    Output Arguments:
       pp_plane - Pointer to a pointer to a plane geom
 
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_NOT_IMPLEMENTED - This is not a planar cross-section.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s): incorrect xsec
                                or output arg may be NULL.
*/

extern ProError ProXsecCompXhatchGet( ProXsec *xsec, int id, ProView p_view,
                                      ProXsecXhatch **p_xhatch_arr );
/*
   Purpose:     Returns cross-section component xhatching

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components


 Output Arguments:
      p_xhatch_arr - ProArray of cross-section component line patterns.
                     Free this using ProArrayFree().
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or
                           doesn't have the component with given id that is inside the view
                           or the component doesn't have xhatches.
      PRO_TK_UNSUPPORTED - Input cross-section is with non-linear-hatch. 
                           Not supported with non-linear-hatch. 
                           Can be used ProXsecCompNewXhatchStyleGet() instead.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompXhatchAdd( ProXsec *xsec, int id, ProView p_view,
                                      ProXsecXhatch *xhatch );
/*
   Purpose:     Adds line pattern to cross-section component xhatching

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components
      xhatch -  Pointer to ProXsecXhatch structure with line pattern


 Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or 
                           doesn't have the component with given id that is inside the view.
      PRO_TK_E_FOUND     - Cross-section component already has the input line pattern. 
                           Nothing added.
      PRO_TK_UNSUPPORTED - Input cross-section is with non-linear-hatch. 
                           New line can't be added for non-linear-hatch.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompXhatchReplace( ProXsec *xsec, int id, ProView p_view,
                                          ProXsecXhatch *xhatch );
/*
   Purpose:     Replaces line patterns with new one in cross-section component xhatching

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components
      xhatch -  Pointer to ProXsecXhatch structure with line pattern


 Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or 
                           doesn't have the component with given id that is inside the view.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProOffsetXsecGet(ProXsec *xsec, ProView p_view, Pro2dLinedef **p_ent_arr, ProPlanedata *plane, ProBoolean *p_one_sided, ProBoolean *p_flip);

/*
   DEPRECATED: Since Creo 9
   SUCCESSORS: ProOffsetXsecInfoGet
   Purpose:     Returns parameters of offset X-section
   <p><b>NOTE: </b>
   This function is deprecated. Please use ProOffsetXsecInfoGet instead.
   
   Input Arguments:
      xsec   - Cross-section handle
      p_view -  View handle


 Output Arguments:
      p_ent_arr - ProArray of Pro2dLinedef structures for X-section entities.
                  Free this using ProArrayFree().
      plane - ProPlanedata for an entity plane.
      p_one_sided - TRUE if X-section is on one side of entity plane; FALSE - both sided.
      p_flip - FALSE, we remove material from the left of the oriented entities 
                      (if we look from the positive normal to entity plane)
                      and if one_sided = TRUE, only from one side of entity plane opposite to its normal.
               TRUE, we instead keep this area and remove the rest of the material.
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_NOT_IMPLEMENTED  - Some of X-section entities is not a line segment.
*/

extern ProError ProOffsetXsecInfoGet(ProXsec *xsec, ProView p_view, Pro2dLinedef **p_ent_arr, ProPlanedata *plane, ProBoolean *p_one_sided, ProBoolean *p_flip, ProXsecOffsetSide* p_side_xsec_mode);
/*
   Purpose:     Returns parameters of offset X-section

   Input Arguments:
      xsec   - Cross-section handle
      p_view -  View handle


 Output Arguments:
      p_ent_arr - ProArray of Pro2dLinedef structures for X-section entities.
                  Free this using ProArrayFree().
      plane - ProPlanedata for an entity plane.
      p_one_sided - TRUE if X-section is on one side of entity plane; FALSE - both sided.
      p_flip - FALSE, we remove material from the left of the oriented entities 
                      (if we look from the positive normal to entity plane)
                      and if one_sided = TRUE, only from one side of entity plane opposite to its normal.
               TRUE, we instead keep this area and remove the rest of the material.
	  p_side_xsec_mode - returns orientation as 
	                    PRO_XSEC_OFFSET_SIDE_1/PRO_XSEC_OFFSET_SIDE_2/
						PRO_XSEC_OFFSET_BOTH_SIDES
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_NOT_IMPLEMENTED  - Some of X-section entities is not a line segment.
*/

extern ProError ProFeatureZoneGet (ProFeature *zone, ProPlanedata **p_planes, int **p_oper_arr);

/*
    Purpose:     Return zone feature planes and operations.
 
    Input Arguments:
       zone   - ProFeature handle.
 
    Output Arguments:
       p_planes - ProArray of ProPlanedata structures.
                  Free this using ProArrayFree().
       p_oper_arr - ProArray of operations: 0 - intersection, 1 - union. 
                    We keep the material that belongs to the intersection and union of planes' half spaces.
                    Free this using ProArrayFree().
 
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s). 
*/

extern ProError ProXsecAsModelitemGet (ProXsec *p_xsec, ProModelitem *p_item);

/*
   Purpose:     Converts ProXsec into ProModelitem

   Input Arguments:
      p_xsec   - Cross-section handle.

   Output Arguments:
      p_item - ProModelitem.

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully converted.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_INVALID_PTR - Invalid input parameter(s).
*/

extern ProError ProXsecGet(ProMdl owner, int id, ProXsec *p_xsec);

/*
   Purpose:     Get ProXsec from owner and id. 

   Input Arguments:
      owner - Solid owner.
      id    - xsec id.

   Output Arguments:
      p_xsec   - Cross-section handle.

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully converted.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_INVALID_PTR - Invalid input parameter(s).
*/

extern ProError ProModelitemIsZone(ProModelitem *p_item, ProBoolean *p_val);

/*
   Purpose:     Check if ProModelitem is a zone feature. 

   Input Arguments:
      p_item - ProModelitem handle.

   Output Arguments:
      p_val   - ProBoolean is TRUE for zone, otherwise FALSE.

   Return Values:
      PRO_TK_NO_ERROR    - p_item successfully checked.
      PRO_TK_BAD_INPUTS  - p_item is NULL or p_item->owner is invalid.
*/

extern ProError ProXsecParallelCreate( ProSolid      solid_owner,
                                       ProName       xsec_name,
                                       int           plane_id,
                                       double        distance,
                                       ProXsec       *p_xsec,
                                       ProDimension  *p_dimension );

/*
    Purpose:     Create a cross section parallel to a given plane.

    Input Arguments:
        solid_owner   - Solid in which the xsec is to be created. Cannot be NULL.
        xsec_name     - Name of the cross section. Cannot be NULL. Cannot be empty.
        plane_id      - ID of the given plane. This plane must belong to the solid_owner.
        distance      - Distance from the given plane to the cross section plane.

    Output Arguments:
        p_xsec          - Handle to created cross section. Cannot be NULL.
        p_dimension     - Handle for created dimension between given plane and 
                          the cross section.

    Return Values:
        PRO_TK_NO_ERROR   - Cross section successfully created.
        PRO_TK_BAD_INPUTS - Invalid input parameters: NULL arguments, or 
                            solid_owner is not a solid, or empty xsec_name, 
                            or plane_id does not correspond to a plane.
        PRO_TK_E_FOUND    - Cross section with such name already exists.
        PRO_TK_GENERAL_ERROR - Failed to create cross section.
*/

extern ProError ProFeatureZonesectionCreate(ProSolid p_solid, 
                                            ProZoneReference *zone_refs, 
                                            ProName zone_name, 
                                            ProFeature *p_zone);

/*
    Purpose:     Create zone feature by its planes and operations.
 
    Input Arguments:
       p_solid      - The solid handle.
       zone_refs    - ProArray of ProZoneReference for zone reference planes.
                      We keep the material that belongs to the intersection and union of planes' half spaces.
                      Pass NULL to memb_id_tab member of this structure, when the feature is owned by a part.
       zone_name    - Zone name handle. If a zone with this name exists, the function returns PRO_TK_E_FOUND.

    Output Arguments:
       p_zone   - ProFeature handle.
 
    Return Values:
       PRO_TK_NO_ERROR        - Zone feature successfully created.
       PRO_TK_BAD_INPUTS      - Invalid input/output parameter(s).
       PRO_TK_GENERAL_ERROR   - Failure to create zone.
       PRO_TK_E_FOUND         - Zone with given name already exists.
*/


extern ProError ProXsecCanCreateAsFeature (ProMdl model, ProBoolean *flag);
/*
    Purpose:     Check if section features can be created in a given model
 
    Input Arguments:
       model       - The model handle.

    Output Arguments:
       flag        - ProBoolean is TRUE if new section can be created, 
                     otherwise FALSE.
 
    Return Values:
      PRO_TK_NO_ERROR    - Model successfully checked.
      PRO_TK_BAD_INPUTS  - Model is NULL or invalid.
*/

extern ProError ProXsecOldToNewConvert (ProMdl model);
/*
    Purpose:     Convert all the old sections of a given model to the new 
                 sections

    Input Arguments:
       model       - The model handle.

    Output Arguments:
      None

    Return Values:
      PRO_TK_NO_ERROR      - Sections successfully converted.
      PRO_TK_BAD_INPUTS    - Model is NULL or invalid.
      PRO_TK_GENERAL_ERROR - Failure to convert sections.
*/

extern ProError ProXsecFeatureGet (ProXsec *p_sec, ProFeature *p_feature);
/*
    Purpose:     Returns a pointer to the cross section feature.  

    Input Arguments:
       p_sec       - Cross-section handle. 

    Output Arguments:
       p_feature   - ProFeature handle.

    Return Values:
      PRO_TK_NO_ERROR      - Cross section feature successfully retrieved.
      PRO_TK_BAD_INPUTS    - p_sec or p_feature are NULL or invalid.
      PRO_TK_BAD_CONTEXT   - Legacy cross sections.
      PRO_TK_GENERAL_ERROR - Failure to retrieve section.
*/

extern ProError ProXsecIsFeature( ProXsec *p_sec, ProBoolean *p_value );
/*
    Purpose:  Check whether the cross section is a feature.   

    Input Arguments:
       p_sec       - Cross-section handle.

    Output Arguments:
       p_value     - ProBoolean is TRUE if p_sec is feat, 
                     otherwise FALSE.

    Return Values:
      PRO_TK_NO_ERROR      - p_sec successfully checked.
      PRO_TK_BAD_INPUTS    - p_sec or p_value are NULL or invalid.
*/

extern ProError ProXsecPlanarWithoptionsCreate( ProSolid             solid_owner,
                                                ProName              xsec_name,
                                                int                  plane_id,
                                                ProXsecCutobj        xsec_type,
                                                int                 *memb_id_tab,
                                                int                  quilt_id,
                                                int                  flip,
                                                ProXsecExcludeModels model_opt,
                                                ProAsmpath          *comp_id_tabs,
                                                ProXsec             *xsec );
/*
   DEPRECATED: Since Creo 7
   SUCCESSORS: ProXSectionPlanarCreate
   Purpose:  Creates a cross section through a datum plane and makes it visible.
   <p><b>NOTE: </b>
   This function is deprecated. Please use ProXSectionPlanarCreate instead.

    Input Arguments:
        solid_owner   - Solid in which the xsec is to be created. 
        xsec_name     - Name of the cross section.
        plane_id      - ID of the cutting plane. This plane must belong to the solid_owner.
        xsec_type     - Type of object being cut by the xsec.
        memb_id_tab   - ProArray of integer identifiers forming the path 
                        to the component whose quilt is being cut 
                        if xsec_type is PRO_XSECTYPE_QUILTS, or  
                        the component if xsec_type is PRO_XSECTYPE_ONEPART
        quilt_id      - ID of the quilt being cut if xsec_type is PRO_XSECTYPE_QUILTS;  
                        -1 in all other cases. The quilt may belong to the
                        solid_owner or its sub-assemblies.
        flip          - xsec flip with respect to cutting plane positive normal.
        model_opt     - option for exclude/include;
        comp_id_tabs  - ProArray of ProAsmpath for excluded/included components.

     Output Arguments:
           xsec          - Handle to created cross section 


  Return Values:
        PRO_TK_NO_ERROR      - Cross section successfully created.
        PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
        PRO_TK_GENERAL_ERROR - Failed to create cross section.
*/

extern ProError ProXSectionPlanarCreate( ProSolid              solid_owner, 
                                         ProMdlName            xsec_name,
                                         ProSelection          cutting_plane,
                                         ProXsecCutobj         xsec_type,
                                         ProSelection          quilt_or_one_part,
                                         int                   flip,
                                         ProXsecExcludeModels  excld_incld_opt,
                                         ProSelection         *exclude_items,
                                         ProXSectionCreateData data,
                                         ProXsecMdlname       *r_xsec );
/*
	Purpose:  Creates a cross section through a datum plane and makes it visible.

	Input Arguments:
    solid_owner   - Solid in which the xsec is to be created.
    xsec_name     - Name of the cross section. Name size should be PRO_NAME_SIZE.
    cutting_plane - Selection of cutting plane. Cutting plane should belong to top level 
                    part or assembly.
    xsec_type     - Type of object being cut by the xsec.
    quilt_or_one_part - ProSelection of quilt or component depending on xsec_type.
                        If xsec_type is PRO_XSECTYPE_QUILTS  - Quilt.
                        If xsec_type is PRO_XSECTYPE_ONEPART - component.
    flip            - xsec flip with respect to cutting plane positive normal.
    excld_incld_opt - PRO_XSEC_MODEL_EXCLUDE - exclude exclude_items from cutting by cross section;
                      PRO_XSEC_MODEL_INCLUDE - include in the cross-section only items in exclude_items.
    exclude_items   - ProArray of selected bodies or parts to include/exclude from cross-section.
    data            - Reserved for future use. Pass NULL.

	 Output Arguments:
		   r_xsec       - Handle to created cross section


  Return Values:
		PRO_TK_NO_ERROR      - Cross section successfully created.
		PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
		PRO_TK_GENERAL_ERROR - Failed to create cross section.
    PRO_TK_LINE_TOO_LONG - xsec_name is longer then PRO_NAME_SIZE.
	
  See Also:
	  ProXSecGeometryCollect()
*/

extern ProError ProFeatureZonesectionGet(ProFeature *zone, ProZoneReferenceWithflip **p_zone_refs);
/*
    Purpose:     Return zone feature references.
 
    Input Arguments:
       zone   - ProFeature handle.
 
    Output Arguments:
       p_zone_refs    - ProArray of ProZoneReferenceWithflip for zone reference planes.
 
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s). 
*/

extern ProError ProFeatureZonesectionWithflipCreate(ProSolid p_solid, 
                                                    ProZoneReferenceWithflip *zone_refs, 
                                                    ProName zone_name, 
                                                    ProFeature *p_zone);
/*
    Purpose:     Create zone feature by its planes and operations.
                 The same as ProFeatureZonesectionCreate but also allows 
                 the user to add a flip for zone planes: see ProZoneReferenceWithFlip.
 
    Input Arguments:
       p_solid      - The solid handle.
       zone_refs    - ProArray of ProZoneReferenceWithflip for zone reference planes.
                      We keep the material that belongs to the intersection and union of planes' half spaces.
                      Pass NULL to memb_id_tab member of this structure, when the feature is owned by a part.
       zone_name    - Zone name handle. If a zone with this name exists, the function returns PRO_TK_E_FOUND.

    Output Arguments:
       p_zone   - ProFeature handle.
 
    Return Values:
       PRO_TK_NO_ERROR        - Zone feature successfully created.
       PRO_TK_BAD_INPUTS      - Invalid input/output parameter(s).
       PRO_TK_GENERAL_ERROR   - Failure to create zone.
       PRO_TK_E_FOUND         - Zone with given name already exists.
*/


extern ProError ProFeatureZoneXsecgeomGet(ProFeature *zone, ProXsecGeometry ***r_geom_arrays);
/*
    Purpose:     Return zone feature xsec geometry.
 
    Input Arguments:
       zone   - ProFeature handle.
 
    Output Arguments:
       r_geom_arrays    - ProArray of ProArrays of ProXsecGeometry for zone reference planes.
 
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s).
       PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/


LIB_COREUTILS_API ProError ProZoneReferenceArrayFree( ProZoneReferenceWithflip **p_zone_refs);
/*
    Purpose:     Frees ProArray of zone reference data allocated by ProFeatureZonesectionGet.

    Input Arguments:
        p_zone_refs - The pointer to the ProArray of ProZoneReferenceWithflip.

    Output Arguments:
        none
    
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - p_zone_refs is NULL.
*/


LIB_COREUTILS_API ProError ProZoneReferenceFree( ProZoneReferenceWithflip *zone_ref);
/*
    Purpose:     Frees the zone reference data.
    Input Arguments:
        zone_ref - The pointer to ProZoneReferenceWithflip.

    Output Arguments:
        none
    
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - zone_ref is NULL.
*/

LIB_COREUTILS_API ProError ProFeatureZoneXsecGeomArrayFree(ProXsecGeometry ***p_geom_arrays);
/*
     Purpose:    Frees ProArray of ProArrays of ProXsecGeometry for zone reference planes 
                 allocated by ProFeatureZoneXsecgeomGet.

     Input Arguments:
         p_geom_arrays - Pointer to ProArray of ProArrays of ProXsecGeometry

    Output Arguments:
        none
    
    Return Values:
        PRO_TK_NO_ERROR - The function successfully freed the data.
        PRO_TK_BAD_INPUTS  - p_geom_arrays is NULL.
*/

extern ProError ProXsecFlipGet(ProXsec *xsec, int *p_flip);
/*
    Purpose:     Return xsec flip.
 
    Input Arguments:
       xsec   - ProXsec handle.
 
    Output Arguments:
       p_flip    - planar xsec: 1 - model is clipped in the direction of the positive normal to the xsec plane.
                               -1 - model is clipped in the opposite direction.
                   ply xsec:    1 - model is clipped in the direction of the positive normal to the xsec plane.
                               -1 - model is clipped in the opposite direction.
                   offset xsec (see ProOffsetXsecGet): 
                                1 - we remove material from the left of the oriented entities
                                    if we look from the positive normal to entity plane.
                               -1 - we instead keep this area and remove the rest of the material.
 
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s). 
	   PRO_TK_BAD_CONTEXT     - solid owner is not a composite design model, 
	                            or composite session is not active.
*/

extern ProError ProXsecExcludeCompGet(ProXsec *xsec, ProXsecExcludeModels *p_model_opt, ProAsmpath **p_comp_id_tabs);
/*
   DEPRECATED: Since Creo 7
   SUCCESSORS: ProXSectionExcludeCompGet
   Purpose:  Return pathes to xsec exclude/include components.
   <p><b>NOTE: </b>
   This function is deprecated. Please use ProXSectionExcludeCompGet instead.
 
    Input Arguments:
       xsec   - ProXsec handle.
 
    Output Arguments:
       p_model_opt    -  option for exclude/include:
                         PRO_XSEC_MODEL_EXCLUDE - the output pathes are to excluded components
                         PRO_XSEC_MODEL_INCLUDE - the output pathes are to included components
       
       p_comp_id_tabs -  ProArray of ProAsmpath for components. Free it using ProAsmpathProarrayFree.
       
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s). 
*/

extern ProError ProXSectionExcludeCompGet( ProXsecMdlname         xsec, 
                                           ProXsecExcludeModels  *p_exclude_include_opt, 
                                           ProSelection         **p_exclude_array);
/*
    Purpose:     Return pathes to xsec exclude/include components and bodies.
 
    Input Arguments:
       xsec   - ProXsec handle.
 
    Output Arguments:
       p_exclude_include_opt -  option for exclude/include:
                         PRO_XSEC_MODEL_EXCLUDE - the output selections are to excluded components and bodies
                         PRO_XSEC_MODEL_INCLUDE - the output selections are to included components and bodies
       
       p_exclude_array - ProArray of excluded or included items.
       
    Return Values:
       PRO_TK_NO_ERROR        - Data successfully retrieved.
       PRO_TK_BAD_INPUTS      - Invalid input parameter(s).
*/



extern ProError ProXsecCompXhatchStyleGet( ProXsec *xsec, int id, ProView p_view,
                                           ProXsecXhatchStyle *p_xhatch_style );
/*
  DEPRECATED: Since Creo 7
  SUCCESSORS : ProXsectionCompXhatchStyleGet, ProXSectionItemXhatchStyleGet
  Purpose: Returns cross-section component xhatching
  <p><b>NOTE: </b>
        This function is deprecated. 
        Please use ProXsectionCompXhatchStyleGet to get Xhatch from component.
        Please use ProXsectionCompXhatchStyleGet to get Xhatch from body.

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components


 Output Arguments:
      p_xhatch_style - ProXsecXhatchStyle handle.

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or
                           doesn't have the component with given id that is inside the view
                           or the component doesn't have xhatches.
      PRO_TK_UNSUPPORTED - Input cross-section is with non-linear-hatch. 
                           Not Supported for non-linear-hatch. 
                           Please use instead ProXsecCompNewXhatchStyleGet().
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompNewXhatchStyleGet( ProXsec *xsec, int id, ProView p_view,
                                              ProXsecNewXhatchStyle *p_xhatch_style );
/*
  DEPRECATED: Since Creo 7
  SUCCESSORS : ProXsectionCompXhatchStyleGet, ProXSectionItemXhatchStyleGet
  Purpose: Returns cross-section component xhatching with old/non-linear-hatch
  <p><b>NOTE: </b>
        This function is deprecated. 
        Please use ProXsectionCompXhatchStyleGet to get Xhatch from component.
        Please use ProXsectionCompXhatchStyleGet to get Xhatch from body.

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components


 Output Arguments:
      p_xhatch_style - ProXsecNewXhatchStyle handle. 
                       Unused hatch field (either new_lines or old_lines) will 
                       be set to NULL.

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or
                           doesn't have the component with given id that is inside the view
                           or the component doesn't have xhatches.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompXhatchStyleSet(ProXsec *xsec, int id, ProView p_view, 
                                          ProXsecXhatchStyle *p_xhatch_style );
/*
	DEPRECATED: Since Creo 7
	SUCCESSORS : ProXsectionCompXhatchStyleSet, ProXSectionItemXhatchStyleSet
	Purpose:   Replaces line patterns with new one in cross-section component xhatching
               Non-linear-hatch is not supported.
               Please use ProXsecCompNewXhatchStyleGet() for non-linear-hatch
               support.
			   <p><b>NOTE: </b>
			This function is deprecated. 
      Please use ProXsectionCompXhatchStyleSet to set Xhatch on component.
      Please use ProXSectionItemXhatchStyleSet to set Xhatch on body.

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components
      p_xhatch_style -  ProXsecXhatchStyle handle


 Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or 
                           doesn't have the component with given id that is inside the view.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompNewXhatchStyleSet(ProXsec *xsec, int id, ProView p_view,
                                             ProName hatch_name, 
                                             ProXsecNewXhatchStyle *p_xhatch_style );
/*
	DEPRECATED: Since Creo 7
	SUCCESSORS : ProXsectionCompXhatchStyleSet, ProXSectionItemXhatchStyleSet
	Purpose: Replaces line patterns with new one in cross-section component xhatching.
	<p><b>NOTE: </b>
	  This function is deprecated. 
      Please use ProXsectionCompXhatchStyleSet to set Xhatch on component.
      Please use ProXSectionItemXhatchStyleSet to set Xhatch on body.

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components
      p_xhatch_style -  ProXsecNewXhatchStyle handle
                        Unused hatch field (either new_lines or old_lines) 
                        should be set to NULL.
      hatch_name     - Name for the non-linear-hatching. 
                       A suffix _TK will be added to the name
                       Relevant only for the non-linear-hatch.
                       If NULL, the hatch will be called TK_#.

 Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or 
                           doesn't have the component with given id that is inside the view.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXsecCompNewXhatchStyleSetByName( ProXsec *xsec, int id, 
                                                    ProView p_view, 
                                                    ProName hatch_name,
                                                    int type, ProColor color);
/*
  DEPRECATED: Since Creo 7
	SUCCESSORS : ProXsecNewXhatchStyleCreateFromName, ProXsectionCompXhatchStyleSet, ProXSectionItemXhatchStyleSet
	Purpose:  Replaces line patterns with new one with the name hatch_name
      Relevant only for non-linear-hatch patterns.
	  <p><b>NOTE: </b>	This function is deprecated. 
      Please use ProXsecNewXhatchStyleCreateFromName to create ProXsecNewXhatchStyle
      and set it with function ProXsectionCompXhatchStyleSet or ProXSectionItemXhatchStyleSet.

   Input Arguments:
      xsec   - Cross-section handle
      id     - Cross-section component id in component list
      p_view -  View handle
                if not NULL, in component list we have only solid geometry 
                (non-quilt and non-facetrep)
                components that intersect their non-hidden, non-suppressed
                parts and are inside view borders;
                if NULL, in component list we have all non-empty components
      hatch_name -  hatch pattern name
      type - PRO_XHATCH | PRO_XSEC_EXCLUDED | PRO_XSEC_FILL | PRO_XHATCH_ERASED
      color - hatch pattern color

 Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
      PRO_TK_GENERAL_ERROR - Cross-section fails regeneration.
      PRO_TK_E_NOT_FOUND - Input cross-section is not a drawing view cross-section or 
                           doesn't have the component with given id that is inside the view
                           or there is no hatch pattern with given name.
      PRO_TK_MULTIBODY_UNSUPPORTED - Multi-Body parts are being cut by the Cross-section.
*/

extern ProError ProXSectionItemXhatchStyleGet( ProXSectionItem xsec_item,
                                               ProView         p_view,
                                               ProXsecNewXhatchStyle *p_xhatch_style );
/*
   Purpose: Returns cross-section xhatch style of body.

   Input Arguments:
    xsec_item -  Specific body xsec handle.
    p_view    -  View handle. Could be NULL if not Drawing.

 Output Arguments:
    p_xhatch_style - ProXsecNewXhatchStyle handle.
                     Unused hatch field (either new_lines or old_lines) will
                     be set to NULL.

   Return Values:
    PRO_TK_NO_ERROR    - Data successfully retrieved.
    PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXSectionItemXhatchStyleSet( ProXSectionItem xsec_item,
                                               ProView         p_view,
                                               ProName         hatch_name,
                                               ProXsecNewXhatchStyle *p_xhatch_style );
/*
   Purpose: Sets cross-section xhatch style on body.
            If the XhatchStyle and the hatch_name exist in the session, no new 
            hatch with with TK suffix will be created. The existent hatch will be set.

   Input Arguments:
    xsec_item  - Specific body xsec handle.
    p_view     - View handle. Could be NULL if not Drawing.
    hatch_name - Name for the non-linear-hatching. 
                 A suffix _TK will be added to the name
                 Relevant only for the non-linear-hatch.
                 If NULL, the hatch will be called TK_#.
    p_xhatch_style - ProXsecNewXhatchStyle handle.
                     Unused hatch field (either new_lines or old_lines) should
                     be set to NULL.

 Output Arguments:
    None

   Return Values:
    PRO_TK_NO_ERROR    - Data successfully retrieved.
    PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXsectionCompXhatchStyleGet( ProXsecMdlname  xsec,
                                               ProAsmcomppath *path,
                                               ProView         p_view,
                                               ProXsecNewXhatchStyle *p_xhatch_style );
/*
   Purpose: Returns cross-section xhatch style of component.
            If Xhatch is not the same on all the component bodies error PRO_TK_E_AMBIGUOUS
            will be returned.

   Input Arguments:
    xsec   -  Cross-section handle
    path   -  path to component. For part: owner is the part and table_num is zero.
    p_view -  View handle. Could be NULL if not Drawing.

 Output Arguments:
    p_xhatch_style - ProXsecNewXhatchStyle handle.
                     Unused hatch field (either new_lines or old_lines) will
                     be set to NULL.

   Return Values:
    PRO_TK_NO_ERROR    - Data successfully retrieved.
    PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
    PRO_TK_E_AMBIGUOUS - Indicates bodies of component have different hatch.
*/

extern ProError ProXsectionCompXhatchStyleSet( ProXsecMdlname  xsec,
                                               ProAsmcomppath *path,
                                               ProView         p_view,
                                               ProName         hatch_name,
                                               ProXsecNewXhatchStyle *p_xhatch_style );
/*
   Purpose: Sets cross-section xhatch style on component.
            If the XhatchStyle and the hatch_name exist in the session, no new 
            hatch with with TK suffix will be created. The existent hatch will be set.

   Input Arguments:
    xsec   -  Cross-section handle
    path   -  path to component. For part: owner is the part and table_num is zero.
    p_view -  View handle. Could be NULL if not Drawing.
    hatch_name - Name for the non-linear-hatching. 
                 A suffix _TK will be added to the name
                 Relevant only for the non-linear-hatch.
                 If NULL, the hatch will be called TK_#.
                 If the XhatchStyle is created by 
    p_xhatch_style - ProXsecNewXhatchStyle handle.
                     Unused hatch field (either new_lines or old_lines) should
                     be set to NULL.
 Output Arguments:
    None

   Return Values:
    PRO_TK_NO_ERROR    - Data successfully retrieved.
    PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXsecNewXhatchStyleCreateFromName( ProName hatch_name, 
                                                     ProColor color, int type,
                                                     ProXsecNewXhatchStyle *p_xhatch_style );
/*
   Purpose: Creates ProXsecNewXhatchStyle from hatch name.
            Relevant only to PAT hatch (non-linear-hatch).
            Created p_xhatch_style could be set by functions 
            ProXSectionItemXhatchStyleSet and ProXsectionCompXhatchStyleSet.

   Input Arguments:
    hatch_name - Name of existing PAT hatch.
    color - color of the newly created pattern.
    type  - PRO_XHATCH | PRO_XSEC_EXCLUDED | PRO_XSEC_FILL | PRO_XHATCH_ERASED


 Output Arguments:
    p_xhatch_style - ProXsecNewXhatchStyle handle.
                     Unused hatch field (old_lines) will be set to NULL.

   Return Values:
    PRO_TK_NO_ERROR    - Data successfully retrieved.
    PRO_TK_BAD_INPUTS  - Invalid input parameter(s).
*/

extern ProError ProXsecOffsetCreate(ProSolid solid_owner, 
                                    ProName xsec_name, 
                                    double trf[4][3], 
                                    Pro2dLinedef *ent_arr, 
                                    ProXsecOffsetSide side, 
                                    int flip, 
                                    ProXsecExcludeModels model_opt, 
                                    ProAsmpath *comp_id_tabs, 
                                    ProXsec *xsec);

/*
   DEPRECATED: Since Creo 7
   SUCCESSORS: ProXSectionOffsetCreate
   Purpose:  Creates an offset cross section with polyline lying on the plane given by local sys.
   <p><b>NOTE: </b>
   This function is deprecated. Please use ProXSectionOffsetCreate instead.

    Input Arguments:
        solid_owner   - Solid in which the xsec is to be created. 
        xsec_name     - Name of the cross section.
        trf           - Local sys of the plane containing cross section polyline.
        ent_arr       - ProArray of Pro2dLinedef structures for polyline.
        side          - PRO_XSEC_OFFSET_SIDE_1/2 - we remove material only from positive/negative normal of polyline plane;
                        PRO_XSEC_OFFSET_BOTH_SIDES - cut in both directions.
        flip          - FALSE - we keep material from the right of the oriented polyline,
                                if we look from the positive normal to polyline plane
                                and if side = PRO_XSEC_OFFSET_SIDE_1/2, only from the positive/negative normal to this plane;
                        TRUE - we instead remove this area and keep the rest of the material.
                        If cross section polyline is closed, flip has different meaning:
                        for clockwise polyline, FALSE means we keep material inside it and if side = PRO_XSEC_OFFSET_SIDE_1/2, 
                                                      only from the positive/negative normal to this plane;
                                                TRUE means we remove this area and keep the rest of the material.
                        for counter-clockwise polyline, TRUE means the same as FALSE for clockwise polyline and FALSE means the same as TRUE for it.
        model_opt     - PRO_XSEC_MODEL_EXCLUDE - exclude assembly components with paths in comp_id_tabs from cutting by cross section;
                        PRO_XSEC_MODEL_INCLUDE - cut only components with paths in comp_id_tabs.
        comp_id_tabs  - ProArray of ProAsmpath for excluded/included components.

     Output Arguments:
           xsec          - Handle to created cross section 


  Return Values:
        PRO_TK_NO_ERROR      - Cross section successfully created.
        PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
        PRO_TK_GENERAL_ERROR - Failed to create cross section.
*/

extern ProError ProXSectionOffsetCreate( ProSolid          solid_owner, 
                                         ProMdlName        xsec_name, 
                                         double            trf[4][3], 
                                         Pro2dLinedef     *ent_arr, 
                                         ProXsecOffsetSide side, 
                                         int               flip,
                                         ProXsecExcludeModels  excld_incld_opt,
                                         ProSelection         *exclude_items,
                                         ProXSectionCreateData data,
                                         ProXsecMdlname       *r_xsec);


/*
    Purpose:     Creates an offset cross section with polyline lying on the plane 
                 given by local sys.

    Input Arguments:
        solid_owner   - Solid in which the xsec is to be created. 
        xsec_name     - Name of the cross section. Name size should be PRO_NAME_SIZE.
        trf           - Local sys of the plane containing cross section polyline.
        ent_arr       - ProArray of Pro2dLinedef structures for polyline.
        side          - PRO_XSEC_OFFSET_SIDE_1/2 - we remove material only from positive/negative 
                        normal of polyline plane;
                        PRO_XSEC_OFFSET_BOTH_SIDES - cut in both directions.
        flip          - FALSE - we keep material from the right of the oriented polyline,
                                if we look from the positive normal to polyline plane
                                and if side = PRO_XSEC_OFFSET_SIDE_1/2, only from the positive/negative normal to this plane;
                        TRUE - we instead remove this area and keep the rest of the material.
                        If cross section polyline is closed, flip has different meaning:
                        for clockwise polyline, FALSE means we keep material inside it and if side = PRO_XSEC_OFFSET_SIDE_1/2, 
                        only from the positive/negative normal to this plane;
                        TRUE means we remove this area and keep the rest of the material.
                        for counter-clockwise polyline, TRUE means the same as FALSE for clockwise polyline and FALSE means the same as TRUE for it.
        excld_incld_opt - PRO_XSEC_MODEL_EXCLUDE - exclude exclude_items from cutting by cross section;
                          PRO_XSEC_MODEL_INCLUDE - include in the cross-section only items in exclude_items.
        exclude_items   - ProArray of selected bodies or parts to include/exclude from cross-section.
        data            - Used to set quilt xsec type ( PRO_XSECTYPE_QUILTS or PRO_XSECTYPE_MODELQUILTS ) for offset xsec creation.
                          Used to set quilt selection for offset xsec creation when PRO_XSECTYPE_QUILTS option is used.

     Output Arguments:
           r_xsec       - Handle to created cross section 


  Return Values:
        PRO_TK_NO_ERROR      - Cross section successfully created.
        PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
        PRO_TK_GENERAL_ERROR - Failed to create cross section.
        PRO_TK_LINE_TOO_LONG - xsec_name is longer then PRO_NAME_SIZE.
*/

extern ProError ProXsecIsVisible(ProXsec *xsec, ProBoolean *p_vis);
/*
   Purpose:     Return xsec visibility. 

   Input Arguments:
      xsec   - Cross-section handle

   Output Arguments:
      p_vis - ProBoolean is TRUE if xsec is visible (xhatched), FALSE if not.

   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid xsec or p_vis is NULL.
      PRO_TK_BAD_CONTEXT   - solid owner is not a composite design model
                             or composite session is not active.

      PRO_TK_E_NOT_FOUND - Current view and model is different from where xsec was created.
      
*/

extern ProError ProXsecMakeVisible(ProXsec *xsec);
/*
   Purpose:     Make xsec visible (xhatched). 

   Input Arguments:
      xsec   - Cross-section handle

   Output Arguments:
        none
   
   Return Values:
      PRO_TK_NO_ERROR    - Data successfully retrieved.
      PRO_TK_BAD_INPUTS  - Invalid xsec.
      PRO_TK_BAD_CONTEXT   - solid owner is not a composite design model
                             or composite session is not active.

      PRO_TK_E_NOT_FOUND - Current view and model is different from where xsec was created.
*/

extern ProError ProXsecActiveGet( ProXsec *p_xsec );
/*
Purpose:     Return Active xsec

Input Arguments:
none

Output Arguments:
p_xsec - Cross-section which is active

Return Values:
PRO_TK_NO_ERROR      - Data successfully retrieved.
PRO_TK_GENERAL_ERROR - Failed to retrieve data
PRO_TK_E_NOT_FOUND   - Current view does not have an active xsec

*/

extern ProError ProXsecActiveSet( ProXsec *xsec );
/*
Purpose:     Make xsec active

Input Arguments:
xsec   - Cross-section handle

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    - Data successfully retrieved.
PRO_TK_BAD_INPUTS  - Invalid xsec.
PRO_TK_BAD_CONTEXT - solid owner is not a composite design model
                     or composite session is not active.

*/

extern ProError ProXSectionCreateDataAlloc( ProXSectionCreateData *r_data );
/*
  Purpose: Allocates ProXSectionCreateData empty data.

  Input Arguments:
    none.

  Output Arguments:
    r_data - ProXSectionCreateData data.

  Return Values:
    PRO_TK_NO_ERROR   - Data successfully allocated.
    PRO_TK_BAD_INPUTS - r_data is NULL.
*/

extern ProError ProXSectionCreateDataFree( ProXSectionCreateData *pp_data );
/*
  Purpose: Releases ProXSectionCreateData data.

  Input Arguments:
    pp_data - Address to ProXSectionCreateData data.

  Output Arguments:
    none.

  Return Values:
    PRO_TK_NO_ERROR   - Data successfully released.
    PRO_TK_BAD_INPUTS - pp_data is NULL.
*/

extern ProError ProXSectionCreateDataQuiltSelSet( 
                                             ProXSectionCreateData p_data,
                                             ProSelection          quilt_sel );
/*
  Purpose: Sets quilt selection into ProXSectionCreateData data.

  Input Arguments:
    p_data    - ProXSectionCreateData data.
    quilt_sel - quilt selection.

  Output Arguments:
    none.

  Return Values:
    PRO_TK_NO_ERROR   - Set successfully completed.
    PRO_TK_BAD_INPUTS - p_data is NULL.
*/

extern ProError ProXSectionCreateDataQuiltSelGet( 
                                         ProXSectionCreateData  p_data,
                                         ProSelection          *r_quilt_sel );
/*
  Purpose: Gets quilt selection from ProXSectionCreateData data.

  Input Arguments:
    p_data - ProXSectionCreateData data.

  Output Arguments:
    r_quilt_sel - Address of quilt selection empty pointer.

  Return Values:
    PRO_TK_NO_ERROR   - Get successfully completed.
    PRO_TK_BAD_INPUTS - p_data is NULL.
*/

extern ProError ProXSectionCreateDataQuiltTypeSet( 
                                            ProXSectionCreateData p_data,
                                            ProXsecCutobj         xsec_type );
/*
  Purpose: Sets quilt xsec type into ProXSectionCreateData data.

  Input Arguments:
    p_data    - ProXSectionCreateData data.
    xsec_type - Either PRO_XSECTYPE_QUILTS or PRO_XSECTYPE_MODELQUILTS.

  Output Arguments:
    none.

  Return Values:
    PRO_TK_NO_ERROR   - Set successfully completed.
    PRO_TK_BAD_INPUTS - p_data is NULL or xsec_type isn't of two allowed types.
*/

extern ProError ProXSectionCreateDataQuiltTypeGet( 
                                         ProXSectionCreateData  p_data,
                                         ProXsecCutobj         *r_xsec_type );
/*
  Purpose: Gets quilt xsec type from ProXSectionCreateData data
           ( Either PRO_XSECTYPE_QUILTS or PRO_XSECTYPE_MODELQUILTS ).

  Input Arguments:
    p_data - ProXSectionCreateData data.

  Output Arguments:
    r_xsec_type - Address of ProXsecCutobj pointer.

  Return Values:
    PRO_TK_NO_ERROR   - Get successfully completed.
    PRO_TK_BAD_INPUTS - p_data is NULL or xsec_type on data isn't of two 
                        allowed types.
*/

extern ProError ProXSectionLaminateCreate( ProSolid              solid_owner, 
                                      ProMdlName            xsec_name,
                                      ProSelection          cutting_plane,
                                      int                   flip,
                                      ProXsecMdlname       *r_xsec );
/*
	Purpose:  Creates a cross section through a datum plane and makes it visible.

	Input Arguments:
        solid_owner   -  Solid in which the xsec is to be created.
        xsec_name     -  Name of the cross section. Name size should be PRO_NAME_SIZE.
        cutting_plane -  Selection of cutting plane. Cutting plane should belong to 
        				 solid_owner.
        flip          -  xsec flip with respect to cutting plane positive normal.

	 Output Arguments:
	    r_xsec        -  Handle to created cross section


  Return Values:
		PRO_TK_NO_ERROR      - Cross section successfully created.
		PRO_TK_BAD_INPUTS    - Invalid input parameter(s).
		PRO_TK_BAD_CONTEXT   - solid owner is not a composite design model
                               or composite session is not active.
		PRO_TK_GENERAL_ERROR - Failed to create cross section.
        PRO_TK_LINE_TOO_LONG - xsec_name is longer than PRO_MDLNAME_SIZE.
 
  See Also:
	  ProXSecGeometryCollect()
*/


extern ProError ProXSectionLaminateScaleGet( ProXsecMdlname  xsec,
                                        double         *p_scale );
/*
	Purpose:  Get the value of the ply section exaggerated scale.

	Input Arguments:
        xsec   - ProXsecMdlname handle.
	
	Output Arguments:
        p_scale       - the exaggerated scale value.


    Return Values:
		PRO_TK_NO_ERROR      - Cross section is valid and scale found.
		PRO_TK_BAD_INPUTS    - Invalid input parameter(s), or 
                                       xsec is not a ply section.

    See Also:
	    ProXSectionLaminateScaleModify()
*/

extern ProError ProXSectionLaminateScaleModify( ProXsecMdlname  xsec,
                                           double          scale );
/*
	Purpose:  Modifies the value of the ply section exaggerated scale.

	Input Arguments:
        xsec   - ProXsecMdlname handle.
        scale  - the exaggerated scale value to set.
		
	Output Arguments:
        none		

    Return Values:
		PRO_TK_NO_ERROR      - Cross section is valid and scale found.
		PRO_TK_BAD_INPUTS    - Invalid input parameter(s), or 
                                       xsec is not a ply section.

    See Also:
	    ProXSectionLaminateScaleGet()
*/

PRO_END_C_DECLS

#endif
