section .text
global ft_strcpy

ft_strcpy:
    mov rax, rdi                    ; Copy the destination pointer to rax
    mov rcx, rsi                    ; Copy the source pointer to rcx
    cmp rax, rcx                    ; Check if the pointers are equal (self-copy)
    je .done
    test rcx, rcx                   ; Check if the source pointer is null
    je .set_errno_einval

.loop:
    movzx rdx, byte [rcx]           ; Load a byte from [rcx] with zero-extension (rdx = *src)
    mov [rax], dl                   ; Store the byte in [rax] (*dest = *src)
    test dl, dl                     ; Check if the byte is null
    je .done
    inc rcx                         ; src++
    inc rax                         ; dest++
    jmp .loop

.set_errno_einval:
    mov eax, 22                     ; errno = EINVAL
    jmp .set_errno

.set_errno:
    mov rdi, [rel errno_location]   ; Set errno using the errno_location external symbol (rdi = &errno)
    mov dword [rdi], eax            ; Set errno to eax, previously set to EINVAL

.done:
    xor eax, eax                    ; return dest
    ret