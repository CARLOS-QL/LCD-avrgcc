/*
 * HD44780.h
 *
 * Created: 7/12/2023 6:03:54 PM
 *  Author: marti
 */ 


#ifndef HD44780_H_
#define HD44780_H_

#define high_nibble(x) ((x)>>4)
#define low_nibble(x) ((x) & 0x0F)
#define set_bit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

#define F_CPU 16000000UL

#include <stdlib.h>	//Para poder mostrar enteros
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>



//******** Pines para los datos del LCD *********

#define D4	PB0
#define D5  PB1
#define D6  PB2
#define D7  PB3

//******** Pines para el control del LCD **********


#define RS	PB4
#define EN  PB5

#define ON  1
#define OFF 0

/******** Comandos para LCD *******/

#define LCD_CLEAR       0X01    //Limpia pantalla
#define LCD_HOME		0X02    //Primera l?nea
#define LCD_CURSOR_OFF  0X0C    //Cursor off 0b0000_1100(12)
#define LCD_CURSOR_ON   0X0F    //Cursor ON (15)
#define LCD_LEFT        0X10    //Mueve cursor izquierda(16)
#define LCD_RIGHT       0X14    //Mueve cursor derecha(20)
#define ROT_LEFT        0X18    //Rotar izquierda(24)
#define ROT_RIGHT       0X1C    //Rotar derecha(28)
#define LCD_LINEA2      0XC0    //Segunda l?nea
#define LCD_LINEA3      0x94    //Tercera l?nea
#define LCD_LINEA4      0XD4    //Cuarta l?nea


/************ Prototipos de funciones *************/

void LCD_init(void);                    	//Inicializa LCD
void LCD_write_nible(unsigned char nible);
void LCD_cmd(unsigned char);                //Envia comando
void LCD_dato(char);               //Envia dato
void LCD_write(unsigned char dato);         //Rutina para enviar dato
//void LCD_printf(char*);            //Imprime cadena de caracteres
void LCD_goto(uint8_t, uint8_t);            //Mueve cursor a un XY
void LCD_cursor(unsigned char);             //Activa o desactiva cursor
void LCD_clear(void);
void LCD_home(void);
void LCD_custom_char(unsigned char loc,unsigned char *msg);
static int LCD_putchar(char character, FILE *stream);

static FILE mystdout = FDEV_SETUP_STREAM(LCD_putchar, NULL, _FDEV_SETUP_WRITE);


#endif /* HD44780_H_ */