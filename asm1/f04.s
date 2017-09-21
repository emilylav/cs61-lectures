	.text
	.file	"f04.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movl	a(%rip), %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f

	.type	a,@object               # @a
	.data
	.globl	a
	.align	4
a:
	.long	10                      # 0xa
	.size	a, 4


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
