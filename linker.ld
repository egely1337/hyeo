OUTPUT_FORMAT(binary)

INPUT(
    objects/init.o 
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
    objects/vs.o
)

OUTPUT(
    kernel.bin
)


SECTIONS
{
    . = 0x8000;

    .text : ALIGN(0x1000){
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