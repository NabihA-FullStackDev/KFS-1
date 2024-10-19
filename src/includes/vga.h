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
void prints(const char *s);
void reset_screen(void);
void new_line(void);
void scroll_screen(void);

#endif
