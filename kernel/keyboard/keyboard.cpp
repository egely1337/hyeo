#include "keyboard.h"


const char ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'q', 'w', 'e', 'r', 't', 'y', 
    'u', 'i', 'o', 'p', '[', ']', '?', '?', 'a', 's', 'd', 'f', 'g', 
    'h', 'j', 'k', 'l', ';', '\'', '`', '?', '\\', 'z', 'x', 'c', 'v', 
    'b', 'n', 'm', ',', '.', '/', '?', '?', '?', ' '
};

extern void Reboot();
extern "C" bool kernelStarted;
char input[128];
uint32_t current = 0;
extern "C" char program[];

void keyboard_handler(Registers _regs){
    uint8_t scan_code = inb(0x60);
    if(!kernelStarted) return;
    if(scan_code == 0x1C){
        input[current+1] = '\0';
        if(!strcmp(input, "crash")){
            int b = (5/0);
        } 
        if(!strcmp(input,"program.bin")){
            printf("\n");
            memcpy((void*)0x12000,program,4264);
            ((void (*)())0x12000)();  
        }
        if(!strcmp(input,"experimental")){
            for(int i = 0; i < 10; i++){
                _printf("i: %d\n", i);
            }
        }
        if(!strcmp(input,"help")){
            _printf(
                "\n\nCommands:\nclear: will clear your screen\ncrash: will crash your os\nhelp: will show this message\nticks: will show sys ticks\nauthor: will show the author.\nreboot: will reboot your computer\n"
            );
        } 
        if(!strcmp(input,"clear")){
            clear_screen_color(VGA_BLACK , VGA_WHITEGRAY);
        }
         if(!strcmp(input,"ticks")){
            _printf("\nsystem booted up for %d seconds\n", getSeconds());
        }
        if(!strcmp(input,"reboot")){
            Reboot();
        }
        else if(!strcmp(input,"author")) _printf("\nThis OS made by hyper [%s]",
        "https://github.com/hyper1923");
        current = 0;
        for(volatile int i = 0; i < 128; i++){
            input[i] = 0;
        }
        _printf("\n\nhyeo@user$- ");
        return;
    }
    if(scan_code == 0x0E){
        if(current == 0) return;
        deleteOneCharacter();
        current--;
        input[current] = 0;
        return;
    }
    if(scan_code > 58) return;
    _printf("%c", ascii[scan_code]);
    input[current] = ascii[scan_code];
    current++;
}
void init_keyboard(void){
    register_interrupt_handler(IRQ1,keyboard_handler);
}