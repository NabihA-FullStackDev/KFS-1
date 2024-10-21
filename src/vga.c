#include "includes/vga.h"

vga_t vga_state = {
    .column = 0,
    .line = 0,
    .vga = (uint16_t *const) 0xB8000,
    .default_color = (DFT_TXT_COLOR << 8) | (DFT_BG_COLOR << 12),
    .current_color = (DFT_TXT_COLOR << 8) | (DFT_BG_COLOR << 12)
};

void change_colors(const uint16_t txt, const uint16_t bg)
{
    if (!(txt > 16 || bg > 16) && (txt != bg))
    {
        uint16_t color = (txt << 8) | (bg << 12);
        vga_state.current_color = color;
    }
}

void reset_screen()
{
    char c = ' ';

    vga_state.line = 0;
    vga_state.column = 0;
    for (uint16_t y = 0; y < HEIGHT; y++)
        for (uint16_t x = 0; x <= WIDTH; x++)
            printc_at(&c, vga_state.default_color, x, y);
}

void scroll_screen()
{
    for (uint16_t y = 0; y < HEIGHT; y++)
        for (uint16_t x = 0; x <= WIDTH ; x++)
            vga_state.vga[y * WIDTH + x] = vga_state.vga[(y + 1) * WIDTH + x];

    for (uint16_t x = 0; x <= WIDTH; x++)
        vga_state.vga[(HEIGHT - 1) * WIDTH + x] = ' ' | vga_state.current_color;
}

void new_line()
{
    if (vga_state.line >= HEIGHT - 1)
        scroll_screen();
    else
        vga_state.line++;
    vga_state.column = 0;
}

void printc_at(const char *c, uint16_t color, const uint16_t x, const uint16_t y)
{
    vga_state.vga[y * WIDTH + x] = *c | color;
}

void printc(const char *c, uint16_t color)
{
    vga_state.vga[vga_state.line * WIDTH + vga_state.column] = *c | color;
}

void prints(const char *s)
{
    while (*s)
    {
        if (vga_state.column >= WIDTH || *s == '\n')
            new_line();
        else
        {
            printc(s, vga_state.current_color);
            vga_state.column++;
        }
        s++;
    }
}
