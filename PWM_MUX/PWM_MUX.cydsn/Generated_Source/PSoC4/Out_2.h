/*******************************************************************************
* File Name: Out_2.h  
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

#if !defined(CY_PINS_Out_2_H) /* Pins Out_2_H */
#define CY_PINS_Out_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Out_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Out_2_Write(uint8 value) ;
void    Out_2_SetDriveMode(uint8 mode) ;
uint8   Out_2_ReadDataReg(void) ;
uint8   Out_2_Read(void) ;
uint8   Out_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Out_2_DRIVE_MODE_BITS        (3)
#define Out_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Out_2_DRIVE_MODE_BITS))

#define Out_2_DM_ALG_HIZ         (0x00u)
#define Out_2_DM_DIG_HIZ         (0x01u)
#define Out_2_DM_RES_UP          (0x02u)
#define Out_2_DM_RES_DWN         (0x03u)
#define Out_2_DM_OD_LO           (0x04u)
#define Out_2_DM_OD_HI           (0x05u)
#define Out_2_DM_STRONG          (0x06u)
#define Out_2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Out_2_MASK               Out_2__MASK
#define Out_2_SHIFT              Out_2__SHIFT
#define Out_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out_2_PS                     (* (reg32 *) Out_2__PS)
/* Port Configuration */
#define Out_2_PC                     (* (reg32 *) Out_2__PC)
/* Data Register */
#define Out_2_DR                     (* (reg32 *) Out_2__DR)
/* Input Buffer Disable Override */
#define Out_2_INP_DIS                (* (reg32 *) Out_2__PC2)


#if defined(Out_2__INTSTAT)  /* Interrupt Registers */

    #define Out_2_INTSTAT                (* (reg32 *) Out_2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Out_2_DRIVE_MODE_SHIFT       (0x00u)
#define Out_2_DRIVE_MODE_MASK        (0x07u << Out_2_DRIVE_MODE_SHIFT)


#endif /* End Pins Out_2_H */


/* [] END OF FILE */
