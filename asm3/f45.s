	.text
	.file	"f45.c"
	.globl	mget
	.align	16, 0x90
	.type	mget,@function
mget:                                   # @mget
	pushq	%rax
.Ltmp0:
	cmpl	%esi, (%rdi)
	jle	.LBB0_3
	cmpl	%edx, 4(%rdi)
	jle	.LBB0_4
	movslq	%edx, %rax
	movslq	%esi, %rcx
	movq	8(%rdi), %rdx
	movq	(%rdx,%rcx,8), %rcx
	movl	(%rcx,%rax,4), %eax
	popq	%rcx
	retq
.LBB0_3:
	movl	$.L.str, %edi
	movl	$.L.str.1, %esi
	movl	$11, %edx
	movl	$.L__PRETTY_FUNCTION__.mget, %ecx
	callq	__assert_fail
.LBB0_4:
	movl	$.L.str.2, %edi
	movl	$.L.str.1, %esi
	movl	$12, %edx
	movl	$.L__PRETTY_FUNCTION__.mget, %ecx
	callq	__assert_fail
.Lfunc_end0:
	.size	mget, .Lfunc_end0-mget

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"i < m->nrows"
	.size	.L.str, 13

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"f45.c"
	.size	.L.str.1, 6

	.type	.L__PRETTY_FUNCTION__.mget,@object # @__PRETTY_FUNCTION__.mget
.L__PRETTY_FUNCTION__.mget:
	.asciz	"int mget(struct matrix *, int, int)"
	.size	.L__PRETTY_FUNCTION__.mget, 36

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"j < m->ncols"
	.size	.L.str.2, 13


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
