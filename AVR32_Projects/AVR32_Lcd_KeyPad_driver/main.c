/*
 * Lcd_KeyPad_driver.c
 *
 * Created: 7/6/2021 5:32:02 PM
 * Author : Diaa Abayazeed
 */ 

#include "LCD_Driver_/LCD.h"
#include "KeyPad_Driver/KeyPad.h"
int main(void)
{
	Init_LCD ();
	Init_KeyPad();
	unsigned char Pressed_data ;
    /* Replace with your application code */
    while (1) 
    {
		/*
		Send_Command (LCD_ENTRY_MODE);
		Send_Command (LCD_DISP_ON_CURSOR);
		Send_Command (LCD_BEGIN_AT_FIRST_ROW);
*/
		Pressed_data =Get_Data();
		switch(Pressed_data){
			case 'N':
				break;
			case '!':
				clear_screan();
				break;
			default:
				Send_data(Pressed_data);
				break;			
		}
    }
}

