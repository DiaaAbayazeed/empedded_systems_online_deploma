/*
 * KeyPad.c
 *
 * Created: 7/12/2021 12:30:42 AM
 *  Author: Diaa Abayazeed
 */ 

#include "KeyPad.h"

	int Data_ROW[] ={R0,R1,R2,R3};
	int Data_COL[] ={C0,C1,C2,C3};

void Init_KeyPad()
{

	KeyPad_Dir &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));//direction of rows is input
	KeyPad_Dir |=((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));//direction of colums is output
	KeyPad_Data =0xff;//data in all pins is 1

	
	
}
char Get_Data()
{
	int i,j;
	for(i=0;i<4;i++){	
		KeyPad_Data |=((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));//put 1 in all colums
		KeyPad_Data &=~(1<< Data_COL[i]) ;
		for(j=0;j<4;j++){
			if(!(KeyPad_Input & (1 << Data_ROW[j])))
			{
				while(!(KeyPad_Input & (1 << Data_ROW[j])));//for avoid repeat data when press

				switch(i){
					case(0):
					if(j==0) return '7';
					else if(j==1) return '4';
					else if(j==2) return '1';
					else if(j==3) return '!';
					break;
					case(1):
					if(j==0) return '8';
					else if(j==1) return '5';
					else if(j==2) return '2';
					else if(j==3) return '0';
					break;
					case(2):
					if(j==0) return '9';
					else if(j==1) return '6';
					else if(j==2) return '3';
					else if(j==3) return '=';
					break;
					case(3):
					if(j==0) return '/';
					else if(j==1) return '*';
					else if(j==2) return '-';
					else if(j==3) return '+';
					break;
				}
						
			}			
		}	
	}
	return 'N';	
}