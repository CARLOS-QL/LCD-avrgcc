# LCD-avrgcc
HD44780_liquidC is a library that allow us to control a lcd to display information. It's written in *C* (for future portability any uC) and is intend for use with the entire **AVR family** of microcontrollers with *7 pins*.

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

You can see on the channel of youtube of [carlosQL][youtube]

## Feature

### Functions

-  `lcd_init()` Inicializa las salidas y configura el lcd a 4-bits, limpia la pantalla.
- `lcd_cmd(uint8_t dato)` envia instrucciones de control, puedes ver las instrucciones de control en la parte de abajo.
- `lcd_printf(char *dato)` envia un array de caracteres (string), como si usaramos el printf de *C*.
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

1. clone the repository.
2. add the repository to your project.
3. In the main.c write: `#include "lcd.h"`

If you´re using **platforIO**:
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
### Structure

## Useful resources

- [video][youtube] on youtube Carlos QL


## Author

- [Carlos QL][carlosQL] made main library,
- [Martin GH][martingh] documentation in GitHub and registry in PlatformIO


[youtube]: https://www.youtube.com/watch?v=fgXfFPAbIKo&list=PL5a8rjiFubvetVKc8T-bHUXx6KZXm6XkA&index=10

[carlosQL]: https://www.youtube.com/@CarlosQL
[martinGh]: https://github.com/micro-marti

