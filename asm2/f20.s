	.text
	.file	"f20.c"
	.globl	xor
	.align	16, 0x90
	.type	xor,@function
xor:                                    # @xor
	xorl	%esi, %edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	xor, .Lfunc_end0-xor


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
