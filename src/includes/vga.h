#ifndef __VGA_H__
#define __VGA_H__

#include "stdint.h"

#define WIDTH       80
#define HEIGHT      25

#define BLACK       0
#define BLUE        3
#define RED         4
#define GREEN       10
#define WHITE       15

#define DFT_BG_COLOR BLACK
#define DFT_TXT_COLOR WHITE

void printc(const char *c, const uint16_t color);
void printc_at(const char *c, const uint16_t color, const uint16_t x, const uint16_t y);
void prints(const char *s);
void reset_screen(void);
void new_line(void);
void scroll_screen(void);
void change_colors(const uint16_t txt, const uint16_t bg);

typedef struct vga_s {
    uint16_t column;
    uint16_t line;
    uint16_t *vga;
    uint16_t default_color;
    uint16_t current_color;
} vga_t;

#endif
