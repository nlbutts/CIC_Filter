/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "cytypes.h" 
#include "pdm_1_pdm.h" 
#include "pdm_1_defs.h" 
  
uint8 pdm_1_GetOutput(void) 
{ 
    return CY_GET_REG8(pdm_1_Datapath_F0_PTR); 
} 

/* [] END OF FILE */
