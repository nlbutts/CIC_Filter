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
#include "project.h"

int main(void)
{
    volatile uint8 data;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    pdm_1_CtrlReg_Write(0);    
    Control_Reg_1_Write(0);
    Control_Reg_1_Write(3);    
    data = pdm_1_GetOutput();    
    Control_Reg_1_Write(0);    
    Control_Reg_1_Write(1);
    data = pdm_1_GetOutput();    
    Control_Reg_1_Write(2);

    // Test falling edge
    pdm_1_CtrlReg_Write(1);    
    Control_Reg_1_Write(3);    
    Control_Reg_1_Write(2);
    data = pdm_1_GetOutput();    
    Control_Reg_1_Write(1);
    Control_Reg_1_Write(0);    
    data = pdm_1_GetOutput();    
    Control_Reg_1_Write(0);

    // Test FIFO
    pdm_1_CtrlReg_Write(0);    
    Control_Reg_1_Write(0);
    Control_Reg_1_Write(3);    

    Control_Reg_1_Write(0);    
    Control_Reg_1_Write(1);

    Control_Reg_1_Write(0);
    Control_Reg_1_Write(3);    

    Control_Reg_1_Write(0);    
    Control_Reg_1_Write(1);

    data = pdm_1_GetOutput();    
    data = pdm_1_GetOutput();    
    data = pdm_1_GetOutput();    
    data = pdm_1_GetOutput();    

    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
