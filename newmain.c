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
   plot_monstre(28,3,10,10,24);
  
    while(1)
    {
            ;
    }

       

}// end of the main function

// make sure to have an empty LAST line in any *.c file (just hit an Enter)!