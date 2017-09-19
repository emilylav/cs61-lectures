	.text
	.file	"f13.c"
	.globl	not
	.align	16, 0x90
	.type	not,@function
not:                                    # @not
	notl	%edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	not, .Lfunc_end0-not


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
