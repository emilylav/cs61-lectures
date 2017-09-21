	.text
	.file	"f35.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	pushq	%rbp
.Ltmp0:
.Ltmp1:
	movq	%rsp, %rbp
.Ltmp2:
	pushq	%rbx
	subq	$72, %rsp
.Ltmp3:
	movabsq	$.L.str, %rax
	movl	%edi, -12(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.1, %rdi
	movl	%eax, -32(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.2, %rdi
	movl	%eax, -36(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.3, %rdi
	movl	-12(%rbp), %esi
	movl	-12(%rbp), %ecx
	addl	$1, %ecx
	movl	-12(%rbp), %edx
	addl	$2, %edx
	movl	-12(%rbp), %r8d
	addl	$3, %r8d
	movl	-12(%rbp), %r9d
	addl	$4, %r9d
	movl	-12(%rbp), %r10d
	addl	$5, %r10d
	movl	-12(%rbp), %r11d
	addl	$6, %r11d
	movl	-12(%rbp), %ebx
	addl	$7, %ebx
	movl	%edx, -40(%rbp)         # 4-byte Spill
	movl	%ecx, %edx
	movl	-40(%rbp), %ecx         # 4-byte Reload
	movl	%r10d, (%rsp)
	movl	%r11d, 8(%rsp)
	movl	%ebx, 16(%rsp)
	movl	%eax, -44(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.4, %rdi
	movl	%eax, -28(%rbp)
	movq	-24(%rbp), %rsi
	movl	-28(%rbp), %edx
	movb	$0, %al
	callq	printf
	movl	%eax, -48(%rbp)         # 4-byte Spill
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	pushq	%rbp
.Ltmp4:
.Ltmp5:
	movq	%rsp, %rbp
.Ltmp6:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %edi
	movq	-16(%rbp), %rsi
	movq	(%rsi), %rsi
	callq	f
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
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


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
