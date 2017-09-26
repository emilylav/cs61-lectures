	.text
	.file	"f57.c"
	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI0_0:
	.long	1                       # 0x1
	.long	1                       # 0x1
	.long	1                       # 0x1
	.long	1                       # 0x1
.LCPI0_1:
	.long	0                       # 0x0
	.long	4294967295              # 0xffffffff
	.long	4294967294              # 0xfffffffe
	.long	4294967293              # 0xfffffffd
.LCPI0_2:
	.long	4294967292              # 0xfffffffc
	.long	4294967291              # 0xfffffffb
	.long	4294967290              # 0xfffffffa
	.long	4294967289              # 0xfffffff9
	.text
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
	movl	$1, %eax
	testl	%edi, %edi
	jle	.LBB0_12
	cmpl	$2, %edi
	movl	$1, %eax
	movl	$1, %ecx
	cmovll	%edi, %ecx
	notl	%ecx
	leal	2(%rdi,%rcx), %ecx
	cmpl	$8, %ecx
	jb	.LBB0_11
	movl	%ecx, %r8d
	andl	$-8, %r8d
	movl	%ecx, %r9d
	andl	$-8, %r9d
	je	.LBB0_11
	cmpl	$2, %edi
	movl	$1, %eax
	cmovll	%edi, %eax
	notl	%eax
	leal	-6(%rdi,%rax), %edx
	movl	%edx, %eax
	shrl	$3, %eax
	btl	$3, %edx
	jb	.LBB0_4
	movd	%edi, %xmm0
	pshufd	$0, %xmm0, %xmm1        # xmm1 = xmm0[0,0,0,0]
	movdqa	.LCPI0_1(%rip), %xmm0   # xmm0 = [0,4294967295,4294967294,4294967293]
	paddd	%xmm1, %xmm0
	paddd	.LCPI0_2(%rip), %xmm1
	movl	$8, %esi
	jmp	.LBB0_6
.LBB0_4:
	movdqa	.LCPI0_0(%rip), %xmm0   # xmm0 = [1,1,1,1]
	xorl	%esi, %esi
	movdqa	%xmm0, %xmm1
.LBB0_6:                                # %vector.body.preheader.split
	testl	%eax, %eax
	je	.LBB0_9
	movl	%edi, %eax
	notl	%eax
	cmpl	$-3, %eax
	movl	$-2, %edx
	cmovgl	%eax, %edx
	leal	2(%rdi,%rdx), %eax
	andl	$-8, %eax
	subl	%esi, %eax
	movl	%edi, %edx
	subl	%esi, %edx
	movdqa	.LCPI0_1(%rip), %xmm2   # xmm2 = [0,4294967295,4294967294,4294967293]
	movdqa	.LCPI0_2(%rip), %xmm3   # xmm3 = [4294967292,4294967291,4294967290,4294967289]
	.align	16, 0x90
