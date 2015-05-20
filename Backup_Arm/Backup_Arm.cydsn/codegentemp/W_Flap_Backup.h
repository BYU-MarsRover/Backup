/*******************************************************************************
* File Name: W_Flap_Backup.h  
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

#if !defined(CY_PINS_W_Flap_Backup_H) /* Pins W_Flap_Backup_H */
#define CY_PINS_W_Flap_Backup_H

#include "cytypes.h"
#include "cyfitter.h"
#include "W_Flap_Backup_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    W_Flap_Backup_Write(uint8 value) ;
void    W_Flap_Backup_SetDriveMode(uint8 mode) ;
uint8   W_Flap_Backup_ReadDataReg(void) ;
uint8   W_Flap_Backup_Read(void) ;
uint8   W_Flap_Backup_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define W_Flap_Backup_DRIVE_MODE_BITS        (3)
#define W_Flap_Backup_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - W_Flap_Backup_DRIVE_MODE_BITS))

#define W_Flap_Backup_DM_ALG_HIZ         (0x00u)
#define W_Flap_Backup_DM_DIG_HIZ         (0x01u)
#define W_Flap_Backup_DM_RES_UP          (0x02u)
#define W_Flap_Backup_DM_RES_DWN         (0x03u)
#define W_Flap_Backup_DM_OD_LO           (0x04u)
#define W_Flap_Backup_DM_OD_HI           (0x05u)
#define W_Flap_Backup_DM_STRONG          (0x06u)
#define W_Flap_Backup_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define W_Flap_Backup_MASK               W_Flap_Backup__MASK
#define W_Flap_Backup_SHIFT              W_Flap_Backup__SHIFT
#define W_Flap_Backup_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define W_Flap_Backup_PS                     (* (reg32 *) W_Flap_Backup__PS)
/* Port Configuration */
#define W_Flap_Backup_PC                     (* (reg32 *) W_Flap_Backup__PC)
/* Data Register */
#define W_Flap_Backup_DR                     (* (reg32 *) W_Flap_Backup__DR)
/* Input Buffer Disable Override */
#define W_Flap_Backup_INP_DIS                (* (reg32 *) W_Flap_Backup__PC2)


#if defined(W_Flap_Backup__INTSTAT)  /* Interrupt Registers */

    #define W_Flap_Backup_INTSTAT                (* (reg32 *) W_Flap_Backup__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define W_Flap_Backup_DRIVE_MODE_SHIFT       (0x00u)
#define W_Flap_Backup_DRIVE_MODE_MASK        (0x07u << W_Flap_Backup_DRIVE_MODE_SHIFT)


#endif /* End Pins W_Flap_Backup_H */


/* [] END OF FILE */
