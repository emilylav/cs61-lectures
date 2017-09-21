	.text
	.file	"f31.c"
	.globl	func5
	.align	16, 0x90
	.type	func5,@function
func5:                                  # @func5
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	addq	%r8, %rax
	retq
.Lfunc_end0:
	.size	func5, .Lfunc_end0-func5


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
