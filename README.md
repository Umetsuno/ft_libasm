# ft_libasm
64 bits ASM basic functions

## ft_strlen.s
---
`section .text`
Declaration which specifies the section of the executable file where the strlen function will be placed. In this case, it specifies the .text section, which is typically used for code and constants.

In NASM syntax, the section directive is used to specify the type of section for the code or data that follows. The .text section is a standard section in most executable file formats, including ELF (Executable and Linkable Format) used in Linux and other Unix-like operating systems.

By placing the strlen function in the .text section, it will be placed in a part of the executable file that is dedicated to code and will be loaded into memory as read-only. This ensures that the code is stored in a secure part of memory and that it cannot be accidentally overwritten or modified by other parts of the program.
