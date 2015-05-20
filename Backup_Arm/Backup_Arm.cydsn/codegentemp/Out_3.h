/*******************************************************************************
* File Name: Out_3.h  
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

#if !defined(CY_PINS_Out_3_H) /* Pins Out_3_H */
#define CY_PINS_Out_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Out_3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Out_3_Write(uint8 value) ;
void    Out_3_SetDriveMode(uint8 mode) ;
uint8   Out_3_ReadDataReg(void) ;
uint8   Out_3_Read(void) ;
uint8   Out_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Out_3_DRIVE_MODE_BITS        (3)
#define Out_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Out_3_DRIVE_MODE_BITS))

#define Out_3_DM_ALG_HIZ         (0x00u)
#define Out_3_DM_DIG_HIZ         (0x01u)
#define Out_3_DM_RES_UP          (0x02u)
#define Out_3_DM_RES_DWN         (0x03u)
#define Out_3_DM_OD_LO           (0x04u)
#define Out_3_DM_OD_HI           (0x05u)
#define Out_3_DM_STRONG          (0x06u)
#define Out_3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Out_3_MASK               Out_3__MASK
#define Out_3_SHIFT              Out_3__SHIFT
#define Out_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out_3_PS                     (* (reg32 *) Out_3__PS)
/* Port Configuration */
#define Out_3_PC                     (* (reg32 *) Out_3__PC)
/* Data Register */
#define Out_3_DR                     (* (reg32 *) Out_3__DR)
/* Input Buffer Disable Override */
#define Out_3_INP_DIS                (* (reg32 *) Out_3__PC2)


#if defined(Out_3__INTSTAT)  /* Interrupt Registers */

    #define Out_3_INTSTAT                (* (reg32 *) Out_3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Out_3_DRIVE_MODE_SHIFT       (0x00u)
#define Out_3_DRIVE_MODE_MASK        (0x07u << Out_3_DRIVE_MODE_SHIFT)


#endif /* End Pins Out_3_H */


/* [] END OF FILE */
