/*******************************************************************************
* File Name: Cam_sel_PWM.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the Cam_sel_PWM
*  component
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

#include "Cam_sel_PWM.h"

uint8 Cam_sel_PWM_initVar = 0u;


/*******************************************************************************
* Function Name: Cam_sel_PWM_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default Cam_sel_PWM configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (Cam_sel_PWM__QUAD == Cam_sel_PWM_CONFIG)
        Cam_sel_PWM_CONTROL_REG = Cam_sel_PWM_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Cam_sel_PWM_TRIG_CONTROL1_REG  = Cam_sel_PWM_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        Cam_sel_PWM_SetInterruptMode(Cam_sel_PWM_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        Cam_sel_PWM_SetCounterMode(Cam_sel_PWM_COUNT_DOWN);
        Cam_sel_PWM_WritePeriod(Cam_sel_PWM_QUAD_PERIOD_INIT_VALUE);
        Cam_sel_PWM_WriteCounter(Cam_sel_PWM_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (Cam_sel_PWM__QUAD == Cam_sel_PWM_CONFIG) */

    #if (Cam_sel_PWM__TIMER == Cam_sel_PWM_CONFIG)
        Cam_sel_PWM_CONTROL_REG = Cam_sel_PWM_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        Cam_sel_PWM_TRIG_CONTROL1_REG  = Cam_sel_PWM_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Cam_sel_PWM_SetInterruptMode(Cam_sel_PWM_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        Cam_sel_PWM_WritePeriod(Cam_sel_PWM_TC_PERIOD_VALUE );

        #if (Cam_sel_PWM__COMPARE == Cam_sel_PWM_TC_COMP_CAP_MODE)
            Cam_sel_PWM_WriteCompare(Cam_sel_PWM_TC_COMPARE_VALUE);

            #if (1u == Cam_sel_PWM_TC_COMPARE_SWAP)
                Cam_sel_PWM_SetCompareSwap(1u);
                Cam_sel_PWM_WriteCompareBuf(Cam_sel_PWM_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == Cam_sel_PWM_TC_COMPARE_SWAP) */
        #endif  /* (Cam_sel_PWM__COMPARE == Cam_sel_PWM_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (Cam_sel_PWM_CY_TCPWM_V2 && Cam_sel_PWM_TIMER_UPDOWN_CNT_USED && !Cam_sel_PWM_CY_TCPWM_4000)
            Cam_sel_PWM_WriteCounter(1u);
        #elif(Cam_sel_PWM__COUNT_DOWN == Cam_sel_PWM_TC_COUNTER_MODE)
            Cam_sel_PWM_WriteCounter(Cam_sel_PWM_TC_PERIOD_VALUE);
        #else
            Cam_sel_PWM_WriteCounter(0u);
        #endif /* (Cam_sel_PWM_CY_TCPWM_V2 && Cam_sel_PWM_TIMER_UPDOWN_CNT_USED && !Cam_sel_PWM_CY_TCPWM_4000) */
    #endif  /* (Cam_sel_PWM__TIMER == Cam_sel_PWM_CONFIG) */

    #if (Cam_sel_PWM__PWM_SEL == Cam_sel_PWM_CONFIG)
        Cam_sel_PWM_CONTROL_REG = Cam_sel_PWM_CTRL_PWM_BASE_CONFIG;

        #if (Cam_sel_PWM__PWM_PR == Cam_sel_PWM_PWM_MODE)
            Cam_sel_PWM_CONTROL_REG |= Cam_sel_PWM_CTRL_PWM_RUN_MODE;
            Cam_sel_PWM_WriteCounter(Cam_sel_PWM_PWM_PR_INIT_VALUE);
        #else
            Cam_sel_PWM_CONTROL_REG |= Cam_sel_PWM_CTRL_PWM_ALIGN | Cam_sel_PWM_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (Cam_sel_PWM_CY_TCPWM_V2 && Cam_sel_PWM_PWM_UPDOWN_CNT_USED && !Cam_sel_PWM_CY_TCPWM_4000)
                Cam_sel_PWM_WriteCounter(1u);
            #elif (Cam_sel_PWM__RIGHT == Cam_sel_PWM_PWM_ALIGN)
                Cam_sel_PWM_WriteCounter(Cam_sel_PWM_PWM_PERIOD_VALUE);
            #else 
                Cam_sel_PWM_WriteCounter(0u);
            #endif  /* (Cam_sel_PWM_CY_TCPWM_V2 && Cam_sel_PWM_PWM_UPDOWN_CNT_USED && !Cam_sel_PWM_CY_TCPWM_4000) */
        #endif  /* (Cam_sel_PWM__PWM_PR == Cam_sel_PWM_PWM_MODE) */

        #if (Cam_sel_PWM__PWM_DT == Cam_sel_PWM_PWM_MODE)
            Cam_sel_PWM_CONTROL_REG |= Cam_sel_PWM_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (Cam_sel_PWM__PWM_DT == Cam_sel_PWM_PWM_MODE) */

        #if (Cam_sel_PWM__PWM == Cam_sel_PWM_PWM_MODE)
            Cam_sel_PWM_CONTROL_REG |= Cam_sel_PWM_CTRL_PWM_PRESCALER;
        #endif  /* (Cam_sel_PWM__PWM == Cam_sel_PWM_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        Cam_sel_PWM_TRIG_CONTROL1_REG  = Cam_sel_PWM_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        Cam_sel_PWM_SetInterruptMode(Cam_sel_PWM_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (Cam_sel_PWM__PWM_PR == Cam_sel_PWM_PWM_MODE)
            Cam_sel_PWM_TRIG_CONTROL2_REG =
                    (Cam_sel_PWM_CC_MATCH_NO_CHANGE    |
                    Cam_sel_PWM_OVERLOW_NO_CHANGE      |
                    Cam_sel_PWM_UNDERFLOW_NO_CHANGE);
        #else
            #if (Cam_sel_PWM__LEFT == Cam_sel_PWM_PWM_ALIGN)
                Cam_sel_PWM_TRIG_CONTROL2_REG = Cam_sel_PWM_PWM_MODE_LEFT;
            #endif  /* ( Cam_sel_PWM_PWM_LEFT == Cam_sel_PWM_PWM_ALIGN) */

            #if (Cam_sel_PWM__RIGHT == Cam_sel_PWM_PWM_ALIGN)
                Cam_sel_PWM_TRIG_CONTROL2_REG = Cam_sel_PWM_PWM_MODE_RIGHT;
            #endif  /* ( Cam_sel_PWM_PWM_RIGHT == Cam_sel_PWM_PWM_ALIGN) */

            #if (Cam_sel_PWM__CENTER == Cam_sel_PWM_PWM_ALIGN)
                Cam_sel_PWM_TRIG_CONTROL2_REG = Cam_sel_PWM_PWM_MODE_CENTER;
            #endif  /* ( Cam_sel_PWM_PWM_CENTER == Cam_sel_PWM_PWM_ALIGN) */

            #if (Cam_sel_PWM__ASYMMETRIC == Cam_sel_PWM_PWM_ALIGN)
                Cam_sel_PWM_TRIG_CONTROL2_REG = Cam_sel_PWM_PWM_MODE_ASYM;
            #endif  /* (Cam_sel_PWM__ASYMMETRIC == Cam_sel_PWM_PWM_ALIGN) */
        #endif  /* (Cam_sel_PWM__PWM_PR == Cam_sel_PWM_PWM_MODE) */

        /* Set other values from customizer */
        Cam_sel_PWM_WritePeriod(Cam_sel_PWM_PWM_PERIOD_VALUE );
        Cam_sel_PWM_WriteCompare(Cam_sel_PWM_PWM_COMPARE_VALUE);

        #if (1u == Cam_sel_PWM_PWM_COMPARE_SWAP)
            Cam_sel_PWM_SetCompareSwap(1u);
            Cam_sel_PWM_WriteCompareBuf(Cam_sel_PWM_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == Cam_sel_PWM_PWM_COMPARE_SWAP) */

        #if (1u == Cam_sel_PWM_PWM_PERIOD_SWAP)
            Cam_sel_PWM_SetPeriodSwap(1u);
            Cam_sel_PWM_WritePeriodBuf(Cam_sel_PWM_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == Cam_sel_PWM_PWM_PERIOD_SWAP) */
    #endif  /* (Cam_sel_PWM__PWM_SEL == Cam_sel_PWM_CONFIG) */
    
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_Enable
********************************************************************************
*
* Summary:
*  Enables the Cam_sel_PWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Cam_sel_PWM_BLOCK_CONTROL_REG |= Cam_sel_PWM_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (Cam_sel_PWM__PWM_SEL == Cam_sel_PWM_CONFIG)
        #if (0u == Cam_sel_PWM_PWM_START_SIGNAL_PRESENT)
            Cam_sel_PWM_TriggerCommand(Cam_sel_PWM_MASK, Cam_sel_PWM_CMD_START);
        #endif /* (0u == Cam_sel_PWM_PWM_START_SIGNAL_PRESENT) */
    #endif /* (Cam_sel_PWM__PWM_SEL == Cam_sel_PWM_CONFIG) */

    #if (Cam_sel_PWM__TIMER == Cam_sel_PWM_CONFIG)
        #if (0u == Cam_sel_PWM_TC_START_SIGNAL_PRESENT)
            Cam_sel_PWM_TriggerCommand(Cam_sel_PWM_MASK, Cam_sel_PWM_CMD_START);
        #endif /* (0u == Cam_sel_PWM_TC_START_SIGNAL_PRESENT) */
    #endif /* (Cam_sel_PWM__TIMER == Cam_sel_PWM_CONFIG) */
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_Start
********************************************************************************
*
* Summary:
*  Initializes the Cam_sel_PWM with default customizer
*  values when called the first time and enables the Cam_sel_PWM.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Cam_sel_PWM_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time Cam_sel_PWM_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the Cam_sel_PWM_Start() routine.
*
*******************************************************************************/
void Cam_sel_PWM_Start(void)
{
    if (0u == Cam_sel_PWM_initVar)
    {
        Cam_sel_PWM_Init();
        Cam_sel_PWM_initVar = 1u;
    }

    Cam_sel_PWM_Enable();
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_Stop
********************************************************************************
*
* Summary:
*  Disables the Cam_sel_PWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_BLOCK_CONTROL_REG &= (uint32)~Cam_sel_PWM_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the Cam_sel_PWM. This function is used when
*  configured as a generic Cam_sel_PWM and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the Cam_sel_PWM to operate in
*   Values:
*   - Cam_sel_PWM_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - Cam_sel_PWM_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - Cam_sel_PWM_MODE_QUAD - Quadrature decoder
*         - Cam_sel_PWM_MODE_PWM - PWM
*         - Cam_sel_PWM_MODE_PWM_DT - PWM with dead time
*         - Cam_sel_PWM_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_MODE_MASK;
    Cam_sel_PWM_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - Cam_sel_PWM_MODE_X1 - Counts on phi 1 rising
*         - Cam_sel_PWM_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - Cam_sel_PWM_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_QUAD_MODE_MASK;
    Cam_sel_PWM_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - Cam_sel_PWM_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - Cam_sel_PWM_PRESCALE_DIVBY2    - Divide by 2
*         - Cam_sel_PWM_PRESCALE_DIVBY4    - Divide by 4
*         - Cam_sel_PWM_PRESCALE_DIVBY8    - Divide by 8
*         - Cam_sel_PWM_PRESCALE_DIVBY16   - Divide by 16
*         - Cam_sel_PWM_PRESCALE_DIVBY32   - Divide by 32
*         - Cam_sel_PWM_PRESCALE_DIVBY64   - Divide by 64
*         - Cam_sel_PWM_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_PRESCALER_MASK;
    Cam_sel_PWM_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the Cam_sel_PWM runs
*  continuously or stops when terminal count is reached.  By default the
*  Cam_sel_PWM operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_ONESHOT_MASK;
    Cam_sel_PWM_CONTROL_REG |= ((uint32)((oneShotEnable & Cam_sel_PWM_1BIT_MASK) <<
                                                               Cam_sel_PWM_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPWMMode(uint32 modeMask)
{
    Cam_sel_PWM_TRIG_CONTROL2_REG = (modeMask & Cam_sel_PWM_6BIT_MASK);
}



/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_PWM_SYNC_KILL_MASK;
    Cam_sel_PWM_CONTROL_REG |= ((uint32)((syncKillEnable & Cam_sel_PWM_1BIT_MASK)  <<
                                               Cam_sel_PWM_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_PWM_STOP_KILL_MASK;
    Cam_sel_PWM_CONTROL_REG |= ((uint32)((stopOnKillEnable & Cam_sel_PWM_1BIT_MASK)  <<
                                                         Cam_sel_PWM_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_PRESCALER_MASK;
    Cam_sel_PWM_CONTROL_REG |= ((uint32)((deadTime & Cam_sel_PWM_8BIT_MASK) <<
                                                          Cam_sel_PWM_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - Cam_sel_PWM_INVERT_LINE   - Inverts the line output
*         - Cam_sel_PWM_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_INV_OUT_MASK;
    Cam_sel_PWM_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: Cam_sel_PWM_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_WriteCounter(uint32 count)
{
    Cam_sel_PWM_COUNTER_REG = (count & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadCounter(void)
{
    return (Cam_sel_PWM_COUNTER_REG & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - Cam_sel_PWM_COUNT_UP       - Counts up
*     - Cam_sel_PWM_COUNT_DOWN     - Counts down
*     - Cam_sel_PWM_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - Cam_sel_PWM_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_UPDOWN_MASK;
    Cam_sel_PWM_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_WritePeriod(uint32 period)
{
    Cam_sel_PWM_PERIOD_REG = (period & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadPeriod(void)
{
    return (Cam_sel_PWM_PERIOD_REG & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_RELOAD_CC_MASK;
    Cam_sel_PWM_CONTROL_REG |= (swapEnable & Cam_sel_PWM_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_WritePeriodBuf(uint32 periodBuf)
{
    Cam_sel_PWM_PERIOD_BUF_REG = (periodBuf & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadPeriodBuf(void)
{
    return (Cam_sel_PWM_PERIOD_BUF_REG & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_CONTROL_REG &= (uint32)~Cam_sel_PWM_RELOAD_PERIOD_MASK;
    Cam_sel_PWM_CONTROL_REG |= ((uint32)((swapEnable & Cam_sel_PWM_1BIT_MASK) <<
                                                            Cam_sel_PWM_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_WriteCompare(uint32 compare)
{
    #if (Cam_sel_PWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */

    #if (Cam_sel_PWM_CY_TCPWM_4000)
        currentMode = ((Cam_sel_PWM_CONTROL_REG & Cam_sel_PWM_UPDOWN_MASK) >> Cam_sel_PWM_UPDOWN_SHIFT);

        if (((uint32)Cam_sel_PWM__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)Cam_sel_PWM__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */
    
    Cam_sel_PWM_COMP_CAP_REG = (compare & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadCompare(void)
{
    #if (Cam_sel_PWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */

    #if (Cam_sel_PWM_CY_TCPWM_4000)
        currentMode = ((Cam_sel_PWM_CONTROL_REG & Cam_sel_PWM_UPDOWN_MASK) >> Cam_sel_PWM_UPDOWN_SHIFT);
        
        regVal = Cam_sel_PWM_COMP_CAP_REG;
        
        if (((uint32)Cam_sel_PWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Cam_sel_PWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Cam_sel_PWM_16BIT_MASK);
    #else
        return (Cam_sel_PWM_COMP_CAP_REG & Cam_sel_PWM_16BIT_MASK);
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_WriteCompareBuf(uint32 compareBuf)
{
    #if (Cam_sel_PWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */

    #if (Cam_sel_PWM_CY_TCPWM_4000)
        currentMode = ((Cam_sel_PWM_CONTROL_REG & Cam_sel_PWM_UPDOWN_MASK) >> Cam_sel_PWM_UPDOWN_SHIFT);

        if (((uint32)Cam_sel_PWM__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)Cam_sel_PWM__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */
    
    Cam_sel_PWM_COMP_CAP_BUF_REG = (compareBuf & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadCompareBuf(void)
{
    #if (Cam_sel_PWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */

    #if (Cam_sel_PWM_CY_TCPWM_4000)
        currentMode = ((Cam_sel_PWM_CONTROL_REG & Cam_sel_PWM_UPDOWN_MASK) >> Cam_sel_PWM_UPDOWN_SHIFT);

        regVal = Cam_sel_PWM_COMP_CAP_BUF_REG;
        
        if (((uint32)Cam_sel_PWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)Cam_sel_PWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & Cam_sel_PWM_16BIT_MASK);
    #else
        return (Cam_sel_PWM_COMP_CAP_BUF_REG & Cam_sel_PWM_16BIT_MASK);
    #endif /* (Cam_sel_PWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadCapture(void)
{
    return (Cam_sel_PWM_COMP_CAP_REG & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadCaptureBuf(void)
{
    return (Cam_sel_PWM_COMP_CAP_BUF_REG & Cam_sel_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Cam_sel_PWM_TRIG_LEVEL     - Level
*     - Cam_sel_PWM_TRIG_RISING    - Rising edge
*     - Cam_sel_PWM_TRIG_FALLING   - Falling edge
*     - Cam_sel_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_TRIG_CONTROL1_REG &= (uint32)~Cam_sel_PWM_CAPTURE_MASK;
    Cam_sel_PWM_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Cam_sel_PWM_TRIG_LEVEL     - Level
*     - Cam_sel_PWM_TRIG_RISING    - Rising edge
*     - Cam_sel_PWM_TRIG_FALLING   - Falling edge
*     - Cam_sel_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_TRIG_CONTROL1_REG &= (uint32)~Cam_sel_PWM_RELOAD_MASK;
    Cam_sel_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Cam_sel_PWM_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Cam_sel_PWM_TRIG_LEVEL     - Level
*     - Cam_sel_PWM_TRIG_RISING    - Rising edge
*     - Cam_sel_PWM_TRIG_FALLING   - Falling edge
*     - Cam_sel_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_TRIG_CONTROL1_REG &= (uint32)~Cam_sel_PWM_START_MASK;
    Cam_sel_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Cam_sel_PWM_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Cam_sel_PWM_TRIG_LEVEL     - Level
*     - Cam_sel_PWM_TRIG_RISING    - Rising edge
*     - Cam_sel_PWM_TRIG_FALLING   - Falling edge
*     - Cam_sel_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_TRIG_CONTROL1_REG &= (uint32)~Cam_sel_PWM_STOP_MASK;
    Cam_sel_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Cam_sel_PWM_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - Cam_sel_PWM_TRIG_LEVEL     - Level
*     - Cam_sel_PWM_TRIG_RISING    - Rising edge
*     - Cam_sel_PWM_TRIG_FALLING   - Falling edge
*     - Cam_sel_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_TRIG_CONTROL1_REG &= (uint32)~Cam_sel_PWM_COUNT_MASK;
    Cam_sel_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << Cam_sel_PWM_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - Cam_sel_PWM_CMD_CAPTURE    - Trigger Capture command
*     - Cam_sel_PWM_CMD_RELOAD     - Trigger Reload command
*     - Cam_sel_PWM_CMD_STOP       - Trigger Stop command
*     - Cam_sel_PWM_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    Cam_sel_PWM_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the Cam_sel_PWM.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - Cam_sel_PWM_STATUS_DOWN    - Set if counting down
*     - Cam_sel_PWM_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 Cam_sel_PWM_ReadStatus(void)
{
    return ((Cam_sel_PWM_STATUS_REG >> Cam_sel_PWM_RUNNING_STATUS_SHIFT) |
            (Cam_sel_PWM_STATUS_REG & Cam_sel_PWM_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - Cam_sel_PWM_INTR_MASK_TC       - Terminal count mask
*     - Cam_sel_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetInterruptMode(uint32 interruptMask)
{
    Cam_sel_PWM_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - Cam_sel_PWM_INTR_MASK_TC       - Terminal count mask
*     - Cam_sel_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Cam_sel_PWM_GetInterruptSourceMasked(void)
{
    return (Cam_sel_PWM_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - Cam_sel_PWM_INTR_MASK_TC       - Terminal count mask
*     - Cam_sel_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 Cam_sel_PWM_GetInterruptSource(void)
{
    return (Cam_sel_PWM_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - Cam_sel_PWM_INTR_MASK_TC       - Terminal count mask
*     - Cam_sel_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_ClearInterrupt(uint32 interruptMask)
{
    Cam_sel_PWM_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: Cam_sel_PWM_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - Cam_sel_PWM_INTR_MASK_TC       - Terminal count mask
*     - Cam_sel_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void Cam_sel_PWM_SetInterrupt(uint32 interruptMask)
{
    Cam_sel_PWM_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
