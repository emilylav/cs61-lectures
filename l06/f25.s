	.text
	.file	"f16.c"
	.globl	sum
	.align	16, 0x90
	.type	sum,@function
sum:                                    # @sum
	imulq	$1000, %rdi, %rax       # imm = 0x3E8
	imulq	$10000, %rsi, %rcx      # imm = 0x2710
	addq	%rax, %rcx
	imulq	$100000, %rdx, %rax     # imm = 0x186A0
	addq	%rcx, %rax
	retq
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
