	.text
	.file	"fibonacci.pas"
	.globl	fib                             # -- Begin function fib
	.p2align	4, 0x90
	.type	fib,@function
fib:                                    # @fib
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -40(%rsp)
	movq	$0, -32(%rsp)
	movq	$0, -24(%rsp)
	movq	$0, -16(%rsp)
	movq	$0, -8(%rsp)
	cmpq	$0, -40(%rsp)
	jg	.LBB0_2
# %bb.1:                                # %if.then
	xorl	%eax, %eax
                                        # kill: def $rax killed $eax
	retq
.LBB0_2:                                # %if.else
	movq	$0, -32(%rsp)
	movq	$1, -24(%rsp)
	movq	$2, -8(%rsp)
.LBB0_3:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	movq	-8(%rsp), %rax
	cmpq	-40(%rsp), %rax
	jg	.LBB0_5
# %bb.4:                                # %for.body
                                        #   in Loop: Header=BB0_3 Depth=1
	movq	-32(%rsp), %rax
	addq	-24(%rsp), %rax
	movq	%rax, -16(%rsp)
	movq	-24(%rsp), %rax
	movq	%rax, -32(%rsp)
	movq	-16(%rsp), %rax
	movq	%rax, -24(%rsp)
	movq	-8(%rsp), %rax
	addq	$1, %rax
	movq	%rax, -8(%rsp)
	jmp	.LBB0_3
.LBB0_5:                                # %for.end
	movq	-24(%rsp), %rax
	retq
.Lfunc_end0:
	.size	fib, .Lfunc_end0-fib
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
	movq	%rax, position(%rip)
	movq	position(%rip), %rdi
	callq	fib@PLT
	movq	%rax, %rsi
	leaq	.L__unnamed_1(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	leaq	.L__unnamed_2(%rip), %rdi
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
	.type	position,@object                # @position
	.local	position
	.comm	position,8,8
	.type	.L__unnamed_1,@object           # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%lld"
	.size	.L__unnamed_1, 5

	.type	.L__unnamed_2,@object           # @1
.L__unnamed_2:
	.asciz	"\n"
	.size	.L__unnamed_2, 2

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym atoi
	.addrsig_sym fib
	.addrsig_sym __minipas_argc
	.addrsig_sym __minipas_argv
	.addrsig_sym position
