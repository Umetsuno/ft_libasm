section .text
global ft_read
extern __errno_location

; this implementation asumes that the arguments are already provided
; rdi is the file descriptor
; rsi points to the buffer
; rdx is the counter of bytes to read

ft_read:
    mov rax, 0          ; system call number for read
    syscall
    cmp rax, -1         ; check for error by comparing the return value with -1
    jns no_error        ; if the return value is not negative, there was no error

    call __errno_location
    mov [rax], edi      ; store the error code in errno
    ret

no_error:
    ret
