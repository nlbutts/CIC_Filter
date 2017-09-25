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

#if !defined (`$INSTANCE_NAME`CIC_H) 
    #define `$INSTANCE_NAME`_CIC_H 
     
#include "cytypes.h" 
#include "cyfitter.h"
   
void `$INSTANCE_NAME`_Start();
void `$INSTANCE_NAME`_SetInput(uint32); 
void `$INSTANCE_NAME`_SetFifo(uint32); 
uint32 `$INSTANCE_NAME`_GetInput(); 
uint32 `$INSTANCE_NAME`_GetA0(void); 
uint32 `$INSTANCE_NAME`_GetA1(void); 
uint32 `$INSTANCE_NAME`_GetD0(void);
 
#endif 
/* [] END OF FILE */
