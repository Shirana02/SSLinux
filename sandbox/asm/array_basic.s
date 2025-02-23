.text
.global array_add, array_clear

array_add:
	/*FastFunc
		arg
		rax:SrcAddr
		rdi:DstAddr
		rsi:UnitSize(byte)
		rdx:DstLen(count)
		r10:DstFilled(count)
	*/
	check_Full:
		cmpq %r10, %rdx
		jge  then_Full
		jl   else_Full
	then_Full:
		movq $0, %rax
		ret
	else_Full:
		

		movq $1, %rax
		ret
