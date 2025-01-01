/* 
    Author: Harold1970
    Date created: 12/29/2024
*/

#ifndef CPU_H
#define CPU_H
#include "../../stdint.h"

#define halt outw(0x604, 0x2000)

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);
void outw(uint16_t port, uint16_t value);
#endif // CPU.H
