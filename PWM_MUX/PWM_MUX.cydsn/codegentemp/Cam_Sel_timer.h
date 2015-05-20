/*******************************************************************************
* File Name: Cam_Sel_timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Cam_Sel_timer
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_Cam_Sel_timer_H)
#define CY_TCPWM_Cam_Sel_timer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Cam_Sel_timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Cam_Sel_timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Cam_Sel_timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Cam_Sel_timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Cam_Sel_timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Cam_Sel_timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Cam_Sel_timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Cam_Sel_timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Cam_Sel_timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Cam_Sel_timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Cam_Sel_timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Cam_Sel_timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Cam_Sel_timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Cam_Sel_timer_TC_RUN_MODE                    (0lu)
#define Cam_Sel_timer_TC_COUNTER_MODE                (0lu)
#define Cam_Sel_timer_TC_COMP_CAP_MODE               (2lu)
#define Cam_Sel_timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Cam_Sel_timer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Cam_Sel_timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Cam_Sel_timer_TC_START_SIGNAL_MODE           (0lu)
#define Cam_Sel_timer_TC_STOP_SIGNAL_MODE            (1lu)
#define Cam_Sel_timer_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Cam_Sel_timer_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Cam_Sel_timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Cam_Sel_timer_TC_START_SIGNAL_PRESENT        (1lu)
#define Cam_Sel_timer_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Cam_Sel_timer_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Cam_Sel_timer_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define Cam_Sel_timer_PWM_KILL_EVENT                 (0lu)
#define Cam_Sel_timer_PWM_STOP_EVENT                 (0lu)
#define Cam_Sel_timer_PWM_MODE                       (4lu)
#define Cam_Sel_timer_PWM_OUT_N_INVERT               (0lu)
#define Cam_Sel_timer_PWM_OUT_INVERT                 (0lu)
#define Cam_Sel_timer_PWM_ALIGN                      (0lu)
#define Cam_Sel_timer_PWM_RUN_MODE                   (0lu)
#define Cam_Sel_timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Cam_Sel_timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Cam_Sel_timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Cam_Sel_timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Cam_Sel_timer_PWM_START_SIGNAL_MODE          (0lu)
#define Cam_Sel_timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Cam_Sel_timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Cam_Sel_timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Cam_Sel_timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Cam_Sel_timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Cam_Sel_timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Cam_Sel_timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Cam_Sel_timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Cam_Sel_timer_TC_PERIOD_VALUE                (65535lu)
#define Cam_Sel_timer_TC_COMPARE_VALUE               (65535lu)
#define Cam_Sel_timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Cam_Sel_timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Cam_Sel_timer_PWM_PERIOD_VALUE               (65535lu)
#define Cam_Sel_timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Cam_Sel_timer_PWM_PERIOD_SWAP                (0lu)
#define Cam_Sel_timer_PWM_COMPARE_VALUE              (65535lu)
#define Cam_Sel_timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Cam_Sel_timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Cam_Sel_timer__LEFT 0
#define Cam_Sel_timer__RIGHT 1
#define Cam_Sel_timer__CENTER 2
#define Cam_Sel_timer__ASYMMETRIC 3

#define Cam_Sel_timer__X1 0
#define Cam_Sel_timer__X2 1
#define Cam_Sel_timer__X4 2

#define Cam_Sel_timer__PWM 4
#define Cam_Sel_timer__PWM_DT 5
#define Cam_Sel_timer__PWM_PR 6

#define Cam_Sel_timer__INVERSE 1
#define Cam_Sel_timer__DIRECT 0

#define Cam_Sel_timer__CAPTURE 2
#define Cam_Sel_timer__COMPARE 0

#define Cam_Sel_timer__TRIG_LEVEL 3
#define Cam_Sel_timer__TRIG_RISING 0
#define Cam_Sel_timer__TRIG_FALLING 1
#define Cam_Sel_timer__TRIG_BOTH 2

#define Cam_Sel_timer__INTR_MASK_TC 1
#define Cam_Sel_timer__INTR_MASK_CC_MATCH 2
#define Cam_Sel_timer__INTR_MASK_NONE 0
#define Cam_Sel_timer__INTR_MASK_TC_CC 3

#define Cam_Sel_timer__UNCONFIG 8
#define Cam_Sel_timer__TIMER 1
#define Cam_Sel_timer__QUAD 3
#define Cam_Sel_timer__PWM_SEL 7

#define Cam_Sel_timer__COUNT_UP 0
#define Cam_Sel_timer__COUNT_DOWN 1
#define Cam_Sel_timer__COUNT_UPDOWN0 2
#define Cam_Sel_timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Cam_Sel_timer_PRESCALE_DIVBY1                ((uint32)(0u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY2                ((uint32)(1u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY4                ((uint32)(2u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY8                ((uint32)(3u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY16               ((uint32)(4u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY32               ((uint32)(5u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY64               ((uint32)(6u << Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_PRESCALE_DIVBY128              ((uint32)(7u << Cam_Sel_timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Cam_Sel_timer_MODE_TIMER_COMPARE             ((uint32)(Cam_Sel_timer__COMPARE         <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))
#define Cam_Sel_timer_MODE_TIMER_CAPTURE             ((uint32)(Cam_Sel_timer__CAPTURE         <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))
#define Cam_Sel_timer_MODE_QUAD                      ((uint32)(Cam_Sel_timer__QUAD            <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))
#define Cam_Sel_timer_MODE_PWM                       ((uint32)(Cam_Sel_timer__PWM             <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))
#define Cam_Sel_timer_MODE_PWM_DT                    ((uint32)(Cam_Sel_timer__PWM_DT          <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))
#define Cam_Sel_timer_MODE_PWM_PR                    ((uint32)(Cam_Sel_timer__PWM_PR          <<  \
                                                                  Cam_Sel_timer_MODE_SHIFT))

/* Quad Modes */
#define Cam_Sel_timer_MODE_X1                        ((uint32)(Cam_Sel_timer__X1              <<  \
                                                                  Cam_Sel_timer_QUAD_MODE_SHIFT))
