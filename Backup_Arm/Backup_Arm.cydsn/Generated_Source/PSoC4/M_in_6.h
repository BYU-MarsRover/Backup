/*******************************************************************************
* File Name: M_in_6.h  
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

#if !defined(CY_PINS_M_in_6_H) /* Pins M_in_6_H */
#define CY_PINS_M_in_6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "M_in_6_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    M_in_6_Write(uint8 value) ;
void    M_in_6_SetDriveMode(uint8 mode) ;
uint8   M_in_6_ReadDataReg(void) ;
uint8   M_in_6_Read(void) ;
uint8   M_in_6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define M_in_6_DRIVE_MODE_BITS        (3)
#define M_in_6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - M_in_6_DRIVE_MODE_BITS))

#define M_in_6_DM_ALG_HIZ         (0x00u)
#define M_in_6_DM_DIG_HIZ         (0x01u)
#define M_in_6_DM_RES_UP          (0x02u)
#define M_in_6_DM_RES_DWN         (0x03u)
#define M_in_6_DM_OD_LO           (0x04u)
#define M_in_6_DM_OD_HI           (0x05u)
#define M_in_6_DM_STRONG          (0x06u)
#define M_in_6_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define M_in_6_MASK               M_in_6__MASK
#define M_in_6_SHIFT              M_in_6__SHIFT
#define M_in_6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M_in_6_PS                     (* (reg32 *) M_in_6__PS)
/* Port Configuration */
#define M_in_6_PC                     (* (reg32 *) M_in_6__PC)
/* Data Register */
#define M_in_6_DR                     (* (reg32 *) M_in_6__DR)
/* Input Buffer Disable Override */
#define M_in_6_INP_DIS                (* (reg32 *) M_in_6__PC2)


#if defined(M_in_6__INTSTAT)  /* Interrupt Registers */

    #define M_in_6_INTSTAT                (* (reg32 *) M_in_6__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define M_in_6_DRIVE_MODE_SHIFT       (0x00u)
#define M_in_6_DRIVE_MODE_MASK        (0x07u << M_in_6_DRIVE_MODE_SHIFT)


#endif /* End Pins M_in_6_H */


/* [] END OF FILE */
