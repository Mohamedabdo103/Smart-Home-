/*
*  Smart Home Final Project
*
* Created: 9/3/2024 10:23:33 AM
*  Author: Mohamed_Abdo
*/


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "STD_TYPES1.h"
#include "BIT_MATH.h"
#include "STD_MACROS.h"
#include "CLCD_interface.h"
#include "Kypd.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_privet.h"
#include "USART_interface.h"
#include "USART_privet.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_privet.h"

#define BUZZER_PIN PA4

//#define F_CPU 8000000UL
void unlock_system() {
	// Unlock system for 5 minutes
	_delay_ms(300000); // 5 minutes
}

U8 arr_id_1[4]={"123\0"}; //ID for users
U8 arr_id_2[4]={"456\0"};
U8 arr_pass_1[4]={"123\0"}; //pass for users
U8 arr_pass_2[4]={"456\0"};
U8 arr_read_id[4]={"\0"};
U8 arr_read_pass[4]={"\0"};
U8 id ,pass ,press;
U8 count=3 ;
U8 j=0;
U16 value1 ;


void alerm(void)
{
	if (!(PIND & (1 << PD2))){
		DIO_enumSetPinValue(BUZZER_PIN, DIO_PORTA, DIO_HIGH);
		CLCD_GoTo(1,1);
		CLCD_SendString(" !!! Bell Ring");
		_delay_ms(2000);
		CLCD_CLR();
		DIO_enumSetPinValue(BUZZER_PIN, DIO_PORTA, DIO_LOW);}
	
}

void temp (void)
{	
	
	U16 temp;
	U8 clr;
	temp = ADC_u16GetChannalResult(ADC_CHANNAL_0);
	float tempf = temp /2.01 ;
	if (tempf>40.0){
		while(1){
			CLCD_CLR();
			CLCD_GoTo(1,1);
			CLCD_SendString(" !Temp Above 40");	
			DIO_enumSetPinValue(DIO_PIN1,DIO_PORTA,DIO_HIGH);
			DIO_enumSetPinValue(DIO_PIN2,DIO_PORTA,DIO_HIGH);
			_delay_ms(2000);
			temp = ADC_u16GetChannalResult(ADC_CHANNAL_0);
			float tempf = temp /2.01 ;
			if (tempf < 40.0)
			{
				CLCD_CLR();
				DIO_enumSetPinValue(DIO_PIN1,DIO_PORTA,DIO_LOW);
				DIO_enumSetPinValue(DIO_PIN2,DIO_PORTA,DIO_LOW);
				break;
			}
			
		}
	}
	
	

	
}

