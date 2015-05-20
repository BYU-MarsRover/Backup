/*******************************************************************************
* File Name: Arm_select_timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Arm_select_timer
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

#if !defined(CY_TCPWM_Arm_select_timer_H)
#define CY_TCPWM_Arm_select_timer_H


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
} Arm_select_timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Arm_select_timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Arm_select_timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Arm_select_timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Arm_select_timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Arm_select_timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Arm_select_timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Arm_select_timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Arm_select_timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Arm_select_timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Arm_select_timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Arm_select_timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Arm_select_timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Arm_select_timer_TC_RUN_MODE                    (0lu)
#define Arm_select_timer_TC_COUNTER_MODE                (0lu)
#define Arm_select_timer_TC_COMP_CAP_MODE               (2lu)
#define Arm_select_timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Arm_select_timer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Arm_select_timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Arm_select_timer_TC_START_SIGNAL_MODE           (0lu)
#define Arm_select_timer_TC_STOP_SIGNAL_MODE            (1lu)
#define Arm_select_timer_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Arm_select_timer_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Arm_select_timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Arm_select_timer_TC_START_SIGNAL_PRESENT        (1lu)
#define Arm_select_timer_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Arm_select_timer_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Arm_select_timer_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define Arm_select_timer_PWM_KILL_EVENT                 (0lu)
#define Arm_select_timer_PWM_STOP_EVENT                 (0lu)
#define Arm_select_timer_PWM_MODE                       (4lu)
#define Arm_select_timer_PWM_OUT_N_INVERT               (0lu)
#define Arm_select_timer_PWM_OUT_INVERT                 (0lu)
#define Arm_select_timer_PWM_ALIGN                      (0lu)
#define Arm_select_timer_PWM_RUN_MODE                   (0lu)
#define Arm_select_timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Arm_select_timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Arm_select_timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Arm_select_timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Arm_select_timer_PWM_START_SIGNAL_MODE          (0lu)
#define Arm_select_timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Arm_select_timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Arm_select_timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Arm_select_timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Arm_select_timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Arm_select_timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Arm_select_timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Arm_select_timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Arm_select_timer_TC_PERIOD_VALUE                (65535lu)
#define Arm_select_timer_TC_COMPARE_VALUE               (65535lu)
#define Arm_select_timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Arm_select_timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Arm_select_timer_PWM_PERIOD_VALUE               (65535lu)
#define Arm_select_timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Arm_select_timer_PWM_PERIOD_SWAP                (0lu)
#define Arm_select_timer_PWM_COMPARE_VALUE              (65535lu)
#define Arm_select_timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Arm_select_timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Arm_select_timer__LEFT 0
#define Arm_select_timer__RIGHT 1
#define Arm_select_timer__CENTER 2
#define Arm_select_timer__ASYMMETRIC 3

#define Arm_select_timer__X1 0
#define Arm_select_timer__X2 1
#define Arm_select_timer__X4 2

#define Arm_select_timer__PWM 4
#define Arm_select_timer__PWM_DT 5
#define Arm_select_timer__PWM_PR 6

#define Arm_select_timer__INVERSE 1
#define Arm_select_timer__DIRECT 0

#define Arm_select_timer__CAPTURE 2
#define Arm_select_timer__COMPARE 0

#define Arm_select_timer__TRIG_LEVEL 3
#define Arm_select_timer__TRIG_RISING 0
#define Arm_select_timer__TRIG_FALLING 1
#define Arm_select_timer__TRIG_BOTH 2

#define Arm_select_timer__INTR_MASK_TC 1
#define Arm_select_timer__INTR_MASK_CC_MATCH 2
#define Arm_select_timer__INTR_MASK_NONE 0
#define Arm_select_timer__INTR_MASK_TC_CC 3

#define Arm_select_timer__UNCONFIG 8
#define Arm_select_timer__TIMER 1
#define Arm_select_timer__QUAD 3
#define Arm_select_timer__PWM_SEL 7

#define Arm_select_timer__COUNT_UP 0
#define Arm_select_timer__COUNT_DOWN 1
#define Arm_select_timer__COUNT_UPDOWN0 2
#define Arm_select_timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Arm_select_timer_PRESCALE_DIVBY1                ((uint32)(0u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY2                ((uint32)(1u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY4                ((uint32)(2u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY8                ((uint32)(3u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY16               ((uint32)(4u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY32               ((uint32)(5u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY64               ((uint32)(6u << Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_PRESCALE_DIVBY128              ((uint32)(7u << Arm_select_timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Arm_select_timer_MODE_TIMER_COMPARE             ((uint32)(Arm_select_timer__COMPARE         <<  \
                                                                  Arm_select_timer_MODE_SHIFT))
#define Arm_select_timer_MODE_TIMER_CAPTURE             ((uint32)(Arm_select_timer__CAPTURE         <<  \
                                                                  Arm_select_timer_MODE_SHIFT))
#define Arm_select_timer_MODE_QUAD                      ((uint32)(Arm_select_timer__QUAD            <<  \
                                                                  Arm_select_timer_MODE_SHIFT))
#define Arm_select_timer_MODE_PWM                       ((uint32)(Arm_select_timer__PWM             <<  \
                                                                  Arm_select_timer_MODE_SHIFT))
#define Arm_select_timer_MODE_PWM_DT                    ((uint32)(Arm_select_timer__PWM_DT          <<  \
                                                                  Arm_select_timer_MODE_SHIFT))
#define Arm_select_timer_MODE_PWM_PR                    ((uint32)(Arm_select_timer__PWM_PR          <<  \
                                                                  Arm_select_timer_MODE_SHIFT))

/* Quad Modes */
#define Arm_select_timer_MODE_X1                        ((uint32)(Arm_select_timer__X1              <<  \
                                                                  Arm_select_timer_QUAD_MODE_SHIFT))
