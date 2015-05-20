/*******************************************************************************
* File Name: Timer_3.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Timer_3
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

#if !defined(CY_TCPWM_Timer_3_H)
#define CY_TCPWM_Timer_3_H


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
} Timer_3_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Timer_3_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Timer_3_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Timer_3_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Timer_3_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Timer_3_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Timer_3_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Timer_3_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Timer_3_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Timer_3_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Timer_3_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Timer_3_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Timer_3_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Timer_3_TC_RUN_MODE                    (0lu)
#define Timer_3_TC_COUNTER_MODE                (0lu)
#define Timer_3_TC_COMP_CAP_MODE               (2lu)
#define Timer_3_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Timer_3_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Timer_3_TC_COUNT_SIGNAL_MODE           (3lu)
#define Timer_3_TC_START_SIGNAL_MODE           (0lu)
#define Timer_3_TC_STOP_SIGNAL_MODE            (1lu)
#define Timer_3_TC_CAPTURE_SIGNAL_MODE         (1lu)

/* Signal present */
#define Timer_3_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Timer_3_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Timer_3_TC_START_SIGNAL_PRESENT        (1lu)
#define Timer_3_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Timer_3_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define Timer_3_TC_INTERRUPT_MASK              (2lu)

/* PWM Mode */
/* Parameters */
#define Timer_3_PWM_KILL_EVENT                 (0lu)
#define Timer_3_PWM_STOP_EVENT                 (0lu)
#define Timer_3_PWM_MODE                       (4lu)
#define Timer_3_PWM_OUT_N_INVERT               (0lu)
#define Timer_3_PWM_OUT_INVERT                 (0lu)
#define Timer_3_PWM_ALIGN                      (0lu)
#define Timer_3_PWM_RUN_MODE                   (0lu)
#define Timer_3_PWM_DEAD_TIME_CYCLE            (0lu)
#define Timer_3_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Timer_3_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Timer_3_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Timer_3_PWM_START_SIGNAL_MODE          (0lu)
#define Timer_3_PWM_STOP_SIGNAL_MODE           (0lu)
#define Timer_3_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Timer_3_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Timer_3_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Timer_3_PWM_START_SIGNAL_PRESENT       (0lu)
#define Timer_3_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Timer_3_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Timer_3_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Timer_3_TC_PERIOD_VALUE                (65535lu)
#define Timer_3_TC_COMPARE_VALUE               (65535lu)
#define Timer_3_TC_COMPARE_BUF_VALUE           (65535lu)
#define Timer_3_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Timer_3_PWM_PERIOD_VALUE               (65535lu)
#define Timer_3_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Timer_3_PWM_PERIOD_SWAP                (0lu)
#define Timer_3_PWM_COMPARE_VALUE              (65535lu)
#define Timer_3_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Timer_3_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Timer_3__LEFT 0
#define Timer_3__RIGHT 1
#define Timer_3__CENTER 2
#define Timer_3__ASYMMETRIC 3

#define Timer_3__X1 0
#define Timer_3__X2 1
#define Timer_3__X4 2

#define Timer_3__PWM 4
#define Timer_3__PWM_DT 5
#define Timer_3__PWM_PR 6

#define Timer_3__INVERSE 1
#define Timer_3__DIRECT 0

#define Timer_3__CAPTURE 2
#define Timer_3__COMPARE 0

#define Timer_3__TRIG_LEVEL 3
#define Timer_3__TRIG_RISING 0
#define Timer_3__TRIG_FALLING 1
#define Timer_3__TRIG_BOTH 2

#define Timer_3__INTR_MASK_TC 1
#define Timer_3__INTR_MASK_CC_MATCH 2
#define Timer_3__INTR_MASK_NONE 0
#define Timer_3__INTR_MASK_TC_CC 3

#define Timer_3__UNCONFIG 8
#define Timer_3__TIMER 1
#define Timer_3__QUAD 3
#define Timer_3__PWM_SEL 7

