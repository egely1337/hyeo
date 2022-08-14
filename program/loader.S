global _loader
extern _start

[bits 32]
_loader:
    call _start
    ret