#include "../idt/idt.h"
#include "../inc/typedefs.h"
#include "../inc/tty.h"
#include "../mem/memory.h"
#include "../keyboard/keyboard.h"
#include "../hyeo-fs/hfs.h"

#define SYS_CLEAR_SCREEN 0
#define SYS_PRINT_CHAR 1
#define SYS_NEW_LINE 2
#define SYS_PRINT_INTEGER 3
#define SYS_PROCESS_EXIT 4
#define SYS_RANDOM 5
#define SYS_READCHAR 6
#define SYS_DELETEONECHARACTER 7
#define SYS_SLEEP 8
#define SYS_BOOT_SECONDS 9
#define SYS_KERNEL_MEMCPY 10
#define SYS_KERNEL_MEMSET 11
#define SYS_CRASH 12
#define SYS_HFS_GET_DATA 13




void sys_call_init(void);
void set_call_handler(void);
void syscall(void);
void call_handler(void);
void syscall_handler(char type, char argv1, char argv2, char argv3);