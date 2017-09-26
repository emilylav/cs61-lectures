	.text
	.file	"f24.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movq	8(%rsp), %rax
	movq	%rdi, -8(%rsp)
	movq	%rsi, -16(%rsp)
	movq	%rdx, -24(%rsp)
	movq	%rcx, -32(%rsp)
	movq	%r8, -40(%rsp)
	movq	%r9, -48(%rsp)
	movq	%rax, -56(%rsp)
	movq	-8(%rsp), %rax
	movq	-16(%rsp), %rcx
	shlq	$1, %rcx
	addq	%rcx, %rax
	imulq	$3, -24(%rsp), %rcx
	addq	%rcx, %rax
	movq	-32(%rsp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	imulq	$5, -40(%rsp), %rcx
	addq	%rcx, %rax
	imulq	$6, -48(%rsp), %rcx
	addq	%rcx, %rax
	imulq	$7, -56(%rsp), %rcx
	addq	%rcx, %rax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
