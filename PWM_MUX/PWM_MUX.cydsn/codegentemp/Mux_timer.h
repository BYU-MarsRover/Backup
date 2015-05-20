/*******************************************************************************
* File Name: Mux_timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Mux_timer
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

#if !defined(CY_TCPWM_Mux_timer_H)
#define CY_TCPWM_Mux_timer_H


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
} Mux_timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Mux_timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Mux_timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Mux_timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Mux_timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Mux_timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Mux_timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Mux_timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Mux_timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Mux_timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Mux_timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Mux_timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Mux_timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Mux_timer_TC_RUN_MODE                    (0lu)
#define Mux_timer_TC_COUNTER_MODE                (0lu)
#define Mux_timer_TC_COMP_CAP_MODE               (2lu)
#define Mux_timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Mux_timer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Mux_timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Mux_timer_TC_START_SIGNAL_MODE           (0lu)
#define Mux_timer_TC_STOP_SIGNAL_MODE            (1lu)
#define Mux_timer_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Mux_timer_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Mux_timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Mux_timer_TC_START_SIGNAL_PRESENT        (1lu)
#define Mux_timer_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Mux_timer_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Mux_timer_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define Mux_timer_PWM_KILL_EVENT                 (0lu)
#define Mux_timer_PWM_STOP_EVENT                 (0lu)
#define Mux_timer_PWM_MODE                       (4lu)
#define Mux_timer_PWM_OUT_N_INVERT               (0lu)
#define Mux_timer_PWM_OUT_INVERT                 (0lu)
#define Mux_timer_PWM_ALIGN                      (0lu)
#define Mux_timer_PWM_RUN_MODE                   (0lu)
#define Mux_timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Mux_timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Mux_timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Mux_timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Mux_timer_PWM_START_SIGNAL_MODE          (0lu)
#define Mux_timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Mux_timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Mux_timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Mux_timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Mux_timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Mux_timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Mux_timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Mux_timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Mux_timer_TC_PERIOD_VALUE                (65535lu)
#define Mux_timer_TC_COMPARE_VALUE               (65535lu)
#define Mux_timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Mux_timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Mux_timer_PWM_PERIOD_VALUE               (65535lu)
#define Mux_timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Mux_timer_PWM_PERIOD_SWAP                (0lu)
#define Mux_timer_PWM_COMPARE_VALUE              (65535lu)
#define Mux_timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Mux_timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Mux_timer__LEFT 0
#define Mux_timer__RIGHT 1
#define Mux_timer__CENTER 2
#define Mux_timer__ASYMMETRIC 3

#define Mux_timer__X1 0
#define Mux_timer__X2 1
#define Mux_timer__X4 2

#define Mux_timer__PWM 4
#define Mux_timer__PWM_DT 5
#define Mux_timer__PWM_PR 6

#define Mux_timer__INVERSE 1
#define Mux_timer__DIRECT 0

#define Mux_timer__CAPTURE 2
#define Mux_timer__COMPARE 0

#define Mux_timer__TRIG_LEVEL 3
#define Mux_timer__TRIG_RISING 0
#define Mux_timer__TRIG_FALLING 1
#define Mux_timer__TRIG_BOTH 2

#define Mux_timer__INTR_MASK_TC 1
#define Mux_timer__INTR_MASK_CC_MATCH 2
#define Mux_timer__INTR_MASK_NONE 0
#define Mux_timer__INTR_MASK_TC_CC 3

#define Mux_timer__UNCONFIG 8
#define Mux_timer__TIMER 1
#define Mux_timer__QUAD 3
#define Mux_timer__PWM_SEL 7

#define Mux_timer__COUNT_UP 0
#define Mux_timer__COUNT_DOWN 1
#define Mux_timer__COUNT_UPDOWN0 2
#define Mux_timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Mux_timer_PRESCALE_DIVBY1                ((uint32)(0u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY2                ((uint32)(1u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY4                ((uint32)(2u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY8                ((uint32)(3u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY16               ((uint32)(4u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY32               ((uint32)(5u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY64               ((uint32)(6u << Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_PRESCALE_DIVBY128              ((uint32)(7u << Mux_timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Mux_timer_MODE_TIMER_COMPARE             ((uint32)(Mux_timer__COMPARE         <<  \
                                                                  Mux_timer_MODE_SHIFT))
#define Mux_timer_MODE_TIMER_CAPTURE             ((uint32)(Mux_timer__CAPTURE         <<  \
                                                                  Mux_timer_MODE_SHIFT))
#define Mux_timer_MODE_QUAD                      ((uint32)(Mux_timer__QUAD            <<  \
                                                                  Mux_timer_MODE_SHIFT))
#define Mux_timer_MODE_PWM                       ((uint32)(Mux_timer__PWM             <<  \
                                                                  Mux_timer_MODE_SHIFT))
#define Mux_timer_MODE_PWM_DT                    ((uint32)(Mux_timer__PWM_DT          <<  \
                                                                  Mux_timer_MODE_SHIFT))
#define Mux_timer_MODE_PWM_PR                    ((uint32)(Mux_timer__PWM_PR          <<  \
                                                                  Mux_timer_MODE_SHIFT))

/* Quad Modes */
#define Mux_timer_MODE_X1                        ((uint32)(Mux_timer__X1              <<  \
                                                                  Mux_timer_QUAD_MODE_SHIFT))
