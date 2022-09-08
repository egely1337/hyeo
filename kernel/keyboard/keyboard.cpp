#include "keyboard.h"


const char ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'q', 'w', 'e', 'r', 't', 'y', 
    'u', 'i', 'o', 'p', '[', ']', '?', '?', 'a', 's', 'd', 'f', 'g', 
    'h', 'j', 'k', 'l', ';', '\'', '`', '?', '\\', 'z', 'x', 'c', 'v', 
    'b', 'n', 'm', ',', '.', '/', '?', '?', '?', ' '
};
extern void Reboot();
extern "C" char program[];

void keyboard_handler(Registers _regs){
    uint8_t scan_code = inb(0x60);
    if(scan_code > 58) return;
}
void init_keyboard(void){
    register_interrupt_handler(IRQ1,keyboard_handler);
}

char readChar()
{
	int run = 1;
	char out = 0;
    bool isShift = 0;
	while (run)
	{
		if (inb(0x64) & 0x1)
		{
			if (inb(0x60) == 0x2A && !isShift)
				isShift = 1;
			else if (inb(0x60) == 0xAA && isShift)
				isShift = 0;
			if (!isShift)
				out = ascii[inb(0x60)];
			else if (isShift)
				out = ascii[inb(0x60)];
			if (out != 0 && inb(0x60) < 60)
				run = 0;
		}
	}
	return out;
}