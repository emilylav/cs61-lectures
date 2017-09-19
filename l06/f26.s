	.text
	.file	"f17.c"
	.globl	sum
	.align	16, 0x90
	.type	sum,@function
sum:                                    # @sum
	leal	(%rdi,%rsi), %eax
	retq
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
