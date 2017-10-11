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
#include "`$INSTANCE_NAME`_pdm.h" 
#include "`$INSTANCE_NAME`_defs.h" 
  
uint8 `$INSTANCE_NAME`_GetOutput(void) 
{ 
    return CY_GET_REG8(`$INSTANCE_NAME`_Datapath_F0_PTR); 
} 

/* [] END OF FILE */
