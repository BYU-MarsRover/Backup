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
    Cam_Sel_timer_Start();
    Cam_sel_PWM_Start();
    Default_PWM_Start();
    

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {

        uint16 timer1 = Mux_timer_ReadCapture();
        uint16 cam_select_value = Cam_Sel_timer_ReadCapture();
      
        if(Arm_select_Read() == 0) 
        {
            if (timer1 >= 500 && timer1 <= 2500)
            {
                if (timer1 > 1700)
                {
                    LED_Write(1);
                    INPUT_SELECT_Write(1);
                }
                else
                {
                    LED_Write(0);
                    INPUT_SELECT_Write(0);
                }
            }
            else
            {
                INPUT_SELECT_Write(0);
                LED_Write(0);
            }
            
            if (cam_select_value >= 500 && cam_select_value <= 2500)
            {
                Cam_sel_PWM_WriteCompare(cam_select_value);
            }
            else
            {
                Cam_sel_PWM_WriteCompare(1500);
            }
            
            
        }
        else
        {
            INPUT_SELECT_Write(3);
            LED_Write(0);
        }
            
        

    }
}

/* [] END OF FILE */
