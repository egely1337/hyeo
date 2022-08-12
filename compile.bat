nasm bootloader/bootloader.asm -f bin -o bootloader.bin
nasm kernel/kernel.asm -f elf32 -o init.o
nasm kernel/idt/interrupts.asm -f elf32 -o isr.o
nasm kernel/vs.asm -f elf32 -o vs.o
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/kmain.cpp" -o "kernel.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/mem/memory.cpp" -o "mem.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/inc/io.cpp" -o "io.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/inc/tty.cpp" -o "tty.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/idt/idt.cpp" -o "idtc.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc -ffreestanding -m32 -g -c "./kernel/idt/isr.cpp" -o "isrc.o"
wsl /home/hyper/i386-elf/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld --oformat binary -Ttext 0x8000 "init.o" "mem.o" "idtc.o" "isr.o" "io.o" "tty.o"  "isrc.o" "kernel.o"  -o "kernel.bin"
copy /b bootloader.bin+kernel.bin+program.bin hyeo-i386.flp
move hyeo-i386.flp ./build/x86_64/
del bootloader.bin
del kernel.bin
del vs.o
del kernel.o
del init.o 
del isr.o
del isrc.o 
del idtc.o 
del io.o 
del tty.o 
del mem.o
qemu-system-i386.exe build/x86_64/hyeo-i386.flp -m 512M