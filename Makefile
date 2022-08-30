build:
	nasm bootloader/bootloader.asm -f bin -o bootloader.bin
	nasm kernel/kernel.asm -f elf32 -o objects/init.o
	nasm kernel/idt/interrupts.asm -f elf32 -o objects/isr.o
	nasm kernel/vs.asm -f elf32 -o objects/vs.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/kmain.cpp -o objects/kernel.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/syscall/syscall.cpp -o objects/syscall.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/keyboard/keyboard.cpp -o objects/keyboard.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/timer/timer.cpp -o objects/timer.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/mem/memory.cpp -o objects/mem.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/inc/io.cpp -o objects/io.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/inc/tty.cpp -o objects/tty.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/idt/idt.cpp -o objects/idtc.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/idt/isr.cpp -o objects/isrc.o
	i386-elf-ld --oformat binary -Ttext 0x8000  objects/init.o objects/syscall.o objects/mem.o objects/idtc.o objects/isr.o objects/keyboard.o objects/timer.o objects/io.o objects/tty.o  objects/isrc.o objects/kernel.o objects/vs.o  -o kernel.bin
	cat bootloader.bin kernel.bin program.bin > hyeo-i386.flp
	mv hyeo-i386.flp ./build/x86_64/
	rm bootloader.bin	
	rm kernel.bin

bc:
	nasm bootloader/bootloader.asm -f bin -o bootloader.bin
	nasm kernel/kernel.asm -f elf32 -o objects/init.o
	nasm kernel/idt/interrupts.asm -f elf32 -o objects/isr.o
	nasm kernel/vs.asm -f elf32 -o objects/vs.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/kmain.cpp -o objects/kernel.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/syscall/syscall.cpp -o objects/syscall.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/keyboard/keyboard.cpp -o objects/keyboard.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/timer/timer.cpp -o objects/timer.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/mem/memory.cpp -o objects/mem.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/inc/io.cpp -o objects/io.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/inc/tty.cpp -o objects/tty.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/idt/idt.cpp -o objects/idtc.o
	i386-elf-gcc -ffreestanding -m32 -g -c ./kernel/idt/isr.cpp -o objects/isrc.o
	i386-elf-ld --oformat binary -Ttext 0x8000  objects/init.o objects/syscall.o objects/mem.o objects/idtc.o objects/isr.o objects/keyboard.o objects/timer.o objects/io.o objects/tty.o  objects/isrc.o objects/kernel.o objects/vs.o  -o kernel.bin
	cat bootloader.bin kernel.bin program.bin > hyeo-i386.flp
	mv hyeo-i386.flp ./build/x86_64/
	rm bootloader.bin	
	rm kernel.bin
	qemu-system-i386 build/x86_64/hyeo-i386.flp -m 512M
run:
	qemu-system-i386 build/x86_64/hyeo-i386.flp -m 512M

commit:
	git add ./
	git commit -am "push from makefile"
	git push origin master
