	.file	"degerlendirme.c"
	.text
	.type	random_array, @function
random_array:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movl	%r8d, -56(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L3:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	$-2147483648, (%rax)
	addl	$1, -20(%rbp)
.L2:
	movl	-20(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L3
	movl	-52(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L4
.L5:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	call	rand
	cltd
	idivl	-44(%rbp)
	movl	%edx, %eax
	movl	%eax, (%rbx)
	addl	$1, -20(%rbp)
.L4:
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	cmpl	-20(%rbp), %eax
	jg	.L5
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	jmp	.L6
.L7:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	$-2147483648, (%rax)
	addl	$1, -20(%rbp)
.L6:
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%eax, %edx
	movl	-56(%rbp), %eax
	addl	%edx, %eax
	cmpl	-20(%rbp), %eax
	jg	.L7
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	random_array, .-random_array
	.type	is_sorted_inc, @function
is_sorted_inc:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$2, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L9
.L12:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L10
	movl	$0, -8(%rbp)
	jmp	.L11
.L10:
	addl	$1, -4(%rbp)
.L9:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	-4(%rbp), %eax
	jg	.L12
.L11:
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	is_sorted_inc, .-is_sorted_inc
	.type	is_sorted_dec, @function
is_sorted_dec:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$1, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L15
.L18:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L16
	movl	$0, -8(%rbp)
	jmp	.L17
.L16:
	addl	$1, -4(%rbp)
.L15:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	-4(%rbp), %eax
	jg	.L18
.L17:
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	is_sorted_dec, .-is_sorted_dec
	.section	.rodata
.LC0:
	.string	"test_stdout.out"
	.data
	.align 8
	.type	test_stdout, @object
	.size	test_stdout, 8
test_stdout:
	.quad	.LC0
	.section	.rodata
.LC1:
	.string	"/dev/pts/1"
	.data
	.align 8
	.type	orig_stdout, @object
	.size	orig_stdout, 8
orig_stdout:
	.quad	.LC1
	.section	.rodata
.LC2:
	.string	"w"
	.text
	.type	disable_stdout, @function
disable_stdout:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	stdout(%rip), %rdx
	movq	test_stdout(%rip), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	freopen
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	disable_stdout, .-disable_stdout
	.section	.rodata
.LC3:
	.string	"a"
	.text
	.type	enable_stdout, @function
enable_stdout:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	stdout(%rip), %rdx
	movq	orig_stdout(%rip), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	freopen
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	enable_stdout, .-enable_stdout
	.section	.rodata
.LC4:
	.string	"r"
	.text
	.type	print_stdout, @function
print_stdout:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	test_stdout(%rip), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L23
.L24:
	addl	$1, -4(%rbp)
	movq	stderr(%rip), %rdx
	movl	-20(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fputc
.L23:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_IO_getc
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	jne	.L24
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	print_stdout, .-print_stdout
	.section	.rodata
	.align 8
.LC5:
	.string	"\tUYARI: Ekrana yazi yazdiniz.\n"
	.align 8
.LC6:
	.string	"\tBu soruda ekrana yazi istenilmiyor!!!\n"
	.text
	.type	no_stdout_warning, @function
no_stdout_warning:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	print_stdout
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L26
	movq	stderr(%rip), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	movl	$.LC5, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$39, %edx
	movl	$1, %esi
	movl	$.LC6, %edi
	call	fwrite
.L26:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	no_stdout_warning, .-no_stdout_warning
	.section	.rodata
.LC7:
	.string	"{ "
.LC8:
	.string	"%d "
.LC9:
	.string	"}\n"
	.text
	.type	print_array, @function
print_array:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC7, %edi
	call	fwrite
	movl	$0, -4(%rbp)
	jmp	.L29
.L30:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC8, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -4(%rbp)
.L29:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L30
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	$.LC9, %edi
	call	fwrite
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	print_array, .-print_array
	.type	degerlendirme_round, @function
degerlendirme_round:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	cvttss2si	-24(%rbp), %eax
	pxor	%xmm0, %xmm0
	cvtsi2ss	%eax, %xmm0
	movss	-20(%rbp), %xmm1
	subss	%xmm0, %xmm1
	movd	%xmm1, %eax
	movl	%eax, -4(%rbp)
	movss	.LC10(%rip), %xmm0
	ucomiss	-4(%rbp), %xmm0
	jbe	.L36
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	cvttss2si	-24(%rbp), %eax
	jmp	.L34
.L36:
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	cvttss2si	-24(%rbp), %eax
	addl	$1, %eax
.L34:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	degerlendirme_round, .-degerlendirme_round
	.section	.rodata
	.align 32
	.type	puanlar_max, @object
	.size	puanlar_max, 32
puanlar_max:
	.long	0
	.long	5
	.long	10
	.long	10
	.long	20
	.long	20
	.long	15
	.long	20
	.local	puanlar
	.comm	puanlar,32,32
	.local	enabled_questions
	.comm	enabled_questions,32,32
	.comm	vars,4,4
	.local	init_test_ok
	.comm	init_test_ok,4,4
	.text
	.type	init_test, @function
init_test:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	init_test_ok(%rip), %eax
	testl	%eax, %eax
	jne	.L38
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
.L38:
	movl	$1, init_test_ok(%rip)
	movl	-4(%rbp), %eax
	cltq
	movl	$1, enabled_questions(,%rax,4)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	init_test, .-init_test
	.section	.rodata
.LC11:
	.string	"NUMARANIZI GIRMEDINIZ\n"
	.align 8
.LC12:
	.string	"TERMINAL NUMARASINI GIRMEDINIZ\n"
.LC13:
	.string	">> ogrenci numarasi: %ld\n"
.LC14:
	.string	">> terminal no: %d\n"
	.text
	.globl	test_ogrenci_bilgileri
	.type	test_ogrenci_bilgileri, @function
test_ogrenci_bilgileri:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	OGRENCI_NO(%rip), %rax
	testq	%rax, %rax
	jne	.L40
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$22, %edx
	movl	$1, %esi
	movl	$.LC11, %edi
	call	fwrite
	movl	$0, %edi
	call	exit
.L40:
	movl	TERM_NO(%rip), %eax
	testl	%eax, %eax
	jne	.L41
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$31, %edx
	movl	$1, %esi
	movl	$.LC12, %edi
	call	fwrite
	movl	$0, %edi
	call	exit
.L41:
	movq	OGRENCI_NO(%rip), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC13, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	TERM_NO(%rip), %edx
	movq	stderr(%rip), %rax
	movl	$.LC14, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	test_ogrenci_bilgileri, .-test_ogrenci_bilgileri
	.section	.rodata
.LC15:
	.string	"----------------------\n"
.LC16:
	.string	">> soru 1 degerlendiriliyor\n"
	.text
	.globl	test_1
	.type	test_1, @function
test_1:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, %edi
	call	init_test
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC16, %edi
	call	fwrite
	movl	$0, %eax
	call	disable_stdout
	movl	$0, %eax
	call	soru_1
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	test_1, .-test_1
	.section	.rodata
.LC17:
	.string	"\tsizin cevabiniz: "
.LC18:
	.string	"\tdogru cevap: "
	.text
	.globl	_test_1
	.type	_test_1, @function
_test_1:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$4, -20(%rbp)
	movl	$5, -16(%rbp)
	leaq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movl	$20, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcmp
	testl	%eax, %eax
	jne	.L44
	movl	$5, %eax
	movl	%eax, puanlar+4(%rip)
	jmp	.L43
.L44:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$1, %esi
	movl	$.LC17, %edi
	call	fwrite
	movq	-40(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	print_array
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$14, %edx
	movl	$1, %esi
	movl	$.LC18, %edi
	call	fwrite
	leaq	-32(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	print_array
.L43:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	_test_1, .-_test_1
	.section	.rodata
.LC19:
	.string	"\tilk yanlis.\n"
.LC20:
	.string	"\tcevabiniz: %d, dogrusu: %d\n\n"
.LC21:
	.string	"\tbastan_ucuncu yanlis.\n"
.LC22:
	.string	"\tson yanlis\n"
.LC23:
	.string	"\tsondan_ikinci yanlis.\n"
.LC25:
	.string	"\tdizi: "
	.text
	.globl	_test_2
	.type	_test_2, @function
_test_2:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	%ecx, -36(%rbp)
	movl	%r8d, -40(%rbp)
	movl	%r9d, -44(%rbp)
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-32(%rbp), %eax
	jne	.L47
	addl	$1, -4(%rbp)
	jmp	.L48
.L47:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$.LC19, %edi
	call	fwrite
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	movq	stderr(%rip), %rax
	movl	-32(%rbp), %edx
	movl	$.LC20, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L48:
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %eax
	cmpl	-36(%rbp), %eax
	jne	.L49
	addl	$1, -4(%rbp)
	jmp	.L50
.L49:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC21, %edi
	call	fwrite
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %ecx
	movq	stderr(%rip), %rax
	movl	-36(%rbp), %edx
	movl	$.LC20, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L50:
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	-40(%rbp), %eax
	jne	.L51
	addl	$1, -4(%rbp)
	jmp	.L52
.L51:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$12, %edx
	movl	$1, %esi
	movl	$.LC22, %edi
	call	fwrite
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	stderr(%rip), %rax
	movl	-40(%rbp), %edx
	movl	$.LC20, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L52:
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-8(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	-44(%rbp), %eax
	jne	.L53
	addl	$1, -4(%rbp)
	jmp	.L54
.L53:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC23, %edi
	call	fwrite
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-8(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movq	stderr(%rip), %rax
	movl	-44(%rbp), %edx
	movl	$.LC20, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L54:
	pxor	%xmm0, %xmm0
	cvtsi2sd	-4(%rbp), %xmm0
	movsd	.LC24(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	movl	$10, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	call	degerlendirme_round
	movl	%eax, puanlar+8(%rip)
	cmpl	$4, -4(%rbp)
	je	.L46
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$7, %edx
	movl	$1, %esi
	movl	$.LC25, %edi
	call	fwrite
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	print_array
.L46:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_test_2, .-_test_2
	.section	.rodata
.LC26:
	.string	">> soru 2 degerlendiriliyor\n"
	.text
	.globl	test_2
	.type	test_2, @function
test_2:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	$2, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC26, %edi
	call	fwrite
	leaq	-128(%rbp), %rax
	movl	$10, %r8d
	movl	$10, %ecx
	movl	$10, %edx
	movl	$100, %esi
	movq	%rax, %rdi
	call	random_array
	leaq	-128(%rbp), %rax
	addq	$40, %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	soru_2
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	test_2, .-test_2
	.section	.rodata
.LC27:
	.string	"\tbeklenen cevap: %d\n"
.LC28:
	.string	"\tsizin cevabiniz: %d\n"
	.text
	.globl	_test_3
	.type	_test_3, @function
_test_3:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4032, %rsp
	movl	%edi, -4020(%rbp)
	movl	%esi, -4024(%rbp)
	movl	%edx, -4028(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$0, -4020(%rbp)
	je	.L58
	movl	-4028(%rbp), %esi
	movl	-4028(%rbp), %ecx
	movl	-4024(%rbp), %edx
	leaq	-4016(%rbp), %rax
	movl	%esi, %r8d
	movl	$10, %esi
	movq	%rax, %rdi
	call	random_array
	jmp	.L59
.L58:
	movl	-4028(%rbp), %esi
	movl	-4028(%rbp), %ecx
	movl	-4024(%rbp), %edx
	leaq	-4016(%rbp), %rax
	movl	%esi, %r8d
	movl	$1000, %esi
	movq	%rax, %rdi
	call	random_array
.L59:
	movl	$0, -12(%rbp)
	movl	-4028(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L60
.L61:
	movl	-8(%rbp), %eax
	cltq
	movl	-4016(%rbp,%rax,4), %eax
	addl	%eax, -12(%rbp)
	addl	$1, -8(%rbp)
.L60:
	movl	-4028(%rbp), %edx
	movl	-4024(%rbp), %eax
	addl	%edx, %eax
	cmpl	-8(%rbp), %eax
	jg	.L61
	leaq	-4016(%rbp), %rax
	movl	-4028(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4024(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	soru_3
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L62
	movl	$100, -4(%rbp)
	jmp	.L63
.L62:
	cmpl	$0, -4020(%rbp)
	je	.L63
	movq	stderr(%rip), %rax
	movq	%rax, %rsi
	movl	$9, %edi
	call	fputc
	leaq	-4016(%rbp), %rax
	movl	-4028(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4024(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	print_array
	movq	stderr(%rip), %rax
	movl	-12(%rbp), %edx
	movl	$.LC27, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	stderr(%rip), %rax
	movl	-16(%rbp), %edx
	movl	$.LC28, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L63:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	_test_3, .-_test_3
	.section	.rodata
.LC29:
	.string	">> soru 3 degerlendiriliyor\n"
	.align 8
.LC30:
	.string	"\tfarkli degerlerde yanlis sonuc uretiyor\n"
.LC31:
	.string	"\tkodu gozden gecirin\n"
	.text
	.globl	test_3
	.type	test_3, @function
test_3:
.LFB19:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$3, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC29, %edi
	call	fwrite
	movl	$5, %edx
	movl	$5, %esi
	movl	$1, %edi
	call	_test_3
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	movl	$0, %eax
	call	disable_stdout
	movl	$100, %edx
	movl	$200, %esi
	movl	$0, %edi
	call	_test_3
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L66
.L68:
	movl	$25, %edx
	movl	$50, %esi
	movl	$0, %edi
	call	_test_3
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L67
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$41, %edx
	movl	$1, %esi
	movl	$.LC30, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	movl	$.LC31, %edi
	call	fwrite
.L67:
	addl	$1, -4(%rbp)
.L66:
	cmpl	$4, -4(%rbp)
	jle	.L68
	movl	$10, %eax
	imull	-8(%rbp), %eax
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, puanlar+12(%rip)
	movl	$0, %eax
	call	enable_stdout
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	test_3, .-test_3
	.section	.rodata
	.align 8
.LC32:
	.string	"\thazir fonksiyon kullanmadan yaziniz\n"
.LC33:
	.string	"\tters siraladiniz\n"
	.text
	.globl	_test_4
	.type	_test_4, @function
_test_4:
.LFB20:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4032, %rsp
	movl	%edi, -4020(%rbp)
	movl	%esi, -4024(%rbp)
	movl	%edx, -4028(%rbp)
	cmpl	$0, -4020(%rbp)
	je	.L70
	movl	-4028(%rbp), %esi
	movl	-4028(%rbp), %ecx
	movl	-4024(%rbp), %edx
	leaq	-4016(%rbp), %rax
	movl	%esi, %r8d
	movl	$10, %esi
	movq	%rax, %rdi
	call	random_array
	jmp	.L71
.L70:
	movl	-4028(%rbp), %esi
	movl	-4028(%rbp), %ecx
	movl	-4024(%rbp), %edx
	leaq	-4016(%rbp), %rax
	movl	%esi, %r8d
	movl	$1000, %esi
	movq	%rax, %rdi
	call	random_array
.L71:
	leaq	-4016(%rbp), %rax
	movl	-4028(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4024(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	soru_4
	movl	$0, -4(%rbp)
	movl	$0, vars(%rip)
	movl	vars(%rip), %eax
	testl	%eax, %eax
	je	.L72
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$37, %edx
	movl	$1, %esi
	movl	$.LC32, %edi
	call	fwrite
	jmp	.L73
.L72:
	leaq	-4016(%rbp), %rax
	movl	-4028(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4024(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	is_sorted_inc
	testl	%eax, %eax
	je	.L74
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$1, %esi
	movl	$.LC33, %edi
	call	fwrite
	movl	$30, -4(%rbp)
	jmp	.L73
.L74:
	leaq	-4016(%rbp), %rax
	movl	-4028(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4024(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	is_sorted_dec
	testl	%eax, %eax
	je	.L73
	movl	$100, -4(%rbp)
.L73:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	_test_4, .-_test_4
	.section	.rodata
.LC34:
	.string	">> soru 4 degerlendiriliyor\n"
	.text
	.globl	test_4
	.type	test_4, @function
test_4:
.LFB21:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$4, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC34, %edi
	call	fwrite
	movl	$10, %edx
	movl	$10, %esi
	movl	$1, %edi
	call	_test_4
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	movl	$100, %edx
	movl	$200, %esi
	movl	$0, %edi
	call	_test_4
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L77
.L79:
	movl	$25, %edx
	movl	$50, %esi
	movl	$0, %edi
	call	_test_4
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L78
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$41, %edx
	movl	$1, %esi
	movl	$.LC30, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	movl	$.LC31, %edi
	call	fwrite
.L78:
	addl	$1, -4(%rbp)
.L77:
	cmpl	$4, -4(%rbp)
	jle	.L79
	movl	$20, %eax
	imull	-8(%rbp), %eax
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, puanlar+16(%rip)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	test_4, .-test_4
	.globl	sirala_s5
	.type	sirala_s5, @function
sirala_s5:
.LFB22:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	vars(%rip), %eax
	addl	$1, %eax
	movl	%eax, vars(%rip)
	movl	$1, -4(%rbp)
	jmp	.L81
.L85:
	movl	$0, -8(%rbp)
	jmp	.L82
.L84:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L83
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, (%rdx)
.L83:
	addl	$1, -8(%rbp)
.L82:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	-8(%rbp), %eax
	jg	.L84
	addl	$1, -4(%rbp)
.L81:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L85
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	sirala_s5, .-sirala_s5
	.section	.rodata
.LC35:
	.string	">> soru 5 degerlendiriliyor\n"
	.align 8
.LC36:
	.string	"\tverilen siralama fonksiyonunu kullanmadiniz\n"
	.align 8
.LC37:
	.string	"\tsoruyu dikkatlice okuyup tekrar deneyin\n"
.LC38:
	.string	"\tsiralama yanlis\n"
	.align 8
.LC39:
	.string	"\tsirala_s5 fonksiyonunu 1 kere kullaniniz. %d kere kullandiniz\n"
	.align 8
.LC40:
	.string	"\tsiralama dogru fakat sonuc yanlis\n"
.LC41:
	.string	"\tbeklenen: %d, cevap: %d\n"
	.text
	.globl	test_5
	.type	test_5, @function
test_5:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$512, %rsp
	movl	$5, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC35, %edi
	call	fwrite
	leaq	-272(%rbp), %rax
	movl	$20, %r8d
	movl	$20, %ecx
	movl	$20, %edx
	movl	$100, %esi
	movq	%rax, %rdi
	call	random_array
	leaq	-512(%rbp), %rax
	leaq	-272(%rbp), %rdx
	movl	$30, %ecx
	movq	%rax, %rdi
	movq	%rdx, %rsi
	rep movsq
	leaq	-512(%rbp), %rax
	addq	$80, %rax
	movl	$20, %esi
	movq	%rax, %rdi
	call	sirala_s5
	movl	$0, -8(%rbp)
	movl	$20, -4(%rbp)
	jmp	.L87
.L88:
	movl	-4(%rbp), %eax
	cltq
	movl	-512(%rbp,%rax,4), %eax
	addl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L87:
	cmpl	$24, -4(%rbp)
	jle	.L88
	movl	$0, vars(%rip)
	leaq	-272(%rbp), %rax
	addq	$80, %rax
	movl	$20, %esi
	movq	%rax, %rdi
	call	soru_5
	movl	%eax, -16(%rbp)
	leaq	-512(%rbp), %rcx
	leaq	-272(%rbp), %rax
	movl	$240, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcmp
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-8(%rbp), %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -24(%rbp)
	movl	$0, -12(%rbp)
	movl	vars(%rip), %eax
	testl	%eax, %eax
	jne	.L89
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$45, %edx
	movl	$1, %esi
	movl	$.LC36, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$41, %edx
	movl	$1, %esi
	movl	$.LC37, %edi
	call	fwrite
	jmp	.L90
.L89:
	cmpl	$0, -20(%rbp)
	jne	.L91
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$17, %edx
	movl	$1, %esi
	movl	$.LC38, %edi
	call	fwrite
	jmp	.L90
.L91:
	movl	vars(%rip), %eax
	cmpl	$1, %eax
	je	.L92
	movl	vars(%rip), %edx
	movq	stderr(%rip), %rax
	movl	$.LC39, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L90
.L92:
	addl	$50, -12(%rbp)
	cmpl	$0, -24(%rbp)
	je	.L93
	addl	$50, -12(%rbp)
	jmp	.L90
.L93:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$35, %edx
	movl	$1, %esi
	movl	$.LC40, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movl	-16(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	$.LC41, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L90:
	movl	$20, %eax
	imull	-12(%rbp), %eax
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, puanlar+20(%rip)
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE23:
	.size	test_5, .-test_5
	.section	.rodata
.LC42:
	.string	">> soru 6 degerlendiriliyor\n"
	.text
	.globl	test_6
	.type	test_6, @function
test_6:
.LFB24:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$864, %rsp
	movl	$6, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC42, %edi
	call	fwrite
	leaq	-864(%rbp), %rax
	addq	$200, %rax
	movq	%rax, -32(%rbp)
	movl	$100, -36(%rbp)
	movl	$50, -40(%rbp)
	movl	-40(%rbp), %esi
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %edx
	leaq	-864(%rbp), %rax
	movl	%esi, %r8d
	movl	$100, %esi
	movq	%rax, %rdi
	call	random_array
	movq	-32(%rbp), %rax
	movl	120(%rax), %eax
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %edx
	movl	-36(%rbp), %ecx
	movq	-32(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	soru_6
	movl	%eax, -48(%rbp)
	call	rand
	movl	%eax, %ecx
	movl	$274877907, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$6, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$1000, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	addl	$100, %eax
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %edx
	movl	-36(%rbp), %ecx
	movq	-32(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	soru_6
	movl	%eax, -56(%rbp)
	movl	$0, -60(%rbp)
	movl	-60(%rbp), %edx
	movl	-36(%rbp), %ecx
	movq	-32(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	soru_6
	movl	%eax, -64(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -16(%rbp)
	jmp	.L95
.L99:
	movl	-16(%rbp), %eax
	cltq
	movl	-864(%rbp,%rax,4), %eax
	cmpl	-44(%rbp), %eax
	jne	.L96
	addl	$1, -4(%rbp)
.L96:
	movl	-16(%rbp), %eax
	cltq
	movl	-864(%rbp,%rax,4), %eax
	cmpl	-52(%rbp), %eax
	jne	.L97
	addl	$1, -8(%rbp)
.L97:
	movl	-16(%rbp), %eax
	cltq
	movl	-864(%rbp,%rax,4), %eax
	cmpl	-60(%rbp), %eax
	jne	.L98
	addl	$1, -12(%rbp)
.L98:
	addl	$1, -16(%rbp)
.L95:
	movl	-36(%rbp), %edx
	movl	-40(%rbp), %eax
	addl	%edx, %eax
	cmpl	-16(%rbp), %eax
	jg	.L99
	movl	$0, -20(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jne	.L100
	movl	-8(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jne	.L100
	movl	-12(%rbp), %eax
	cmpl	-64(%rbp), %eax
	jne	.L100
	movl	$100, -20(%rbp)
.L100:
	movl	$15, %eax
	imull	-20(%rbp), %eax
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, puanlar+24(%rip)
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE24:
	.size	test_6, .-test_6
	.globl	_test_7
	.type	_test_7, @function
_test_7:
.LFB25:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	%ecx, -52(%rbp)
	movl	$-1, -12(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L102
.L107:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -32(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L103
.L105:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	-32(%rbp), %eax
	jne	.L104
	addl	$1, -20(%rbp)
.L104:
	addl	$1, -8(%rbp)
.L103:
	movl	-8(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L105
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jle	.L106
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -12(%rbp)
.L106:
	addl	$1, -4(%rbp)
.L102:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L107
	movl	$0, -24(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jne	.L108
	movl	-48(%rbp), %eax
	cmpl	-12(%rbp), %eax
	je	.L108
	movl	$0, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L109
.L111:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	-48(%rbp), %eax
	jne	.L110
	addl	$1, -28(%rbp)
.L110:
	addl	$1, -4(%rbp)
.L109:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L111
	movl	-28(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L112
	movl	$100, -24(%rbp)
	jmp	.L113
.L112:
	jmp	.L113
.L108:
	movl	-48(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	.L113
	movl	-52(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L113
	movl	$100, -24(%rbp)
.L113:
	movl	$20, %eax
	imull	-24(%rbp), %eax
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, puanlar+28(%rip)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE25:
	.size	_test_7, .-_test_7
	.section	.rodata
.LC43:
	.string	">> soru 7 degerlendiriliyor\n"
	.text
	.globl	test_7
	.type	test_7, @function
test_7:
.LFB26:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$400, %rsp
	movl	$7, %edi
	call	init_test
	movl	$0, %eax
	call	disable_stdout
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$28, %edx
	movl	$1, %esi
	movl	$.LC43, %edi
	call	fwrite
	leaq	-400(%rbp), %rax
	movl	$25, %r8d
	movl	$25, %ecx
	movl	$50, %edx
	movl	$100, %esi
	movq	%rax, %rdi
	call	random_array
	leaq	-400(%rbp), %rax
	addq	$100, %rax
	movl	$50, %esi
	movq	%rax, %rdi
	call	soru_7
	movl	$0, %eax
	call	enable_stdout
	movl	$0, %eax
	call	no_stdout_warning
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	test_7, .-test_7
	.section	.rodata
.LC44:
	.string	">> sonuc:\n"
.LC45:
	.string	"soru %d: %d/%d\n"
.LC46:
	.string	"soru %d: disabled\n"
.LC47:
	.string	">> toplam: %d/%d\n\n"
	.text
	.globl	sonuc
	.type	sonuc, @function
sonuc:
.LFB27:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$10, %edx
	movl	$1, %esi
	movl	$.LC44, %edi
	call	fwrite
	movl	$1, -4(%rbp)
	jmp	.L116
.L119:
	movl	-4(%rbp), %eax
	cltq
	movl	enabled_questions(,%rax,4), %eax
	testl	%eax, %eax
	je	.L117
	movl	-4(%rbp), %eax
	cltq
	movl	puanlar_max(,%rax,4), %esi
	movl	-4(%rbp), %eax
	cltq
	movl	puanlar(,%rax,4), %ecx
	movq	stderr(%rip), %rax
	movl	-4(%rbp), %edx
	movl	%esi, %r8d
	movl	$.LC45, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L118
.L117:
	movq	stderr(%rip), %rax
	movl	-4(%rbp), %edx
	movl	$.LC46, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L118:
	addl	$1, -4(%rbp)
.L116:
	movl	-4(%rbp), %eax
	cmpl	$7, %eax
	jbe	.L119
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L120
.L121:
	movl	-4(%rbp), %eax
	cltq
	movl	puanlar(,%rax,4), %eax
	addl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L120:
	movl	-4(%rbp), %eax
	cmpl	$7, %eax
	jbe	.L121
	movl	$0, -12(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L122
.L124:
	movl	-4(%rbp), %eax
	cltq
	movl	enabled_questions(,%rax,4), %eax
	testl	%eax, %eax
	je	.L123
	movl	-4(%rbp), %eax
	cltq
	movl	puanlar_max(,%rax,4), %eax
	addl	%eax, -12(%rbp)
.L123:
	addl	$1, -4(%rbp)
.L122:
	movl	-4(%rbp), %eax
	cmpl	$7, %eax
	jbe	.L124
	movq	stderr(%rip), %rax
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	$.LC47, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE27:
	.size	sonuc, .-sonuc
	.section	.rodata
	.align 8
.LC48:
	.string	">> Program calisma aninda olusan bir hatadan dolayi sonlandi\n"
	.align 8
.LC49:
	.string	"\tsorulardan bazilarini devre disi birakarak:\n"
	.align 8
.LC50:
	.string	"\t - hatanin yerini tespit edebilirsiniz\n"
	.align 8
.LC51:
	.string	"\t - ya da hatayi cozmeden diger sorulari cozebilirsiniz\n"
	.align 8
.LC52:
	.string	"\n>> hatanin kaynagi: signum = %d\n"
.LC53:
	.string	"\tsifira bolme hatasi\n"
.LC54:
	.string	"\tbellek erisimi hatasi:\n"
	.align 8
.LC55:
	.string	"\t- dizi sinirlarinizin disina cikmadiginizdan emin olun\n"
	.align 8
.LC56:
	.string	"\t- pointer tipinde degisken varsa kontrol edin\n"
	.align 8
.LC57:
	.string	"\t- sonsuza giden recursive fonksiyon olmadigindan emin olun\n"
	.align 8
.LC58:
	.string	"\tbu hatayi almamaniz gerekli. kodunuzu gorevliye gosterin\n"
	.align 8
.LC59:
	.string	"\tanimli standart hatalardan biri degil\n"
	.text
	.globl	sighandler
	.type	sighandler, @function
sighandler:
.LFB28:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$61, %edx
	movl	$1, %esi
	movl	$.LC48, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$45, %edx
	movl	$1, %esi
	movl	$.LC49, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$40, %edx
	movl	$1, %esi
	movl	$.LC50, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$56, %edx
	movl	$1, %esi
	movl	$.LC51, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movl	-4(%rbp), %edx
	movl	$.LC52, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	-4(%rbp), %eax
	cmpl	$8, %eax
	je	.L127
	cmpl	$11, %eax
	je	.L128
	cmpl	$4, %eax
	je	.L129
	jmp	.L131
.L127:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	movl	$.LC53, %edi
	call	fwrite
	jmp	.L130
.L128:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$24, %edx
	movl	$1, %esi
	movl	$.LC54, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$56, %edx
	movl	$1, %esi
	movl	$.LC55, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$47, %edx
	movl	$1, %esi
	movl	$.LC56, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$60, %edx
	movl	$1, %esi
	movl	$.LC57, %edi
	call	fwrite
	jmp	.L130
.L129:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$58, %edx
	movl	$1, %esi
	movl	$.LC58, %edi
	call	fwrite
	jmp	.L130
.L131:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$39, %edx
	movl	$1, %esi
	movl	$.LC59, %edi
	call	fwrite
.L130:
	movl	-4(%rbp), %eax
	movl	$0, %esi
	movl	%eax, %edi
	call	signal
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE28:
	.size	sighandler, .-sighandler
	.section	.rodata
	.align 4
.LC10:
	.long	1056964608
	.align 8
.LC24:
	.long	0
	.long	1074790400
	.ident	"GCC: (Debian 4.9.1-19) 4.9.1"
	.section	.note.GNU-stack,"",@progbits
