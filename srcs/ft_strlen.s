section .text
global ft_strlen

ft_strlen:
    ; Set up the function
    push rbp
    mov rbp, rsp
    xor rax, rax

.loop:
    movzx rdx, byte [rdi+rax]       ; Load the current character into rdx
    test rdx, rdx                   ; If the current character is 0, we've reached the end of the string
    jz .end
    inc rax                         ; loop otherwise
    jmp .loop

.end:
    pop rbp
    ret