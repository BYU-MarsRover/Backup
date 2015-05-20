/*******************************************************************************
* File Name: Arm_select_timer_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Arm_select_timer.h"

static Arm_select_timer_BACKUP_STRUCT Arm_select_timer_backup;


/*******************************************************************************
* Function Name: Arm_select_timer_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Arm_select_timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Arm_select_timer_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Arm_select_timer_Sleep(void)
{
    if(0u != (Arm_select_timer_BLOCK_CONTROL_REG & Arm_select_timer_MASK))
    {
        Arm_select_timer_backup.enableState = 1u;
    }
    else
    {
        Arm_select_timer_backup.enableState = 0u;
    }

    Arm_select_timer_Stop();
    Arm_select_timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Arm_select_timer_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Arm_select_timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Arm_select_timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Arm_select_timer_Wakeup(void)
{
    Arm_select_timer_RestoreConfig();

    if(0u != Arm_select_timer_backup.enableState)
    {
        Arm_select_timer_Enable();
    }
}


/* [] END OF FILE */