#define Arm_select_timer_MODE_X2                        ((uint32)(Arm_select_timer__X2              <<  \
                                                                  Arm_select_timer_QUAD_MODE_SHIFT))
#define Arm_select_timer_MODE_X4                        ((uint32)(Arm_select_timer__X4              <<  \
                                                                  Arm_select_timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Arm_select_timer_COUNT_UP                       ((uint32)(Arm_select_timer__COUNT_UP        <<  \
                                                                  Arm_select_timer_UPDOWN_SHIFT))
#define Arm_select_timer_COUNT_DOWN                     ((uint32)(Arm_select_timer__COUNT_DOWN      <<  \
                                                                  Arm_select_timer_UPDOWN_SHIFT))
#define Arm_select_timer_COUNT_UPDOWN0                  ((uint32)(Arm_select_timer__COUNT_UPDOWN0   <<  \
                                                                  Arm_select_timer_UPDOWN_SHIFT))
#define Arm_select_timer_COUNT_UPDOWN1                  ((uint32)(Arm_select_timer__COUNT_UPDOWN1   <<  \
                                                                  Arm_select_timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Arm_select_timer_INVERT_LINE                    ((uint32)(Arm_select_timer__INVERSE         <<  \
                                                                  Arm_select_timer_INV_OUT_SHIFT))
#define Arm_select_timer_INVERT_LINE_N                  ((uint32)(Arm_select_timer__INVERSE         <<  \
                                                                  Arm_select_timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Arm_select_timer_TRIG_RISING                    ((uint32)Arm_select_timer__TRIG_RISING)
#define Arm_select_timer_TRIG_FALLING                   ((uint32)Arm_select_timer__TRIG_FALLING)
#define Arm_select_timer_TRIG_BOTH                      ((uint32)Arm_select_timer__TRIG_BOTH)
#define Arm_select_timer_TRIG_LEVEL                     ((uint32)Arm_select_timer__TRIG_LEVEL)

