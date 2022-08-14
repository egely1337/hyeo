nasm loader.S -f elf32 -o crt0.o
wsl $WSLENV/bin/i386-elf-gcc -ffreestanding -m32 -g -c "main.cpp" -o "main.o"
wsl $WSLENV/bin/i386-elf-gcc -ffreestanding -m32 -g -c "inc/stdio.cpp" -o "stdio.o"
wsl $WSLENV/bin/i386-elf-ld --oformat binary -Ttext 0x12000 "crt0.o" "main.o" "stdio.o" -o "../program.bin"
