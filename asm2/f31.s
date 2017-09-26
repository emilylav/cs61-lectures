	.text
	.file	"f31.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	pushq	%rbp
.Ltmp0:
.Ltmp1:
	movq	%rsp, %rbp
.Ltmp2:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	addl	$1, %edi
	callq	g
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
