BITS 32
align 4

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
