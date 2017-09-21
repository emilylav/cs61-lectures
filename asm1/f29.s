	.text
	.file	"f29.c"
	.globl	func2
	.align	16, 0x90
	.type	func2,@function
func2:                                  # @func2
	leaq	(%rdi,%rsi), %rax
	retq
.Lfunc_end0:
	.size	func2, .Lfunc_end0-func2


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
