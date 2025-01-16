.data
bufUnit:		.quad 1
bufLen:		.quad 64
bufFilled:	.quad 0	/*like LUMO*/
bufBody:		.space 64
.balign 8
numbersChar:	.ascii "0123456789ABCDEFx+-."
.balign 8

.text
.global print_clear, print_print
.global print_Char, print_Hex, print_Dec
.global print_LF, print_HTab

print_print: /*arg:*/
	movq $1, %rdi
	lea  bufBody(%rip), %rsi
	movq bufFilled(%rip), %rdx
	call write
	call print_clear
	ret

print_clear: /*arg:*/
	movq $0, bufFilled(%rip)
	ret

print_Char: /*arg:rax=char*/
	movq bufLen(%rip), %rdi
	cmpq bufFilled(%rip), %rdi
	jg   ExecuteAdd
	jle  AutoPrint

	AutoPrint:
	push %rax
	call print_print
	pop  %rax

	ExecuteAdd:
	lea  bufBody(%rip), %rsi
	movq bufFilled(%rip), %rdi
	movb %al, (%rsi,%rdi,1)
	addq $1, %rdi
	movq %rdi, bufFilled(%rip)
	ret

addInt: /*arg:rax=SourceInt, rdi=Divisor, rsi=Base(2,10,16)*/
	push %r12
	push %r13
	push %r14
	push %r15

	movq %rax, %r12 /*Source Integer*/
	movq %rdi, %r13 /*Dvisor*/
	movq %rsi, %r14 /*Base(2,10,16)*/
	movq $0, %r15   /*Flag:bit0=NoZero*/

	Loop_RunOverAllDigit:
		/*exec div*/
		xorq %rdx, %rdx
		movq %r12, %rax
		divq %r13
		/*show div result*/
		movq %rdx, %r12
		cmpq $0, %rax 
		jne  AddDigitChar/*if the digit is not equals zero*/

		/*padding zero is skiped*/
		movq %r15, %rdi
		andq $0b0001, %rdi
		cmpq $0, %rdi
		je   SetNextDigit
		jne  AddDigitChar

		AddDigitChar:
		lea  numbersChar(%rip), %rdi
		movb (%rdi,%rax,1), %al
		call print_Char
		orq  $0b0001, %r15
		/*set next digit*/
		SetNextDigit:
		xorq %rdx, %rdx
		movq %r13, %rax
		divq %r14
		movq %rax, %r13

		cmpq $0, %r13
		jg  Loop_RunOverAllDigit

	cmpq $0, %r15
	jnz  EndSeaquence
	/*source int is zero*/
	movb numbersChar(%rip), %al
	call print_Char
	
	EndSeaquence:
	pop %r15
	pop %r14
	pop %r13
	pop %r12
	ret

print_Hex: /*arg:rax=SourceInt*/
	movq %rax, %r8
	movb numbersChar(%rip), %al
	call print_Char
	movq $16, %r9
	lea  numbersChar(%rip), %r10
	movb (%r10,%r9,1), %al
	call print_Char

	movq %r8, %rax
	movq $0x1000000000000000, %rdi
	movq $0x10, %rsi
	call addInt

	ret

print_Dec:
	cmpq $0, %rax
	jl   ValueIsMinus

	ValueIsPlus:
	movq $17, %r9
	jmp PrintSignChar

	ValueIsMinus:
	movq $18, %r9
	xorq %rdx, %rdx
	movq $-1, %rdi
	mulq %rdi
	jmp  PrintSignChar

	PrintSignChar:
	push %rax   /*escape rax*/
	lea  numbersChar(%rip), %r10
	movb (%r10,%r9,1), %al
	call print_Char
	pop  %rax

	movq $10000000000000000000, %rdi
	movq $10, %rsi
	call addInt
	
	ret

print_LF:
	movb $0x0a, %al
	call print_Char
	ret

print_HTab:
	movb $0x09, %al
	call print_Char
	ret
