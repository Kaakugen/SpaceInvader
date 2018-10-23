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


 

void main (void)
{ 
    // call the function that will init the PIC
    initMyPIC18F();
    glcd_Init(GLCD_ON);

   glcd_Image();
   __delay_ms(1000);
   glcd_FillScreen(0); 
    
   plot_vie(-8,0,8,8,3);
   plot_monstre(24,3,10,10,24);
   
   plot_joueur(56,53,11,11);
   plot_tir(3,6);
  
   
   unsigned char i;
    while(1)
    {
         bouger_tir();
        
/*        for(i=0;i <10;i++)
        {
         bouger_joueurD();
         
        }
          for(i=0;i <10;i++)
        {
         bouger_joueurG();
          }
        */
        
        ;
    } 

}


   
   
void __interrupt() irqB()        // interrupt function 
{
         if (INTCONbits.RBIF == 1 ) // PORTB flag 
    { 
        INTCONbits.RBIF=0; // reset flag
       
        if (PORTBbits.RB7==1) // si RB7 == 1 alors on va à gauche
        {
            bouger_joueurG();
        }
    
        else if (PORTBbits.RB6==1) // si RB6 == 1 alors on va à droite
        {
            bouger_joueurD();
        }
        
    }
 
}


// end of the main function

// make sure to have an empty LAST line in any *.c file (just hit an Enter)!