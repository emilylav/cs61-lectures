	.text
	.file	"f57.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	.align	16, 0x90
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	jmp	.LBB0_1
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
