/*******************************************************************************
* File Name: Timer_3_PM.c
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

#include "Timer_3.h"

static Timer_3_BACKUP_STRUCT Timer_3_backup;


/*******************************************************************************
* Function Name: Timer_3_SaveConfig
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
void Timer_3_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_3_Sleep
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
void Timer_3_Sleep(void)
{
    if(0u != (Timer_3_BLOCK_CONTROL_REG & Timer_3_MASK))
    {
        Timer_3_backup.enableState = 1u;
    }
    else
    {
        Timer_3_backup.enableState = 0u;
    }

    Timer_3_Stop();
    Timer_3_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_3_RestoreConfig
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
void Timer_3_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_3_Wakeup
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
void Timer_3_Wakeup(void)
{
    Timer_3_RestoreConfig();

    if(0u != Timer_3_backup.enableState)
    {
        Timer_3_Enable();
    }
}


/* [] END OF FILE */
