/*
 * USART_interface.h
 *
 *  Created on: May 3, 2021
 *      Author: INTEL
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidINIT(void);
void USART_voidTRANSMITR(U8 DATA);
U8   USART_u8RECIVER(void);
void USART_VoidSendString(U8 *COPYu8StringPtr);
U8 *USART_PtrRecieveString(void);

#endif /* USART_INTERFACE_H_ */
