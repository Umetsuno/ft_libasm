section .text
global strlen

strlen:
    mov rax, 0              ; Initialize the counter to 0
    cmp byte [rdi], 0       ; Check if the first byte us null
    je .done                ; If true, return 0

.loop:
    inc rax                 ; Increment the counter
    cmp byte [rdi+rax], 0   ; Check if the next byte is null terminator
    jne .loop               ; If not, keep looping

.done:
    ret
