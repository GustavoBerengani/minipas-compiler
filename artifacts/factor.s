	.text
	.file	"factor.pas"
	.globl	showfactor                      # -- Begin function showfactor
	.p2align	4, 0x90
	.type	showfactor,@function
showfactor:                             # @showfactor
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rdi, (%rsp)
	testb	$1, first(%rip)
	jne	.LBB0_1
	jmp	.LBB0_3
.LBB0_1:                                # %if.then
	movq	(%rsp), %rsi
	leaq	.L__unnamed_1(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	movb	$0, first(%rip)
.LBB0_2:                                # %if.end
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.LBB0_3:                                # %if.else
	.cfi_def_cfa_offset 16
	leaq	.L__unnamed_2(%rip), %rdi
	leaq	.L__unnamed_3(%rip), %rsi
	movb	$0, %al
	callq	printf@PLT
	movq	(%rsp), %rsi
	leaq	.L__unnamed_4(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	jmp	.LBB0_2
.Lfunc_end0:
	.size	showfactor, .Lfunc_end0-showfactor
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
	movq	$2, divisor(%rip)
	movb	$1, first(%rip)
.LBB1_1:                                # %while.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_4 Depth 2
	cmpq	$1, number(%rip)
	jle	.LBB1_3
# %bb.2:                                # %while.body
                                        #   in Loop: Header=BB1_1 Depth=1
	jmp	.LBB1_4
.LBB1_3:                                # %while.end
	leaq	.L__unnamed_5(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.LBB1_4:                                # %while.cond1
                                        #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	.cfi_def_cfa_offset 16
	movq	number(%rip), %rax
	cqto
	idivq	divisor(%rip)
	cmpq	$0, %rdx
	jne	.LBB1_6
# %bb.5:                                # %while.body2
                                        #   in Loop: Header=BB1_4 Depth=2
	movq	divisor(%rip), %rdi
	callq	showfactor@PLT
	movq	number(%rip), %rax
	cqto
	idivq	divisor(%rip)
	movq	%rax, number(%rip)
	jmp	.LBB1_4
.LBB1_6:                                # %while.end3
                                        #   in Loop: Header=BB1_1 Depth=1
	movq	divisor(%rip), %rax
	addq	$1, %rax
	movq	%rax, divisor(%rip)
	jmp	.LBB1_1
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
	.type	divisor,@object                 # @divisor
	.local	divisor
	.comm	divisor,8,8
	.type	first,@object                   # @first
	.local	first
	.comm	first,1,1
	.type	.L__unnamed_1,@object           # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%lld"
	.size	.L__unnamed_1, 5

	.type	.L__unnamed_3,@object           # @1
.L__unnamed_3:
	.asciz	" "
	.size	.L__unnamed_3, 2

	.type	.L__unnamed_2,@object           # @2
.L__unnamed_2:
	.asciz	"%s"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_4,@object           # @3
.L__unnamed_4:
	.asciz	"%lld"
	.size	.L__unnamed_4, 5

	.type	.L__unnamed_5,@object           # @4
.L__unnamed_5:
	.asciz	"\n"
	.size	.L__unnamed_5, 2

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym atoi
	.addrsig_sym showfactor
	.addrsig_sym __minipas_argc
	.addrsig_sym __minipas_argv
	.addrsig_sym number
	.addrsig_sym divisor
	.addrsig_sym first
