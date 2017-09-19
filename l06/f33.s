	.text
	.file	"f32.c"
	.globl	func7
	.align	16, 0x90
	.type	func7,@function
func7:                                  # @func7
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	addq	%r8, %rax
	addq	%r9, %rax
	addq	8(%rsp), %rax
	retq
.Lfunc_end0:
	.size	func7, .Lfunc_end0-func7


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
