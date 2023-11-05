global ft_strdup
extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	call	ft_strlen				; Get the length of the source string
	push	rdi						; Save the source string pointer (rdi) on the stack
	mov		rdi, rax
	call	malloc					; Allocate memory for the new string
	jc		.error					; Handle malloc error
	mov		rdi, rax				; Copy the source string
	pop		rsi
	call	ft_strcpy
	ret								; Pointer to the new string

.error:								; Set errno and return -1
	mov		rdi, rax
	push	rdi
	call	__errno_location
	pop		rdi
	mov		[rax], rdi
	mov		rax, -1
	ret