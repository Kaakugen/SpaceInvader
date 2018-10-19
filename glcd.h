/* 
 * File:   glcd.h
* Author: Adrian Chazottes
 *
 * Created on 18 novembre 2016, 10:00
 */

#ifndef GLCD_H
#define	GLCD_H

#define 	LCD_WIDTH			128
#define 	LCD_HEIGHT			64

#define 	GLCD_CS1			LATBbits.LATB0
#define 	GLCD_CS2			LATBbits.LATB1
#define 	GLCD_RS				LATBbits.LATB2
#define 	GLCD_RW				LATBbits.LATB3
#define 	GLCD_E				LATBbits.LATB4
#define 	GLCD_RST			LATBbits.LATB5

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

#include <htc.h>

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
<<<<<<< HEAD
extern void glcd_PlotImg(unsigned char** image, int xpos, int ypos);
=======
extern void glcd_PlotImg(unsigned char image[8][64], unsigned char xpos, unsigned char ypos, unsigned char color);
>>>>>>> 4f5eca8b77da9f4a30fc9d0258b1cda891928482

#endif	/* GLCD_H */