/* Interrupt mask */
#define Arm_select_timer_INTR_MASK_TC                   ((uint32)Arm_select_timer__INTR_MASK_TC)
#define Arm_select_timer_INTR_MASK_CC_MATCH             ((uint32)Arm_select_timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Arm_select_timer_CC_MATCH_SET                   (0x00u)
#define Arm_select_timer_CC_MATCH_CLEAR                 (0x01u)
#define Arm_select_timer_CC_MATCH_INVERT                (0x02u)
#define Arm_select_timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Arm_select_timer_OVERLOW_SET                    (0x00u)
#define Arm_select_timer_OVERLOW_CLEAR                  (0x04u)
#define Arm_select_timer_OVERLOW_INVERT                 (0x08u)
#define Arm_select_timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Arm_select_timer_UNDERFLOW_SET                  (0x00u)
#define Arm_select_timer_UNDERFLOW_CLEAR                (0x10u)
#define Arm_select_timer_UNDERFLOW_INVERT               (0x20u)
#define Arm_select_timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Arm_select_timer_PWM_MODE_LEFT                  (Arm_select_timer_CC_MATCH_CLEAR        |   \
                                                         Arm_select_timer_OVERLOW_SET           |   \
                                                         Arm_select_timer_UNDERFLOW_NO_CHANGE)
#define Arm_select_timer_PWM_MODE_RIGHT                 (Arm_select_timer_CC_MATCH_SET          |   \
                                                         Arm_select_timer_OVERLOW_NO_CHANGE     |   \
                                                         Arm_select_timer_UNDERFLOW_CLEAR)
#define Arm_select_timer_PWM_MODE_ASYM                  (Arm_select_timer_CC_MATCH_INVERT       |   \
                                                         Arm_select_timer_OVERLOW_SET           |   \
                                                         Arm_select_timer_UNDERFLOW_CLEAR)

#if (Arm_select_timer_CY_TCPWM_V2)
    #if(Arm_select_timer_CY_TCPWM_4000)
        #define Arm_select_timer_PWM_MODE_CENTER                (Arm_select_timer_CC_MATCH_INVERT       |   \
                                                                 Arm_select_timer_OVERLOW_NO_CHANGE     |   \
                                                                 Arm_select_timer_UNDERFLOW_CLEAR)
    #else
        #define Arm_select_timer_PWM_MODE_CENTER                (Arm_select_timer_CC_MATCH_INVERT       |   \
                                                                 Arm_select_timer_OVERLOW_SET           |   \
                                                                 Arm_select_timer_UNDERFLOW_CLEAR)
    #endif /* (Arm_select_timer_CY_TCPWM_4000) */
#else
    #define Arm_select_timer_PWM_MODE_CENTER                (Arm_select_timer_CC_MATCH_INVERT       |   \
                                                             Arm_select_timer_OVERLOW_NO_CHANGE     |   \
                                                             Arm_select_timer_UNDERFLOW_CLEAR)
#endif /* (Arm_select_timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Arm_select_timer_CMD_CAPTURE                    (0u)
#define Arm_select_timer_CMD_RELOAD                     (8u)
#define Arm_select_timer_CMD_STOP                       (16u)
#define Arm_select_timer_CMD_START                      (24u)

/* Status */
#define Arm_select_timer_STATUS_DOWN                    (1u)
#define Arm_select_timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Arm_select_timer_Init(void);
void   Arm_select_timer_Enable(void);
void   Arm_select_timer_Start(void);
void   Arm_select_timer_Stop(void);

void   Arm_select_timer_SetMode(uint32 mode);
void   Arm_select_timer_SetCounterMode(uint32 counterMode);
void   Arm_select_timer_SetPWMMode(uint32 modeMask);
void   Arm_select_timer_SetQDMode(uint32 qdMode);

void   Arm_select_timer_SetPrescaler(uint32 prescaler);
void   Arm_select_timer_TriggerCommand(uint32 mask, uint32 command);
void   Arm_select_timer_SetOneShot(uint32 oneShotEnable);
uint32 Arm_select_timer_ReadStatus(void);

void   Arm_select_timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Arm_select_timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Arm_select_timer_SetPWMDeadTime(uint32 deadTime);
void   Arm_select_timer_SetPWMInvert(uint32 mask);

void   Arm_select_timer_SetInterruptMode(uint32 interruptMask);
uint32 Arm_select_timer_GetInterruptSourceMasked(void);
uint32 Arm_select_timer_GetInterruptSource(void);
void   Arm_select_timer_ClearInterrupt(uint32 interruptMask);
void   Arm_select_timer_SetInterrupt(uint32 interruptMask);

