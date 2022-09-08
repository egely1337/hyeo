compile:
	nasm loader.S -f elf32 -o crt0.o
	i386-elf-gcc -ffreestanding -m32 -g -c "main.cpp" -o "objects/main.o"
	i386-elf-gcc -ffreestanding -m32 -g -c "inc/stdio.cpp" -o "objects/stdio.o"
	i386-elf-gcc -ffreestanding -m32 -g -c "inc/string.cpp" -o "objects/string.o"
	i386-elf-gcc -ffreestanding -m32 -g -c "inc/hyeo.cpp" -o "objects/hyeo.o"
	i386-elf-ld --oformat binary -Ttext 0x12000 "crt0.o" "objects/main.o" "objects/string.o" "objects/hyeo.o" "objects/stdio.o" -o "../program.bin"
