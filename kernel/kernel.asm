[bits 16]
[extern _kmain]
_enterpm:
    call ClearScreen
    call EnableA20
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp codeseg:_startpmode

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92,  al
    ret
    

%include "bootloader/print.asm"
%include "kernel/gdt.asm"
%include "kernel/cpuid.asm"
%include "kernel/paging.asm"



[bits 32]
_startpmode:
    mov ax, dataseg
    mov ds,ax
    mov ss,ax
    mov es,ax
    mov fs,ax
    mov gs,ax
    call _kmain
    call _detectCpuId
    call _detectLongMode
    call _setuppaging
    call EditGDT
    jmp codeseg:Start64Bit

    
[bits 64]
Start64Bit:
    call _kmain





times (2048-($-$$)) db 0
