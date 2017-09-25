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

#define ELEMENTS(x)     (sizeof(x)/sizeof(x[0]))

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    volatile uint32 d0[100];
    volatile uint32 a0[100];
    volatile uint32 a1[100];
    volatile uint8 status[100];
    volatile uint32 index = 0;
    
    memset((void*)d0, 0, sizeof(d0));
    memset((void*)a0, 0, sizeof(a0));
    memset((void*)a1, 0, sizeof(a1));
    memset((void*)status, 0, sizeof(status));
    
    Control_Reg_Write(0);    
    d0[0] = cic_1_GetD0();
    a0[0] = cic_1_GetA0();
    a1[0] = cic_1_GetA1();
    status[0] = Status_Reg_Read();

    cic_1_Start();
    
    Control_Reg_Write(1); 
    for(;;)
    {
        if (index < 100)
        {
            d0[index] = cic_1_GetD0();
            a0[index] = cic_1_GetA0();
            a1[index] = cic_1_GetA1();
            status[index] = Status_Reg_Read();
            index++;
        }
        else
        {
            index = 1000;
        }
        
    }
    
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
