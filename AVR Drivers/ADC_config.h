/*
 * ADC_config.h
 *
 *  Created on: Mar 23, 2022
 *      Author: INTEL
 */
#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
/*Enable_OPTION
 *   ADC_ENABLE
 *   ADC_DISABLE
*/
#define ADC_Enable_Status ADC_ENABLE
/*Vref_OPTION
    *ADC_AREF_INTERNAL_Vref_TURNED_OFF
    *ADC_AVCC
    *ADC_INTERNAL_2_56
*/
#define ADC_Vref  ADC_AVCC
/*Adjustment_OPTION
    * ADC_LEFT_ADJUSTMENT
    * ADC_RIGHT_ADJUSTMENT
*/
#define ADC_Adjustment  ADC_RIGHT_ADJUSTMENT
/*Channal_OPTION
    * ADC_CHANNAL_0
    * ADC_CHANNAL_1
    * ADC_CHANNAL_2
    * ADC_CHANNAL_3
    * ADC_CHANNAL_4
    * ADC_CHANNAL_5
    * ADC_CHANNAL_6
    * ADC_CHANNAL_7
 * */
#define ADC_Channal ADC_CHANNAL_0
/*Inturrupt_OPTION
    * ADC_INTERRUPT_ENABLE
    * ADC_INTERRUPT_DISABLE
*/
#define ADC_Inturrupt_Mode  ADC_INTERRUPT_DISABLE
/*Trigger_OPTION
    * ADC_SINGLE_CONVERSION
    * ADC_FREE_RUNNING_MODE
    * ADC_Analog_Comparator
    * ADC_External_Interrupt_Request_0
    * ADC_Timer_Counter_0_Compare Match
    * ADC_Timer_Counter_0_Overflow
    * ADC_Timer_Counter_Compare_Match_B
    * ADC_Timer_Counter_1_Overflow
    * ADC_Timer_Counter_1_Capture_Event
*/
#define ADC_Trigger ADC_FREE_RUNNING_MODE
/*Prescallur_OPTION
    * ADC_PRESCALLER_2
    * ADC_PRESCALLER_4
    * ADC_PRESCALLER_8
    * ADC_PRESCALLER_16
    * ADC_PRESCALLER_32
    * ADC_PRESCALLER_128
*/
#define ADC_Prescallur ADC_PRESCALLER_128
#endif /* MCAL_ADC_ADC_CONFIG_H_ */
