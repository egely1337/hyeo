PROGRAM_SPACE equ 0x7e00 

boot:
    mov ah, 0x02
    mov dl, [BOOT_DISK]
    mov bx, PROGRAM_SPACE
    mov al, 32
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13
    jmp PROGRAM_SPACE
    

BOOT_DISK: 
    db 0