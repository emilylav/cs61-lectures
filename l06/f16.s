	.text
	.file	"f07.c"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	imull	$1000, %edi, %eax       # imm = 0x3E8
	imull	$10000, %esi, %ecx      # imm = 0x2710
	addl	%eax, %ecx
	imull	$100000, %edx, %eax     # imm = 0x186A0
	addl	%ecx, %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
