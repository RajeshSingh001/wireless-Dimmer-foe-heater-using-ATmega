#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
    USARTInit(95);
	InitADC();
	uint16_t adc_value;
	uint8_t t;
	InitLCD(0);
	LCDClear();
	LCDWriteStringXY(5,0,"Welcome");
   _delay_ms(100);
	LCDClear();
	LCDWriteStringXY(0,0,"Heater Control System");
   _delay_ms(100);
   	LCDClear();
   	DDRB=0xFF;
	PORTB=0b00001111;
   while (1)
   {
        adc_value=ReadADC(0);
       	t=adc_value/2;
		LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,t,3);
		
		_delay_ms(10);
		//PORTB=0b00001111;
		//_delay_ms(1000);
		//PORTB=0b00000000;

    char data= USARTReadChar();
	    if(data=='a')
	   {
	   LCDClear();
	   LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,t,3);
	    
		LCDWriteStringXY(0,0,"25% level");
		PORTB=0b00001010;
		_delay_ms(20);
    	}
	 if(data=='b')
	   {
	    LCDClear();
		 LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,t,3)
		LCDWriteStringXY(0,0,"50% level");
		PORTB=0b00000111;
		_delay_ms(20);
    	}
	 if(data=='c')
	   {
	    LCDClear();
		 LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,t,3)
		LCDWriteStringXY(0,0,"75% level");
	    PORTB=0b00000011;
		_delay_ms(20);
    	}
	 if (data=='d')
	   {
	    LCDClear();
		 LCDWriteStringXY(0,1,"Current Temp.")
		LCDWriteIntXY(12,1,t,3)
		LCDWriteStringXY(0,0,"100% level");
	    PORTB=0b00000000;
    	_delay_ms(20);
    	}

		
	/*	if((t>35)&&(t<50))
		{
		PORTB=0b00001111;
		_delay_ms(10);
		
	//	return 0;

		}

		if((t>25)&&(t<35))
		{
		PORTB=0b00000000;
		_delay_ms(10);
     }*/
	}
}