#define Timer_3__COUNT_UP 0
#define Timer_3__COUNT_DOWN 1
#define Timer_3__COUNT_UPDOWN0 2
#define Timer_3__COUNT_UPDOWN1 3


/* Prescaler */
#define Timer_3_PRESCALE_DIVBY1                ((uint32)(0u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY2                ((uint32)(1u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY4                ((uint32)(2u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY8                ((uint32)(3u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY16               ((uint32)(4u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY32               ((uint32)(5u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY64               ((uint32)(6u << Timer_3_PRESCALER_SHIFT))
#define Timer_3_PRESCALE_DIVBY128              ((uint32)(7u << Timer_3_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Timer_3_MODE_TIMER_COMPARE             ((uint32)(Timer_3__COMPARE         <<  \
                                                                  Timer_3_MODE_SHIFT))
#define Timer_3_MODE_TIMER_CAPTURE             ((uint32)(Timer_3__CAPTURE         <<  \
                                                                  Timer_3_MODE_SHIFT))
#define Timer_3_MODE_QUAD                      ((uint32)(Timer_3__QUAD            <<  \
                                                                  Timer_3_MODE_SHIFT))
#define Timer_3_MODE_PWM                       ((uint32)(Timer_3__PWM             <<  \
                                                                  Timer_3_MODE_SHIFT))
#define Timer_3_MODE_PWM_DT                    ((uint32)(Timer_3__PWM_DT          <<  \
                                                                  Timer_3_MODE_SHIFT))
#define Timer_3_MODE_PWM_PR                    ((uint32)(Timer_3__PWM_PR          <<  \
                                                                  Timer_3_MODE_SHIFT))

/* Quad Modes */
#define Timer_3_MODE_X1                        ((uint32)(Timer_3__X1              <<  \
                                                                  Timer_3_QUAD_MODE_SHIFT))
#define Timer_3_MODE_X2                        ((uint32)(Timer_3__X2              <<  \
                                                                  Timer_3_QUAD_MODE_SHIFT))
#define Timer_3_MODE_X4                        ((uint32)(Timer_3__X4              <<  \
                                                                  Timer_3_QUAD_MODE_SHIFT))

/* Counter modes */
#define Timer_3_COUNT_UP                       ((uint32)(Timer_3__COUNT_UP        <<  \
                                                                  Timer_3_UPDOWN_SHIFT))
#define Timer_3_COUNT_DOWN                     ((uint32)(Timer_3__COUNT_DOWN      <<  \
                                                                  Timer_3_UPDOWN_SHIFT))
#define Timer_3_COUNT_UPDOWN0                  ((uint32)(Timer_3__COUNT_UPDOWN0   <<  \
                                                                  Timer_3_UPDOWN_SHIFT))
#define Timer_3_COUNT_UPDOWN1                  ((uint32)(Timer_3__COUNT_UPDOWN1   <<  \
                                                                  Timer_3_UPDOWN_SHIFT))

/* PWM output invert */
#define Timer_3_INVERT_LINE                    ((uint32)(Timer_3__INVERSE         <<  \
                                                                  Timer_3_INV_OUT_SHIFT))
#define Timer_3_INVERT_LINE_N                  ((uint32)(Timer_3__INVERSE         <<  \
                                                                  Timer_3_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Timer_3_TRIG_RISING                    ((uint32)Timer_3__TRIG_RISING)
#define Timer_3_TRIG_FALLING                   ((uint32)Timer_3__TRIG_FALLING)
#define Timer_3_TRIG_BOTH                      ((uint32)Timer_3__TRIG_BOTH)
#define Timer_3_TRIG_LEVEL                     ((uint32)Timer_3__TRIG_LEVEL)