#define Mux_timer_MODE_X2                        ((uint32)(Mux_timer__X2              <<  \
                                                                  Mux_timer_QUAD_MODE_SHIFT))
#define Mux_timer_MODE_X4                        ((uint32)(Mux_timer__X4              <<  \
                                                                  Mux_timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Mux_timer_COUNT_UP                       ((uint32)(Mux_timer__COUNT_UP        <<  \
                                                                  Mux_timer_UPDOWN_SHIFT))
#define Mux_timer_COUNT_DOWN                     ((uint32)(Mux_timer__COUNT_DOWN      <<  \
                                                                  Mux_timer_UPDOWN_SHIFT))
#define Mux_timer_COUNT_UPDOWN0                  ((uint32)(Mux_timer__COUNT_UPDOWN0   <<  \
                                                                  Mux_timer_UPDOWN_SHIFT))
#define Mux_timer_COUNT_UPDOWN1                  ((uint32)(Mux_timer__COUNT_UPDOWN1   <<  \
                                                                  Mux_timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Mux_timer_INVERT_LINE                    ((uint32)(Mux_timer__INVERSE         <<  \
                                                                  Mux_timer_INV_OUT_SHIFT))
#define Mux_timer_INVERT_LINE_N                  ((uint32)(Mux_timer__INVERSE         <<  \
                                                                  Mux_timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Mux_timer_TRIG_RISING                    ((uint32)Mux_timer__TRIG_RISING)
#define Mux_timer_TRIG_FALLING                   ((uint32)Mux_timer__TRIG_FALLING)
#define Mux_timer_TRIG_BOTH                      ((uint32)Mux_timer__TRIG_BOTH)
#define Mux_timer_TRIG_LEVEL                     ((uint32)Mux_timer__TRIG_LEVEL)

/* Interrupt mask */
#define Mux_timer_INTR_MASK_TC                   ((uint32)Mux_timer__INTR_MASK_TC)
#define Mux_timer_INTR_MASK_CC_MATCH             ((uint32)Mux_timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Mux_timer_CC_MATCH_SET                   (0x00u)
#define Mux_timer_CC_MATCH_CLEAR                 (0x01u)
#define Mux_timer_CC_MATCH_INVERT                (0x02u)
#define Mux_timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Mux_timer_OVERLOW_SET                    (0x00u)
#define Mux_timer_OVERLOW_CLEAR                  (0x04u)
#define Mux_timer_OVERLOW_INVERT                 (0x08u)
#define Mux_timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Mux_timer_UNDERFLOW_SET                  (0x00u)
#define Mux_timer_UNDERFLOW_CLEAR                (0x10u)
#define Mux_timer_UNDERFLOW_INVERT               (0x20u)
#define Mux_timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Mux_timer_PWM_MODE_LEFT                  (Mux_timer_CC_MATCH_CLEAR        |   \
                                                         Mux_timer_OVERLOW_SET           |   \
                                                         Mux_timer_UNDERFLOW_NO_CHANGE)
#define Mux_timer_PWM_MODE_RIGHT                 (Mux_timer_CC_MATCH_SET          |   \
                                                         Mux_timer_OVERLOW_NO_CHANGE     |   \
                                                         Mux_timer_UNDERFLOW_CLEAR)
#define Mux_timer_PWM_MODE_ASYM                  (Mux_timer_CC_MATCH_INVERT       |   \
                                                         Mux_timer_OVERLOW_SET           |   \
                                                         Mux_timer_UNDERFLOW_CLEAR)

