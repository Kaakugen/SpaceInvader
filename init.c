#include "init.h"

// --- init the PIC18F device
void initMyPIC18F(void)
{
    
        TRISB = 0xC0;           // Port B bits 7 and 6 are output
        INTCONbits.GIE = 1;                // Global interrupt enable
        INTCONbits.RBIE=1;
              
        
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

    