/* Interrupt mask */
#define Timer_3_INTR_MASK_TC                   ((uint32)Timer_3__INTR_MASK_TC)
#define Timer_3_INTR_MASK_CC_MATCH             ((uint32)Timer_3__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Timer_3_CC_MATCH_SET                   (0x00u)
#define Timer_3_CC_MATCH_CLEAR                 (0x01u)
#define Timer_3_CC_MATCH_INVERT                (0x02u)
#define Timer_3_CC_MATCH_NO_CHANGE             (0x03u)
#define Timer_3_OVERLOW_SET                    (0x00u)
#define Timer_3_OVERLOW_CLEAR                  (0x04u)
#define Timer_3_OVERLOW_INVERT                 (0x08u)
#define Timer_3_OVERLOW_NO_CHANGE              (0x0Cu)
#define Timer_3_UNDERFLOW_SET                  (0x00u)
#define Timer_3_UNDERFLOW_CLEAR                (0x10u)
#define Timer_3_UNDERFLOW_INVERT               (0x20u)
#define Timer_3_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Timer_3_PWM_MODE_LEFT                  (Timer_3_CC_MATCH_CLEAR        |   \
                                                         Timer_3_OVERLOW_SET           |   \
                                                         Timer_3_UNDERFLOW_NO_CHANGE)
#define Timer_3_PWM_MODE_RIGHT                 (Timer_3_CC_MATCH_SET          |   \
                                                         Timer_3_OVERLOW_NO_CHANGE     |   \
                                                         Timer_3_UNDERFLOW_CLEAR)
#define Timer_3_PWM_MODE_ASYM                  (Timer_3_CC_MATCH_INVERT       |   \
                                                         Timer_3_OVERLOW_SET           |   \
                                                         Timer_3_UNDERFLOW_CLEAR)

#if (Timer_3_CY_TCPWM_V2)
    #if(Timer_3_CY_TCPWM_4000)
        #define Timer_3_PWM_MODE_CENTER                (Timer_3_CC_MATCH_INVERT       |   \
                                                                 Timer_3_OVERLOW_NO_CHANGE     |   \
                                                                 Timer_3_UNDERFLOW_CLEAR)
    #else
        #define Timer_3_PWM_MODE_CENTER                (Timer_3_CC_MATCH_INVERT       |   \
                                                                 Timer_3_OVERLOW_SET           |   \
                                                                 Timer_3_UNDERFLOW_CLEAR)
    #endif /* (Timer_3_CY_TCPWM_4000) */
#else
    #define Timer_3_PWM_MODE_CENTER                (Timer_3_CC_MATCH_INVERT       |   \
                                                             Timer_3_OVERLOW_NO_CHANGE     |   \
                                                             Timer_3_UNDERFLOW_CLEAR)
#endif /* (Timer_3_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Timer_3_CMD_CAPTURE                    (0u)
#define Timer_3_CMD_RELOAD                     (8u)
#define Timer_3_CMD_STOP                       (16u)
#define Timer_3_CMD_START                      (24u)

/* Status */
#define Timer_3_STATUS_DOWN                    (1u)
#define Timer_3_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Timer_3_Init(void);
void   Timer_3_Enable(void);
void   Timer_3_Start(void);
void   Timer_3_Stop(void);

void   Timer_3_SetMode(uint32 mode);
void   Timer_3_SetCounterMode(uint32 counterMode);
void   Timer_3_SetPWMMode(uint32 modeMask);
void   Timer_3_SetQDMode(uint32 qdMode);

void   Timer_3_SetPrescaler(uint32 prescaler);
void   Timer_3_TriggerCommand(uint32 mask, uint32 command);
void   Timer_3_SetOneShot(uint32 oneShotEnable);
uint32 Timer_3_ReadStatus(void);

void   Timer_3_SetPWMSyncKill(uint32 syncKillEnable);
void   Timer_3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Timer_3_SetPWMDeadTime(uint32 deadTime);
void   Timer_3_SetPWMInvert(uint32 mask);

