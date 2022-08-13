#include "keyboard.h"


const char ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
    'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
    'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
    'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '
};


void keyboard_handler(Registers _regs){
    uint8_t scan_code = inb(0x60);
    if(scan_code > 58) return;
    _printf("%c", ascii[scan_code]);
}
void init_keyboard(void){
    register_interrupt_handler(IRQ1,keyboard_handler);
}