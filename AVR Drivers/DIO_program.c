#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_privet.h"
#include"DIO_interface.h"
DIO_ErorrStatues DIO_enumSetPortDirection(U8 copy_u8PortName,U8 copy_u8PortDirection){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	switch(copy_u8PortName){
	case DIO_PORTA:
		if((copy_u8PortDirection>=0)&&(copy_u8PortDirection<=255)){
			DDRA_Reg=copy_u8PortDirection;
		}
		break;
	case DIO_PORTB:
		if((copy_u8PortDirection>=0)&&(copy_u8PortDirection<=255)){
			DDRB_Reg=copy_u8PortDirection;
		}
		break;
	case DIO_PORTC:
		if((copy_u8PortDirection>=0)&&(copy_u8PortDirection<=255)){
			DDRC_Reg=copy_u8PortDirection;
		}
		break;
	case DIO_PORTD:
		if((copy_u8PortDirection>=0)&&(copy_u8PortDirection<=255)){
			DDRD_Reg=copy_u8PortDirection;
		}
		break;
	default:
		LOC_enumState=dok_state;
		break;
	}
	return LOC_enumState;
}
DIO_ErorrStatues DIO_enumSetPortValue(U8 copy_u8PortName,U8 copy_u8PortValue){

	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	switch(copy_u8PortName){
	case DIO_PORTA:
		if((copy_u8PortValue>=0)&&(copy_u8PortValue<=255)){
			PORTA_Reg=copy_u8PortValue;
		}
		break;
	case DIO_PORTB:
		if((copy_u8PortValue>=0)&&(copy_u8PortValue<=255)){
			PORTB_Reg=copy_u8PortValue;
		}
		break;
	case DIO_PORTC:
		if((copy_u8PortValue>=0)&&(copy_u8PortValue<=255)){
			PORTC_Reg=copy_u8PortValue;
		}
		break;
	case DIO_PORTD:
		if((copy_u8PortValue>=0)&&(copy_u8PortValue<=255)){
			PORTD_Reg=copy_u8PortValue;
		}
		break;
	default:
		LOC_enumState=dok_state;
		break;
	}
	return LOC_enumState;

}
DIO_ErorrStatues DIO_enumSetPinDirection(U8 copy_u8PinNumber,U8 copy_u8PortName,U8 copy_u8PinDirection){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	if((copy_u8PinNumber>=DIO_PIN0)&&(copy_u8PinNumber<=DIO_PIN7)){
		switch(copy_u8PortName){
		case DIO_PORTA:
			if(copy_u8PinDirection==DIO_OUTPUT){
				SET_BIT(DDRA_Reg,copy_u8PinNumber);
			}else if(copy_u8PinDirection==DIO_INPUT){
				CLR_BIT(DDRA_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTB:
			if(copy_u8PinDirection==DIO_OUTPUT){
				SET_BIT(DDRB_Reg,copy_u8PinNumber);
			}else if(copy_u8PinDirection==DIO_INPUT){
				CLR_BIT(DDRB_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTC:
			if(copy_u8PinDirection==DIO_OUTPUT){
				SET_BIT(DDRC_Reg,copy_u8PinNumber);
			}else if(copy_u8PinDirection==DIO_INPUT){
				CLR_BIT(DDRC_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTD:
			if(copy_u8PinDirection==DIO_OUTPUT){
				SET_BIT(DDRD_Reg,copy_u8PinNumber);
			}else if(copy_u8PinDirection==DIO_INPUT){
				CLR_BIT(DDRD_Reg,copy_u8PinNumber);
			}
			break;
		default:
			LOC_enumState=dok_state;
			break;
		}
	}else{
		LOC_enumState=dok_state;
	}

	return LOC_enumState;

}
DIO_ErorrStatues DIO_enumSetPinValue(U8 copy_u8PinNumber,U8 copy_u8PortName,U8 copy_u8PinValue){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	if((copy_u8PinNumber>=DIO_PIN0)&&(copy_u8PinNumber<=DIO_PIN7)){
		switch(copy_u8PortName){
		case DIO_PORTA:
			if( copy_u8PinValue==DIO_HIGH){
				SET_BIT(PORTA_Reg,copy_u8PinNumber);
			}else if(copy_u8PinValue==DIO_LOW){
				CLR_BIT(PORTA_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTB:
			if( copy_u8PinValue==DIO_HIGH){
				SET_BIT(PORTB_Reg,copy_u8PinNumber);
			}else if(copy_u8PinValue==DIO_LOW){
				CLR_BIT(PORTB_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTC:
			if( copy_u8PinValue==DIO_HIGH){
				SET_BIT(PORTC_Reg,copy_u8PinNumber);
			}else if(copy_u8PinValue==DIO_LOW){
				CLR_BIT(PORTC_Reg,copy_u8PinNumber);
			}
			break;
		case DIO_PORTD:
			if( copy_u8PinValue==DIO_HIGH){
				SET_BIT(PORTD_Reg,copy_u8PinNumber);
			}else if(copy_u8PinValue==DIO_LOW){
				CLR_BIT(PORTD_Reg,copy_u8PinNumber);
			}
			break;
		default:
			LOC_enumState=dok_state;
			break;
		}
	}else{
		LOC_enumState=dok_state;
	}

	return LOC_enumState;

}
DIO_ErorrStatues DIO_enumGetPortValue(U8 copy_u8PortName,U8* copy_u8Ptr){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	switch(copy_u8PortName){
	case DIO_PORTA:
		*copy_u8Ptr=PINA_Reg;
		break;
	case DIO_PORTB:
		*copy_u8Ptr=PINB_Reg;
		break;
	case DIO_PORTC:
		*copy_u8Ptr=PINC_Reg;
		break;
	case DIO_PORTD:
		*copy_u8Ptr=PIND_Reg;
		break;
	default:
		LOC_enumState=dok_state;
	}
	return LOC_enumState;
}
DIO_ErorrStatues DIO_enumGetPinValue(U8 copy_u8PortName,U8 copy_u8PinNumber,U8* copy_u8Ptr){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	if(( copy_u8PinNumber>=DIO_PIN0)&&( copy_u8PinNumber<=DIO_PIN7)){
		switch(copy_u8PortName){
		case DIO_PORTA:
			*copy_u8Ptr=GET_BIT(PINA_Reg, copy_u8PinNumber);
			break;
		case DIO_PORTB:
			*copy_u8Ptr=GET_BIT(PINB_Reg, copy_u8PinNumber);
			break;
		case DIO_PORTC:
			*copy_u8Ptr=GET_BIT(PINC_Reg, copy_u8PinNumber);
			break;
		case DIO_PORTD:
			*copy_u8Ptr=GET_BIT(PIND_Reg, copy_u8PinNumber);
			break;
		default:
			LOC_enumState=dok_state;
			break;
		}
	}else{
		LOC_enumState=dok_state;
	}
	return LOC_enumState;
}
DIO_ErorrStatues DIO_enumTogPin(U8 copy_u8PinNumber,U8 copy_u8PortName){
	DIO_ErorrStatues LOC_enumState;
	LOC_enumState=ok_state;
	if((copy_u8PinNumber>=DIO_PIN0)&&(copy_u8PinNumber<=DIO_PIN7)){
		switch(copy_u8PortName){
		case DIO_PORTA:
			TOG_BIT(PORTA_Reg,copy_u8PinNumber);
			break;
		case DIO_PORTB:
			TOG_BIT(PORTB_Reg,copy_u8PinNumber);
			break;
		case DIO_PORTC:
			TOG_BIT(PORTC_Reg,copy_u8PinNumber);
			break;
		case DIO_PORTD:
			TOG_BIT(PORTD_Reg,copy_u8PinNumber);
			break;
		default:
			LOC_enumState=dok_state;
			break;
		}
	}else{
		LOC_enumState=dok_state;
	}
	return LOC_enumState;
}
