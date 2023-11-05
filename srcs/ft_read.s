section .text
global ft_read
extern __errno_location

ft_read:
	mov	rax, 0				; syscall read
	syscall
	jc	.error
	ret

.error:	
    neg rax
    mov rdi, rax
	push rdi
	call __errno_location
	pop rdi
	mov [rax], rdi
	mov rax, -1
	ret