	.file	"Ever_Ortega_t2.c"
	.text
	.globl	gege
	.bss
	.align 8
	.type	gege, @object
	.size	gege, 8
gege:
	.zero	8
	.globl	len_gege
	.align 4
	.type	len_gege, @object
	.size	len_gege, 4
len_gege:
	.zero	4
	.globl	pos_gege
	.align 4
	.type	pos_gege, @object
	.size	pos_gege, 4
pos_gege:
	.zero	4
	.globl	Len_nom
	.align 4
	.type	Len_nom, @object
	.size	Len_nom, 4
Len_nom:
	.zero	4
	.globl	Len_ap
	.align 4
	.type	Len_ap, @object
	.size	Len_ap, 4
Len_ap:
	.zero	4
	.section	.rodata
	.align 8
.LC0:
	.string	"Se ha procesado por completo la cadena ingresada"
	.text
	.globl	getchar_cad
	.type	getchar_cad, @function
getchar_cad:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	len_gege(%rip), %edx
	movl	pos_gege(%rip), %eax
	cmpl	%eax, %edx
	jg	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	gege(%rip), %rcx
	movl	pos_gege(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, pos_gege(%rip)
	cltq
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getchar_cad, .-getchar_cad
	.section	.rodata
.LC1:
	.string	"Una coma??\n"
	.align 8
.LC2:
	.string	"La cadena se ha terminado mientras se le\303\255a el nombre\n"
	.align 8
.LC3:
	.string	"Se ha alcanzado la longitud m\303\241xima para arr_nom: %d\n"
	.align 8
.LC4:
	.string	"La cadena se ha terminado antes de leer el apellido\n"
	.align 8
.LC5:
	.string	"Se ha ingresado una coma entre el nombre y el apellido\n"
	.align 8
.LC6:
	.string	"Se ha ingresado un salto de l\303\255nea antes de ingresar el apellido\n"
	.align 8
.LC7:
	.string	"No se ha le\303\255do nada en apellido\n"
	.align 8
.LC8:
	.string	"Se ha alcanzado la longitud m\303\241xima para arr_ap: %d\n"
	.align 8
.LC9:
	.string	"Se pretend\303\255a ingresar una tercera cadena para nombre (un nomapellido?)\n"
	.text
	.globl	m_fgets_v2
	.type	m_fgets_v2, @function
m_fgets_v2:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$0, -4(%rbp)
.L5:
	call	getchar_cad
	movl	%eax, -8(%rbp)
	cmpl	$32, -8(%rbp)
	je	.L5
	cmpl	$9, -8(%rbp)
	je	.L5
	cmpl	$10, -8(%rbp)
	je	.L5
	cmpl	$44, -8(%rbp)
	jne	.L7
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$11, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L7:
	cmpl	$-1, -8(%rbp)
	jne	.L9
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$54, %edx
	movl	$1, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L9:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movb	%dl, (%rax)
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jne	.L10
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %eax
	jmp	.L8
.L10:
	call	getchar_cad
	movl	%eax, -8(%rbp)
	cmpl	$10, -8(%rbp)
	je	.L12
	cmpl	$32, -8(%rbp)
	je	.L12
	cmpl	$44, -8(%rbp)
	jne	.L7
	jmp	.L12
.L13:
	call	getchar_cad
	movl	%eax, -8(%rbp)
.L12:
	cmpl	$32, -8(%rbp)
	je	.L13
	cmpl	$9, -8(%rbp)
	je	.L13
	cmpl	$-1, -8(%rbp)
	jne	.L14
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$52, %edx
	movl	$1, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L14:
	cmpl	$44, -8(%rbp)
	jne	.L15
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$55, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L15:
	cmpl	$10, -8(%rbp)
	jne	.L16
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$65, %edx
	movl	$1, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L16:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, Len_nom(%rip)
	movl	$0, -4(%rbp)
.L21:
	cmpl	$-1, -8(%rbp)
	jne	.L17
	cmpl	$0, -4(%rbp)
	jne	.L18
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$33, %edx
	movl	$1, %esi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L8
.L18:
	movl	$0, %eax
	jmp	.L8
.L17:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movb	%dl, (%rax)
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jne	.L19
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %eax
	jmp	.L8
.L19:
	call	getchar_cad
	movl	%eax, -8(%rbp)
	cmpl	$10, -8(%rbp)
	je	.L22
	cmpl	$32, -8(%rbp)
	je	.L22
	cmpl	$9, -8(%rbp)
	je	.L22
	cmpl	$44, -8(%rbp)
	jne	.L21
	jmp	.L22
.L23:
	call	getchar_cad
	movl	%eax, -8(%rbp)
.L22:
	cmpl	$32, -8(%rbp)
	je	.L23
	cmpl	$9, -8(%rbp)
	je	.L23
	cmpl	$44, -8(%rbp)
	je	.L24
	cmpl	$-1, -8(%rbp)
	je	.L24
	cmpl	$10, -8(%rbp)
	jne	.L25
.L24:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, Len_ap(%rip)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movl	$0, %eax
	jmp	.L8
.L25:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$72, %edx
	movl	$1, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	m_fgets_v2, .-m_fgets_v2
	.section	.rodata
.LC10:
	.string	"malloc"
.LC11:
	.string	"'nodo' no  est\303\241 vac\303\255o?\n"
	.text
	.globl	push
	.type	push, @function
push:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L27
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L28
.L27:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L29
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L28
.L29:
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movl	$0, %eax
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	push, .-push
	.globl	borrar_lista
	.type	borrar_lista, @function
borrar_lista:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L31
.L32:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
.L31:
	cmpq	$0, -8(%rbp)
	jne	.L32
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	borrar_lista, .-borrar_lista
	.section	.rodata
	.align 8
.LC12:
	.string	"Ingrese los nombres, ingrese algo que no siga el formato para finalizar (ingresar s\303\263lo 'Nombre 'Apellido', )"
.LC13:
	.string	"Cadena le\303\255da: %s\n"
	.align 8
.LC14:
	.string	"<<< Error, no se ha le\303\255do ning\303\272n nombre completo\n"
	.text
	.globl	leer_nombres
	.type	leer_nombres, @function
leer_nombres:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$352, %rsp
	movq	%rdi, -344(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	$0, -320(%rbp)
	movq	$0, -312(%rbp)
	movl	$0, -332(%rbp)
	movq	$0, -304(%rbp)
	movq	$0, -296(%rbp)
	movq	$0, -288(%rbp)
	leaq	-304(%rbp), %rax
	movq	%rax, -328(%rbp)
	movq	stdin(%rip), %rdx
	leaq	-208(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	leaq	-208(%rbp), %rax
	movq	%rax, gege(%rip)
	movq	gege(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-208(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	addl	$1, %eax
	movl	%eax, len_gege(%rip)
	movl	len_gege(%rip), %eax
	cmpl	$1, %eax
	jg	.L36
	movl	$1, %eax
	jmp	.L41
.L39:
	addl	$1, -332(%rbp)
	movl	Len_nom(%rip), %eax
	cltq
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -320(%rbp)
	cmpq	$0, -320(%rbp)
	jne	.L37
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$224, %edi
	call	exit@PLT
.L37:
	movl	Len_ap(%rip), %eax
	cltq
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -312(%rbp)
	cmpq	$0, -312(%rbp)
	jne	.L38
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$224, %edi
	call	exit@PLT
.L38:
	movl	Len_nom(%rip), %eax
	cltq
	movq	-320(%rbp), %rcx
	leaq	-272(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	memcpy@PLT
	movl	Len_ap(%rip), %eax
	cltq
	movq	-312(%rbp), %rcx
	leaq	-240(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	memcpy@PLT
	movq	-328(%rbp), %rdx
	movq	-312(%rbp), %rcx
	movq	-320(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	push
	movq	-328(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -328(%rbp)
.L36:
	leaq	-240(%rbp), %rcx
	leaq	-272(%rbp), %rax
	movl	$25, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	m_fgets_v2
	testl	%eax, %eax
	je	.L39
	cmpl	$0, -332(%rbp)
	jne	.L40
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$51, %edx
	movl	$1, %esi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L41
.L40:
	movq	-288(%rbp), %rdx
	movq	-344(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, %eax
.L41:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L42
	call	__stack_chk_fail@PLT
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	leer_nombres, .-leer_nombres
	.section	.rodata
.LC15:
	.string	"Todos los nombres:\n"
.LC16:
	.string	"%2d) %s, %s\n"
	.text
	.globl	mostrar_nombres_y_borrar_lista
	.type	mostrar_nombres_y_borrar_lista, @function
mostrar_nombres_y_borrar_lista:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, -12(%rbp)
	jmp	.L44
.L45:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -12(%rbp)
.L44:
	cmpq	$0, -8(%rbp)
	jne	.L45
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	mostrar_nombres_y_borrar_lista, .-mostrar_nombres_y_borrar_lista
	.section	.rodata
	.align 8
.LC17:
	.string	"<<< Error, no se pueden imprimir los nombres debido a que leer_nombres retorn\303\263 un error\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	leer_nombres
	cmpl	$1, %eax
	jne	.L48
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$89, %edx
	movl	$1, %esi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %eax
	jmp	.L50
.L48:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	mostrar_nombres_y_borrar_lista
	movl	$0, %eax
.L50:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L51
	call	__stack_chk_fail@PLT
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-4ubuntu3) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