#if (Mux_timer_CY_TCPWM_V2)
    #if(Mux_timer_CY_TCPWM_4000)
        #define Mux_timer_PWM_MODE_CENTER                (Mux_timer_CC_MATCH_INVERT       |   \
                                                                 Mux_timer_OVERLOW_NO_CHANGE     |   \
                                                                 Mux_timer_UNDERFLOW_CLEAR)
    #else
        #define Mux_timer_PWM_MODE_CENTER                (Mux_timer_CC_MATCH_INVERT       |   \
                                                                 Mux_timer_OVERLOW_SET           |   \
                                                                 Mux_timer_UNDERFLOW_CLEAR)
    #endif /* (Mux_timer_CY_TCPWM_4000) */
#else
    #define Mux_timer_PWM_MODE_CENTER                (Mux_timer_CC_MATCH_INVERT       |   \
                                                             Mux_timer_OVERLOW_NO_CHANGE     |   \
                                                             Mux_timer_UNDERFLOW_CLEAR)
#endif /* (Mux_timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Mux_timer_CMD_CAPTURE                    (0u)
#define Mux_timer_CMD_RELOAD                     (8u)
#define Mux_timer_CMD_STOP                       (16u)
#define Mux_timer_CMD_START                      (24u)

/* Status */
#define Mux_timer_STATUS_DOWN                    (1u)
#define Mux_timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Mux_timer_Init(void);
void   Mux_timer_Enable(void);
void   Mux_timer_Start(void);
void   Mux_timer_Stop(void);

void   Mux_timer_SetMode(uint32 mode);
void   Mux_timer_SetCounterMode(uint32 counterMode);
void   Mux_timer_SetPWMMode(uint32 modeMask);
void   Mux_timer_SetQDMode(uint32 qdMode);

void   Mux_timer_SetPrescaler(uint32 prescaler);
void   Mux_timer_TriggerCommand(uint32 mask, uint32 command);
void   Mux_timer_SetOneShot(uint32 oneShotEnable);
uint32 Mux_timer_ReadStatus(void);

void   Mux_timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Mux_timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Mux_timer_SetPWMDeadTime(uint32 deadTime);
void   Mux_timer_SetPWMInvert(uint32 mask);

void   Mux_timer_SetInterruptMode(uint32 interruptMask);
uint32 Mux_timer_GetInterruptSourceMasked(void);
uint32 Mux_timer_GetInterruptSource(void);
void   Mux_timer_ClearInterrupt(uint32 interruptMask);
void   Mux_timer_SetInterrupt(uint32 interruptMask);

void   Mux_timer_WriteCounter(uint32 count);
uint32 Mux_timer_ReadCounter(void);

uint32 Mux_timer_ReadCapture(void);
uint32 Mux_timer_ReadCaptureBuf(void);

void   Mux_timer_WritePeriod(uint32 period);
uint32 Mux_timer_ReadPeriod(void);
void   Mux_timer_WritePeriodBuf(uint32 periodBuf);
uint32 Mux_timer_ReadPeriodBuf(void);

void   Mux_timer_WriteCompare(uint32 compare);
uint32 Mux_timer_ReadCompare(void);
void   Mux_timer_WriteCompareBuf(uint32 compareBuf);
uint32 Mux_timer_ReadCompareBuf(void);

void   Mux_timer_SetPeriodSwap(uint32 swapEnable);
void   Mux_timer_SetCompareSwap(uint32 swapEnable);

void   Mux_timer_SetCaptureMode(uint32 triggerMode);
void   Mux_timer_SetReloadMode(uint32 triggerMode);
void   Mux_timer_SetStartMode(uint32 triggerMode);
void   Mux_timer_SetStopMode(uint32 triggerMode);
void   Mux_timer_SetCountMode(uint32 triggerMode);

