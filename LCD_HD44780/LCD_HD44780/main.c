/*
 * LCD_HD44780.c
 *
 * Created: 26/10/2019 08:57:15
 * Author : carlos
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "DEF_ATMEGA328P.h"
#include "LCD.h"

float numero2 = 25.12;
int16_t numero1 = -1024;
char st[8];

int main(void)
{
	
	unsigned char customChar [8] = {
		0b00000,
		0b01010,
		0b01010,
		0b01010,
		0b00000,
		0b10001,
		0b01110,
		0b00000
	};

	LCD_init();	
	
	LCD_custom_char(0, customChar);
	
	LCD_goto(1, 1);
	LCD_printf("Linea1 ");
	itoa(numero1, st, 10);
	LCD_printf(st);
	
	LCD_cmd(LCD_LINEA2);
	LCD_printf("Linea2 ");
	itoa(numero1, st, 16);
	LCD_printf(st);
	
	
	LCD_cmd(LCD_LINEA3);
	LCD_printf("Linea3 ");
	dtostrf(numero2, 5, 2, st);
	LCD_printf(st);
	
	LCD_cmd(LCD_LINEA4);
	LCD_printf("Linea4 ");
	LCD_dato(0);


	while (1)
	{
		
		
		
	}
}

