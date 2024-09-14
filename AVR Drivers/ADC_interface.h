/*
 * ADC_interface.h
 *
 *  Created on: Mar 23, 2022
 *      Author: INTEL
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
/*VOLTAGE REFERANCE SELECTION*/
#define ADC_AREF_INTERNAL_Vref_TURNED_OFF  0
#define ADC_AVCC                           1
#define ADC_INTERNAL_2_56                  2
/*ADJUSTMENT SELECTION*/
#define ADC_LEFT_ADJUSTMENT  0
#define ADC_RIGHT_ADJUSTMENT 1
/*ANALOG CHANNEL SELECTION*/
#define ADC_CHANNAL_0 0
#define ADC_CHANNAL_1 1
#define ADC_CHANNAL_2 2
#define ADC_CHANNAL_3 3
#define ADC_CHANNAL_4 4
#define ADC_CHANNAL_5 5
#define ADC_CHANNAL_6 6
#define ADC_CHANNAL_7 7
/*ENABLE SELECTION*/
#define ADC_ENABLE  0
#define ADC_DISABLE 1
/*TRIGGER SELECTION*/
#define ADC_SINGLE_CONVERSION               0
#define ADC_FREE_RUNNING_MODE               1
#define ADC_Analog_Comparator               2
#define ADC_External_Interrupt_Request_0    3
#define ADC_Timer_Counter_0_Compare Match   4
#define ADC_Timer_Counter_0_Overflow        5
#define ADC_Timer_Counter_Compare_Match_B   6
#define ADC_Timer_Counter_1_Overflow        7
#define ADC_Timer_Counter_1_Capture_Event   8
/*ADC INTERRUPT SELECTION*/
#define ADC_INTERRUPT_ENABLE  0
#define ADC_INTERRUPT_DISABLE 1
/*PRESCALLER SELECTION*/
#define ADC_PRESCALLER_2   1
#define ADC_PRESCALLER_4   2
#define ADC_PRESCALLER_8   3
#define ADC_PRESCALLER_16  4
#define ADC_PRESCALLER_32  5
#define ADC_PRESCALLER_64  6
#define ADC_PRESCALLER_128 7

void ADC_voidInit(void);
void ADC_Enable(void);
void ADC_Disable(void);
U16  ADC_u16GetChannalResult(U8 Copy_u8Channal);
U16  ADC_u16GetResult(void);




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
