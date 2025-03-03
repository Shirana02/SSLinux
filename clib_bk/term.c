#include "term.h"
int tm_get_termios(struct termios *dst_termios){
	tcgetattr(0, dst_termios); 
	return 1;
}

int tm_set_termios(struct termios *src_termios){
	int ret;
	ret = tcsetattr(0, TCSANOW, src_termios);
	if(ret == 0){
		return 1;
	}else{
		return 0;
	}
}
int tm_edit_termios_noncanonical(struct termios *src_termios){
	src_termios->c_lflag &= ~(ICANON | ECHO);
	src_termios->c_cc[VMIN] = 1;
	src_termios->c_cc[VTIME] = 0;
	return 1;
}
