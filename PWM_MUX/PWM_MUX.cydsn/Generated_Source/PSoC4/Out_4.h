/*******************************************************************************
* File Name: Out_4.h  
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

#if !defined(CY_PINS_Out_4_H) /* Pins Out_4_H */
#define CY_PINS_Out_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Out_4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Out_4_Write(uint8 value) ;
void    Out_4_SetDriveMode(uint8 mode) ;
uint8   Out_4_ReadDataReg(void) ;
uint8   Out_4_Read(void) ;
uint8   Out_4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Out_4_DRIVE_MODE_BITS        (3)
#define Out_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Out_4_DRIVE_MODE_BITS))

#define Out_4_DM_ALG_HIZ         (0x00u)
#define Out_4_DM_DIG_HIZ         (0x01u)
#define Out_4_DM_RES_UP          (0x02u)
#define Out_4_DM_RES_DWN         (0x03u)
#define Out_4_DM_OD_LO           (0x04u)
#define Out_4_DM_OD_HI           (0x05u)
#define Out_4_DM_STRONG          (0x06u)
#define Out_4_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Out_4_MASK               Out_4__MASK
#define Out_4_SHIFT              Out_4__SHIFT
#define Out_4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out_4_PS                     (* (reg32 *) Out_4__PS)
/* Port Configuration */
#define Out_4_PC                     (* (reg32 *) Out_4__PC)
/* Data Register */
#define Out_4_DR                     (* (reg32 *) Out_4__DR)
/* Input Buffer Disable Override */
#define Out_4_INP_DIS                (* (reg32 *) Out_4__PC2)


#if defined(Out_4__INTSTAT)  /* Interrupt Registers */

    #define Out_4_INTSTAT                (* (reg32 *) Out_4__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Out_4_DRIVE_MODE_SHIFT       (0x00u)
#define Out_4_DRIVE_MODE_MASK        (0x07u << Out_4_DRIVE_MODE_SHIFT)


#endif /* End Pins Out_4_H */


/* [] END OF FILE */