#define Cam_Sel_timer_MODE_X2                        ((uint32)(Cam_Sel_timer__X2              <<  \
                                                                  Cam_Sel_timer_QUAD_MODE_SHIFT))
#define Cam_Sel_timer_MODE_X4                        ((uint32)(Cam_Sel_timer__X4              <<  \
                                                                  Cam_Sel_timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Cam_Sel_timer_COUNT_UP                       ((uint32)(Cam_Sel_timer__COUNT_UP        <<  \
                                                                  Cam_Sel_timer_UPDOWN_SHIFT))
#define Cam_Sel_timer_COUNT_DOWN                     ((uint32)(Cam_Sel_timer__COUNT_DOWN      <<  \
                                                                  Cam_Sel_timer_UPDOWN_SHIFT))
#define Cam_Sel_timer_COUNT_UPDOWN0                  ((uint32)(Cam_Sel_timer__COUNT_UPDOWN0   <<  \
                                                                  Cam_Sel_timer_UPDOWN_SHIFT))
#define Cam_Sel_timer_COUNT_UPDOWN1                  ((uint32)(Cam_Sel_timer__COUNT_UPDOWN1   <<  \
                                                                  Cam_Sel_timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Cam_Sel_timer_INVERT_LINE                    ((uint32)(Cam_Sel_timer__INVERSE         <<  \
                                                                  Cam_Sel_timer_INV_OUT_SHIFT))
#define Cam_Sel_timer_INVERT_LINE_N                  ((uint32)(Cam_Sel_timer__INVERSE         <<  \
                                                                  Cam_Sel_timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Cam_Sel_timer_TRIG_RISING                    ((uint32)Cam_Sel_timer__TRIG_RISING)
#define Cam_Sel_timer_TRIG_FALLING                   ((uint32)Cam_Sel_timer__TRIG_FALLING)
#define Cam_Sel_timer_TRIG_BOTH                      ((uint32)Cam_Sel_timer__TRIG_BOTH)
#define Cam_Sel_timer_TRIG_LEVEL                     ((uint32)Cam_Sel_timer__TRIG_LEVEL)

