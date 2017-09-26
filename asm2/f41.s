	.text
	.file	"f41.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	xorl	%eax, %eax
	testl	%edi, %edi
	je	.LBB0_2
	leal	-1(%rdi), %eax
	leal	-2(%rdi), %ecx
	imulq	%rax, %rcx
	shrq	%rcx
	leal	-1(%rcx,%rdi), %eax
.LBB0_2:                                # %._crit_edge
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
