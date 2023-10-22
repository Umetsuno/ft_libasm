# ft_libasm
64 bits ASM basic functions

## ft_strlen.s
---
`section .text`
Declaration which specifies the section of the executable file where the strlen function will be placed. In this case, it specifies the .text section, which is typically used for code and constants.

In NASM syntax, the section directive is used to specify the type of section for the code or data that follows. The .text section is a standard section in most executable file formats, including ELF (Executable and Linkable Format) used in Linux and other Unix-like operating systems.

By placing the strlen function in the .text section, it will be placed in a part of the executable file that is dedicated to code and will be loaded into memory as read-only. This ensures that the code is stored in a secure part of memory and that it cannot be accidentally overwritten or modified by other parts of the program.

## ft_strcpy.s
---
`should we restore registers to their default values ?`  
There is no need to reset all the registers to their default values at the end of this specific function, since the only register that is modified by the function and needs to be set to a specific value is `eax` (which is set to zero to indicate success).

The other registers that are used in the function (`rdi`, `rsi`, `rcx`, and `rdx`) are all considered "caller-saved" registers in the x86-64 System V calling convention, which means that their values are not guaranteed to be preserved across function calls.

`some inputs on the .loop: part`
First, the movzx instruction is used to load a byte from the memory location pointed to by rcx. The byte keyword specifies that only one byte should be loaded, and the movzx instruction clears the upper bits of the rdx register to avoid introducing any sign extension or other unwanted effects.

Next, the mov instruction is used to store the byte value in the memory location pointed to by rax. Since the byte value is already in the rdx register, we can simply move it into the lower 8 bits of the rax register by using mov [rax], dl. This stores the byte at the memory location pointed to by rax, which is the destination buffer for the strcpy function.

## ft_strcmp.s
---
