CC = i386-elf-gcc

.SILENT: bc

bc:
	@-make -C ./stdio
	@-make -C ./app32/shell 
	@-make -C ./app32/program2 
	@-make -C ./app32/hello-world
	@-make -C ./hyeo-fs build-fs 
	@-nasm kernel/kernel.asm -f elf32 -o objects/init.o
	@-nasm kernel/idt/interrupts.asm -f elf32 -o objects/isr.o
	@-nasm kernel/multiboot.asm -f elf32 -o objects/multiboot.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/kmain.cpp -o objects/kernel.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/cpuid/cpuid.cpp -o objects/cpuid.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/gdt/gdt.cpp -o objects/gdt.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/panic/panic.cpp -o objects/panic.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/syscall/syscall.cpp -o objects/syscall.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/keyboard/keyboard.cpp -o objects/keyboard.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/timer/timer.cpp -o objects/timer.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/mem/memory.cpp -o objects/mem.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/inc/io.cpp -o objects/io.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/inc/tty.cpp -o objects/tty.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/idt/idt.cpp -o objects/idtc.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/idt/isr.cpp -o objects/isrc.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -DEBUG -g -c ./kernel/hyeo-fs/hfs.cpp -o objects/hfs.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/runtime/runtime.cpp -o objects/runtime.o
	@-${CC} -Ttext 0x8000 -ffreestanding -m32 -g -c ./kernel/mem/memmap.cpp -o objects/memmap.o
	@-i386-elf-ld -T ./linker.ld
	grub-mkrescue -o hyeo-i386.iso ./iso_root
run:
	qemu-system-i386 hyeo-i386.iso -m 64M 

commit:
	git add ./
	git commit -am "push from makefile"
	git push origin main --force
