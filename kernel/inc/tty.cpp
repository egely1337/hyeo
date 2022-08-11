#include "tty.h"


void SetCursorPosition(uint16_t position){
    outb(0x3D4,0x0F);
    outb(0x3D5, (uint8_t)(position & 0xFF));
    outb(0x3D4, 0x0e);
    outb(0x3D5,(uint8_t)((position >> 8) & 0xFF));
}

uint16_t poscords(uint16_t x, uint16_t y){
    return y * VGA_WIDTH + x;
}

void clear_screen(){
    for(int i = (int)VGA_MEMORY; VGA_MEMORY; i++){
        *((char*)i) = 0;
    }
}

void print_char(char s)
{
    *(VGA_MEMORY + cursorPosition.returnRawPosition() *2) = s;
    SetCursorPosition(cursorPosition.returnRawPosition());
    cursorPosition.x++;
}

void printf(const char* _text){
    uint8_t* data = (uint8_t*)_text; 
    while(*data != 0){
        if(*data == '\n'){
            cursorPosition.x = 0;
            cursorPosition.y++;
            SetCursorPosition(cursorPosition.returnRawPosition()+1);
            break;
        } else{
            print_char(*data);
            data++;  
        }
    }
}

void printInteger(int _data){  
        int rem;
        int ones;
        int tens;
        int hundreds;
        int thousands;
        int tensThousands;

        int size;
        int sizeTester = (int)_data;
        while(sizeTester / 10 > 0){
            sizeTester /= 10;
            size++;
        }
        for (int i = 0; i < 5; i++) 
        {
            rem = _data %10;
            _data = _data /10;

            if(i == 0)
                ones = rem;
            else if(i == 1)
                tens = rem;
            else if(i == 2)
                hundreds = rem;
            else if(i == 3)
                thousands = rem;
            else if(i == 4)
                tensThousands = rem;
        }

        for (int i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
                print_char('0' + tensThousands);
                break;
            case 1:
                print_char('0' + thousands);
                break;
            case 2:
                print_char('0' + hundreds);
                break;
            case 3:
                print_char('0' + tens);
                break;
            case 4:
                print_char('0' + ones);
                break;                
            }
        }
        
    }