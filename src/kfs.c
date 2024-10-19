#include "includes/vga.h"

void kernel_main(void) {
    reset_screen();
    change_colors(15, 0);
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
    change_colors(10, 0);
    prints("42$> ");
}