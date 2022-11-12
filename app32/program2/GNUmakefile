compile:
	nasm loader.S -f elf32 -o crt0.o
	i386-elf-gcc -ffreestanding -m32 -g -c "main.cpp" -o "objects/main.o"
	i386-elf-ld --oformat binary -Ttext 0x60000 "crt0.o" "objects/main.o" "../../stdio/objects/string.o" "../../stdio/objects/hyeo.o" "../../stdio/objects/stdio.o" -o "../../hyeo-fs/sys/program1.bin"
