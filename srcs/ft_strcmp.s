section .text
global strcmp

strcmp:
    push rbp                 ; save the base pointer
    mov rbp, rsp             ; set up the new base pointer

    ; load the arguments into registers
    mov rdi, rdi             ; first argument (string1)
    mov rsi, rsi             ; second argument (string2)

    cmp rdi, rsi             ; compare the addresses of the strings
    je .end                  ; if they're equal, the strings are equal

.loop:
    mov al, [rdi]            ; load a byte from string1
    mov bl, [rsi]            ; load a byte from string2
    cmp al, bl               ; compare the bytes
    jne .done                ; if they're not equal, we're done
    cmp al, 0                ; check if we've reached the end of string1
    je .end                  ; if so, the strings are equal
    add rdi, 1               ; advance the pointers
    add rsi, 1
    jmp .loop                ; loop back to compare the next bytes

.done:
    xor eax, eax             ; return 0 if the strings are equal
    cmp al, bl               ; set the zero flag based on the last comparison
    jz .end

    ; determine the sign of the result and set errno if needed
    sub al, bl
    jge .set_errno
    mov eax, -1

.end:
    pop rbp                  ; restore the base pointer
    ret

.set_errno:
    mov rax, 0               ; __error or errno_location
    mov rdi, 22              ; EINVAL
    call [rax]               ; set errno
    mov eax, -1              ; return -1
    jmp .end