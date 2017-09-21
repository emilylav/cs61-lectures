	.text
	.file	"f33.c"
	.globl	func6
	.align	16, 0x90
	.type	func6,@function
func6:                                  # @func6
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	addq	%r8, %rax
	addq	%r9, %rax
	retq
.Lfunc_end0:
	.size	func6, .Lfunc_end0-func6


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
