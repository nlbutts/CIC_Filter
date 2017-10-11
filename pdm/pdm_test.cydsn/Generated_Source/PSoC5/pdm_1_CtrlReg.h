/*******************************************************************************
* File Name: pdm_1_CtrlReg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_pdm_1_CtrlReg_H) /* CY_CONTROL_REG_pdm_1_CtrlReg_H */
#define CY_CONTROL_REG_pdm_1_CtrlReg_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} pdm_1_CtrlReg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    pdm_1_CtrlReg_Write(uint8 control) ;
uint8   pdm_1_CtrlReg_Read(void) ;

void pdm_1_CtrlReg_SaveConfig(void) ;
void pdm_1_CtrlReg_RestoreConfig(void) ;
void pdm_1_CtrlReg_Sleep(void) ; 
void pdm_1_CtrlReg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define pdm_1_CtrlReg_Control        (* (reg8 *) pdm_1_CtrlReg_Sync_ctrl_reg__CONTROL_REG )
#define pdm_1_CtrlReg_Control_PTR    (  (reg8 *) pdm_1_CtrlReg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_pdm_1_CtrlReg_H */


/* [] END OF FILE */
