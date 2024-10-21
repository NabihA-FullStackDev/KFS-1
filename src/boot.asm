BITS 32
align 4

; Ajout demander par le linker
; pour le moment ceci n'est qu'un warning
; mais pourra engendrer des probleme de compatibilite.
section .note.GNU-stack noalloc noexec nowrite progbits

section .text
multiboot_header:
    DD 0x1BADB002
    DD 0x0
    DD -(0x1BADB002 + 0x0)

global start
extern kernel_main

start:
    CLI
    MOV esp, kernel_stack
    CALL kernel_main
    HLT

Halt:
    CLI
    HLT
    JMP Halt

section .bss
RESB 8192
kernel_stack:
