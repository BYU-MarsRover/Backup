/*******************************************************************************
* File Name: Drive_Left_Backup.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Drive_Left_Backup_H) /* Pins Drive_Left_Backup_H */
#define CY_PINS_Drive_Left_Backup_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Drive_Left_Backup_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Drive_Left_Backup_Write(uint8 value) ;
void    Drive_Left_Backup_SetDriveMode(uint8 mode) ;
uint8   Drive_Left_Backup_ReadDataReg(void) ;
uint8   Drive_Left_Backup_Read(void) ;
uint8   Drive_Left_Backup_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Drive_Left_Backup_DRIVE_MODE_BITS        (3)
#define Drive_Left_Backup_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Drive_Left_Backup_DRIVE_MODE_BITS))

#define Drive_Left_Backup_DM_ALG_HIZ         (0x00u)
#define Drive_Left_Backup_DM_DIG_HIZ         (0x01u)
#define Drive_Left_Backup_DM_RES_UP          (0x02u)
#define Drive_Left_Backup_DM_RES_DWN         (0x03u)
#define Drive_Left_Backup_DM_OD_LO           (0x04u)
#define Drive_Left_Backup_DM_OD_HI           (0x05u)
#define Drive_Left_Backup_DM_STRONG          (0x06u)
#define Drive_Left_Backup_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Drive_Left_Backup_MASK               Drive_Left_Backup__MASK
#define Drive_Left_Backup_SHIFT              Drive_Left_Backup__SHIFT
#define Drive_Left_Backup_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Drive_Left_Backup_PS                     (* (reg32 *) Drive_Left_Backup__PS)
/* Port Configuration */
#define Drive_Left_Backup_PC                     (* (reg32 *) Drive_Left_Backup__PC)
/* Data Register */
#define Drive_Left_Backup_DR                     (* (reg32 *) Drive_Left_Backup__DR)
/* Input Buffer Disable Override */
#define Drive_Left_Backup_INP_DIS                (* (reg32 *) Drive_Left_Backup__PC2)


#if defined(Drive_Left_Backup__INTSTAT)  /* Interrupt Registers */

    #define Drive_Left_Backup_INTSTAT                (* (reg32 *) Drive_Left_Backup__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Drive_Left_Backup_DRIVE_MODE_SHIFT       (0x00u)
#define Drive_Left_Backup_DRIVE_MODE_MASK        (0x07u << Drive_Left_Backup_DRIVE_MODE_SHIFT)


#endif /* End Pins Drive_Left_Backup_H */


/* [] END OF FILE */
