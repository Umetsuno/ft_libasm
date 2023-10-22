section .text
global ft_write
extern __errno_location

; this implementation asumes that the arguments are already provided
; rdi is the file descriptor in argv[0]
; rsi is the string to write in argv[1]
; rdx is the length of the string in argv[2]

ft_write:
    mov rax, 1                  ; syscall number for write
    syscall
    cmp rax, -1                 ; check for error by comparing the return value with -1
    jns no_error                ; if the return value is not negative, there was no error

    call __errno_location       ; call the __errno_location function to get the address of the errno variable
    mov rax, rdi                ; move the file descriptor to rax

    ; mov rax, -1                 ; set the return value to -1
    ret

no_error:
    ret