/* Interrupt mask */
#define Cam_Sel_timer_INTR_MASK_TC                   ((uint32)Cam_Sel_timer__INTR_MASK_TC)
#define Cam_Sel_timer_INTR_MASK_CC_MATCH             ((uint32)Cam_Sel_timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Cam_Sel_timer_CC_MATCH_SET                   (0x00u)
#define Cam_Sel_timer_CC_MATCH_CLEAR                 (0x01u)
#define Cam_Sel_timer_CC_MATCH_INVERT                (0x02u)
#define Cam_Sel_timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Cam_Sel_timer_OVERLOW_SET                    (0x00u)
#define Cam_Sel_timer_OVERLOW_CLEAR                  (0x04u)
#define Cam_Sel_timer_OVERLOW_INVERT                 (0x08u)
#define Cam_Sel_timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Cam_Sel_timer_UNDERFLOW_SET                  (0x00u)
#define Cam_Sel_timer_UNDERFLOW_CLEAR                (0x10u)
#define Cam_Sel_timer_UNDERFLOW_INVERT               (0x20u)
#define Cam_Sel_timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Cam_Sel_timer_PWM_MODE_LEFT                  (Cam_Sel_timer_CC_MATCH_CLEAR        |   \
                                                         Cam_Sel_timer_OVERLOW_SET           |   \
                                                         Cam_Sel_timer_UNDERFLOW_NO_CHANGE)
#define Cam_Sel_timer_PWM_MODE_RIGHT                 (Cam_Sel_timer_CC_MATCH_SET          |   \
                                                         Cam_Sel_timer_OVERLOW_NO_CHANGE     |   \
                                                         Cam_Sel_timer_UNDERFLOW_CLEAR)
#define Cam_Sel_timer_PWM_MODE_ASYM                  (Cam_Sel_timer_CC_MATCH_INVERT       |   \
                                                         Cam_Sel_timer_OVERLOW_SET           |   \
                                                         Cam_Sel_timer_UNDERFLOW_CLEAR)

#if (Cam_Sel_timer_CY_TCPWM_V2)
    #if(Cam_Sel_timer_CY_TCPWM_4000)
        #define Cam_Sel_timer_PWM_MODE_CENTER                (Cam_Sel_timer_CC_MATCH_INVERT       |   \
                                                                 Cam_Sel_timer_OVERLOW_NO_CHANGE     |   \
                                                                 Cam_Sel_timer_UNDERFLOW_CLEAR)
    #else
        #define Cam_Sel_timer_PWM_MODE_CENTER                (Cam_Sel_timer_CC_MATCH_INVERT       |   \
                                                                 Cam_Sel_timer_OVERLOW_SET           |   \
                                                                 Cam_Sel_timer_UNDERFLOW_CLEAR)
    #endif /* (Cam_Sel_timer_CY_TCPWM_4000) */
#else
    #define Cam_Sel_timer_PWM_MODE_CENTER                (Cam_Sel_timer_CC_MATCH_INVERT       |   \
                                                             Cam_Sel_timer_OVERLOW_NO_CHANGE     |   \
                                                             Cam_Sel_timer_UNDERFLOW_CLEAR)
#endif /* (Cam_Sel_timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Cam_Sel_timer_CMD_CAPTURE                    (0u)
#define Cam_Sel_timer_CMD_RELOAD                     (8u)
#define Cam_Sel_timer_CMD_STOP                       (16u)
#define Cam_Sel_timer_CMD_START                      (24u)

/* Status */
#define Cam_Sel_timer_STATUS_DOWN                    (1u)
#define Cam_Sel_timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Cam_Sel_timer_Init(void);
void   Cam_Sel_timer_Enable(void);
void   Cam_Sel_timer_Start(void);
void   Cam_Sel_timer_Stop(void);

void   Cam_Sel_timer_SetMode(uint32 mode);
void   Cam_Sel_timer_SetCounterMode(uint32 counterMode);
void   Cam_Sel_timer_SetPWMMode(uint32 modeMask);
void   Cam_Sel_timer_SetQDMode(uint32 qdMode);

void   Cam_Sel_timer_SetPrescaler(uint32 prescaler);
void   Cam_Sel_timer_TriggerCommand(uint32 mask, uint32 command);
void   Cam_Sel_timer_SetOneShot(uint32 oneShotEnable);
uint32 Cam_Sel_timer_ReadStatus(void);

void   Cam_Sel_timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Cam_Sel_timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Cam_Sel_timer_SetPWMDeadTime(uint32 deadTime);
void   Cam_Sel_timer_SetPWMInvert(uint32 mask);

void   Cam_Sel_timer_SetInterruptMode(uint32 interruptMask);
uint32 Cam_Sel_timer_GetInterruptSourceMasked(void);
uint32 Cam_Sel_timer_GetInterruptSource(void);
void   Cam_Sel_timer_ClearInterrupt(uint32 interruptMask);
void   Cam_Sel_timer_SetInterrupt(uint32 interruptMask);

