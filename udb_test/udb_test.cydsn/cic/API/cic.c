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
#include "`$INSTANCE_NAME`_cic.h"
#include "`$INSTANCE_NAME`_defs.h" 
 
void `$INSTANCE_NAME`_Start()
{
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_A0_PTR, 0x00000001);  
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_D0_PTR, 0);
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_F0_PTR, 5);
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_F0_PTR, 6);
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_F0_PTR, 7);
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_F0_PTR, 8);
}


void `$INSTANCE_NAME`_SetInput(uint32 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_A0_PTR,val);  
} 
 
void `$INSTANCE_NAME`_SetFifo(uint32 val)
{
    CY_SET_REG32(`$INSTANCE_NAME`_Datapath_F0_PTR,val);  
}

uint32 `$INSTANCE_NAME`_GetInput() 
{ 
    return CY_GET_REG32(`$INSTANCE_NAME`_Datapath_A0_PTR); 
} 
 
uint32 `$INSTANCE_NAME`_GetA0(void)
{
    return CY_GET_REG32(`$INSTANCE_NAME`_Datapath_A0_PTR);     
}

uint32 `$INSTANCE_NAME`_GetA1(void)
{
    return CY_GET_REG32(`$INSTANCE_NAME`_Datapath_A1_PTR);     
}

uint32 `$INSTANCE_NAME`_GetD0(void) 
{ 
    return CY_GET_REG32(`$INSTANCE_NAME`_Datapath_D0_PTR); 
} 
/* [] END OF FILE */