void   Timer_3_SetInterruptMode(uint32 interruptMask);
uint32 Timer_3_GetInterruptSourceMasked(void);
uint32 Timer_3_GetInterruptSource(void);
void   Timer_3_ClearInterrupt(uint32 interruptMask);
void   Timer_3_SetInterrupt(uint32 interruptMask);

void   Timer_3_WriteCounter(uint32 count);
uint32 Timer_3_ReadCounter(void);

uint32 Timer_3_ReadCapture(void);
uint32 Timer_3_ReadCaptureBuf(void);

void   Timer_3_WritePeriod(uint32 period);
uint32 Timer_3_ReadPeriod(void);
void   Timer_3_WritePeriodBuf(uint32 periodBuf);
uint32 Timer_3_ReadPeriodBuf(void);

void   Timer_3_WriteCompare(uint32 compare);
uint32 Timer_3_ReadCompare(void);
void   Timer_3_WriteCompareBuf(uint32 compareBuf);
uint32 Timer_3_ReadCompareBuf(void);

void   Timer_3_SetPeriodSwap(uint32 swapEnable);
void   Timer_3_SetCompareSwap(uint32 swapEnable);

void   Timer_3_SetCaptureMode(uint32 triggerMode);
void   Timer_3_SetReloadMode(uint32 triggerMode);
void   Timer_3_SetStartMode(uint32 triggerMode);
void   Timer_3_SetStopMode(uint32 triggerMode);
void   Timer_3_SetCountMode(uint32 triggerMode);

void   Timer_3_SaveConfig(void);
void   Timer_3_RestoreConfig(void);
void   Timer_3_Sleep(void);
void   Timer_3_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Timer_3_BLOCK_CONTROL_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Timer_3_BLOCK_CONTROL_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Timer_3_COMMAND_REG                    (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Timer_3_COMMAND_PTR                    ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Timer_3_INTRRUPT_CAUSE_REG             (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Timer_3_INTRRUPT_CAUSE_PTR             ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Timer_3_CONTROL_REG                    (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__CTRL )
#define Timer_3_CONTROL_PTR                    ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__CTRL )
#define Timer_3_STATUS_REG                     (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__STATUS )
#define Timer_3_STATUS_PTR                     ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__STATUS )
#define Timer_3_COUNTER_REG                    (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__COUNTER )
#define Timer_3_COUNTER_PTR                    ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__COUNTER )
#define Timer_3_COMP_CAP_REG                   (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__CC )
#define Timer_3_COMP_CAP_PTR                   ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__CC )
#define Timer_3_COMP_CAP_BUF_REG               (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define Timer_3_COMP_CAP_BUF_PTR               ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define Timer_3_PERIOD_REG                     (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__PERIOD )
#define Timer_3_PERIOD_PTR                     ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__PERIOD )
#define Timer_3_PERIOD_BUF_REG                 (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Timer_3_PERIOD_BUF_PTR                 ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Timer_3_TRIG_CONTROL0_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Timer_3_TRIG_CONTROL0_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Timer_3_TRIG_CONTROL1_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Timer_3_TRIG_CONTROL1_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Timer_3_TRIG_CONTROL2_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Timer_3_TRIG_CONTROL2_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Timer_3_INTERRUPT_REQ_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR )
#define Timer_3_INTERRUPT_REQ_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR )
#define Timer_3_INTERRUPT_SET_REG              (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_SET )
#define Timer_3_INTERRUPT_SET_PTR              ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_SET )
#define Timer_3_INTERRUPT_MASK_REG             (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define Timer_3_INTERRUPT_MASK_PTR             ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define Timer_3_INTERRUPT_MASKED_REG           (*(reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Timer_3_INTERRUPT_MASKED_PTR           ( (reg32 *) Timer_3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Timer_3_MASK                           ((uint32)Timer_3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Timer_3_RELOAD_CC_SHIFT                (0u)
#define Timer_3_RELOAD_PERIOD_SHIFT            (1u)
#define Timer_3_PWM_SYNC_KILL_SHIFT            (2u)
#define Timer_3_PWM_STOP_KILL_SHIFT            (3u)
#define Timer_3_PRESCALER_SHIFT                (8u)
#define Timer_3_UPDOWN_SHIFT                   (16u)
#define Timer_3_ONESHOT_SHIFT                  (18u)
#define Timer_3_QUAD_MODE_SHIFT                (20u)
#define Timer_3_INV_OUT_SHIFT                  (20u)
#define Timer_3_INV_COMPL_OUT_SHIFT            (21u)
#define Timer_3_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Timer_3_RELOAD_CC_MASK                 ((uint32)(Timer_3_1BIT_MASK        <<  \
                                                                            Timer_3_RELOAD_CC_SHIFT))
