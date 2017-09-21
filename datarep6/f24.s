	.text
	.file	"f24.c"
	.globl	mul
	.align	16, 0x90
	.type	mul,@function
mul:                                    # @mul
	leal	1000000(%rdi), %eax
	imull	%esi, %eax
	retq
.Lfunc_end0:
	.size	mul, .Lfunc_end0-mul


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
