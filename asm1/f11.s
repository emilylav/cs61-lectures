	.text
	.file	"f11.c"
	.globl	sum
	.align	16, 0x90
	.type	sum,@function
sum:                                    # @sum
	movb	b(%rip), %al
	addb	a(%rip), %al
	movzbl	%al, %eax
	retq
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
