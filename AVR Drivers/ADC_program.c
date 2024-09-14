/*
 * ADC_program.c

 *
 *  Created on: Mar 23, 2022
 *      Author: INTEL
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_privet.h"
void ADC_voidInit(void){
#if ADC_Enable_Status==ADC_ENABLE
    #if ADC_Vref==ADC_AREF_INTERNAL_Vref_TURNED_OFF
	    CLR_BIT(ADMUX,7); CLR_BIT(ADMUX,6);
    #elif ADC_Vref==ADC_AVCC
       CLR_BIT(ADMUX,7); SET_BIT(ADMUX,6);
    #elif ADC_Vref==ADC_INTERNAL_2_56
       SET_BIT(ADMUX,7); SET_BIT(ADMUX,6);
    #endif

    #if ADC_Adjustment==ADC_LEFT_ADJUSTMENT
       SET_BIT(ADMUX,5);
    #elif ADC_Adjustment==ADC_RIGHT_ADJUSTMENT
       CLR_BIT(ADMUX,5);
    #endif

    #if ADC_Channal>=ADC_CHANNAL_0&&ADC_Channal<=ADC_CHANNAL_7
      ADMUX|=ADC_Channal;
    #else
         #warning "wrong ADC Channel"

    #endif


    #if ADC_Trigger==ADC_SINGLE_CONVERSION
      CLR_BIT(ADCSRA,5);
    #elif ADC_Trigger==ADC_FREE_RUNNING_MODE
      SET_BIT(ADCSRA,5);
      CLR_BIT(SFIOR,7); CLR_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_Analog_Comparator
      SET_BIT(ADCSRA,5);
      CLR_BIT(SFIOR,7); CLR_BIT(SFIOR,6); SET_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_External_Interrupt_Request_0
      SET_BIT(ADCSRA,5);
      CLR_BIT(SFIOR,7); SET_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_Timer_Counter_0_Compare
      SET_BIT(ADCSRA,5);
      CLR_BIT(SFIOR,7);  SET_BIT(SFIOR,6);  SET_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_Timer_Counter_0_Overflow
      SET_BIT(ADCSRA,5);
      SET_BIT(SFIOR,7);  CLR_BIT(SFIOR,6);  CLR_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_Timer_Counter_Compare_Match_B
      SET_BIT(ADCSRA,5);
      SET_BIT(SFIOR,7);  CLR_BIT(SFIOR,6);  SET_BIT(SFIOR,5);
    #elif ADC_Trigger==ADC_Timer_Counter_1_Overflow
      SET_BIT(ADCSRA,5);
      SET_BIT(SFIOR,7);  SET_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
    #elif  ADC_Trigger==ADC_Timer_Counter_1_Capture_Event
      SET_BIT(ADCSRA,5);
      SET_BIT(SFIOR,7);  SET_BIT(SFIOR,6);  SET_BIT(SFIOR,5);
    #endif


    #if ADC_Inturrupt_Mode==ADC_INTERRUPT_ENABLE
      SET_BIT(ADCSRA,3);
    #elif ADC_Inturrupt_Mode==ADC_INTERRUPT_DISABLE
      CLR_BIT(ADCSRA,3);
    #endif

    #if ADC_Prescallur>=ADC_PRESCALLER_2 && ADC_Prescallur<=ADC_PRESCALLER_128
        ADCSRA |= ADC_Prescallur;
    #else
          #warning"wrong prescaler"

    #endif

   SET_BIT(ADCSRA,7);
#endif
	}
U16  ADC_u16GetResult(void){
	U16 LOC_Result=0;
	//SINGL CONVERTION-->Start Conversion
	SET_BIT(ADCSRA,6);
	//Read Flag
	while(GET_BIT(ADCSRA,4)==0);
	//Read Counter
    #if ADC_Adjustment==ADC_LEFT_ADJUSTMENT
	    LOC_Result=ADCH;
    #elif ADC_Adjustment==ADC_RIGHT_ADJUSTMENT
	    LOC_Result=ADCL|(ADCH<<8);
    #endif
	//Clear Flag
	SET_BIT(ADCSRA,4);
	//Return Value
	return LOC_Result;

}
U16  ADC_u16GetChannalResult(U8 Copy_u8Channal){
	U16 LOC_Result=0;
	//Copy_u8Channal &=0b00000111;
	//Clear Mux
	ADMUX &=0b11100000;
	//Select MUX
	ADMUX|=Copy_u8Channal;
	//SINGL CONVERTION-->Start Conversion
	SET_BIT(ADCSRA,6);
	//Read Flag
	while(GET_BIT(ADCSRA,4)==0);
	//Read Counter
	    #if ADC_Adjustment==ADC_LEFT_ADJUSTMENT
		    LOC_Result=ADCH;
	    #elif ADC_Adjustment==ADC_RIGHT_ADJUSTMENT
		    LOC_Result=ADCL|(ADCH<<8);
	    #endif
	//Clear Flag
	SET_BIT(ADCSRA,4);
	//Return Value
		return LOC_Result;
}
void ADC_Enable(void){
  SET_BIT(ADCSRA,7);
}
void ADC_Disable(void){
  CLR_BIT(ADCSRA,7);
}
