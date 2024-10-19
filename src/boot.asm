; Mode 32 bits et alignement sur 4 octets
BITS 32
align 4

; Multiboot header pour GRUB avec identifiant, flags et checksum
section .text
multiboot_header:
    dd 0x1BADB002
    dd 0x0
    dd -(0x1BADB002 + 0x0)

; Point d'entrée global, kernel_main est défini ailleurs
global start
extern kernel_main

; Désactive les interruptions, initialise la pile, et appelle kernel_main
start:
    CLI
    MOV esp, kernel_stack
    CALL kernel_main
    HLT

; Boucle d'arrêt pour stopper le processeur
Halt:
    CLI
    HLT
    JMP Halt

; Section BSS : réserve 8 Ko pour la pile du kernel
section .bss
RESB 8192
kernel_stack:
