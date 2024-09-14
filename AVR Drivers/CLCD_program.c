/*
 * CLCD_program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: MaKa
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"util/delay.h"


void CLCD_init(void)
{

	DIO_enumSetPortDirection(CLCD_Data_Port,255);/*o/p*/
	DIO_enumSetPinDirection(CLCD_RS_PIN,CLCD_control_Port,DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_ENPIN,CLCD_control_Port,DIO_OUTPUT);
	_delay_ms(50);
	CLCD_WriteInes(0X38);
	CLCD_WriteInes(0X0C);
	CLCD_WriteInes(0X01);
	_delay_ms(1);
	CLCD_WriteInes(0X06);




}

void CLCD_WriteInes(U8 ins)
{
	DIO_enumSetPinValue(CLCD_RS_PIN,CLCD_control_Port,DIO_LOW);//send commend rs--->0
	DIO_enumSetPortValue(CLCD_Data_Port,ins);//function set /*PORTA_REG=0b00111000*/
	/*EN PULS*/
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);

}
void CLCD_WriteData(U8 Data)
{
	DIO_enumSetPinValue(CLCD_RS_PIN,CLCD_control_Port,DIO_HIGH);//send commend
	DIO_enumSetPortValue(CLCD_Data_Port,Data);//function set 0b1111000

	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);
}
void CLCD_WriteChar(U8 Char)
{
	CLCD_WriteData(Char);
}
void CLCD_GoTo(U8 Row,U8 Col)
{
	Col--;
	Row--;
	switch(Row)
	{
	case 0:CLCD_WriteInes(0X80+Col);break;
	case 1:CLCD_WriteInes(0XC0+Col);break;
	}
}
U8   ConvertNumToASCII(U8 Input)
{
	return Input+0X30;
}
void CLCD_WritNum(U64 NUM)
{
	U64 reverse=1;
	while(NUM!=0)
	{
		reverse=(reverse*10)+(NUM%10);
		NUM/=10;
	}
	while(reverse!=1)
	{
		CLCD_WriteData((reverse%10)+48);
		reverse/=10;
	}
}
void CLCD_PrintBinary(U8 num)
{

	for(S8 i=7;i>=0;i--)
	{
		CLCD_WriteData(GET_BIT(num,i)?'1':'0');
	}

}
U8 arr[] = {
		0x00,
		0x00,
		0x07,
		0x04,
		0x1F,
		0x00,
		0x00,
		0x00
};//-----------print
U8 arr_2[] = {
  0x00,
  0x00,
  0x07,
  0x05,
  0x1F,
  0x10,
  0x10,
  0x10
};

void CLCD_Draw_Char(U8 Address_Data)
{
	CLCD_WriteInes(0X40);//Set CCGram
    for(U8 i=0;i<8;i++)
    {
    	CLCD_WriteData(arr[i]);//Send Data to CGram
    }
   // CLCD_WriteInes(0X48);
    for(U8 i=0;i<8;i++)
        {
        	CLCD_WriteData(arr_2[i]);
        }
    CLCD_WriteInes(0X80);//set DDRam
    CLCD_WriteData(Address_Data);

}
void CLCD_ConvertNumToHex(U8 NUM)
{
	U8 Upper_bits=NUM>>4;
	U8 Lower_bits=NUM&0X0f;
	if(Upper_bits<10)
	{
		CLCD_WriteData('0'+Upper_bits);
	}else
	{
		CLCD_WriteData('A'+(Upper_bits-10));
	}
	if(Lower_bits<10)
		{
			CLCD_WriteData('0'+Lower_bits);
		}else
		{
			CLCD_WriteData('A'+(Lower_bits-10));
		}

}
/*void CLCD_SendString(U8 *String)
{
	U8 i=0;
	while(String[i]!='\0')
	{
		CLCD_WriteData(String[i]);
		i++;
	}
}*/

void CLCD_SendString(U8 *String)
{
/*
o
m
a
r
\0*/

	U8 i=0;
	while(String[i]!='\0')
	{
		CLCD_WriteData(String[i]);
		i++;
	}






}
void CLCD_CLR(void)
{




	CLCD_WriteInes(0X01);

}

















