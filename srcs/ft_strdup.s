section .text
global ft_strdup
extern malloc
extern strcpy

ft_strdup:
    ; Save registers
    push rdi
    push rsi
    push rdx

    ; Calculate the length of the string
    mov rdi, [rsp + 24]  ; Load the string pointer
    xor rax, rax         ; Clear rax to 0, this will hold the length
    jmp check_end        ; Jump to the check_end label

count:
    inc rax              ; Increment the length
check_end:
    cmp byte [rdi + rax], 0  ; Compare the current character with null
    jne count            ; If it's not null, jump back to count

    ; Allocate memory for the new string
    inc rax              ; Add 1 to the length for the null terminator
    mov rdi, rax         ; Move the length to rdi
    call malloc          ; Call malloc
    mov rsi, rax         ; Save the pointer to the new string

    ; Copy the string
    pop rdx              ; Restore the string pointer
    mov rdi, rax         ; Move the new string pointer to rdi
    call strcpy          ; Call strcpy

    ; Restore registers and return
    pop rdx
    pop rsi
    pop rdi
    ret