#define Timer_3_RELOAD_PERIOD_MASK             ((uint32)(Timer_3_1BIT_MASK        <<  \
                                                                            Timer_3_RELOAD_PERIOD_SHIFT))
#define Timer_3_PWM_SYNC_KILL_MASK             ((uint32)(Timer_3_1BIT_MASK        <<  \
                                                                            Timer_3_PWM_SYNC_KILL_SHIFT))
#define Timer_3_PWM_STOP_KILL_MASK             ((uint32)(Timer_3_1BIT_MASK        <<  \
                                                                            Timer_3_PWM_STOP_KILL_SHIFT))
#define Timer_3_PRESCALER_MASK                 ((uint32)(Timer_3_8BIT_MASK        <<  \
                                                                            Timer_3_PRESCALER_SHIFT))
#define Timer_3_UPDOWN_MASK                    ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                            Timer_3_UPDOWN_SHIFT))
#define Timer_3_ONESHOT_MASK                   ((uint32)(Timer_3_1BIT_MASK        <<  \
                                                                            Timer_3_ONESHOT_SHIFT))
#define Timer_3_QUAD_MODE_MASK                 ((uint32)(Timer_3_3BIT_MASK        <<  \
                                                                            Timer_3_QUAD_MODE_SHIFT))
#define Timer_3_INV_OUT_MASK                   ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                            Timer_3_INV_OUT_SHIFT))
#define Timer_3_MODE_MASK                      ((uint32)(Timer_3_3BIT_MASK        <<  \
                                                                            Timer_3_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Timer_3_CAPTURE_SHIFT                  (0u)
#define Timer_3_COUNT_SHIFT                    (2u)
#define Timer_3_RELOAD_SHIFT                   (4u)
#define Timer_3_STOP_SHIFT                     (6u)
#define Timer_3_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Timer_3_CAPTURE_MASK                   ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                  Timer_3_CAPTURE_SHIFT))
#define Timer_3_COUNT_MASK                     ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                  Timer_3_COUNT_SHIFT))
#define Timer_3_RELOAD_MASK                    ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                  Timer_3_RELOAD_SHIFT))
#define Timer_3_STOP_MASK                      ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                  Timer_3_STOP_SHIFT))
#define Timer_3_START_MASK                     ((uint32)(Timer_3_2BIT_MASK        <<  \
                                                                  Timer_3_START_SHIFT))

/* MASK */
#define Timer_3_1BIT_MASK                      ((uint32)0x01u)
#define Timer_3_2BIT_MASK                      ((uint32)0x03u)
#define Timer_3_3BIT_MASK                      ((uint32)0x07u)
#define Timer_3_6BIT_MASK                      ((uint32)0x3Fu)
#define Timer_3_8BIT_MASK                      ((uint32)0xFFu)
#define Timer_3_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Timer_3_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Timer_3_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Timer_3_QUAD_ENCODING_MODES     << Timer_3_QUAD_MODE_SHIFT))       |\
         ((uint32)(Timer_3_CONFIG                  << Timer_3_MODE_SHIFT)))

#define Timer_3_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Timer_3_PWM_STOP_EVENT          << Timer_3_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Timer_3_PWM_OUT_INVERT          << Timer_3_INV_OUT_SHIFT))         |\
         ((uint32)(Timer_3_PWM_OUT_N_INVERT        << Timer_3_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Timer_3_PWM_MODE                << Timer_3_MODE_SHIFT)))

