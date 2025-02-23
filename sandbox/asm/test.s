.text
.global main

main:
	movq $1, %rdi
	call malloc

	movq $3, (%rax)
	movq $10, %rcx
	movq $0xc, (%rax, %rcx, 8)

	testq %rax, %rax
	jz    alloc_err

	movq %rax, %rdi

	movq (%rax, %rcx, 8), %rdi
	call exit

alloc_err:
	movq $1, %rdi
	call exit
