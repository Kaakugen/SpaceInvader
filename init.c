#include "init.h"

// --- init the PIC18F device
void initMyPIC18F(void)
{
    
        TRISB = 0xC0;           // Port B bits 7 and 6 are input
        INTCONbits.GIE = 1;                // Global interrupt enable
        INTCONbits.RBIE=1;
              
     T0CONbits.TMR0ON = 1;
     T0CONbits.T08BIT = 0;
     T0CONbits.T0PS0 =  0;
     T0CONbits.T0PS1 =  0;
     T0CONbits.T0PS2 =  1;
     INTCONbits.TMR0IE = 1;
     TMR0H = 0xc3;
     TMR0L = 0x50;

    // set all ports as OUTPUTS
	TRISA = 0x00;
   // TRISB = 0x00;
	TRISC = 0x00;
	TRISD = 0xFF;
	TRISE = 0x00;
	// PORTA digital
    // set port by port on "all zeros"
    
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
    PORTE = 0x00;
    
	ADCON1 = 0x0F ;
	ADCON0 = 0;
	
	

	
// make sure to have an empty LAST line in any *.c file (just hit an Enter)!
    

}

// make sure to have an empty LAST line in any *.c file (just hit an Enter)!

    