/*
 * USART_privet.h
 *
 *  Created on: May 3, 2021
 *      Author: INTEL
 */

#ifndef USART_PRIVET_H_
#define USART_PRIVET_H_

#define UDR     *((volatile U8*)0X2C)
#define UCSRA   *((volatile U8*)0X2B)
#define UCSRB   *((volatile U8*)0X2A)
#define UCSRC   *((volatile U8*)0X40)
#define UBRRL   *((volatile U8*)0X29)
#define UBRRH   *((volatile U8*)0X40)



#endif /* USART_PRIVET_H_ */
