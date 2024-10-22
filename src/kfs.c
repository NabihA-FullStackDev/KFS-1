#include "includes/misc.h"
#include "includes/vga.h"

void kernel_main(void)
{
    change_colors(15, 0);
    fortytwo_header();
    change_colors(10, 0);
    prompt("42");
}
