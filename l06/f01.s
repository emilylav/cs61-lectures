	.text
	.file	"f01.c"
	.globl	f
	.type	f,@function
f:                                      # @f
	movl	$100, %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