void   Cam_Sel_timer_WriteCounter(uint32 count);
uint32 Cam_Sel_timer_ReadCounter(void);

uint32 Cam_Sel_timer_ReadCapture(void);
uint32 Cam_Sel_timer_ReadCaptureBuf(void);

void   Cam_Sel_timer_WritePeriod(uint32 period);
uint32 Cam_Sel_timer_ReadPeriod(void);
void   Cam_Sel_timer_WritePeriodBuf(uint32 periodBuf);
uint32 Cam_Sel_timer_ReadPeriodBuf(void);

void   Cam_Sel_timer_WriteCompare(uint32 compare);
uint32 Cam_Sel_timer_ReadCompare(void);
void   Cam_Sel_timer_WriteCompareBuf(uint32 compareBuf);
uint32 Cam_Sel_timer_ReadCompareBuf(void);

void   Cam_Sel_timer_SetPeriodSwap(uint32 swapEnable);
void   Cam_Sel_timer_SetCompareSwap(uint32 swapEnable);

void   Cam_Sel_timer_SetCaptureMode(uint32 triggerMode);
void   Cam_Sel_timer_SetReloadMode(uint32 triggerMode);
void   Cam_Sel_timer_SetStartMode(uint32 triggerMode);
void   Cam_Sel_timer_SetStopMode(uint32 triggerMode);
void   Cam_Sel_timer_SetCountMode(uint32 triggerMode);

void   Cam_Sel_timer_SaveConfig(void);
void   Cam_Sel_timer_RestoreConfig(void);
void   Cam_Sel_timer_Sleep(void);
void   Cam_Sel_timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Cam_Sel_timer_BLOCK_CONTROL_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Cam_Sel_timer_BLOCK_CONTROL_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Cam_Sel_timer_COMMAND_REG                    (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Cam_Sel_timer_COMMAND_PTR                    ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Cam_Sel_timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Cam_Sel_timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Cam_Sel_timer_CONTROL_REG                    (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CTRL )
#define Cam_Sel_timer_CONTROL_PTR                    ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CTRL )
#define Cam_Sel_timer_STATUS_REG                     (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__STATUS )
#define Cam_Sel_timer_STATUS_PTR                     ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__STATUS )
#define Cam_Sel_timer_COUNTER_REG                    (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Cam_Sel_timer_COUNTER_PTR                    ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Cam_Sel_timer_COMP_CAP_REG                   (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CC )
#define Cam_Sel_timer_COMP_CAP_PTR                   ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CC )
#define Cam_Sel_timer_COMP_CAP_BUF_REG               (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Cam_Sel_timer_COMP_CAP_BUF_PTR               ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Cam_Sel_timer_PERIOD_REG                     (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Cam_Sel_timer_PERIOD_PTR                     ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Cam_Sel_timer_PERIOD_BUF_REG                 (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Cam_Sel_timer_PERIOD_BUF_PTR                 ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Cam_Sel_timer_TRIG_CONTROL0_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Cam_Sel_timer_TRIG_CONTROL0_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Cam_Sel_timer_TRIG_CONTROL1_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Cam_Sel_timer_TRIG_CONTROL1_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Cam_Sel_timer_TRIG_CONTROL2_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Cam_Sel_timer_TRIG_CONTROL2_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Cam_Sel_timer_INTERRUPT_REQ_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR )
#define Cam_Sel_timer_INTERRUPT_REQ_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR )
#define Cam_Sel_timer_INTERRUPT_SET_REG              (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Cam_Sel_timer_INTERRUPT_SET_PTR              ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Cam_Sel_timer_INTERRUPT_MASK_REG             (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Cam_Sel_timer_INTERRUPT_MASK_PTR             ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Cam_Sel_timer_INTERRUPT_MASKED_REG           (*(reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Cam_Sel_timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Cam_Sel_timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Cam_Sel_timer_MASK                           ((uint32)Cam_Sel_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Cam_Sel_timer_RELOAD_CC_SHIFT                (0u)
#define Cam_Sel_timer_RELOAD_PERIOD_SHIFT            (1u)
#define Cam_Sel_timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Cam_Sel_timer_PWM_STOP_KILL_SHIFT            (3u)
#define Cam_Sel_timer_PRESCALER_SHIFT                (8u)
#define Cam_Sel_timer_UPDOWN_SHIFT                   (16u)
#define Cam_Sel_timer_ONESHOT_SHIFT                  (18u)
#define Cam_Sel_timer_QUAD_MODE_SHIFT                (20u)
#define Cam_Sel_timer_INV_OUT_SHIFT                  (20u)
#define Cam_Sel_timer_INV_COMPL_OUT_SHIFT            (21u)
#define Cam_Sel_timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Cam_Sel_timer_RELOAD_CC_MASK                 ((uint32)(Cam_Sel_timer_1BIT_MASK        <<  \
                                                                            Cam_Sel_timer_RELOAD_CC_SHIFT))
