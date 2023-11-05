global ft_strcpy

ft_strcpy:
	test	rsi, rsi			; Check if source string (rsi) is null
	je		.end
	mov		rax, rdi			; Copy rdi (destination string pointer) to rax (return value)
.loop:		
	mov		dl, byte [rsi]		; Copy byte from source string to destination string
	mov		byte [rdi], dl
	cmp		byte [rsi], 0		; Check the end of the source string
	je		.end
	inc		rsi					; Increment source and destination string pointers
	inc		rdi
	jmp		.loop

.end:		
	ret