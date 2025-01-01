#include "drivers/include/stdio.h"
#include "drivers/include/cpu.h"
#include "drivers/include/strings.h"
void kmain(void);
void kmain(void){
    testChar(); /*displays the char set*/
    puts("Hello, World!\n");
    char key;
    while (1) {
        key = getc();
        
        switch (key)
        {
        case '\b':
            CursorX--;
            putc(' ');
            CursorX--;
            update_cursor(CursorX, CursorY);
            break;
        case 'q':
            halt;
            break;
        default:
            putc(key);
            break;
        }

    }
}