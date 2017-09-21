	.text
	.file	"f13.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
