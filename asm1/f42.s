	.text
	.file	"f42.c"
	.globl	g
	.align	16, 0x90
	.type	g,@function
g:                                      # @g
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	g, .Lfunc_end0-g

	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	xorl	%eax, %eax
	testl	%edi, %edi
	je	.LBB1_2
	leal	-1(%rdi), %eax
	leal	-2(%rdi), %ecx
	imulq	%rax, %rcx
	shrq	%rcx
	leal	-1(%rcx,%rdi), %eax
.LBB1_2:                                # %._crit_edge
	retq
.Lfunc_end1:
	.size	f, .Lfunc_end1-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
