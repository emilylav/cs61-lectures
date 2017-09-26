	.text
	.file	"f54.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movl	$1, %eax
	testl	%edi, %edi
	jle	.LBB0_2
	.align	16, 0x90
.LBB0_1:                                # %tailrecurse
	imull	%edi, %eax
	cmpl	$1, %edi
	leal	-1(%rdi), %ecx
	movl	%ecx, %edi
	jg	.LBB0_1
.LBB0_2:                                # %tailrecurse._crit_edge
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
