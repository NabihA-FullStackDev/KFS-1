/*
** Le fichier de linkage permet principalement
** l'organisation la mémoire.
*/

OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS
 {
    .text   : {*(.text)}
    .rodata : {*(.rodata)}
    .data   : {*(.data)}
    .bss    : {*(.bss)}
 }
