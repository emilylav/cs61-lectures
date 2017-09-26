	.text
	.file	"f52.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	xorl	%eax, %eax
	testl	%esi, %esi
	jle	.LBB0_2
	.align	16, 0x90
.LBB0_1:                                # %.lr.ph
	addl	(%rdi), %eax
	addq	$4, %rdi
	decl	%esi
	jne	.LBB0_1
.LBB0_2:                                # %._crit_edge
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