void   Arm_select_timer_WriteCounter(uint32 count);
uint32 Arm_select_timer_ReadCounter(void);

uint32 Arm_select_timer_ReadCapture(void);
uint32 Arm_select_timer_ReadCaptureBuf(void);

void   Arm_select_timer_WritePeriod(uint32 period);
uint32 Arm_select_timer_ReadPeriod(void);
void   Arm_select_timer_WritePeriodBuf(uint32 periodBuf);
uint32 Arm_select_timer_ReadPeriodBuf(void);

void   Arm_select_timer_WriteCompare(uint32 compare);
uint32 Arm_select_timer_ReadCompare(void);
void   Arm_select_timer_WriteCompareBuf(uint32 compareBuf);
uint32 Arm_select_timer_ReadCompareBuf(void);

void   Arm_select_timer_SetPeriodSwap(uint32 swapEnable);
void   Arm_select_timer_SetCompareSwap(uint32 swapEnable);

void   Arm_select_timer_SetCaptureMode(uint32 triggerMode);
void   Arm_select_timer_SetReloadMode(uint32 triggerMode);
void   Arm_select_timer_SetStartMode(uint32 triggerMode);
void   Arm_select_timer_SetStopMode(uint32 triggerMode);
void   Arm_select_timer_SetCountMode(uint32 triggerMode);

void   Arm_select_timer_SaveConfig(void);
void   Arm_select_timer_RestoreConfig(void);
void   Arm_select_timer_Sleep(void);
void   Arm_select_timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Arm_select_timer_BLOCK_CONTROL_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Arm_select_timer_BLOCK_CONTROL_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Arm_select_timer_COMMAND_REG                    (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Arm_select_timer_COMMAND_PTR                    ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Arm_select_timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Arm_select_timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Arm_select_timer_CONTROL_REG                    (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CTRL )
#define Arm_select_timer_CONTROL_PTR                    ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CTRL )
#define Arm_select_timer_STATUS_REG                     (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__STATUS )
#define Arm_select_timer_STATUS_PTR                     ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__STATUS )
#define Arm_select_timer_COUNTER_REG                    (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Arm_select_timer_COUNTER_PTR                    ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Arm_select_timer_COMP_CAP_REG                   (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CC )
#define Arm_select_timer_COMP_CAP_PTR                   ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CC )
#define Arm_select_timer_COMP_CAP_BUF_REG               (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Arm_select_timer_COMP_CAP_BUF_PTR               ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Arm_select_timer_PERIOD_REG                     (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Arm_select_timer_PERIOD_PTR                     ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Arm_select_timer_PERIOD_BUF_REG                 (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Arm_select_timer_PERIOD_BUF_PTR                 ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Arm_select_timer_TRIG_CONTROL0_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Arm_select_timer_TRIG_CONTROL0_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Arm_select_timer_TRIG_CONTROL1_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Arm_select_timer_TRIG_CONTROL1_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Arm_select_timer_TRIG_CONTROL2_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Arm_select_timer_TRIG_CONTROL2_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Arm_select_timer_INTERRUPT_REQ_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR )
#define Arm_select_timer_INTERRUPT_REQ_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR )
#define Arm_select_timer_INTERRUPT_SET_REG              (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Arm_select_timer_INTERRUPT_SET_PTR              ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Arm_select_timer_INTERRUPT_MASK_REG             (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Arm_select_timer_INTERRUPT_MASK_PTR             ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Arm_select_timer_INTERRUPT_MASKED_REG           (*(reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Arm_select_timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Arm_select_timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Arm_select_timer_MASK                           ((uint32)Arm_select_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Arm_select_timer_RELOAD_CC_SHIFT                (0u)
#define Arm_select_timer_RELOAD_PERIOD_SHIFT            (1u)
#define Arm_select_timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Arm_select_timer_PWM_STOP_KILL_SHIFT            (3u)
#define Arm_select_timer_PRESCALER_SHIFT                (8u)
#define Arm_select_timer_UPDOWN_SHIFT                   (16u)
#define Arm_select_timer_ONESHOT_SHIFT                  (18u)
#define Arm_select_timer_QUAD_MODE_SHIFT                (20u)
#define Arm_select_timer_INV_OUT_SHIFT                  (20u)
#define Arm_select_timer_INV_COMPL_OUT_SHIFT            (21u)
#define Arm_select_timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Arm_select_timer_RELOAD_CC_MASK                 ((uint32)(Arm_select_timer_1BIT_MASK        <<  \
                                                                            Arm_select_timer_RELOAD_CC_SHIFT))
