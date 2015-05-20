/*******************************************************************************
* File Name: W_Rotate_MCU.h  
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

#if !defined(CY_PINS_W_Rotate_MCU_H) /* Pins W_Rotate_MCU_H */
#define CY_PINS_W_Rotate_MCU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "W_Rotate_MCU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    W_Rotate_MCU_Write(uint8 value) ;
void    W_Rotate_MCU_SetDriveMode(uint8 mode) ;
uint8   W_Rotate_MCU_ReadDataReg(void) ;
uint8   W_Rotate_MCU_Read(void) ;
uint8   W_Rotate_MCU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define W_Rotate_MCU_DRIVE_MODE_BITS        (3)
#define W_Rotate_MCU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - W_Rotate_MCU_DRIVE_MODE_BITS))

#define W_Rotate_MCU_DM_ALG_HIZ         (0x00u)
#define W_Rotate_MCU_DM_DIG_HIZ         (0x01u)
#define W_Rotate_MCU_DM_RES_UP          (0x02u)
#define W_Rotate_MCU_DM_RES_DWN         (0x03u)
#define W_Rotate_MCU_DM_OD_LO           (0x04u)
#define W_Rotate_MCU_DM_OD_HI           (0x05u)
#define W_Rotate_MCU_DM_STRONG          (0x06u)
#define W_Rotate_MCU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define W_Rotate_MCU_MASK               W_Rotate_MCU__MASK
#define W_Rotate_MCU_SHIFT              W_Rotate_MCU__SHIFT
#define W_Rotate_MCU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define W_Rotate_MCU_PS                     (* (reg32 *) W_Rotate_MCU__PS)
/* Port Configuration */
#define W_Rotate_MCU_PC                     (* (reg32 *) W_Rotate_MCU__PC)
/* Data Register */
#define W_Rotate_MCU_DR                     (* (reg32 *) W_Rotate_MCU__DR)
/* Input Buffer Disable Override */
#define W_Rotate_MCU_INP_DIS                (* (reg32 *) W_Rotate_MCU__PC2)


#if defined(W_Rotate_MCU__INTSTAT)  /* Interrupt Registers */

    #define W_Rotate_MCU_INTSTAT                (* (reg32 *) W_Rotate_MCU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define W_Rotate_MCU_DRIVE_MODE_SHIFT       (0x00u)
#define W_Rotate_MCU_DRIVE_MODE_MASK        (0x07u << W_Rotate_MCU_DRIVE_MODE_SHIFT)


#endif /* End Pins W_Rotate_MCU_H */


/* [] END OF FILE */
