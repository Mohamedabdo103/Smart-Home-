/*
 * CLCD_interface.h
 *
 *  Created on: Oct 9, 2023
 *      Author: MaKa
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_
#include"STD_TYPES.h"
#define CLCD_RS_PIN       DIO_PIN6
#define CLCD_control_Port DIO_PORTA
#define CLCD_Data_Port    DIO_PORTC
#define CLCD_ENPIN        DIO_PIN7



void CLCD_init(void);
void CLCD_WriteInes(U8 ins);
void CLCD_WriteData(U8 Data);
void CLCD_WriteChar(U8 Char);
void CLCD_GoTo(U8 Row,U8 Col);
void CLCD_SendString(U8 *String);
U8   ConvertNumToASCII(U8 Input);
void CLCD_WritNum(U64 NUM);
void CLCD_PrintBinary(U8 num);
void CLCD_Draw_Char(U8 Address_Data);
void CLCD_ConvertNumToHex(U8 NUM);





















#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
