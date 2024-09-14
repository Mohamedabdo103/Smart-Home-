/*
 * ADC_privet.h
 *
 *  Created on: Mar 23, 2022
 *      Author: INTEL
 */

#ifndef MCAL_ADC_ADC_PRIVET_H_
#define MCAL_ADC_ADC_PRIVET_H_

#define ADMUX    *((volatile U8*)0X27)
#define ADCSRA   *((volatile U8*)0X26)
#define ADCH     *((volatile U8*)0X25)
#define ADCL     *((volatile U8*)0X24)
#define SFIOR    *((volatile U8*)0X50)


#endif /* MCAL_ADC_ADC_PRIVET_H_ */
