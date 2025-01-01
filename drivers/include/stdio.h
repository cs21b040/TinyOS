/* 
    Author: Harold1970
    Date created: 12/29/2024
*/

#ifndef STDIO_H
#define STDIO_H

#include "cpu.h"

// colors
#define COLOR_BLACK_F 0x0000
#define COLOR_BLUE_F 0x0100
#define COLOR_GREEN_F 0x0200
#define COLOR_CYAN_F 0x0300
#define COLOR_RED_F 0x0400
#define COLOR_PURPLE_F 0x0500
#define COLOR_BROWN_F 0x0600
#define COLOR_GREY_F 0x0700
#define COLOR_DARK_GREY_F 0x0800
#define COLOR_BURPLE_F 0x0900
#define COLOR_LIGHT_GREEN_F 0x0a00
#define COLOR_LIGHT_CYAN_F 0x0b00
#define COLOR_LIGHT_RED_F 0x0c00
#define COLOR_LIGHT_PURPLE_F 0x0d00
#define COLOR_YELLOW_F 0X0e00
#define COLOR_WHITE_F 0x0f00

#define COLOR_BLACK_B 0x0000
#define COLOR_BLUE_B 0x1000
#define COLOR_GREEN_B 0x2000
#define COLOR_CYAN_B 0x3000
#define COLOR_RED_B 0x4000
#define COLOR_PURPLE_B 0x5000
#define COLOR_BROWN_B 0x6000
#define COLOR_GREY_B 0x7000
#define COLOR_DARK_GREY_B 0x8000
#define COLOR_BURPLE_B 0x9000
#define COLOR_LIGHT_GREEN_B 0xa000
#define COLOR_LIGHT_CYAN_B 0xb000
#define COLOR_LIGHT_RED_B 0xc000
#define COLOR_LIGHT_PURPLE_B 0xd000
#define COLOR_YELLOW_B 0Xe000
#define COLOR_WHITE_B 0xf000


#define VGA_ADDRESS 0xb8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define RET '\6'
#define DEL '\2'
extern int CursorX, CursorY;
extern int DisplayColor;

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);
void outw(uint16_t port, uint16_t value);
void update_cursor(int x, int y);
void putc(char c);
void puts(const char* message);
void clearScrn(void);
char getc(void);
char* scanf(int charRC);
void testChar();
void putint(int input);
void mvCursor(int nx, int ny);
#endif 
