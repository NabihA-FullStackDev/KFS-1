OUTPUT_FORMAT(elf32-i386)

ENTRY(start)

/*
** Ici nous allons
** Positionner le kernel a l'adresse 0x100000 (souvent utiliser par les bootloader: GRUB)
** Placer le code dans la section .text
** Placer les données modifiables .data
** Placer la zone non initialisée .bss (Block Started by Symbol)
*/

SECTIONS
 {
    . = 0x100000;
    .text : {*(.text)}
    .data : {*(.data)}
    .bss  : {*(.bss)}
 }
