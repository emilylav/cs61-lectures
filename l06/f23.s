	.text
	.file	"f23.c"
	.globl	mul
	.align	16, 0x90
	.type	mul,@function
mul:                                    # @mul
	imull	%esi, %edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	mul, .Lfunc_end0-mul


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
