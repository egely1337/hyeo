

extern "C" int _kmain(){
    *(char*)0xB8000 = 'H';
    *(char*)0xB8002 = 'e';
    *(char*)0xB8004 = 'l';
    *(char*)0xB8006 = 'l';
    *(char*)0xB8008 = 'o';
    while(true);
}