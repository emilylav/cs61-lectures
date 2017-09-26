	.text
	.file	"f40.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	pushq	%rbp
.Ltmp0:
	pushq	%r14
.Ltmp1:
	pushq	%rbx
.Ltmp2:
.Ltmp3:
.Ltmp4:
.Ltmp5:
	movl	%edi, %r14d
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	testl	%r14d, %r14d
	je	.LBB0_2
	.align	16, 0x90
.LBB0_1:                                # %.lr.ph
	movl	%ebp, %edi
	callq	g
	addl	%eax, %ebx
	incl	%ebp
	cmpl	%ebp, %r14d
	jne	.LBB0_1
.LBB0_2:                                # %._crit_edge
	movl	%ebx, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