#define Cam_Sel_timer_RELOAD_PERIOD_MASK             ((uint32)(Cam_Sel_timer_1BIT_MASK        <<  \
                                                                            Cam_Sel_timer_RELOAD_PERIOD_SHIFT))
#define Cam_Sel_timer_PWM_SYNC_KILL_MASK             ((uint32)(Cam_Sel_timer_1BIT_MASK        <<  \
                                                                            Cam_Sel_timer_PWM_SYNC_KILL_SHIFT))
#define Cam_Sel_timer_PWM_STOP_KILL_MASK             ((uint32)(Cam_Sel_timer_1BIT_MASK        <<  \
                                                                            Cam_Sel_timer_PWM_STOP_KILL_SHIFT))
#define Cam_Sel_timer_PRESCALER_MASK                 ((uint32)(Cam_Sel_timer_8BIT_MASK        <<  \
                                                                            Cam_Sel_timer_PRESCALER_SHIFT))
#define Cam_Sel_timer_UPDOWN_MASK                    ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                            Cam_Sel_timer_UPDOWN_SHIFT))
#define Cam_Sel_timer_ONESHOT_MASK                   ((uint32)(Cam_Sel_timer_1BIT_MASK        <<  \
                                                                            Cam_Sel_timer_ONESHOT_SHIFT))
#define Cam_Sel_timer_QUAD_MODE_MASK                 ((uint32)(Cam_Sel_timer_3BIT_MASK        <<  \
                                                                            Cam_Sel_timer_QUAD_MODE_SHIFT))
#define Cam_Sel_timer_INV_OUT_MASK                   ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                            Cam_Sel_timer_INV_OUT_SHIFT))
#define Cam_Sel_timer_MODE_MASK                      ((uint32)(Cam_Sel_timer_3BIT_MASK        <<  \
                                                                            Cam_Sel_timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Cam_Sel_timer_CAPTURE_SHIFT                  (0u)
#define Cam_Sel_timer_COUNT_SHIFT                    (2u)
#define Cam_Sel_timer_RELOAD_SHIFT                   (4u)
#define Cam_Sel_timer_STOP_SHIFT                     (6u)
#define Cam_Sel_timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Cam_Sel_timer_CAPTURE_MASK                   ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                  Cam_Sel_timer_CAPTURE_SHIFT))
#define Cam_Sel_timer_COUNT_MASK                     ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                  Cam_Sel_timer_COUNT_SHIFT))
#define Cam_Sel_timer_RELOAD_MASK                    ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                  Cam_Sel_timer_RELOAD_SHIFT))
#define Cam_Sel_timer_STOP_MASK                      ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                  Cam_Sel_timer_STOP_SHIFT))
#define Cam_Sel_timer_START_MASK                     ((uint32)(Cam_Sel_timer_2BIT_MASK        <<  \
                                                                  Cam_Sel_timer_START_SHIFT))

/* MASK */
#define Cam_Sel_timer_1BIT_MASK                      ((uint32)0x01u)
#define Cam_Sel_timer_2BIT_MASK                      ((uint32)0x03u)
#define Cam_Sel_timer_3BIT_MASK                      ((uint32)0x07u)
#define Cam_Sel_timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Cam_Sel_timer_8BIT_MASK                      ((uint32)0xFFu)
#define Cam_Sel_timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Cam_Sel_timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Cam_Sel_timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Cam_Sel_timer_QUAD_ENCODING_MODES     << Cam_Sel_timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Cam_Sel_timer_CONFIG                  << Cam_Sel_timer_MODE_SHIFT)))

#define Cam_Sel_timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Cam_Sel_timer_PWM_STOP_EVENT          << Cam_Sel_timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Cam_Sel_timer_PWM_OUT_INVERT          << Cam_Sel_timer_INV_OUT_SHIFT))         |\
         ((uint32)(Cam_Sel_timer_PWM_OUT_N_INVERT        << Cam_Sel_timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Cam_Sel_timer_PWM_MODE                << Cam_Sel_timer_MODE_SHIFT)))

