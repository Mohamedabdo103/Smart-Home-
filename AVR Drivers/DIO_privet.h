#ifndef DIO_PRIVET_H_
#define DIO_PRIVET_H_
//enum state to return state of function
typedef enum{
	ok_state,//value=0
	dok_state//value=1
	
}DIO_ErorrStatues;

//PORTA_REGISTER Addrecess
#define DDRA_Reg   *((volatile U8*)0X3A)
#define PORTA_Reg  *((volatile U8*)0X3B)
#define PINA_Reg   *((volatile U8*)0X39)
//PORTB_REGISTER Addrecess
#define DDRB_Reg   *((volatile U8*)0X37)
#define PORTB_Reg  *((volatile U8*)0X38)
#define PINB_Reg   *((volatile U8*)0X36)
//PORTC_REGISTER Addrecess
#define DDRC_Reg   *((volatile U8*)0X34)
#define PORTC_Reg  *((volatile U8*)0X35)
#define PINC_Reg   *((volatile U8*)0X33)
//PORTD_REGISTER Addrecess
#define DDRD_Reg   *((volatile U8*)0X31)
#define PORTD_Reg  *((volatile U8*)0X32)
#define PIND_Reg   *((volatile U8*)0X30)



#endif
