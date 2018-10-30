#include "init.h"

// --- init the PIC18F device
void initMyPIC18F(void)
{
    
                  // Port B bits 7 and 6 are input
                   // Global interrupt enable
        
    
     T0CONbits.TMR0ON = 1; //timer0 est ON
     T0CONbits.T08BIT = 0; //timer0 sur 16bits
     T0CONbits.T0CS=0 ; //internal clock source
     T0CONbits.PSA=0 ; //give the prescaler to TMR0
     T0CONbits.T0PS0 =  1;// prescalaire à 256
     T0CONbits.T0PS1 =  1; //prescalaire à 256
     T0CONbits.T0PS2 =  1; //prescalaire à 256
     INTCONbits.TMR0IE = 1;
     
    ADCON1 = 0x00;
	ADCON0 = 0x00;
    ADCON2 = 0x00;
    // set all ports as OUTPUTS
	TRISA = 0x06;
    LATA =0x00;    
    TRISB = 0xF0; 
    LATB =0x00;
	TRISC = 0x00;
    LATC =0x00;
	TRISD = 0x00;
      LATD =0x00;
	TRISE = 0x00;
    LATE =0x00;
	// PORTA digital
    // set port by port on "all zeros"
    
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
    PORTE = 0x00;
    
        INTCONbits.GIE = 1;  
	INTCONbits.RBIE=1;
   
            
	
	

	
// make sure to have an empty LAST line in any *.c file (just hit an Enter)!
}