int main(void)
{ 
	CLCD_init();
	Kypad_init();
	USART_voidINIT();
	ADC_voidInit();
	
	DIO_enumSetPinDirection(DIO_PIN0 , DIO_PORTA ,DIO_INPUT);
	DIO_enumSetPinDirection(DIO_PIN1 , DIO_PORTA ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN2 , DIO_PORTA ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN3 , DIO_PORTA ,DIO_INPUT);
	DIO_enumSetPinValue(DIO_PIN3 , DIO_PORTA ,DIO_HIGH); //pull up
	DIO_enumSetPinDirection(DIO_PIN4 , DIO_PORTA ,DIO_OUTPUT);

	
	
	DIO_enumSetPinDirection(DIO_PIN0 , DIO_PORTD ,DIO_INPUT);
	DIO_enumSetPinDirection(DIO_PIN1 , DIO_PORTD ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN2 , DIO_PORTD ,DIO_INPUT);
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2); 
	DIO_enumSetPinDirection(DIO_PIN4 , DIO_PORTD ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN5 , DIO_PORTD ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN6 , DIO_PORTD ,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PIN7 , DIO_PORTD ,DIO_OUTPUT);

	    
	
    DDRA |= (1 << BUZZER_PIN);	
	while(1)
	{
		alerm();
		temp();
		CLCD_GoTo(1,0);
		CLCD_SendString(" Welcome Press =");
		USART_voidTRANSMITR('\r');
		USART_voidTRANSMITR('\n');
		USART_VoidSendString("  Welcome ");
		USART_voidTRANSMITR('\r'); 
		USART_voidTRANSMITR('\n');
		USART_VoidSendString("  Press '=' to tack action");
		CLCD_GoTo(2,0);
		CLCD_SendString(" To Tack Action ");
		_delay_ms(6000);
		CLCD_CLR();
		CLCD_GoTo(1,1);
		CLCD_SendString(" Enter your ID : ");
		USART_voidTRANSMITR('\r');
		USART_voidTRANSMITR('\n');
		USART_VoidSendString("  Enter your ID : ");
	    alerm();
		temp();
	
		CLCD_GoTo(2,1);
		do
		{   alerm();
			temp();
			id=Kypad_GetKey();
			if ((id != 'q') && (id != '=') && (j < 3))
			{
				arr_read_id[j++]=id;
				
				//CLCD_WriteData(id);
				CLCD_WriteData(id);
				USART_voidTRANSMITR(id);
			}
						
		} while(id != '=');
		id=0;
		j=0;
		alerm();
		temp();
		_delay_ms(3000);
		CLCD_CLR();
		for(int i =0 ; i<=1 ; i++){
			if(strcmp(arr_id_1 , arr_read_id) == 0 || strcmp(arr_id_2 , arr_read_id) == 0  ){ //id true
				CLCD_GoTo(1,1);
				for(int i=0 ; i<=2; i++){
					CLCD_SendString(" Enter your password :");
					USART_voidTRANSMITR('\r');
					USART_voidTRANSMITR('\n');
					USART_VoidSendString("  Enter your password : ");
					CLCD_GoTo(2,1);
					do
					{	alerm();
						temp();
						id=Kypad_GetKey();
						if ((id != 'q') && (id != '=') && (j < 3))
						{
							arr_read_pass[j++]=id;
							
							//CLCD_WriteData(id);
							CLCD_WriteData(' *');
							USART_voidTRANSMITR('*');
						}						
						
						
					} while(id != '=');
					id=0;
					j=0;
					alerm();
					temp();				
					// _delay_ms(1000);
					CLCD_CLR();
					if(!(((strcmp(arr_pass_1 , arr_read_pass) == 0 && (strcmp(arr_id_1 , arr_read_id) == 0))
					|| (strcmp(arr_pass_2 , arr_read_pass) == 0 ) && (strcmp(arr_id_2 , arr_read_id) == 0)))){ //pass false
						CLCD_GoTo(1,1);
						CLCD_WritNum(count);
						CLCD_SendString(" trial left ");
						
						_delay_ms(3000);
						CLCD_CLR();
						count--;
						continue;
					}
									
					//start
					else
					{ //pass true
						
						int k=1;
						while (k)
						{   alerm();
							temp();
							CLCD_CLR();
							CLCD_SendString(" 1:Room1 ");
							//  CLCD_SendString(" 1- ON led");
							CLCD_GoTo(2,1);
							CLCD_SendString(" 2:Room2 ");
							// CLCD_SendString(" 2- ON motor");
							
							do
							{	alerm();
								temp();
								id =Kypad_GetKey();
								if ((id != 'q') && (id != '=') )
								{
									press =id;			
									USART_voidTRANSMITR(press);
								}
						
							} while(id != '=');
													
							_delay_ms(2500);
							CLCD_CLR();
							
							if (press == '1')// room1
							{	
								alerm();
								temp();						
								int kk=1;
								while (kk) //led fan
								{									
									CLCD_SendString(" 1:Led 3:Back");
									CLCD_GoTo(2,1);
									CLCD_SendString(" 2:Fan 4:CLR");
									do
									{   alerm();
										temp();
										id =Kypad_GetKey();
										if ((id != 'q') && (id != '=') )
										{
											press =id;
											USART_voidTRANSMITR(press);
										}
										
									} while(id != '=');
									
									_delay_ms(2500);
									CLCD_CLR();
									
									if (press == '1') // leds room1
									{
										CLCD_SendString(" 1:Led on 3:Back");
										CLCD_GoTo(2,1);
										CLCD_SendString(" 2:Led off 4:CLR");
										do
										{   alerm();
											temp();
											id =Kypad_GetKey();
											if ((id != 'q') && (id != '=') )
											{
												press =id;
												USART_voidTRANSMITR(press);
											}
											
										} while(id != '=');
										
										_delay_ms(2500);
										CLCD_CLR();
										if (press == '1') // led on room1
										{
											DIO_enumSetPinValue(DIO_PIN4 , DIO_PORTD ,DIO_HIGH);
											
										}
										else if (press == '2') // led off room 1
										{
											DIO_enumSetPinValue(DIO_PIN4 , DIO_PORTD ,DIO_LOW);
										}
										else if (press == '3') // back from led on off
										{
											continue;
										}
										else if (press == '4') // clr
										{
											break;
										}
										else {}
										
									}
									
									else if (press == '2') // fans room1
									{
										CLCD_SendString(" 1:Fan on 3:Back");
										CLCD_GoTo(2,1);
										CLCD_SendString(" 2:Fan off 4:CLR");
										do
										{   alerm();
											temp();
											id =Kypad_GetKey();
											if ((id != 'q') && (id != '=') )
											{
												press =id;
												USART_voidTRANSMITR(press);
											}
											
										} while(id != '=');
										
										_delay_ms(2500);
										CLCD_CLR();
										if (press == '1') // fan on
										{
											DIO_enumSetPinValue(DIO_PIN5 , DIO_PORTD ,DIO_HIGH);
											
										}
										else if (press == '2') // fan off
										{
											DIO_enumSetPinValue(DIO_PIN5 , DIO_PORTD ,DIO_LOW);
										}
										else if (press == '3')// room1 led fan
										{
											continue;
										}
										else if (press == '4')// clr
										{
											break;
										}
										else {}
									}
									else if (press == '3')// room1 led fan
									{
										break;
									}
									else if (press == '4')// clr
									{
										break;
									}
									else {}
								}
								
								if (press == '4') break; // to break the first loop
     							}
	
							else if (press == '2') //room 2
							{
								int kk=1;
								while (kk) //led fan
								{
									alerm();
									temp();
									CLCD_SendString(" 1:Led 3:Back");
									CLCD_GoTo(2,1);
									CLCD_SendString(" 2:Fan 4:CLR");
									do
									{   alerm();
										temp();
										id =Kypad_GetKey();
										if ((id != 'q') && (id != '=') )
										{
											press =id;
											USART_voidTRANSMITR(press);
										}
										
									} while(id != '=');
									
									_delay_ms(2500);
									CLCD_CLR();
									
									if (press == '1') // leds room1
									{   alerm();
										temp();
										CLCD_SendString(" 1:Led on 3:Back");
										CLCD_GoTo(2,1);
										CLCD_SendString(" 2:Led off 4:CLR");
										do
										{   alerm();
											temp();
											id =Kypad_GetKey();
											if ((id != 'q') && (id != '=') )
											{
												press =id;
												USART_voidTRANSMITR(press);
											}
											
										} while(id != '=');
										
										_delay_ms(2500);
										CLCD_CLR();
										if (press == '1') // led on room1
										{
											DIO_enumSetPinValue(DIO_PIN6 , DIO_PORTD ,DIO_HIGH);
											
										}
										else if (press == '2') // led off room 1
										{
											DIO_enumSetPinValue(DIO_PIN6 , DIO_PORTD ,DIO_LOW);
										}
										else if (press == '3') // back from led on off
										{
											continue;
										}
										else if (press == '4') // clr
										{
											break;
										}
										else {}
										
									}

									else if (press == '2') // fans room1
									{   alerm();
										temp();
										CLCD_SendString(" 1:Fan on 3:Back");
										CLCD_GoTo(2,1);
										CLCD_SendString(" 2:Fan off 4:CLR");
										do
										{  alerm();
											temp();
											id =Kypad_GetKey();
											if ((id != 'q') && (id != '=') )
											{
												press =id;
												USART_voidTRANSMITR(press);
											}
											
										} while(id != '=');
										
										_delay_ms(2500);
										CLCD_CLR();
										if (press == '1') // fan on
										{
											DIO_enumSetPinValue(DIO_PIN7 , DIO_PORTD ,DIO_HIGH);
											
										}
										else if (press == '2') // fan off
										{
											DIO_enumSetPinValue(DIO_PIN7 , DIO_PORTD ,DIO_LOW);
										}
										else if (press == '3')// room1 led fan
										{
											continue;
										}
										else if (press == '4')// clr
										{
											break;
										}
										else {}
									}
									else if (press == '3')// room1 led fan
									{
										break;
									}
									else if (press == '4')// clr
									{
										break;
									}
									else {}
							}//
							if (press == '4') break; // to break the first loop					
								}
						}					
						break;
					}
				}
			
										}
			else {  //id false
				continue;
			}
			
		}
				
		if(count==0)
		{   alerm();
			temp();
			CLCD_SendString(" System Lock ");
			CLCD_GoTo(2,1);
			CLCD_SendString(" Wait 5 minutes");
			unlock_system();
			CLCD_CLR();
		}		
	}//end while
}
								