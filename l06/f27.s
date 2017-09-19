	.text
	.file	"f27.c"
	.globl	func1
	.align	16, 0x90
	.type	func1,@function
func1:                                  # @func1
	movq	%rdi, %rax
	retq
.Lfunc_end0:
	.size	func1, .Lfunc_end0-func1


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
