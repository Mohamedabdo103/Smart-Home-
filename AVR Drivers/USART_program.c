/*
 * USART_program.c
 *
 *  Created on: May 3, 2021
 *      Author: INTEL
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_privet.h"

void USART_voidINIT(void){
	/**/
	UCSRA=0b00100000;
	/*bit7--->disable interrupt
	 *bit6---->disable interrupt
	 *bit6---->disable
	 *bit4---->enable tx
	 *bit3---->enable rx
	 *bit2---->0--->8bit size
	 *bit0---->init 0
	 *bit1---->init 0   */
	UCSRB=0b00111000;
	/*bit7-------->select reg
	 * bit6--------->Asyn
	 * bit5-------->0
	 * bit4------->0 disable parity
	 * bit3-------->1 bit stop
	 * bit2-------->
	 * bit1--------->8 bit size
	 * */
	UCSRC=0b10000110;
	/*buad rate=51-------->9600*/
	UBRRL=51;
	UBRRH=0;
}
void USART_voidTRANSMITR(U8 DATA){
	UDR=DATA;
	while(GET_BIT(UCSRA,5)==0){};

}

U8   USART_u8RECIVER(void){
	//u8 DATA=UDR;
	while(GET_BIT(UCSRA,7)==0){};
	return UDR;
}

void USART_VoidSendString(U8 *COPYu8StringPtr){
	U8 LOC_u8Itterator=0;
	while(COPYu8StringPtr[LOC_u8Itterator]!='\0'){

		USART_voidTRANSMITR(COPYu8StringPtr[LOC_u8Itterator]);
		LOC_u8Itterator=LOC_u8Itterator+1;
	}

}

U8 STRING[20];
U8 *USART_PtrRecieveString(void){
	U8 i=0;
	U8 x;
	while((x=USART_u8RECIVER())!=13){
		STRING[i++]=x;

	}
	STRING[i]='\0';

	return STRING;
}



