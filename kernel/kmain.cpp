#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"

extern "C" int _kmain(){
    isr_install();
    clear_screen();
    /*
    experimental
    for(uint32_t i = 0; i < (VGA_WIDTH * MAX_ROWS); i++){
        print_char('H');
    }
    memset((void*)0xB8000,'H',VGA_WIDTH * 2);
    memcut((void*)0xB8000, (void*)(0xb8000 + (VGA_WIDTH * 2)), (VGA_WIDTH * MAX_ROWS *  - (80 * 2)));
    resetCursorPosition();
    */

   /*
   experimental 2
    _printf(
        "Lipendisin annesine gotten giriyoruzzz: %d\nBugun ne yapiyoruz ananizin amini sikiyoruz %s"
        , 10 , "nerden? gotten!"
    );
    */

   /*
   experimental 3
   _printf(
    "hi guys we are gonna do something you now\nOh looks like you are gay\neax: %d\tesi: %d",
    100,100
   );
   */
    
    /*
    kernel panic experimental testing
    int b = (5/0);
    */
    return -123;
}