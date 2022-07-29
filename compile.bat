nasm bootloader/bootloader.asm -f bin -o bootloader.bin
nasm kernel/kernel.asm -f elf64 -o init.o
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "./kernel/kmain.cpp" -o "kernel.o"
wsl $WSLENV/x86_64-elf-ld -o kernel.tmp -Ttext 0x7e00  init.o kernel.o
wsl /usr/bin/objcopy -O binary kernel.tmp kernel.bin
copy /b bootloader.bin+kernel.bin armenianOS-x86_64.flp
move armenianOS-x86_64.flp ./build/x86_64/
del kernel.bin
del bootloader.bin
del kernel.o 
del init.o 
del kernel.tmp
qemu-system-x86_64.exe build/x86_64/armenianOS-x86_64.flp