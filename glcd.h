/* 
 * File:   glcd.h
* Author: Adrian Chazottes
 *
 * Created on 18 novembre 2016, 10:00
 */



//CONFIG

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements


// PIC18F4450 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 2       // PLL Prescaler Selection bits (Divide by 2 (8 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 21        // Brown-out Reset Voltage bits (2.1V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config BBSIZ = BB1K     // Boot Block Size Select bit (1KW Boot block size)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) or (001000-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) or (000000-000FFFh) is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) or (001000-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) or (000000-000FFFh) is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) or (001000-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) or (000000-000FFFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>



#ifndef GLCD_H
#define	GLCD_H

#define 	LCD_WIDTH			128
#define 	LCD_HEIGHT			64

#define 	GLCD_CS1			LATBbits.LATB0
#define 	GLCD_CS2			LATBbits.LATB1
#define 	GLCD_RS				LATBbits.LATB2
#define 	GLCD_RW				LATBbits.LATB3
#define 	GLCD_E				LATEbits.LATE0
#define 	GLCD_RST			LATEbits.LATE2

#define 	GLCD_DATA_TRIS		TRISD
#define 	WR_DATA				LATD		
#define 	RD_DATA				PORTD	

#define 	GLCD_LEFT   	 	0
#define 	GLCD_RIGHT  	 	1	
	
#define 	GLCD_OFF			0
#define 	GLCD_ON				1

#define		OUT					0
#define		IN					1

#define		f3X6				0
#define		f8X8				1

#define XTAL_FREQ 8000000 // oscillator frequency for _delay()

#define _XTAL_FREQ 8000000 // oscillator frequency for _delay_ms()



//************************************************************************
// PROTOTYPES
//************************************************************************
extern void glcd_Init(unsigned char mode);
extern void glcd_WriteByte(unsigned char side, unsigned char data);
extern unsigned char glcd_ReadByte(unsigned char side);
extern void glcd_PlotPixel(unsigned char x, unsigned char y, unsigned char color);
extern void glcd_SetCursor(unsigned char xpos,unsigned char ypos);
extern void glcd_FillScreen(unsigned char color);
extern void glcd_WriteChar8X8( unsigned char ch, unsigned char color);
extern void glcd_WriteChar3x6( unsigned char ch, unsigned char color);
extern void glcd_WriteString(unsigned char str[],unsigned char font,unsigned char color);
extern void glcd_Image();
extern void glcd_Image2();
extern void glcd_Image3();
//fonction ajoutés

//fonction monstre
extern void plot_monstre(unsigned char xpos,  unsigned char ypos, unsigned char xmax,  unsigned char ymax,unsigned char nbMonstre2);
extern void remove_Allmonstre(unsigned char xmax, unsigned char ymax,unsigned char nbMonstre);
extern void remove_monstre(unsigned char posx,unsigned char posy, unsigned char xmax,unsigned char ymax);
extern void bouger_MonstreG();
extern void bouger_MonstreD();


extern void plot_vie( unsigned char xpos,  unsigned char ypos, char xmax, unsigned char ymax,unsigned char nbVie);

//fonction joueur
extern void plot_joueur( unsigned char xpos,  unsigned char ypos, char xmax, unsigned char ymax);
extern void remove_joueur(unsigned char posPersoX, unsigned char posPersoY,unsigned char xmax,unsigned char ymax);
extern void bouger_joueurD();
extern void bouger_joueurG();

//fonction tir
extern void plot_tir(unsigned char xmax, unsigned char ymax);
extern void remove_tir(unsigned char xmax, unsigned char ymax);
extern void bouger_tir();

extern void plot_tirMonstre(unsigned char xmax, unsigned char ymax);
extern void remove_tirMonstre(unsigned char xmax, unsigned char ymax);
extern void bouger_tirMonstre();

extern void  remove_coeur(unsigned char posx,unsigned char posy, unsigned char xmax,unsigned char ymax);

#endif	/* GLCD_H */