.LBB0_8:                                # %vector.body
	movd	%edx, %xmm4
	pshufd	$0, %xmm4, %xmm4        # xmm4 = xmm4[0,0,0,0]
	movdqa	%xmm4, %xmm5
	paddd	%xmm2, %xmm5
	paddd	%xmm3, %xmm4
	pshufd	$245, %xmm5, %xmm6      # xmm6 = xmm5[1,1,3,3]
	pmuludq	%xmm0, %xmm5
	pshufd	$232, %xmm5, %xmm5      # xmm5 = xmm5[0,2,2,3]
	pshufd	$245, %xmm0, %xmm0      # xmm0 = xmm0[1,1,3,3]
	pmuludq	%xmm6, %xmm0
	pshufd	$232, %xmm0, %xmm0      # xmm0 = xmm0[0,2,2,3]
	punpckldq	%xmm0, %xmm5    # xmm5 = xmm5[0],xmm0[0],xmm5[1],xmm0[1]
	pshufd	$245, %xmm4, %xmm0      # xmm0 = xmm4[1,1,3,3]
	pmuludq	%xmm1, %xmm4
	pshufd	$232, %xmm4, %xmm4      # xmm4 = xmm4[0,2,2,3]
	pshufd	$245, %xmm1, %xmm1      # xmm1 = xmm1[1,1,3,3]
	pmuludq	%xmm0, %xmm1
	pshufd	$232, %xmm1, %xmm0      # xmm0 = xmm1[0,2,2,3]
	punpckldq	%xmm0, %xmm4    # xmm4 = xmm4[0],xmm0[0],xmm4[1],xmm0[1]
	leal	-8(%rdx), %esi
	movd	%esi, %xmm0
	pshufd	$0, %xmm0, %xmm1        # xmm1 = xmm0[0,0,0,0]
	movdqa	%xmm1, %xmm0
	paddd	%xmm2, %xmm0
	paddd	%xmm3, %xmm1
	pshufd	$245, %xmm0, %xmm6      # xmm6 = xmm0[1,1,3,3]
	pmuludq	%xmm5, %xmm0
	pshufd	$232, %xmm0, %xmm0      # xmm0 = xmm0[0,2,2,3]
	pshufd	$245, %xmm5, %xmm5      # xmm5 = xmm5[1,1,3,3]
	pmuludq	%xmm6, %xmm5
	pshufd	$232, %xmm5, %xmm5      # xmm5 = xmm5[0,2,2,3]
	punpckldq	%xmm5, %xmm0    # xmm0 = xmm0[0],xmm5[0],xmm0[1],xmm5[1]
	pshufd	$245, %xmm1, %xmm5      # xmm5 = xmm1[1,1,3,3]
	pmuludq	%xmm4, %xmm1
	pshufd	$232, %xmm1, %xmm1      # xmm1 = xmm1[0,2,2,3]
	pshufd	$245, %xmm4, %xmm4      # xmm4 = xmm4[1,1,3,3]
	pmuludq	%xmm5, %xmm4
	pshufd	$232, %xmm4, %xmm4      # xmm4 = xmm4[0,2,2,3]
	punpckldq	%xmm4, %xmm1    # xmm1 = xmm1[0],xmm4[0],xmm1[1],xmm4[1]
	addl	$-16, %edx
	addl	$-16, %eax
	jne	.LBB0_8
.LBB0_9:                                # %middle.block
	pshufd	$245, %xmm1, %xmm2      # xmm2 = xmm1[1,1,3,3]
	pmuludq	%xmm0, %xmm1
	pshufd	$232, %xmm1, %xmm1      # xmm1 = xmm1[0,2,2,3]
	pshufd	$245, %xmm0, %xmm0      # xmm0 = xmm0[1,1,3,3]
	pmuludq	%xmm2, %xmm0
	pshufd	$232, %xmm0, %xmm0      # xmm0 = xmm0[0,2,2,3]
	punpckldq	%xmm0, %xmm1    # xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	pshufd	$78, %xmm1, %xmm0       # xmm0 = xmm1[2,3,0,1]
	pshufd	$245, %xmm1, %xmm2      # xmm2 = xmm1[1,1,3,3]
	pmuludq	%xmm0, %xmm1
	pshufd	$232, %xmm1, %xmm1      # xmm1 = xmm1[0,2,2,3]
	pshufd	$245, %xmm0, %xmm0      # xmm0 = xmm0[1,1,3,3]
	pmuludq	%xmm2, %xmm0
	pshufd	$232, %xmm0, %xmm0      # xmm0 = xmm0[0,2,2,3]
	punpckldq	%xmm0, %xmm1    # xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	pshufd	$229, %xmm1, %xmm0      # xmm0 = xmm1[1,1,2,3]
	pshufd	$245, %xmm1, %xmm2      # xmm2 = xmm1[1,1,3,3]
	pmuludq	%xmm0, %xmm1
	pshufd	$232, %xmm1, %xmm1      # xmm1 = xmm1[0,2,2,3]
	pshufd	$245, %xmm0, %xmm0      # xmm0 = xmm0[1,1,3,3]
	pmuludq	%xmm2, %xmm0
	pshufd	$232, %xmm0, %xmm0      # xmm0 = xmm0[0,2,2,3]
	punpckldq	%xmm0, %xmm1    # xmm1 = xmm1[0],xmm0[0],xmm1[1],xmm0[1]
	movd	%xmm1, %eax
	cmpl	%r9d, %ecx
	je	.LBB0_12
	subl	%r8d, %edi
	.align	16, 0x90
.LBB0_11:                               # %tailrecurse
	imull	%edi, %eax
	cmpl	$1, %edi
	leal	-1(%rdi), %ecx
	movl	%ecx, %edi
	jg	.LBB0_11
.LBB0_12:                               # %tailrecurse._crit_edge
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
