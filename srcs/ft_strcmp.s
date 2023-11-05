global ft_strcmp
extern __errno_location

ft_strcmp:
.loop:
	movzx	r8, byte [rdi]			; Load characters from both strings into r8 and r9
	movzx	r9, byte [rsi]
	cmp		r8, r9
	jne		.end
	cmp		byte [rdi], 0			; Check if we've reached the end of either string
	je		.end
	cmp		byte [rsi], 0
	je		.end
	add		rdi, 1
	add		rsi, 1
	jmp		.loop

.end:		
	mov		rax, r8					; Subtract the last two characters compared and return
	sub		rax, r9
	ret