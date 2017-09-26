	.text
	.file	"f23.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movq	%rdi, -8(%rsp)
	movq	%rsi, -16(%rsp)
	movq	%rdx, -24(%rsp)
	movq	%rcx, -32(%rsp)
	movq	%r8, -40(%rsp)
	movq	%r9, -48(%rsp)
	movq	-8(%rsp), %rcx
	movq	-16(%rsp), %rdx
	shlq	$1, %rdx
	addq	%rdx, %rcx
	imulq	$3, -24(%rsp), %rdx
	addq	%rdx, %rcx
	movq	-32(%rsp), %rdx
	shlq	$2, %rdx
	addq	%rdx, %rcx
	imulq	$5, -40(%rsp), %rdx
	addq	%rdx, %rcx
	imulq	$6, -48(%rsp), %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
