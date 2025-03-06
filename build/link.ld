/* Linker script for NevaOS */

ENTRY(start)

SECTIONS {
    /* 1. Text Section (Code) */
    . = 0x100000;

    .text : {
        *(.text)
    }

    /* 2. Data Section */
    .data : {
        *(.data)
    }

    /* 3. BSS Section (Uninitialized Data) */
    .bss : {
        *(.bss)
        *(COMMON)
    }

    /* 4. Stack */
    .stack : {
        . = . + 0x1000; /* 4KB Stack */
    }
}