	.text
	.file	"f29.c"
	.globl	func3
	.align	16, 0x90
	.type	func3,@function
func3:                                  # @func3
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	retq
.Lfunc_end0:
	.size	func3, .Lfunc_end0-func3


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
