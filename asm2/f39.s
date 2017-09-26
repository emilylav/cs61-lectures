	.text
	.file	"f39.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	cmpl	%esi, %edi
	jl	.LBB0_2
	cmpl	%edx, %edi
	jl	.LBB0_2
	movl	%edi, %eax
	retq
.LBB0_2:
	cmpl	%edx, %esi
	movl	%esi, %eax
	cmovll	%edx, %eax
	cmpl	%edi, %esi
	cmovll	%edx, %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
