#include "term.h"
#include <stdio.h>
#define Cntl 96
#define Shift 32

int main(void){
	struct termios oldtm, newtm;
	tm_get_termios(&oldtm);
	tm_get_termios(&newtm);

	tm_edit_termios_noncanonical(&newtm);
	tm_set_termios(&newtm);

	int c;
	fflush(stdout);
	tm_clear();
	tm_mvOrg();

printf("hogefugaereki\nhohohohhohohohhoh");
	while(1){
		c = getc(stdin);
		switch (c){
			case 'k': tm_mvUp(); break;
			case 'j': tm_mvDown(); break;
			case 'h': tm_mvLeft(); break;
			case 'l': tm_mvRight(); break;
			case 'k'-Shift: tm_mvUp7(); break;
			case 'j'-Shift: tm_mvDown7(); break;
			case 'h'-Shift: tm_mvLeft7(); break;
			case 'l'-Shift: tm_mvRight7(); break;
			case 'r' : tm_setRevert(); break;
			case '0' : tm_resetFont(); break;
			default : break;
		}
		fflush(stdout);
	}

	tm_resetFont();
	tm_set_termios(&oldtm);
	return 0;
}
	
