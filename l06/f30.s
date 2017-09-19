	.text
	.file	"f29.c"
	.globl	func4
	.align	16, 0x90
	.type	func4,@function
func4:                                  # @func4
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	retq
.Lfunc_end0:
	.size	func4, .Lfunc_end0-func4


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
