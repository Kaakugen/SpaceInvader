/* 
 * File:   newmain.c
 * Author: Adrian Chazottes
 *
 * Created on 18 novembre 2016, 10:00
 */

#include "main.h"


#pragma config FOSC = HS 		//oscillator HS
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF 		//Disable watchDog
#pragma config LVP = OFF 		//Disable low voltage programmig
#pragma config DEBUG = ON		//Debug ON


unsigned char flag = 0;

void main (void)
{ 
    // call the function that will init the PIC
    initMyPIC18F();
    glcd_Init(GLCD_ON);
 
    glcd_Image();
   __delay_ms(1000);
   glcd_FillScreen(0); 
    
  plot_vie(-8,0,8,8,3);
  plot_monstre(24,1,10,10,24);
  // remove_Allmonstre(24,1,10,10,24);
   plot_joueur(56,53,11,11);
   
  
  plot_tir(3,6);
  
    
       while(1)
    {
            bouger_tir();
       /*   
    bouger_MonstreG();
    bouger_tir();
    bouger_MonstreG();
    bouger_tir();
    bouger_MonstreD();
    bouger_tir();
    bouger_MonstreD();
    bouger_tir();
     bouger_MonstreD();
    
    */
          
         
               ;/*
              if(PORTD == 0x80 || 0x40  )
              {  */
       }   
        
}
   /*
void __interrupt() irqB()        // interrupt function 
{
         if (INTCONbits.RBIF == 1 ) // PORTB flag 
    { 
             //plot_vie(-8,0,20,8,3);
        INTCONbits.RBIF=0; // reset flag
       
        if (PORTBbits.RB7==1) // si RB7 == 1 alors on va � gauche
        {
            bouger_joueurG();
        }
    
        else if (PORTBbits.RB6==1) // si RB6 == 1 alors on va � droite
        {
            bouger_joueurD();
        }
        
    }
 
}*/

void __interrupt() Tim()        // interrupt function 
{
         if (INTCONbits.TMR0IF == 1 ) // PORTB flag 
    { 
             //plot_vie(-8,0,20,8,3);
        INTCONbits.TMR0IF=0; // reset flag
        
        if(flag ==0)
        {
         bouger_MonstreG();
         flag = 1;
        }
        if(flag == 1)
        {
         bouger_MonstreD();
         flag = 0;
        }
    }
}
// end of the main function

// make sure to have an empty LAST line in any *.c file (just hit an Enter)!

