.text
.global mem_mov

mem_mov:
	/*
		-local
			16:
			8 :RemaininagWriteByte
		+arg(RBP)
			0 :HeadAddr
			8 :ByteSize
		ret
			rax:always 1
	*/
	mov_FrontByteLoop:
		movq 
		
