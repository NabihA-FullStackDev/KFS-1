#ifndef __VGA_H__
#define __VGA_H__

#include "stdint.h"

#define BG_COLOR    0
#define TXT_COLOR   10

#define WIDTH       80
#define HEIGHT      25

void print(const char *s);
void resetScreen(void);

#endif
