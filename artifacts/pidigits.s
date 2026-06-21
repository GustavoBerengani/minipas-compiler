	.text
	.file	"pidigits.pas"
	.globl	arctaninverse                   # -- Begin function arctaninverse
	.p2align	4, 0x90
	.type	arctaninverse,@function
arctaninverse:                          # @arctaninverse
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -56(%rsp)
	movq	%rsi, -48(%rsp)
	movq	$0, -40(%rsp)
	movq	$0, -32(%rsp)
	movq	$0, -24(%rsp)
	movq	$0, -16(%rsp)
	movq	$0, -8(%rsp)
	movq	-48(%rsp), %rax
	cqto
	idivq	-56(%rsp)
	movq	%rax, -40(%rsp)
	movq	-40(%rsp), %rax
	movq	%rax, -32(%rsp)
	movq	$3, -24(%rsp)
	movq	$-1, -8(%rsp)
.LBB0_1:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	cmpq	$0, -40(%rsp)
	je	.LBB0_3
# %bb.2:                                # %while.body
                                        #   in Loop: Header=BB0_1 Depth=1
	movq	-40(%rsp), %rax
	movq	-56(%rsp), %rcx
	imulq	-56(%rsp), %rcx
	cqto
	idivq	%rcx
	movq	%rax, -40(%rsp)
	movq	-40(%rsp), %rax
	cqto
	idivq	-24(%rsp)
	movq	%rax, -16(%rsp)
	cmpq	$0, -8(%rsp)
	jl	.LBB0_4
	jmp	.LBB0_6
.LBB0_3:                                # %while.end
	movq	-32(%rsp), %rax
	retq
.LBB0_4:                                # %if.then
                                        #   in Loop: Header=BB0_1 Depth=1
	movq	-32(%rsp), %rax
	subq	-16(%rsp), %rax
	movq	%rax, -32(%rsp)
.LBB0_5:                                # %if.end
                                        #   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rsp), %rax
	addq	$2, %rax
	movq	%rax, -24(%rsp)
	xorl	%eax, %eax
                                        # kill: def $rax killed $eax
	subq	-8(%rsp), %rax
	movq	%rax, -8(%rsp)
	jmp	.LBB0_1
.LBB0_6:                                # %if.else
                                        #   in Loop: Header=BB0_1 Depth=1
	movq	-32(%rsp), %rax
	addq	-16(%rsp), %rax
	movq	%rax, -32(%rsp)
	jmp	.LBB0_5
.Lfunc_end0:
	.size	arctaninverse, .Lfunc_end0-arctaninverse
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
	movq	%rax, digits(%rip)
	cmpq	$13, digits(%rip)
	jle	.LBB1_2
# %bb.1:                                # %if.then
	movq	$13, digits(%rip)
.LBB1_2:                                # %if.end
	cmpq	$0, digits(%rip)
	jle	.LBB1_4
# %bb.3:                                # %if.then3
	movabsq	$1000000000000000, %rax         # imm = 0x38D7EA4C68000
	movq	%rax, scale(%rip)
	movq	scale(%rip), %rsi
	movl	$5, %edi
	callq	arctaninverse@PLT
	shlq	$4, %rax
	movq	%rax, (%rsp)                    # 8-byte Spill
	movq	scale(%rip), %rsi
	movl	$239, %edi
	callq	arctaninverse@PLT
	movq	%rax, %rcx
	movq	(%rsp), %rax                    # 8-byte Reload
	shlq	$2, %rcx
	subq	%rcx, %rax
	movq	%rax, pivalue(%rip)
	movq	scale(%rip), %rax
	movq	%rax, divisor(%rip)
	movq	$0, count(%rip)
	jmp	.LBB1_5
.LBB1_4:                                # %if.end4
	leaq	.L__unnamed_1(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.LBB1_5:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	.cfi_def_cfa_offset 16
	movq	count(%rip), %rax
	cmpq	digits(%rip), %rax
	jge	.LBB1_7
# %bb.6:                                # %while.body
                                        #   in Loop: Header=BB1_5 Depth=1
	movq	pivalue(%rip), %rax
	cqto
	idivq	divisor(%rip)
	movl	$10, %ecx
	cqto
	idivq	%rcx
	movq	%rdx, current(%rip)
	movq	current(%rip), %rsi
	leaq	.L__unnamed_2(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	movq	count(%rip), %rax
	addq	$1, %rax
	movq	%rax, count(%rip)
	cmpq	$1, count(%rip)
	sete	%al
	cmpq	$1, digits(%rip)
	setg	%cl
	andb	%cl, %al
	testb	$1, %al
	jne	.LBB1_8
	jmp	.LBB1_9
.LBB1_7:                                # %while.end
	jmp	.LBB1_4
.LBB1_8:                                # %if.then14
                                        #   in Loop: Header=BB1_5 Depth=1
	leaq	.L__unnamed_3(%rip), %rdi
	leaq	.L__unnamed_4(%rip), %rsi
	movb	$0, %al
	callq	printf@PLT
.LBB1_9:                                # %if.end15
                                        #   in Loop: Header=BB1_5 Depth=1
	movq	divisor(%rip), %rax
	movl	$10, %ecx
	cqto
	idivq	%rcx
	movq	%rax, divisor(%rip)
	jmp	.LBB1_5
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
	.type	digits,@object                  # @digits
	.local	digits
	.comm	digits,8,8
	.type	scale,@object                   # @scale
	.local	scale
	.comm	scale,8,8
	.type	pivalue,@object                 # @pivalue
	.local	pivalue
	.comm	pivalue,8,8
	.type	divisor,@object                 # @divisor
	.local	divisor
	.comm	divisor,8,8
	.type	current,@object                 # @current
	.local	current
	.comm	current,8,8
	.type	count,@object                   # @count
	.local	count
	.comm	count,8,8
	.type	.L__unnamed_2,@object           # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"%lld"
	.size	.L__unnamed_2, 5

	.type	.L__unnamed_4,@object           # @1
.L__unnamed_4:
	.asciz	"."
	.size	.L__unnamed_4, 2

	.type	.L__unnamed_3,@object           # @2
.L__unnamed_3:
	.asciz	"%s"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_1,@object           # @3
.L__unnamed_1:
	.asciz	"\n"
	.size	.L__unnamed_1, 2

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym atoi
	.addrsig_sym arctaninverse
	.addrsig_sym __minipas_argc
	.addrsig_sym __minipas_argv
	.addrsig_sym digits
	.addrsig_sym scale
	.addrsig_sym pivalue
	.addrsig_sym divisor
	.addrsig_sym current
	.addrsig_sym count
