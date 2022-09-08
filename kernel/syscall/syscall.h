#include "../idt/idt.h"
#include "../inc/typedefs.h"
#include "../inc/tty.h"
#include "../mem/memory.h"
#include "../keyboard/keyboard.h"

#define SYS_CLEAR_SCREEN 0
#define SYS_PRINT_CHAR 1
#define SYS_NEW_LINE 2
#define SYS_PRINT_INTEGER 3
#define SYS_PROCESS_EXIT 4
#define SYS_RANDOM 5
#define SYS_READCHAR 6




void sys_call_init(void);
void set_call_handler(void);
void syscall(void);
void call_handler(void);
void syscall_handler(char type, char argv1, char argv2, char argv3);