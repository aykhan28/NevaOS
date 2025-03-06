;; kernel.asm
;; NevaOS Bootloader Entry Point

bits 32
section .text

; Multiboot Header (GRUB ile çalışması için gerekli)
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)

global start
extern k_main

start:
    cli
    call k_main
    hlt