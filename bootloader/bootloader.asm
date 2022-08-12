org 0x7c00

mov bx, hw
call PrintString


mov [BOOT_DISK], dl
mov bp, 0x7c00
mov sp, bp
call boot


hw:
    db "Loading hyeo...",0


%include "bootloader/disk.asm"
%include "bootloader/print.asm"

times (510-($-$$)) db 0
dw 0xaa55    