#include "term.h"
#include "cst.h"
#include <stdio.h>
#define Cntl 96
#define Shift 32

int main(void){
	cst *cstp = cst_make(16);
	char c = 'a';
	for(c = 'a'; c <= 'z'; c++){
		char idx = c - 'a';
		if(cst_isOOR(cstp, idx)){
			cst *oldcstp = cstp;
			cstp = cst_sizeup(cstp);
			if(cstp == oldcstp) goto Exception;
		}
		cst_access(cstp, idx) = c;
		cst_access(cstp, idx+1) = '\0';
		puts(cst_getptr(cstp,0));
	}
	return 0;

	Exception:
	fflush(stdout);
	printf("\nException\n");
	return 1;
}
	
