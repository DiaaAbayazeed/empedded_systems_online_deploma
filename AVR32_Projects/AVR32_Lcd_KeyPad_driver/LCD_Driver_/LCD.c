/*
 * LCD.c
 *
 * Created: 7/7/2021 10:41:41 PM
 *  Author: Diaa Abayazeed
 */ 

#include "LCD.h"
void Init_LCD ()
{
	LCD_CONTROL_DIR=0xff;
	if (((PINA>> 7) & 1 )==1){
		IsBusy();		
	}
	LCD_data_DIR = 0xFF ; //port is OUTPUT
	LCD_CONTROL &=~(1<<RW_Switch); // turn RW off
	LCD_CONTROL &=~(1<<RS_Switch);
	#ifdef EIGHT_BIT_2_LINE
	    LCD_data = LCD_FUNCTION_8BIT_2LINES;
	#endif
	#ifdef FOUR_BIT_2_LINE
		LCD_data = LCD_FUNCTION_4BIT_2LINES;
	#endif
    LCD_data = 0x38;
	LCD_CONTROL &=~(1<<EN_Switch);
	_delay_ms(500);
	LCD_CONTROL |=(1<<EN_Switch);
	clear_screan();
	Send_Command(LCD_ENTRY_MODE);
	Send_Command(LCD_BEGIN_AT_FIRST_ROW);
	Send_Command(LCD_DISP_ON_CURSOR_BLINK);
}

void Send_Command (unsigned char Command)
{
	LCD_data =0xff;
	LCD_data_DIR = 0xFF ; //port is OUTPUT
	LCD_CONTROL &=~(1<<RW_Switch); // turn RW off
	LCD_CONTROL &=~(1<<RS_Switch);
	LCD_data = Command;
	LCD_CONTROL &=~(1<<EN_Switch);
	_delay_ms(500);
	LCD_CONTROL |=(1<<EN_Switch);	
	_delay_ms(20);
}
void IsBusy()
{
	LCD_data_DIR = 0x00 ; //port is input
	
	LCD_CONTROL |=(1<<RW_Switch);
	LCD_CONTROL &=~(1<<RS_Switch);	
}

void Send_data(unsigned char data){
		LCD_data_DIR = 0xFF ; //port is OUTPUT
		LCD_CONTROL &=~(1<<RW_Switch); // turn RW off
		LCD_CONTROL |=(1<<RS_Switch);
		LCD_data = data;
		LCD_CONTROL &=~(1<<EN_Switch);
		_delay_ms(500);
		LCD_CONTROL |=(1<<EN_Switch);
		_delay_ms(20);

}

void clear_screan (){
	
	Send_Command(LCD_CLEAR_SCREEN);	
}

void send_string (unsigned char* data)
{
int count =0;
	while(count<32){

		if(count<16){
			LCD_GOTO_XY(count,1);
			Send_data(*data);
		}
		else if( count>=16 && count<32 )
		{
					LCD_GOTO_XY(count,2);
					Send_data(*data);
		}	
		else 
		{
			clear_screan();
			count =0;
			LCD_GOTO_XY(count,1);

		}
				data++;
				count++;	
		
	}	
	
}

void LCD_GOTO_XY (int position,int row)
{
if (position<16 && row==1)
{
	Send_Command(LCD_BEGIN_AT_FIRST_ROW + position);
}
else if (position >=16 && row ==2)
{
	position-=16;
	Send_Command(0x3c);
	Send_Command(LCD_BEGIN_AT_SECOND_ROW + position);
}	
	
}