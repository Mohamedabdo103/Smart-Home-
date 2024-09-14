#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include"DIO_privet.h"
//macro for direction
#define DIO_OUTPUT 1
#define DIO_INPUT  0
//macro for value 
#define DIO_HIGH   1
#define DIO_LOW    0
//macro for port
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
//macro for pins
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7
//prototype of function
DIO_ErorrStatues DIO_enumSetPortDirection(U8 copy_u8PortName,U8 copy_u8PortDirection);
DIO_ErorrStatues DIO_enumSetPortValue(U8 copy_u8PortName,U8 copy_u8PortValue);
DIO_ErorrStatues DIO_enumSetPinDirection(U8 copy_u8PinNumber,U8 copy_u8PortName,U8 copy_u8PinDirection);
DIO_ErorrStatues DIO_enumSetPinValue(U8 copy_u8PinNumber,U8 copy_u8PortName,U8 copy_u8PinValue);
DIO_ErorrStatues DIO_enumGetPortValue(U8 copy_u8PortName,U8* copy_u8Ptr);
DIO_ErorrStatues DIO_enumGetPinValue(U8 copy_u8PortName,U8 copy_u8PinNumber,U8* copy_u8Ptr);
DIO_ErorrStatues DIO_enumTogPin(U8 copy_u8PinNumber,U8 copy_u8PortName);

#endif
