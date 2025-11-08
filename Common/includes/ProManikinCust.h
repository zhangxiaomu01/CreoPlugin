#ifndef PRO_MAN_CUST
#define PRO_MAN_CUST



#include <ProToolkit.h>
#include <ProParamval.h>
#include <ProSizeConst.h>

PRO_BEGIN_C_DECLS

/*
  This API works with the custom manikin which has to be the top object in
  the current CREO work window. All modifications will be applied to this 
  model immediately. The setting of the dimension influences other manikin 
  dimensions in the same manner as in the Manikin Editor UI. It means that set
  of the height will change to the default all rest dimensions, etc.  

  The list of parameters allowed for modification in customizable manikin.

  ------------------  The dimensions section ----------------------------------

  --- Height and Weight ------------------------------------------------------- 
     "DESIRED_HEIGHT" - "Height" - double value in meter. 
                      The direct dependence - "MODEL_HEIGHT".
                      Drives all manikin dimensions.      
     "DESIRED_WEIGHT" - "Weight" - double value in kilogram. 
                      The direct dependence - "MODEL_WEIGHT".
                      Drives the weigth dependent manikin dimensions. 
                      The "Chest, "Waist", "Thigh" are dependent. 
                      The "Shoulder width" is dependent if it has not been set
                      erlier.
  --- Anthropometric Dimensions, first part ----------------------------------- 
     Only 2 of parameters in this section can be modified. When the user sets 
     1 parameter - 2 other will change. When the user sets 2 parameters - 1
     the reset parameter will change.
     "DESIRED_UPPER_BODY_LENGTH" - "Upper body length" - double value in meter. 
                      The dependence - "MODEL_UPPER_BODY_LENGTH".
     "DESIRED_UPPER_LEG_LENGTH" - "Upper leg length, seated" - double value 
                      in meter. The dependence - "MODEL_UPPER_LEG_LENGTH_SEATED".
     "DESIRED_LOWER_LEG_LENGTH" - "Lower leg length, seated - double value
                      in meter. The dependence - L"MODEL_LOWER_LEG_LENGTH_SEATED".
  --- Anthropometric Dimensions,  second part -------------------------------
     "DESIRED_ARM_LENGTH" - "Arm length" - double value in meter.
                      The dependence - "MODEL_ARM_LENGTH".
     "DESIRED_SHOULDER_WIDTH" - "Shoulder width" - double value in meter. 
                      The dependence - "MODEL_SHOULDER_WIDTH".
     "DESIRED_HAND_LENGTH" - "Hand length" - double value in meter. 
                      The dependence - "MODEL_HAND_LENGTH". 
     "DESIRED_HAND_WIDTH" - "Hand width" - double value in meter.
                      The dependence - "MODEL_HAND_WIDTH".
     "DESIRED_SHOE_LENGTH" - "Shoe length" - double value in meter.
                      The dependence - "MODEL_SHOE_LENGTH".
  --- Circumferences ----------------------------------------------------------
     Optimization is used to achieve this value. As a result getting
     the desired value requires some time.
     "DESIRED_CHEST_CIRCUMFERENCE" - "Chest" - double value in meter.
                      The dependence - "MODEL_CHEST_CIRCUMFERENCE".
     "DESIRED_WAIST_CIRCUMFERENCE" - "Waist" - double value in meter. 
                      The dependence - "MODEL_WAIST_CIRCUMFERENCE".
     "DESIRED_THIGH_CIRCUMFERENCE" - "Thigh" - double value in meter. 
                      The dependence - "MODEL_THIGH_CIRCUMFERENCE".

  ------------------  The attributes section ---------------------------------- 

     "MANIKIN_AGE_GROUP" - "Age group" - ProLine value.
     "MANIKIN_COUNTRY" - "Country" - ProLine value.
     "MANIKIN_DATABASE" - "Data base" - ProLine value.
     "MANIKIN_PERCENTILE" - "Size percentile" - integer value.
     "MANIKIN_VERSION" - "Version" - double value.
     "MODELED_BY" - "Modeled by" - ProLine value.
     "DESCRIPTION" - "Description" - ProLine value. 
*/

typedef struct manikin_edit_var_pair
{
  ProName        param_name; /* See the list of the allowed parameters. */
  ProParamvalue  p_val; 
  ProBool        reset;  /* Reset the parameter to the default value. 
                            In this case, the p_val value will be ignored.
                            For the attributes section, this argument 
                            does nothing. */
} ProManikinEditVarPair;

extern ProError ProManikinCustomize (const ProManikinEditVarPair *vars_array, 
                                     ProName failed_param_name);
/*
   Purpose: This function sets the specified parameters and performs 
            regeneration if required. 
            The logics of parameters update is following:
            height change resets all other dimensions;
            weight change resets 3 or 4 dimemnsions mentioned above;
            any antropometric dim from the 1st part influences all other
            dimensions on this section;
            all other parameters would be left unchanged.
            If required to set the parameter to the default value 
            ProManikinEditVarPair.reset has to be set to PRO_B_TRUE
            Order of the parameters in ProManikinEditVarPair is not important.

   Input Arguments:
      vars_array - ProArray array of ProManikinEditVarPair

   Output Arguments:
      failed_param_name - if the process failed it would contain 
                          the problematic parameter we were unable to satisfy.
   
   Return Values:
      PRO_TK_NO_ERROR      - The function was successful.
      PRO_TK_BAD_CONTEXT   - The cust manikin must be the top window object.
      PRO_TK_BAD_INPUTS    - Invalid input in this case failed_param_name will 
                             return the problematic parameter. 
      PRO_TK_INVALID_TYPE  - ProManikinEditVarPair.p_val does not 
                             match type of ProManikinEditVarPair.ProParamvalue -
                             failed_param_name will be set.
      PRO_TK_NOT_VALID     - A parameter not in bounds or the regeneration 
                             failed - failed_param_name will be set. 
      PRO_TK_GENERAL_ERROR - The function failed by other reason.
*/

PRO_END_C_DECLS

#endif  /* PRO_MAN_CUST */
