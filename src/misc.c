#include "includes/vga.h"


void fortytwo_header()
{
    reset_screen();
    prints("\n");
    prints("                                :::       ::::::::                               ");
    prints("                              :+:       :+:    :+:                               ");
    prints("                            +:+ +:+          +:+                                 ");
    prints("                          +#+  +:+         +#+                                   ");
    prints("                        +#+#+#+#+#+      +#+                                     ");
    prints("                              #+#       #+#                                      ");
    prints("                             ###      ##########                                 ");
    prints("\n");
    prints("\n");
}

void prompt(const char *s)
{
    prints(s);
    prints(" $> ");
}