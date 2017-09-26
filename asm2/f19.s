	.text
	.file	"f19.c"
	.globl	or
	.align	16, 0x90
	.type	or,@function
or:                                     # @or
	orl	%esi, %edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	or, .Lfunc_end0-or


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
