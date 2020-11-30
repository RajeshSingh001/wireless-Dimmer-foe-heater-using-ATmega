#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
DDRB&=~(1<<0);
PORTB|=(1<<0);
DDRB&=~(1<<1);
PORTB|=(1<<1);
DDRB&=~(1<<2);
PORTB|=(1<<2);
DDRB&=~(1<<3);
PORTB|=(1<<3);


    MCUCSR=0x80;
	MCUCSR=0x80;
	USARTInit(95);
	InitLCD(0);
	LCDClear();
	LCDWriteString("Welcome");
   _delay_ms(100);
   	LCDClear();
	while(1)
	{
        /*char data=USARTReadChar();
		LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,data,3);*/

	    if((!(PINB&1))&&(PINB&2)&&(PINB&4)&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"25% level");
		USARTWriteChar('a');
		_delay_ms(10);
		}
		else if((PINB&1)&&(!(PINB&2))&&(PINB&4)&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"50% level");
		USARTWriteChar('b');
		_delay_ms(10);
        }
		 else if((PINB&1)&&(PINB&2)&&(!(PINB&4))&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"75% level");
		USARTWriteChar('c');
		_delay_ms(10);
        }
		 else if((PINB&1)&&(PINB&2)&&(PINB&4)&&(!(PINB&8)))
		{
		LCDClear();
		LCDWriteStringXY(0,0,"100% level");
		USARTWriteChar('d');
    	_delay_ms(10);
		}
		else
		USARTWriteChar('e');
    	_delay_ms(100);
	
    }
}
