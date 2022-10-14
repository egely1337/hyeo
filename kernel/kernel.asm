[bits 16]
[extern _kmain]

_enterpm:
    call ClearScreen
    ;call detect_memory
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

succ:
    db "Successfully booted OS.", 0
    
%include "bootloader/print.asm"
%include "kernel/gdt.asm"
%include "kernel/mem.asm"


[bits 32]
_startpmode:
    call _kmain


times (2048-($-$$)) db 0