#define Timer_3_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Timer_3_PWM_RUN_MODE         << Timer_3_ONESHOT_SHIFT))
            
#define Timer_3_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Timer_3_PWM_ALIGN            << Timer_3_UPDOWN_SHIFT))

#define Timer_3_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Timer_3_PWM_KILL_EVENT      << Timer_3_PWM_SYNC_KILL_SHIFT))

#define Timer_3_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Timer_3_PWM_DEAD_TIME_CYCLE  << Timer_3_PRESCALER_SHIFT))

#define Timer_3_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Timer_3_PWM_PRESCALER        << Timer_3_PRESCALER_SHIFT))

#define Timer_3_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Timer_3_TC_PRESCALER            << Timer_3_PRESCALER_SHIFT))       |\
         ((uint32)(Timer_3_TC_COUNTER_MODE         << Timer_3_UPDOWN_SHIFT))          |\
         ((uint32)(Timer_3_TC_RUN_MODE             << Timer_3_ONESHOT_SHIFT))         |\
         ((uint32)(Timer_3_TC_COMP_CAP_MODE        << Timer_3_MODE_SHIFT)))
        
#define Timer_3_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Timer_3_QUAD_PHIA_SIGNAL_MODE   << Timer_3_COUNT_SHIFT))           |\
         ((uint32)(Timer_3_QUAD_INDEX_SIGNAL_MODE  << Timer_3_RELOAD_SHIFT))          |\
         ((uint32)(Timer_3_QUAD_STOP_SIGNAL_MODE   << Timer_3_STOP_SHIFT))            |\
         ((uint32)(Timer_3_QUAD_PHIB_SIGNAL_MODE   << Timer_3_START_SHIFT)))

#define Timer_3_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Timer_3_PWM_SWITCH_SIGNAL_MODE  << Timer_3_CAPTURE_SHIFT))         |\
         ((uint32)(Timer_3_PWM_COUNT_SIGNAL_MODE   << Timer_3_COUNT_SHIFT))           |\
         ((uint32)(Timer_3_PWM_RELOAD_SIGNAL_MODE  << Timer_3_RELOAD_SHIFT))          |\
         ((uint32)(Timer_3_PWM_STOP_SIGNAL_MODE    << Timer_3_STOP_SHIFT))            |\
         ((uint32)(Timer_3_PWM_START_SIGNAL_MODE   << Timer_3_START_SHIFT)))

#define Timer_3_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Timer_3_TC_CAPTURE_SIGNAL_MODE  << Timer_3_CAPTURE_SHIFT))         |\
         ((uint32)(Timer_3_TC_COUNT_SIGNAL_MODE    << Timer_3_COUNT_SHIFT))           |\
         ((uint32)(Timer_3_TC_RELOAD_SIGNAL_MODE   << Timer_3_RELOAD_SHIFT))          |\
         ((uint32)(Timer_3_TC_STOP_SIGNAL_MODE     << Timer_3_STOP_SHIFT))            |\
         ((uint32)(Timer_3_TC_START_SIGNAL_MODE    << Timer_3_START_SHIFT)))
        
#define Timer_3_TIMER_UPDOWN_CNT_USED                                                          \
                ((Timer_3__COUNT_UPDOWN0 == Timer_3_TC_COUNTER_MODE)                  ||\
                 (Timer_3__COUNT_UPDOWN1 == Timer_3_TC_COUNTER_MODE))

#define Timer_3_PWM_UPDOWN_CNT_USED                                                            \
                ((Timer_3__CENTER == Timer_3_PWM_ALIGN)                               ||\
                 (Timer_3__ASYMMETRIC == Timer_3_PWM_ALIGN))               
        
#define Timer_3_PWM_PR_INIT_VALUE              (1u)
#define Timer_3_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Timer_3_H */

/* [] END OF FILE */
