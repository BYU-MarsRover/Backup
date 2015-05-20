/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    Mux_timer_Start();
    Arm_select_timer_Start();
    Default_PWM_Start();
    

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {

        uint16 timer1 = Mux_timer_ReadCapture();
        uint16 arm_select_value = Arm_select_timer_ReadCapture();
      
       
            if (timer1 >= 500 && timer1 <= 2500)
            {
                if (timer1 > 1700)
                {
                    if(arm_select_value >= 500 && arm_select_value <= 2500 && arm_select_value > 1700)
                    {
                        LED_Write(1);
                        INPUT_SELECT_Write(1);
                        Arm_select_Write(1);
                    }
                    else
                    {
                        Arm_select_Write(0);
                        LED_Write(0);
                        INPUT_SELECT_Write(3);
                    }
                        
                    
                }
                else
                {
                    LED_Write(0);
                    INPUT_SELECT_Write(0);
                    Arm_select_Write(0);
                }
            }
            else
            {
                INPUT_SELECT_Write(0);
                LED_Write(0);
                Arm_select_Write(0);
            }       
            
    }
}
/* [] END OF FILE */