void   Mux_timer_SaveConfig(void);
void   Mux_timer_RestoreConfig(void);
void   Mux_timer_Sleep(void);
void   Mux_timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Mux_timer_BLOCK_CONTROL_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Mux_timer_BLOCK_CONTROL_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Mux_timer_COMMAND_REG                    (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Mux_timer_COMMAND_PTR                    ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Mux_timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Mux_timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Mux_timer_CONTROL_REG                    (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CTRL )
#define Mux_timer_CONTROL_PTR                    ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CTRL )
#define Mux_timer_STATUS_REG                     (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__STATUS )
#define Mux_timer_STATUS_PTR                     ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__STATUS )
#define Mux_timer_COUNTER_REG                    (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Mux_timer_COUNTER_PTR                    ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__COUNTER )
#define Mux_timer_COMP_CAP_REG                   (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CC )
#define Mux_timer_COMP_CAP_PTR                   ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CC )
#define Mux_timer_COMP_CAP_BUF_REG               (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Mux_timer_COMP_CAP_BUF_PTR               ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Mux_timer_PERIOD_REG                     (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Mux_timer_PERIOD_PTR                     ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__PERIOD )
#define Mux_timer_PERIOD_BUF_REG                 (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Mux_timer_PERIOD_BUF_PTR                 ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Mux_timer_TRIG_CONTROL0_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Mux_timer_TRIG_CONTROL0_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Mux_timer_TRIG_CONTROL1_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Mux_timer_TRIG_CONTROL1_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Mux_timer_TRIG_CONTROL2_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Mux_timer_TRIG_CONTROL2_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Mux_timer_INTERRUPT_REQ_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR )
#define Mux_timer_INTERRUPT_REQ_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR )
#define Mux_timer_INTERRUPT_SET_REG              (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Mux_timer_INTERRUPT_SET_PTR              ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Mux_timer_INTERRUPT_MASK_REG             (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Mux_timer_INTERRUPT_MASK_PTR             ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Mux_timer_INTERRUPT_MASKED_REG           (*(reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Mux_timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Mux_timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Mux_timer_MASK                           ((uint32)Mux_timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Mux_timer_RELOAD_CC_SHIFT                (0u)
#define Mux_timer_RELOAD_PERIOD_SHIFT            (1u)
#define Mux_timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Mux_timer_PWM_STOP_KILL_SHIFT            (3u)
#define Mux_timer_PRESCALER_SHIFT                (8u)
#define Mux_timer_UPDOWN_SHIFT                   (16u)
#define Mux_timer_ONESHOT_SHIFT                  (18u)
#define Mux_timer_QUAD_MODE_SHIFT                (20u)
#define Mux_timer_INV_OUT_SHIFT                  (20u)
#define Mux_timer_INV_COMPL_OUT_SHIFT            (21u)
#define Mux_timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Mux_timer_RELOAD_CC_MASK                 ((uint32)(Mux_timer_1BIT_MASK        <<  \
                                                                            Mux_timer_RELOAD_CC_SHIFT))
#define Mux_timer_RELOAD_PERIOD_MASK             ((uint32)(Mux_timer_1BIT_MASK        <<  \
                                                                            Mux_timer_RELOAD_PERIOD_SHIFT))
#define Mux_timer_PWM_SYNC_KILL_MASK             ((uint32)(Mux_timer_1BIT_MASK        <<  \
                                                                            Mux_timer_PWM_SYNC_KILL_SHIFT))
#define Mux_timer_PWM_STOP_KILL_MASK             ((uint32)(Mux_timer_1BIT_MASK        <<  \
                                                                            Mux_timer_PWM_STOP_KILL_SHIFT))
#define Mux_timer_PRESCALER_MASK                 ((uint32)(Mux_timer_8BIT_MASK        <<  \
                                                                            Mux_timer_PRESCALER_SHIFT))
#define Mux_timer_UPDOWN_MASK                    ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                            Mux_timer_UPDOWN_SHIFT))
#define Mux_timer_ONESHOT_MASK                   ((uint32)(Mux_timer_1BIT_MASK        <<  \
                                                                            Mux_timer_ONESHOT_SHIFT))
#define Mux_timer_QUAD_MODE_MASK                 ((uint32)(Mux_timer_3BIT_MASK        <<  \
                                                                            Mux_timer_QUAD_MODE_SHIFT))
#define Mux_timer_INV_OUT_MASK                   ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                            Mux_timer_INV_OUT_SHIFT))
#define Mux_timer_MODE_MASK                      ((uint32)(Mux_timer_3BIT_MASK        <<  \
                                                                            Mux_timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Mux_timer_CAPTURE_SHIFT                  (0u)
#define Mux_timer_COUNT_SHIFT                    (2u)
#define Mux_timer_RELOAD_SHIFT                   (4u)
#define Mux_timer_STOP_SHIFT                     (6u)
#define Mux_timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Mux_timer_CAPTURE_MASK                   ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                  Mux_timer_CAPTURE_SHIFT))
#define Mux_timer_COUNT_MASK                     ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                  Mux_timer_COUNT_SHIFT))
#define Mux_timer_RELOAD_MASK                    ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                  Mux_timer_RELOAD_SHIFT))
#define Mux_timer_STOP_MASK                      ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                  Mux_timer_STOP_SHIFT))
#define Mux_timer_START_MASK                     ((uint32)(Mux_timer_2BIT_MASK        <<  \
                                                                  Mux_timer_START_SHIFT))

