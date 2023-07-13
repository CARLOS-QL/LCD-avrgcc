# LCD-avrgcc

HD44780_liquidC es una *static library* que te permite controlar un display LCD con el **controlador HD44780** a 4-bits, se integro la función `printf("")` para una mayor facilidad de uso.

Esta escrita en *C* para el **uC** *ATmega328P* (Arduino UNO) pero puedes ver el código principal en la carpeta **src/** de este repositorio y extenderlo a otros uC.

> Esta library ocupa **6 GPIO** (RS,EN,D4..D7), solo modifica el header *src/HD44480.h* en el `#define`,
en su configuración actual ocupa el DDRB,PORT.

## Table of content

- [Demo](#demo)
- [Feature](#feature)
  - [Functions](#functions)
  - [Comands LCD](#commands-lcd)
- [Installation Step](#installation-step)
- [The process](#the-process)
  - [Built with](#built-with)
  - [Structure](#structure)
- [Useful resources](#useful-resources)
- License
- [Author](#author)

## Demo

<img src="https://i.imgur.com/5Lg9aQR.jpg" width="300" align="center">

Puedes ver su funcionamiento en el canal de [carlosQL][youtube] o tambien programarla online en [Wookwi][wookwi].

## Feature

A parte de la función printf() cuenta con las siguientes funciones y comandos:

### Functions

- `lcd_init()` Inicializa las salidas y configura el lcd a 4-bits, limpia la pantalla.
- `lcd_cmd(uint8_t dato)` envia instrucciones de control, puedes ver las instrucciones de control en la parte de abajo.
- `lcd_goto(uint8_t x, uint8_t y)` mueve el cursor a una posición (x,y).
- `lcd_cursor(unsigned char cursor)` Activa o desactiva el cursor.
- `lcd_clean()` Limpia toda la pantalla lcd.
- `lcd_custom_char(unsigned char loc, unsigned char *msg)` para personalizar caracteres.

### Commands LCD

- `LCD_CLEAR`
- `LCD_HOME`
- `LCD_CURSOR_OFF` cursor underline off
- `LCD_CURSOR_ON`  cursor underline on, cursor blink on
- `LCD_LEFT` cursor left shift
- `LCD_RIGHT` cursor right shift
- `ROT_LEFT`
- `ROT_RIGHT`

## Installation Step

Existen varias formas para usar la libreria, aquí usaremos 2 y esto dependera del *IDE* o *Editor de texto* que ocupes:

- **Microchip Studio**
  1. Clona este repositorio.
  2. Abre microchip studio ve a la parte de: File>Open>Project/solution.. y busca tu repositorio descargado y selecciona el archivo **.cproj**.
  3. Oprime el boton de **Build** y te generara una static library **.a**
  4. En tu projecto principal das click derecho en **Libraries** y selecciones **Add Library**, buscas la static library generada.
  5. Opcionalmente agrega el header **HD44780.h** al proyecto principal para no tener warnigns del compilador.
- **PlatformIO (VScode)**
  1. only change the directory to project where *platformio.ini* is located.
  2. copy the following comand of cli shell and press enter.

    ```shell
    pio pkg install --library "marti-beta/HD44780_liquidC@^1.0.0"
    ```

  3. In the main.c write: `#include <lcd.h>`

## The process

### Built with

Technologies used in the project:

- C lenguage
- platformIO library
- Atmega328p (*uC of Arduino*)
- LCD 16x2 or 20x4

## Useful resources

- [video][youtube] on youtube Carlos QL

## Author

- [Carlos QL][carlosQL] library creator,
- [Martin GH][martingh] documentation.

[youtube]: https://www.youtube.com/watch?v=fgXfFPAbIKo&list=PL5a8rjiFubvetVKc8T-bHUXx6KZXm6XkA&index=10

[carlosQL]: https://www.youtube.com/@CarlosQL
[martinGh]: https://github.com/micro-marti
[wookwi]: https://wokwi.com/projects/370099311707629569
