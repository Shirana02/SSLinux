.text
.global addr_alignHead, addr_alignTail

diffHead:
	/*
		arg
		rax:CurrentAddr
		ret
		rax:diff to next head
	*/
	xorq %rdx, %rdx
	movq $8, %rsi
	divq %rsi
	cmpq $0, %rdx
	je   diffHead_HereIsHead

	diffHead_HereIsNotHead:
	movq %rsi, %rax
	subq %rdx, %rax
	ret

	diffHead_HereIsHead:
	movq $0, %rax
	ret

diffTail:
	/*
		arg
		rax:CurrentAddr
		ret
		rax:diff to next tail
	*/
	call diffHead
	cmpq $0, %rax
	je   diffTail_HereIsHead

	diffTail_HereIsNotHead:
	subq $1, %rax
	ret

	diffTail_HereIsHead:
	addq $7, %rax
	ret

addr_alignHead:
	/*
		arg
		rax:CurrentAddr
		ret
		rax:next head address
	*/
	push %rax
	call diffHead
	pop  %rdi
	addq %rdi, %rax
	ret

addr_alignTail:
	/*
		arg
		rax:CurrentAddr
		ret
		rax:next tail address
	*/
	push %rax
	call diffTail
	pop  %rdi
	addq %rdi, %rax
	ret
