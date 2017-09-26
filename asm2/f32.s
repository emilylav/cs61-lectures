	.text
	.file	"f32.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movl	b(%rip), %eax
	cmpl	x(%rip), %eax
	jne	.LBB0_2
	movl	a(%rip), %eax
.LBB0_2:                                # %select.end
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
