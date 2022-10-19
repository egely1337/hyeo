OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

ENTRY(_kmain)

INPUT(
    objects/multiboot.o
    objects/init.o 
    objects/gdt.o
    objects/syscall.o 
    objects/hfs.o 
    objects/panic.o
    objects/runtime.o
    objects/memmap.o
    objects/mem.o 
    objects/idtc.o 
    objects/isr.o 
    objects/keyboard.o 
    objects/timer.o 
    objects/io.o 
    objects/tty.o
    objects/isrc.o 
    objects/kernel.o 
)

OUTPUT(
    iso_root/boot/hyeo-i386.elf
)


SECTIONS
{
    . = 0x8000;

    .text : ALIGN(0x1000){
       *(.multiboot)
        *(.text)
    }

    .data : ALIGN(0x1000){
        *(.data)
    }
    .rodata : ALIGN(0x1000) {
        *(.rodata)
    }

    .bss : ALIGN(0x1000){
        *(COMMON)
        *(.bss)
    }
}