/* MASK */
#define Mux_timer_1BIT_MASK                      ((uint32)0x01u)
#define Mux_timer_2BIT_MASK                      ((uint32)0x03u)
#define Mux_timer_3BIT_MASK                      ((uint32)0x07u)
#define Mux_timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Mux_timer_8BIT_MASK                      ((uint32)0xFFu)
#define Mux_timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Mux_timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Mux_timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Mux_timer_QUAD_ENCODING_MODES     << Mux_timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Mux_timer_CONFIG                  << Mux_timer_MODE_SHIFT)))

#define Mux_timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Mux_timer_PWM_STOP_EVENT          << Mux_timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Mux_timer_PWM_OUT_INVERT          << Mux_timer_INV_OUT_SHIFT))         |\
         ((uint32)(Mux_timer_PWM_OUT_N_INVERT        << Mux_timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Mux_timer_PWM_MODE                << Mux_timer_MODE_SHIFT)))

#define Mux_timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Mux_timer_PWM_RUN_MODE         << Mux_timer_ONESHOT_SHIFT))
            
#define Mux_timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Mux_timer_PWM_ALIGN            << Mux_timer_UPDOWN_SHIFT))

#define Mux_timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Mux_timer_PWM_KILL_EVENT      << Mux_timer_PWM_SYNC_KILL_SHIFT))

#define Mux_timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Mux_timer_PWM_DEAD_TIME_CYCLE  << Mux_timer_PRESCALER_SHIFT))

#define Mux_timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Mux_timer_PWM_PRESCALER        << Mux_timer_PRESCALER_SHIFT))

#define Mux_timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Mux_timer_TC_PRESCALER            << Mux_timer_PRESCALER_SHIFT))       |\
         ((uint32)(Mux_timer_TC_COUNTER_MODE         << Mux_timer_UPDOWN_SHIFT))          |\
         ((uint32)(Mux_timer_TC_RUN_MODE             << Mux_timer_ONESHOT_SHIFT))         |\
         ((uint32)(Mux_timer_TC_COMP_CAP_MODE        << Mux_timer_MODE_SHIFT)))
        
#define Mux_timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Mux_timer_QUAD_PHIA_SIGNAL_MODE   << Mux_timer_COUNT_SHIFT))           |\
         ((uint32)(Mux_timer_QUAD_INDEX_SIGNAL_MODE  << Mux_timer_RELOAD_SHIFT))          |\
         ((uint32)(Mux_timer_QUAD_STOP_SIGNAL_MODE   << Mux_timer_STOP_SHIFT))            |\
         ((uint32)(Mux_timer_QUAD_PHIB_SIGNAL_MODE   << Mux_timer_START_SHIFT)))

#define Mux_timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Mux_timer_PWM_SWITCH_SIGNAL_MODE  << Mux_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Mux_timer_PWM_COUNT_SIGNAL_MODE   << Mux_timer_COUNT_SHIFT))           |\
         ((uint32)(Mux_timer_PWM_RELOAD_SIGNAL_MODE  << Mux_timer_RELOAD_SHIFT))          |\
         ((uint32)(Mux_timer_PWM_STOP_SIGNAL_MODE    << Mux_timer_STOP_SHIFT))            |\
         ((uint32)(Mux_timer_PWM_START_SIGNAL_MODE   << Mux_timer_START_SHIFT)))

#define Mux_timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Mux_timer_TC_CAPTURE_SIGNAL_MODE  << Mux_timer_CAPTURE_SHIFT))         |\
         ((uint32)(Mux_timer_TC_COUNT_SIGNAL_MODE    << Mux_timer_COUNT_SHIFT))           |\
         ((uint32)(Mux_timer_TC_RELOAD_SIGNAL_MODE   << Mux_timer_RELOAD_SHIFT))          |\
         ((uint32)(Mux_timer_TC_STOP_SIGNAL_MODE     << Mux_timer_STOP_SHIFT))            |\
         ((uint32)(Mux_timer_TC_START_SIGNAL_MODE    << Mux_timer_START_SHIFT)))
        
#define Mux_timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Mux_timer__COUNT_UPDOWN0 == Mux_timer_TC_COUNTER_MODE)                  ||\
                 (Mux_timer__COUNT_UPDOWN1 == Mux_timer_TC_COUNTER_MODE))

#define Mux_timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Mux_timer__CENTER == Mux_timer_PWM_ALIGN)                               ||\
                 (Mux_timer__ASYMMETRIC == Mux_timer_PWM_ALIGN))               
        
#define Mux_timer_PWM_PR_INIT_VALUE              (1u)
#define Mux_timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Mux_timer_H */

/* [] END OF FILE */
