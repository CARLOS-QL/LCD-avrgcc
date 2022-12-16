
//////////////////////////////////////////////////////////////////////////
////  Nombre :      LCD.h                                             ////
////  Creaci�n :    04/11/2018                                        ////
////  Descripci�n:  Configurable con cualquier PIN                    ////
//////////////////////////////////////////////////////////////////////////

#ifndef HD44780_H_
#define HD44780_H_

#include <stdlib.h>	//Para poder mostrar enteros
#include <stdint.h>	//Para poder usar tipo uint



//******** Pines para los datos del LCD *********

#define D4			PORTDbits.PD5_          // pin 11 lcd
#define D5          PORTDbits.PD6_          // pin 12 lcd
#define D6          PORTDbits.PD7_          // pin 13 lcd
#define D7          PORTBbits.PB0_          // pin 14 lcd

#define DDR_D4     DDRDbits.DDRD5			//D4 Out
#define DDR_D5     DDRDbits.DDRD6			//D5 Out
#define DDR_D6     DDRDbits.DDRD7			//D6 Out
#define DDR_D7     DDRBbits.DDRB0			//D7 Out

//******** Pines para el control del LCD **********


#define RS         PORTDbits.PD3_          //Pin 4 LCD
#define EN          PORTDbits.PD4_          //Pin 6 LCD
#define DDR_RS		DDRDbits.DDRD3        //RS Out
#define DDR_EN		DDRDbits.DDRD4       //EN Out

#define ON  1
#define OFF 0

/******** Comandos para LCD *******/

#define LCD_CLEAR       0X01    //Limpia pantalla
#define LCD_CURSOR_ON   0X0F    //Cursor ON
#define LCD_CURSOR_OFF  0X0C    //Cursor off
#define LCD_HOME		0X02    //Primera l�nea
#define LCD_LINEA2      0XC0    //Segunda l�nea
#define LCD_LINEA3      0x94    //Tercera l�nea
#define LCD_LINEA4      0XD4    //Cuarta l�nea
#define LCD_LEFT        0X10    //Mueve cursor izquierda
#define LCD_RIGHT       0X14    //Mueve cursor derecha

#define ROT_LEFT        0X18    //Rotar izquierda
#define ROT_RIGHT       0X1C    //Rotar derecha

/************ Prototipos de funciones *************/

void LCD_init(void);                    	//Inicializa LCD
void LCD_write_nible(unsigned char nible);
void LCD_cmd(unsigned char);                //Envia comando
void LCD_dato(char);               //Envia dato
void LCD_write(unsigned char dato);         //Rutina para enviar dato
void LCD_printf(char*);            //Imprime cadena de caracteres
void LCD_goto(uint8_t, uint8_t);            //Mueve cursor a un XY
void LCD_cursor(unsigned char);             //Activa o desactiva cursor
void LCD_clear(void);
void LCD_home(void);
void LCD_custom_char(unsigned char loc,unsigned char *msg);

#endif /*HD44780_H_*/
