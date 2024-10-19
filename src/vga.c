#include "includes/vga.h"

uint16_t column = 0;
uint16_t line = 0;
uint16_t *const vga = (uint16_t *const) 0xB8000;
const uint16_t defaultColor = (DFT_TXT_COLOR << 8) | (DFT_BG_COLOR << 12);
uint16_t currentColor = defaultColor;

void reset_screen()
{
    char c = ' ';

    line = 0;
    column = 0;

    while (line < HEIGHT)
    {
        column = 0;
        while (column < WIDTH)
        {
            printc(&c, defaultColor);
            column++;
        }
        line++;
    }
    line = 0;
    column = 0;
}

void new_line()
{
    column = 0;
    if (line >= HEIGHT)
    {
        reset_screen();
        line = 0;
    }
    else
        line++;
}

void printc(const char *c, uint16_t color)
{
    vga[line * WIDTH + column] = *c | color;
}

void prints(const char *s)
{
    while (*s)
    {
        if (column >= WIDTH || *s == '\n')
            new_line();
        else if (line >= HEIGHT)
        {
            reset_screen();
            line = 0;
        }
        else
        {
            printc(s, currentColor);
            column++;
        }
        s++;
    }
}