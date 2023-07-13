/*
 * HD44780.c
 *
 * Created: 7/12/2023 5:57:22 PM
 * Author : marti
 */ 

#include "HD44780.h"

/***********************************************
 ------- Inicializa LCD 4 bits de datos -------
 ***********************************************/

void LCD_init(void)
{
    DDRB = 0x3F;
    clear_bit(PORTB, EN);
    clear_bit(PORTB, RS);
	stdout = &mystdout;

    LCD_write_nible(0x03);
    LCD_write_nible(0x03);
    LCD_write_nible(0x03);

    LCD_cmd(0x33); // initialize controller
    LCD_cmd(0x32); // set to 4-bit input mode
    LCD_cmd(0x28); // Configura el LCD a 4 Bits, 2 Lineas Y Fuente de 5*7
    LCD_cmd(0x0C); // LCD Prendido, Cursor Apagado, Destello Cursor apagado
    LCD_cmd(0x06); // No rota el mensaje Y se incrementa el contador de direccion
    LCD_cmd(0x01); // Limpia pantalla
    _delay_ms(3);
}

/***********************************************
 ---- Rutina para enviar datos y comandos ------
 ***********************************************/

void LCD_write_nible(unsigned char nibble)
{
    PORTB = (PINB & 0xF0) | nibble;
    set_bit(PORTB, EN);
    _delay_us(50); // Enable pulse width PWeh min 230ns
    clear_bit(PORTB, EN);
}
/***********************************************
 ---------- Env?a comandos por el LCD ----------
 ***********************************************/

void LCD_cmd(uint8_t dato)
{
    clear_bit(PORTB, RS);
    asm("nop");
    LCD_write_nible(high_nibble(dato));
    LCD_write_nible(low_nibble(dato));
    _delay_ms(1);
}

/***********************************************
 ----------- Env?a datos por el LCD ------------
 ***********************************************/

void LCD_dato(char dato)
{
    set_bit(PORTB, RS);
    asm("nop");
    LCD_write_nible(high_nibble(dato));
    LCD_write_nible(low_nibble(dato));
    _delay_ms(1); // tiempo m?nimo 40us
}

/***********************************************
 ----------- Imprime string por LCD ------------
 ***********************************************/

/*void LCD_printf(char *dato)
{
    while (*dato != NULL)
    {
        LCD_dato(*dato); // Envio el dato al LCD
        dato++;          // Incrementa el buffer de dato
    }
}*/

/***********************************************
 ----- Mueve el cursor a una posici?n x y ------
 ***********************************************/

void LCD_goto(uint8_t x, uint8_t y)
{
    uint8_t posicion;
    switch (y)
    {
    case 1:
        posicion = 0x00 + x - 1;
        break;
    case 2:
        posicion = 0x40 + x - 1;
        break;
    case 3:
        posicion = 0x14 + x - 1;
        break;
    case 4:
        posicion = 0x54 + x - 1;
        break;
    default:
        posicion = 0x00 + x - 1;
        break;
    }
    LCD_cmd(0x80 | posicion);
}

/***********************************************
 --------- Activa o desactiva cursor ----------
 ***********************************************/

void LCD_cursor(unsigned char cursor)
{
    if (cursor)
        LCD_cmd(0x0F);
    else
        LCD_cmd(0x0C);
}

/***********************************************
 --------- Limpia toda la pantalla LCD ---------
 ***********************************************/

void LCD_clear(void)
{
    LCD_cmd(0x01);
    _delay_ms(2);
}

/***********************************************
 ---------- Cursor Regresa al inicio ----------
 ***********************************************/

void LCD_home(void)
{
    LCD_cmd(0x02);
    _delay_ms(2);
}

/***********************************************
 --------- Para personalizar caracter ----------
 ***********************************************/

void LCD_custom_char(unsigned char loc, unsigned char *msg)
{

    unsigned char i;
    if (loc < 8)
    {
        LCD_cmd(0x40 + (loc * 8)); /* Command 0x40 and onwards forces the device to point CGRAM address */
        for (i = 0; i < 8; i++)    /* Write 8 byte for generation of 1 character */
            LCD_dato(msg[i]);
    }
}

static int LCD_putchar(char character, FILE *stream)
{
    if (character == '\n'){
        LCD_cmd(LCD_LINEA2);
		return 0;
	}
    LCD_dato(character);
    return 0;
}



