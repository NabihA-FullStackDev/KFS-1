#include "includes/vga.h"

uint16_t column = 0;
uint16_t line = 0;
uint16_t *const vga = (uint16_t *const) 0xB8000;
const uint16_t defaultColor = (TXT_COLOR << 8) | (BG_COLOR << 12);
uint16_t currentColor = defaultColor;

void reset_screen()
{
    line = 0;
    column = 0;
    currentColor = defaultColor;

    for (uint16_t y = 0; y < HEIGHT; y++)
        for (uint16_t x = 0; x < WIDTH; x++)
            vga[y * WIDTH + x] = ' ' | defaultColor;
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

void print(const char *s)
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
            vga[line * WIDTH + (column++)] = *s | currentColor;
        s++;
    }
}