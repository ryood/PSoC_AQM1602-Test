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
#include <stdio.h>

#include "SPLC792-I2C.h"

int main()
{
    char8 lcdLine[17];
    int cnt = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    I2CM_LCD_Start();
    
    Pin_LCD_Reset_Write(0u);
	CyDelay(1);
	Pin_LCD_Reset_Write(1u);
	CyDelay(10);
    
    LCD_Init(0x3e, 63);
    LCD_Clear();
    LCD_Puts("Hello World");

    for(;;)
    {
        sprintf(lcdLine, "PSoC 5LP %d", cnt);
        LCD_SetPos(0, 1);
        LCD_Puts(lcdLine);
        
        cnt++;
    }
}

/* [] END OF FILE */
