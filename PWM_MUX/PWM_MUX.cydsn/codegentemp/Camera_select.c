/*******************************************************************************
* File Name: Camera_select.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Camera_select.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Camera_select_PC =   (Camera_select_PC & \
                                (uint32)(~(uint32)(Camera_select_DRIVE_MODE_IND_MASK << (Camera_select_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Camera_select_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Camera_select_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Camera_select_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Camera_select_DR & (uint8)(~Camera_select_MASK));
    drVal = (drVal | ((uint8)(value << Camera_select_SHIFT) & Camera_select_MASK));
    Camera_select_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Camera_select_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Camera_select_DM_STRONG     Strong Drive 
*  Camera_select_DM_OD_HI      Open Drain, Drives High 
*  Camera_select_DM_OD_LO      Open Drain, Drives Low 
*  Camera_select_DM_RES_UP     Resistive Pull Up 
*  Camera_select_DM_RES_DWN    Resistive Pull Down 
*  Camera_select_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Camera_select_DM_DIG_HIZ    High Impedance Digital 
*  Camera_select_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Camera_select_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Camera_select__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Camera_select_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Camera_select_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Camera_select_Read(void) 
{
    return (uint8)((Camera_select_PS & Camera_select_MASK) >> Camera_select_SHIFT);
}


/*******************************************************************************
* Function Name: Camera_select_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Camera_select_ReadDataReg(void) 
{
    return (uint8)((Camera_select_DR & Camera_select_MASK) >> Camera_select_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Camera_select_INTSTAT) 

    /*******************************************************************************
    * Function Name: Camera_select_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Camera_select_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Camera_select_INTSTAT & Camera_select_MASK);
		Camera_select_INTSTAT = maskedStatus;
        return maskedStatus >> Camera_select_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