#define Arm_select_timer_RELOAD_PERIOD_MASK             ((uint32)(Arm_select_timer_1BIT_MASK        <<  \
                                                                            Arm_select_timer_RELOAD_PERIOD_SHIFT))
#define Arm_select_timer_PWM_SYNC_KILL_MASK             ((uint32)(Arm_select_timer_1BIT_MASK        <<  \
                                                                            Arm_select_timer_PWM_SYNC_KILL_SHIFT))
#define Arm_select_timer_PWM_STOP_KILL_MASK             ((uint32)(Arm_select_timer_1BIT_MASK        <<  \
                                                                            Arm_select_timer_PWM_STOP_KILL_SHIFT))
#define Arm_select_timer_PRESCALER_MASK                 ((uint32)(Arm_select_timer_8BIT_MASK        <<  \
                                                                            Arm_select_timer_PRESCALER_SHIFT))
#define Arm_select_timer_UPDOWN_MASK                    ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                            Arm_select_timer_UPDOWN_SHIFT))
#define Arm_select_timer_ONESHOT_MASK                   ((uint32)(Arm_select_timer_1BIT_MASK        <<  \
                                                                            Arm_select_timer_ONESHOT_SHIFT))
#define Arm_select_timer_QUAD_MODE_MASK                 ((uint32)(Arm_select_timer_3BIT_MASK        <<  \
                                                                            Arm_select_timer_QUAD_MODE_SHIFT))
#define Arm_select_timer_INV_OUT_MASK                   ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                            Arm_select_timer_INV_OUT_SHIFT))
#define Arm_select_timer_MODE_MASK                      ((uint32)(Arm_select_timer_3BIT_MASK        <<  \
                                                                            Arm_select_timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Arm_select_timer_CAPTURE_SHIFT                  (0u)
#define Arm_select_timer_COUNT_SHIFT                    (2u)
#define Arm_select_timer_RELOAD_SHIFT                   (4u)
#define Arm_select_timer_STOP_SHIFT                     (6u)
#define Arm_select_timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Arm_select_timer_CAPTURE_MASK                   ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                  Arm_select_timer_CAPTURE_SHIFT))
#define Arm_select_timer_COUNT_MASK                     ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                  Arm_select_timer_COUNT_SHIFT))
#define Arm_select_timer_RELOAD_MASK                    ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                  Arm_select_timer_RELOAD_SHIFT))
#define Arm_select_timer_STOP_MASK                      ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                  Arm_select_timer_STOP_SHIFT))
#define Arm_select_timer_START_MASK                     ((uint32)(Arm_select_timer_2BIT_MASK        <<  \
                                                                  Arm_select_timer_START_SHIFT))

/* MASK */
#define Arm_select_timer_1BIT_MASK                      ((uint32)0x01u)
#define Arm_select_timer_2BIT_MASK                      ((uint32)0x03u)
#define Arm_select_timer_3BIT_MASK                      ((uint32)0x07u)
#define Arm_select_timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Arm_select_timer_8BIT_MASK                      ((uint32)0xFFu)
#define Arm_select_timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Arm_select_timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Arm_select_timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Arm_select_timer_QUAD_ENCODING_MODES     << Arm_select_timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Arm_select_timer_CONFIG                  << Arm_select_timer_MODE_SHIFT)))

#define Arm_select_timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Arm_select_timer_PWM_STOP_EVENT          << Arm_select_timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Arm_select_timer_PWM_OUT_INVERT          << Arm_select_timer_INV_OUT_SHIFT))         |\
         ((uint32)(Arm_select_timer_PWM_OUT_N_INVERT        << Arm_select_timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Arm_select_timer_PWM_MODE                << Arm_select_timer_MODE_SHIFT)))

