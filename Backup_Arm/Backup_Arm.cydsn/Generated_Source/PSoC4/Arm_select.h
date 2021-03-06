/*******************************************************************************
* File Name: Arm_select.h  
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

#if !defined(CY_PINS_Arm_select_H) /* Pins Arm_select_H */
#define CY_PINS_Arm_select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Arm_select_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Arm_select_Write(uint8 value) ;
void    Arm_select_SetDriveMode(uint8 mode) ;
uint8   Arm_select_ReadDataReg(void) ;
uint8   Arm_select_Read(void) ;
uint8   Arm_select_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Arm_select_DRIVE_MODE_BITS        (3)
#define Arm_select_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Arm_select_DRIVE_MODE_BITS))

#define Arm_select_DM_ALG_HIZ         (0x00u)
#define Arm_select_DM_DIG_HIZ         (0x01u)
#define Arm_select_DM_RES_UP          (0x02u)
#define Arm_select_DM_RES_DWN         (0x03u)
#define Arm_select_DM_OD_LO           (0x04u)
#define Arm_select_DM_OD_HI           (0x05u)
#define Arm_select_DM_STRONG          (0x06u)
#define Arm_select_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Arm_select_MASK               Arm_select__MASK
#define Arm_select_SHIFT              Arm_select__SHIFT
#define Arm_select_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Arm_select_PS                     (* (reg32 *) Arm_select__PS)
/* Port Configuration */
#define Arm_select_PC                     (* (reg32 *) Arm_select__PC)
/* Data Register */
#define Arm_select_DR                     (* (reg32 *) Arm_select__DR)
/* Input Buffer Disable Override */
#define Arm_select_INP_DIS                (* (reg32 *) Arm_select__PC2)


#if defined(Arm_select__INTSTAT)  /* Interrupt Registers */

    #define Arm_select_INTSTAT                (* (reg32 *) Arm_select__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Arm_select_DRIVE_MODE_SHIFT       (0x00u)
#define Arm_select_DRIVE_MODE_MASK        (0x07u << Arm_select_DRIVE_MODE_SHIFT)


#endif /* End Pins Arm_select_H */


/* [] END OF FILE */
