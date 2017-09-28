	.text
	.file	"f46.c"
	.globl	second_plus_third
	.align	16, 0x90
	.type	second_plus_third,@function
second_plus_third:                      # @second_plus_third
	movq	8(%rdi), %rcx
	movq	8(%rcx), %rax
	movl	(%rax), %eax
	addl	(%rcx), %eax
	retq
.Lfunc_end0:
	.size	second_plus_third, .Lfunc_end0-second_plus_third


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