#define Arm_select_timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Arm_select_timer_PWM_RUN_MODE         << Arm_select_timer_ONESHOT_SHIFT))
            
#define Arm_select_timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Arm_select_timer_PWM_ALIGN            << Arm_select_timer_UPDOWN_SHIFT))

#define Arm_select_timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Arm_select_timer_PWM_KILL_EVENT      << Arm_select_timer_PWM_SYNC_KILL_SHIFT))

#define Arm_select_timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Arm_select_timer_PWM_DEAD_TIME_CYCLE  << Arm_select_timer_PRESCALER_SHIFT))

#define Arm_select_timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Arm_select_timer_PWM_PRESCALER        << Arm_select_timer_PRESCALER_SHIFT))

#define Arm_select_timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Arm_select_timer_TC_PRESCALER            << Arm_select_timer_PRESCALER_SHIFT))       |\
         ((uint32)(Arm_select_timer_TC_COUNTER_MODE         << Arm_select_timer_UPDOWN_SHIFT))          |\
         ((uint32)(Arm_select_timer_TC_RUN_MODE             << Arm_select_timer_ONESHOT_SHIFT))         |\
         ((uint32)(Arm_select_timer_TC_COMP_CAP_MODE        << Arm_select_timer_MODE_SHIFT)))
        
#define Arm_select_timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Arm_select_timer_QUAD_PHIA_SIGNAL_MODE   << Arm_select_timer_COUNT_SHIFT))           |\
         ((uint32)(Arm_select_timer_QUAD_INDEX_SIGNAL_MODE  << Arm_select_timer_RELOAD_SHIFT))          |\
         ((uint32)(Arm_select_timer_QUAD_STOP_SIGNAL_MODE   << Arm_select_timer_STOP_SHIFT))            |\
         ((uint32)(Arm_select_timer_QUAD_PHIB_SIGNAL_MODE   << Arm_select_timer_START_SHIFT)))

#define Arm_select_timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Arm_select_timer_PWM_SWITCH_SIGNAL_MODE  << Arm_select_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Arm_select_timer_PWM_COUNT_SIGNAL_MODE   << Arm_select_timer_COUNT_SHIFT))           |\
         ((uint32)(Arm_select_timer_PWM_RELOAD_SIGNAL_MODE  << Arm_select_timer_RELOAD_SHIFT))          |\
         ((uint32)(Arm_select_timer_PWM_STOP_SIGNAL_MODE    << Arm_select_timer_STOP_SHIFT))            |\
         ((uint32)(Arm_select_timer_PWM_START_SIGNAL_MODE   << Arm_select_timer_START_SHIFT)))

#define Arm_select_timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Arm_select_timer_TC_CAPTURE_SIGNAL_MODE  << Arm_select_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Arm_select_timer_TC_COUNT_SIGNAL_MODE    << Arm_select_timer_COUNT_SHIFT))           |\
         ((uint32)(Arm_select_timer_TC_RELOAD_SIGNAL_MODE   << Arm_select_timer_RELOAD_SHIFT))          |\
         ((uint32)(Arm_select_timer_TC_STOP_SIGNAL_MODE     << Arm_select_timer_STOP_SHIFT))            |\
         ((uint32)(Arm_select_timer_TC_START_SIGNAL_MODE    << Arm_select_timer_START_SHIFT)))
        
#define Arm_select_timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Arm_select_timer__COUNT_UPDOWN0 == Arm_select_timer_TC_COUNTER_MODE)                  ||\
                 (Arm_select_timer__COUNT_UPDOWN1 == Arm_select_timer_TC_COUNTER_MODE))

#define Arm_select_timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Arm_select_timer__CENTER == Arm_select_timer_PWM_ALIGN)                               ||\
                 (Arm_select_timer__ASYMMETRIC == Arm_select_timer_PWM_ALIGN))               
        
#define Arm_select_timer_PWM_PR_INIT_VALUE              (1u)
#define Arm_select_timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Arm_select_timer_H */

/* [] END OF FILE */
