#include "../include/HD44780.h"

/***********************************************
 ------- Inicializa LCD 4 bits de datos -------
 ***********************************************/

void LCD_init(void)
{   
	DDR_RS = 1;		//RS salida
	DDR_EN = 1;		//EN salida
	EN = 0;			
	RS = 0; 
   
	DDR_D4 = 1;		//D4 salida
    DDR_D5 = 1;		//D5 salida
	DDR_D6 = 1;		//D6 salida
	DDR_D7 = 1;		//D7 salida	

 
	_delay_ms(20);						//Espera que se estabilicen puertos

	for(unsigned char i=0; i<3; i++){   //Recomendado
		LCD_write_nible(0x03);          //por fabricante
		_delay_ms(5);
	}
    
    LCD_cmd(0x33);						// initialize controller
    LCD_cmd(0x32);						//set to 4-bit input mode
    LCD_cmd(0x28);						//Configura el LCD a 4 Bits, 2 Lineas Y Fuente de 5*7
    LCD_cmd(0x0C);						//LCD Prendido, Cursor Apagado, Destello Cursor apagado
    LCD_cmd(0x06);						//No rota el mensaje Y se incrementa el contador de direccion
	LCD_cmd(0x01);						//Limpia pantalla
    _delay_ms(3);
}

/***********************************************
 ---- Rutina para enviar datos y comandos ------
 ***********************************************/

void LCD_write_nible(unsigned char nible)
{  
    if (nible & (1<<0)) D4 = 1; else D4 = 0;             
    if (nible & (1<<1)) D5 = 1; else D5 = 0;
    if (nible & (1<<2)) D6 = 1; else D6 = 0;
    if (nible & (1<<3)) D7 = 1; else D7 = 0;
    
    EN = 1;     
    _delay_us(50);	//Enable pulse width PWeh min 230ns
    EN = 0; 
}
/***********************************************
 ---------- Env�a comandos por el LCD ----------
 ***********************************************/

void LCD_cmd(uint8_t dato)
{
    RS = 0; 
	asm("nop");
    LCD_write_nible(dato>>4);
    LCD_write_nible(dato & 0x0F);
	_delay_ms(1);		
}

/***********************************************
 ----------- Env�a datos por el LCD ------------
 ***********************************************/

void LCD_dato(char dato)
{
	RS = 1;
	asm("nop");	
    LCD_write_nible(dato>>4);
    LCD_write_nible(dato & 0x0F);
	_delay_ms(1);			//tiempo m�nimo 40us
}


/***********************************************
 ----------- Imprime string por LCD ------------
 ***********************************************/

void LCD_printf(char *dato) {
    while (*dato){
        LCD_dato(*dato);    // Envio el dato al LCD
        dato++;             // Incrementa el buffer de dato
    }
}

/***********************************************
 ----- Mueve el cursor a una posici�n x y ------
 ***********************************************/

void LCD_goto(uint8_t x, uint8_t y){
    uint8_t posicion;
    switch (y) {
        case 1: posicion = 0x00 + x - 1; break;
        case 2: posicion = 0x40 + x - 1; break;
        case 3: posicion = 0x14 + x - 1; break;
        case 4: posicion = 0x54 + x - 1; break;
        default: posicion = 0x00 + x - 1; break;
    }
    LCD_cmd(0x80 | posicion);
}

/***********************************************
 --------- Activa o desactiva cursor ----------
 ***********************************************/

void LCD_cursor(unsigned char cursor){
    if(cursor) 
        LCD_cmd(0x0F);
    else 
        LCD_cmd(0x0C);
}


/***********************************************
 --------- Limpia toda la pantalla LCD ---------
 ***********************************************/

void LCD_clear(void) {
    LCD_cmd(0x01);
    _delay_ms(2);
}

/***********************************************
 ---------- Cursor Regresa al inicio ----------
 ***********************************************/

void LCD_home(void) {
   LCD_cmd(0x02);
   _delay_ms(2);
}

/***********************************************
 --------- Para personalizar caracter ----------
 ***********************************************/

void LCD_custom_char(unsigned char loc,unsigned char *msg){
    
    unsigned char i;
    if(loc<8){
        LCD_cmd(0x40+(loc*8));  /* Command 0x40 and onwards forces the device to point CGRAM address */
        for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */
            LCD_dato(msg[i]);
    }   
}