#define Cam_Sel_timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Cam_Sel_timer_PWM_RUN_MODE         << Cam_Sel_timer_ONESHOT_SHIFT))
            
#define Cam_Sel_timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Cam_Sel_timer_PWM_ALIGN            << Cam_Sel_timer_UPDOWN_SHIFT))

#define Cam_Sel_timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Cam_Sel_timer_PWM_KILL_EVENT      << Cam_Sel_timer_PWM_SYNC_KILL_SHIFT))

#define Cam_Sel_timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Cam_Sel_timer_PWM_DEAD_TIME_CYCLE  << Cam_Sel_timer_PRESCALER_SHIFT))

#define Cam_Sel_timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Cam_Sel_timer_PWM_PRESCALER        << Cam_Sel_timer_PRESCALER_SHIFT))

#define Cam_Sel_timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Cam_Sel_timer_TC_PRESCALER            << Cam_Sel_timer_PRESCALER_SHIFT))       |\
         ((uint32)(Cam_Sel_timer_TC_COUNTER_MODE         << Cam_Sel_timer_UPDOWN_SHIFT))          |\
         ((uint32)(Cam_Sel_timer_TC_RUN_MODE             << Cam_Sel_timer_ONESHOT_SHIFT))         |\
         ((uint32)(Cam_Sel_timer_TC_COMP_CAP_MODE        << Cam_Sel_timer_MODE_SHIFT)))
        
#define Cam_Sel_timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Cam_Sel_timer_QUAD_PHIA_SIGNAL_MODE   << Cam_Sel_timer_COUNT_SHIFT))           |\
         ((uint32)(Cam_Sel_timer_QUAD_INDEX_SIGNAL_MODE  << Cam_Sel_timer_RELOAD_SHIFT))          |\
         ((uint32)(Cam_Sel_timer_QUAD_STOP_SIGNAL_MODE   << Cam_Sel_timer_STOP_SHIFT))            |\
         ((uint32)(Cam_Sel_timer_QUAD_PHIB_SIGNAL_MODE   << Cam_Sel_timer_START_SHIFT)))

#define Cam_Sel_timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Cam_Sel_timer_PWM_SWITCH_SIGNAL_MODE  << Cam_Sel_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Cam_Sel_timer_PWM_COUNT_SIGNAL_MODE   << Cam_Sel_timer_COUNT_SHIFT))           |\
         ((uint32)(Cam_Sel_timer_PWM_RELOAD_SIGNAL_MODE  << Cam_Sel_timer_RELOAD_SHIFT))          |\
         ((uint32)(Cam_Sel_timer_PWM_STOP_SIGNAL_MODE    << Cam_Sel_timer_STOP_SHIFT))            |\
         ((uint32)(Cam_Sel_timer_PWM_START_SIGNAL_MODE   << Cam_Sel_timer_START_SHIFT)))

#define Cam_Sel_timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Cam_Sel_timer_TC_CAPTURE_SIGNAL_MODE  << Cam_Sel_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Cam_Sel_timer_TC_COUNT_SIGNAL_MODE    << Cam_Sel_timer_COUNT_SHIFT))           |\
         ((uint32)(Cam_Sel_timer_TC_RELOAD_SIGNAL_MODE   << Cam_Sel_timer_RELOAD_SHIFT))          |\
         ((uint32)(Cam_Sel_timer_TC_STOP_SIGNAL_MODE     << Cam_Sel_timer_STOP_SHIFT))            |\
         ((uint32)(Cam_Sel_timer_TC_START_SIGNAL_MODE    << Cam_Sel_timer_START_SHIFT)))
        
#define Cam_Sel_timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Cam_Sel_timer__COUNT_UPDOWN0 == Cam_Sel_timer_TC_COUNTER_MODE)                  ||\
                 (Cam_Sel_timer__COUNT_UPDOWN1 == Cam_Sel_timer_TC_COUNTER_MODE))

#define Cam_Sel_timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Cam_Sel_timer__CENTER == Cam_Sel_timer_PWM_ALIGN)                               ||\
                 (Cam_Sel_timer__ASYMMETRIC == Cam_Sel_timer_PWM_ALIGN))               
        
#define Cam_Sel_timer_PWM_PR_INIT_VALUE              (1u)
#define Cam_Sel_timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Cam_Sel_timer_H */

/* [] END OF FILE */
