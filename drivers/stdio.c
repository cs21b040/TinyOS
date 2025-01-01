/* 
    Author: Harold1970
    Date created: 12/29/2024
*/

#include "include/stdio.h" 
#include "../stdint.h"
#include "include/keymaps.h"
#define halt outw(0x604, 0x2000)


int CursorX = 0, CursorY = 0;
int DisplayColor = 0x0F00;

void update_cursor(int x, int y) {
    uint16_t pos = y * VGA_WIDTH + CursorX;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}
void scrollUp() {
    uint16_t *vga = (uint16_t *)VGA_ADDRESS;

    for (int y = 1; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga[(y - 1) * VGA_WIDTH + x] = vga[y * VGA_WIDTH + x];
        }
    }

    for (int x = 0; x < VGA_WIDTH; x++) {
        vga[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = 0x0F00; 
    }

    CursorY--;
    if (CursorY < 0) {
        CursorY = 0; 
    }
}
void putc(char c) {
    uint16_t *vga = (uint16_t *)VGA_ADDRESS;
    if (c == '\e') {
        return;
    }
    if (c == '\n') {
        CursorX = 0;
        CursorY++;
        if (CursorY >= VGA_HEIGHT) {
            scrollUp();
        }
        update_cursor(CursorX, CursorY);
        return;
    }

    if (c != '\0') {
        vga[CursorY * VGA_WIDTH + CursorX] = (c | DisplayColor); // White text on black background
        CursorX++;
        if (CursorX >= VGA_WIDTH) {
            CursorX = 0;
            CursorY++;
            if (CursorY >= VGA_HEIGHT) {
                scrollUp();
            }
        }
        update_cursor(CursorX, CursorY);
    }
}

void puts(const char* message) {
    int i = 0;
    while (message[i] != 0) {
        putc(message[i]);
        i++;
    }
}
void mvCursor(int nx, int ny) {
    CursorX = nx;
    CursorY = ny;
    return;
} 
void clearScrn() {
    uint16_t *vga = (uint16_t *)VGA_ADDRESS;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga[i] = 0x0F00; // Clear screen to white text on black background
    }
}

char translateScanCode(uint8_t scanCode) {
    return scanCodes[scanCode];
}
char getc(void) {
    while ((inb(KEYBOARD_STATUS_PORT) & 0x01) == 0);
    
    uint8_t scancode = inb(KEYBOARD_DATA_PORT);
    return (scancode & 0x80) ? 0 : translateScanCode(scancode);

}


void testChar() {
    for (int i = 0; i <= 128; i++) {
        putc(i);
    }
    return;
}