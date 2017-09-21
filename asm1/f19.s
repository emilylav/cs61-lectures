	.text
	.file	"f19.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	imull	$1000, %edi, %eax       # imm = 0x3E8
	imull	%edx, %esi
	subl	%esi, %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
