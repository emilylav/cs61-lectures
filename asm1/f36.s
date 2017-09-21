	.text
	.file	"f36.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	pushq	%r14
.Ltmp0:
	pushq	%rbx
.Ltmp1:
	subq	$24, %rsp
.Ltmp2:
.Ltmp3:
.Ltmp4:
	movq	%rsi, %r14
	movl	%edi, %ebx
	movl	$.Lstr, %edi
	callq	puts
	movl	$.Lstr.5, %edi
	callq	puts
	movl	$.Lstr.6, %edi
	callq	puts
	leal	1(%rbx), %edx
	leal	2(%rbx), %ecx
	leal	3(%rbx), %r8d
	leal	4(%rbx), %r9d
	leal	5(%rbx), %eax
	leal	6(%rbx), %esi
	leal	7(%rbx), %edi
	movl	%edi, 16(%rsp)
	movl	%esi, 8(%rsp)
	movl	%eax, (%rsp)
	movl	$.L.str.3, %edi
	xorl	%eax, %eax
	movl	%ebx, %esi
	callq	printf
	movl	%eax, %ecx
	movl	$.L.str.4, %edi
	xorl	%eax, %eax
	movq	%r14, %rsi
	movl	%ecx, %edx
	addq	$24, %rsp
	popq	%rbx
	popq	%r14
	jmp	printf                  # TAILCALL
.Lfunc_end0:
	.size	f, .Lfunc_end0-f

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	pushq	%rax
.Ltmp5:
	movq	(%rsi), %rsi
	callq	f
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello.\n"
	.size	.L.str, 8

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"This is Dr. Evil.\n"
	.size	.L.str.1, 19

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"I am calling from inside the house.\n"
	.size	.L.str.2, 37

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"I can count: %d %d %d %d %d %d %d %d\n"
	.size	.L.str.3, 38

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"I hate you, %s. Printed %d chars.\n"
	.size	.L.str.4, 35

	.type	.Lstr,@object           # @str
.Lstr:
	.asciz	"Hello."
	.size	.Lstr, 7

	.type	.Lstr.5,@object         # @str.5
	.section	.rodata.str1.16,"aMS",@progbits,1
	.align	16
.Lstr.5:
	.asciz	"This is Dr. Evil."
	.size	.Lstr.5, 18

	.type	.Lstr.6,@object         # @str.6
	.align	16
.Lstr.6:
	.asciz	"I am calling from inside the house."
	.size	.Lstr.6, 36


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
