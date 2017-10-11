/*******************************************************************************
* File Name: pdm_1_CtrlReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "pdm_1_CtrlReg.h"

/* Check for removal by optimization */
#if !defined(pdm_1_CtrlReg_Sync_ctrl_reg__REMOVED)

static pdm_1_CtrlReg_BACKUP_STRUCT  pdm_1_CtrlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: pdm_1_CtrlReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pdm_1_CtrlReg_SaveConfig(void) 
{
    pdm_1_CtrlReg_backup.controlState = pdm_1_CtrlReg_Control;
}


/*******************************************************************************
* Function Name: pdm_1_CtrlReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void pdm_1_CtrlReg_RestoreConfig(void) 
{
     pdm_1_CtrlReg_Control = pdm_1_CtrlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: pdm_1_CtrlReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pdm_1_CtrlReg_Sleep(void) 
{
    pdm_1_CtrlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: pdm_1_CtrlReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pdm_1_CtrlReg_Wakeup(void)  
{
    pdm_1_CtrlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
