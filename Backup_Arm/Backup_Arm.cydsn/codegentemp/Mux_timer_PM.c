/*******************************************************************************
* File Name: Mux_timer_PM.c
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

#include "Mux_timer.h"

static Mux_timer_BACKUP_STRUCT Mux_timer_backup;


/*******************************************************************************
* Function Name: Mux_timer_SaveConfig
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
void Mux_timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Mux_timer_Sleep
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
void Mux_timer_Sleep(void)
{
    if(0u != (Mux_timer_BLOCK_CONTROL_REG & Mux_timer_MASK))
    {
        Mux_timer_backup.enableState = 1u;
    }
    else
    {
        Mux_timer_backup.enableState = 0u;
    }

    Mux_timer_Stop();
    Mux_timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Mux_timer_RestoreConfig
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
void Mux_timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Mux_timer_Wakeup
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
void Mux_timer_Wakeup(void)
{
    Mux_timer_RestoreConfig();

    if(0u != Mux_timer_backup.enableState)
    {
        Mux_timer_Enable();
    }
}


/* [] END OF FILE */
