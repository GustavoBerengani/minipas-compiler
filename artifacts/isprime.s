	.text
	.file	"isprime.pas"
	.globl	prime                           # -- Begin function prime
	.p2align	4, 0x90
	.type	prime,@function
prime:                                  # @prime
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -24(%rsp)
	movq	$0, -16(%rsp)
	movb	$0, -1(%rsp)
	cmpq	$2, -24(%rsp)
	jge	.LBB0_3
# %bb.1:                                # %if.then
	movb	$0, -1(%rsp)
.LBB0_2:                                # %if.end
	movb	-1(%rsp), %al
	retq
.LBB0_3:                                # %if.else
	movq	$2, -16(%rsp)
	movb	$1, -1(%rsp)
.LBB0_4:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	movq	-16(%rsp), %rax
	imulq	-16(%rsp), %rax
	cmpq	-24(%rsp), %rax
	setle	%al
	andb	-1(%rsp), %al
	testb	$1, %al
	jne	.LBB0_5
	jmp	.LBB0_6
.LBB0_5:                                # %while.body
                                        #   in Loop: Header=BB0_4 Depth=1
	movq	-24(%rsp), %rax
	cqto
	idivq	-16(%rsp)
	cmpq	$0, %rdx
	je	.LBB0_7
	jmp	.LBB0_8
.LBB0_6:                                # %while.end
	jmp	.LBB0_2
.LBB0_7:                                # %if.then6
                                        #   in Loop: Header=BB0_4 Depth=1
	movb	$0, -1(%rsp)
.LBB0_8:                                # %if.end7
                                        #   in Loop: Header=BB0_4 Depth=1
	movq	-16(%rsp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rsp)
	jmp	.LBB0_4
.Lfunc_end0:
	.size	prime, .Lfunc_end0-prime
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, __minipas_argc(%rip)
	movq	%rsi, __minipas_argv(%rip)
	movq	__minipas_argv(%rip), %rax
	movq	8(%rax), %rdi
	callq	atoi@PLT
	cltq
	movq	%rax, number(%rip)
	movq	number(%rip), %rdi
	callq	prime@PLT
	movb	%al, %cl
	leaq	.L__unnamed_1(%rip), %rsi
	leaq	.L__unnamed_2(%rip), %rax
	testb	$1, %cl
	cmovneq	%rax, %rsi
	leaq	.L__unnamed_3(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	leaq	.L__unnamed_4(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	__minipas_argc,@object          # @__minipas_argc
	.local	__minipas_argc
	.comm	__minipas_argc,4,4
	.type	__minipas_argv,@object          # @__minipas_argv
	.local	__minipas_argv
	.comm	__minipas_argv,8,8
	.type	number,@object                  # @number
	.local	number
	.comm	number,8,8
	.type	.L__unnamed_2,@object           # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"true"
	.size	.L__unnamed_2, 5

	.type	.L__unnamed_1,@object           # @1
.L__unnamed_1:
	.asciz	"false"
	.size	.L__unnamed_1, 6

	.type	.L__unnamed_3,@object           # @2
.L__unnamed_3:
	.asciz	"%s"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_4,@object           # @3
.L__unnamed_4:
	.asciz	"\n"
	.size	.L__unnamed_4, 2

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym atoi
	.addrsig_sym prime
	.addrsig_sym __minipas_argc
	.addrsig_sym __minipas_argv
	.addrsig_sym number
