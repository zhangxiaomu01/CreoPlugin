#ifndef PRO_VOL_INTF
#define PRO_VOL_INTF



#include <ProSelection.h>
#include <ProObjects.h>
#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

typedef struct volume_intf_data *ProVolumeInterferenceData;  

typedef struct ProVolumeIntfInfo
{
  ProAsmcomppath comp;                  /*component interfering with the quilt*/
  ProVolumeInterferenceData intf_data; /* Resulting volume interference data */
} ProVolumeInterferenceInfo;

extern ProError ProVolumeInterferenceCompute (ProSelection quilt, 
                    ProVolumeInterferenceInfo **p_intf_infos);
/*
  Purpose: This function computes volume interference of the selected closed 
           quilt with the assembly as it is done in the Volume Interference UI.

      
Input Arguments:
           quilt - The quilt with which the interefrance should be computed
      
Output Arguments:
           p_intf_infos - pointer to a ProArray (allocated inside) where
                          the interference results will be stored,
                          users need to free the allocated array using 
                          ProVolumeInterferenceInfoArrayFree


Return Values:
           PRO_TK_NO_ERROR      - The function succeeded.
           PRO_TK_GENERAL_ERROR - An error is encountered.
           PRO_TK_BAD_INPUTS    - The input argument is invalid.
See Also:
        ProVolumeInterferenceInfoArrayFree()
*/

extern ProError ProVolumeInterferenceBodiesGet (
                    ProVolumeInterferenceData interf_data,
                    ProSolidBody **r_bodies);
/*
  Purpose: 
          This function should be called after ProVolumeInterferenceCompute().
          Given the interference data of a component part, it obtains the set
          of that part's solid bodies which participate in the interference.

Input Arguments:
          interf_data - pointer to the interference data for the corresponding 
                        component that interferes with the quilt

Output Arguments:
          r_bodies    - pointer to the array of ProSolidBody structures which is
                        allocated by the function (as ProArray); may not be NULL

Return Values:
          PRO_TK_NO_ERROR      - The function succeeded.
          PRO_TK_GENERAL_ERROR - A general error is encountered.
          PRO_TK_BAD_INPUTS    - An argument is invalid.
          PRO_TK_E_NOT_FOUND   - Could not find any valid bodies in the
                                 supplied data
*/

extern ProError ProVolumeInterferenceDisplay (
                    ProVolumeInterferenceData interf_data,
                    ProColortype color, ProBool hilite);
/*
  Purpose: 
          This function should be called after ProVolumeInterferenceCompute().
          It will display/hide the curves and surfaces that interfere 
          with the closed quilt that was selected by user. 
      
Input Arguments:
          interf_data - pointer to the interference data for the corresponding 
                        component that interfere with the quilt
          color       - The preferred color for highlighting the ineterference
          hilite      - PRO_B_TRUE for displaying or PRO_B_FALSE for hiding
                        the current component interference data.
             
Output Arguments:
                  None
      
Return Values:
              PRO_TK_NO_ERROR      - The function succeeded.
              PRO_TK_GENERAL_ERROR - A general error is encountered.
              PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/

extern ProError ProVolumeInterferenceDisplayForBody (
                    ProVolumeInterferenceData interf_data, ProSolidBody *p_body,
                    ProColortype color, ProBool hilite);
/*
  Purpose: 
          This function should be called after ProVolumeInterferenceCompute().
          It will display/hide the given solid body's curves and surfaces that
          interfere with the closed quilt that was selected by user.
      
Input Arguments:
          interf_data - pointer to the interference data for the corresponding 
                        component that interferes with the quilt
          p_body      - pointer to the desired solid body in that component
          color       - The preferred color for highlighting the ineterference
          hilite      - PRO_B_TRUE for displaying or PRO_B_FALSE for hiding
                        the given body's interference geometry.

Output Arguments:
          None

Return Values:
          PRO_TK_NO_ERROR      - The function succeeded.
          PRO_TK_GENERAL_ERROR - A general error is encountered.
          PRO_TK_BAD_INPUTS    - An input argument is invalid.
          PRO_TK_E_NOT_FOUND   - The given body doesn't interfere with the quilt
*/
        
extern ProError ProVolumeInterferenceInfoArrayFree (
                    ProVolumeInterferenceInfo *p_intf_infos);
/*
  Purpose: This function frees the memory that was allocated by 
           ProVolumeInterferenceCompute().
           Call this API to remove the interference highlighted by the function
           ProVolumeInterferenceDisplay().
           This function also refreshes the screen.
		   This API is supported in DLL mode only.

Input Arguments:
           p_intf_infos - pointer to the interference data array that is no
           longer needed and should be freed.
		  
Output Arguments:
                  None
      
Return Values:
             PRO_TK_NO_ERROR      - The function succeeded.
             PRO_TK_GENERAL_ERROR - A general error is encountered.
             PRO_TK_BAD_INPUTS    - Pointer to the interference data array is invalid.

*/

PRO_END_C_DECLS

#endif 

