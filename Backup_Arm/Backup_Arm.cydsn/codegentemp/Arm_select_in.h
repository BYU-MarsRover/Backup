/*******************************************************************************
* File Name: Arm_select_in.h  
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

#if !defined(CY_PINS_Arm_select_in_H) /* Pins Arm_select_in_H */
#define CY_PINS_Arm_select_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Arm_select_in_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Arm_select_in_Write(uint8 value) ;
void    Arm_select_in_SetDriveMode(uint8 mode) ;
uint8   Arm_select_in_ReadDataReg(void) ;
uint8   Arm_select_in_Read(void) ;
uint8   Arm_select_in_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Arm_select_in_DRIVE_MODE_BITS        (3)
#define Arm_select_in_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Arm_select_in_DRIVE_MODE_BITS))

#define Arm_select_in_DM_ALG_HIZ         (0x00u)
#define Arm_select_in_DM_DIG_HIZ         (0x01u)
#define Arm_select_in_DM_RES_UP          (0x02u)
#define Arm_select_in_DM_RES_DWN         (0x03u)
#define Arm_select_in_DM_OD_LO           (0x04u)
#define Arm_select_in_DM_OD_HI           (0x05u)
#define Arm_select_in_DM_STRONG          (0x06u)
#define Arm_select_in_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Arm_select_in_MASK               Arm_select_in__MASK
#define Arm_select_in_SHIFT              Arm_select_in__SHIFT
#define Arm_select_in_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Arm_select_in_PS                     (* (reg32 *) Arm_select_in__PS)
/* Port Configuration */
#define Arm_select_in_PC                     (* (reg32 *) Arm_select_in__PC)
/* Data Register */
#define Arm_select_in_DR                     (* (reg32 *) Arm_select_in__DR)
/* Input Buffer Disable Override */
#define Arm_select_in_INP_DIS                (* (reg32 *) Arm_select_in__PC2)


#if defined(Arm_select_in__INTSTAT)  /* Interrupt Registers */

    #define Arm_select_in_INTSTAT                (* (reg32 *) Arm_select_in__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Arm_select_in_DRIVE_MODE_SHIFT       (0x00u)
#define Arm_select_in_DRIVE_MODE_MASK        (0x07u << Arm_select_in_DRIVE_MODE_SHIFT)


#endif /* End Pins Arm_select_in_H */


/* [] END OF FILE */
