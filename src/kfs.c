#include "includes/vga.h"

void kernel_main(void);

void kernel_main(void) {
    resetScreen();
    print("42");
}