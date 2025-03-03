#include <termios.h>
int tm_get_termios(struct termios *dst_termios);
int tm_set_termios(struct termios *src_termios);
int tm_edit_termios_noncanonical(struct termios *src_termios);

//ANSI escape seaquence
#define tm_mvOrg() printf("\033[1;1H")
//move1
#define tm_mvUp() printf("\033[A")
#define tm_mvDown() printf("\033[B")
#define tm_mvRight() printf("\033[C")
#define tm_mvLeft() printf("\033[D")
//move7
#define tm_mvUp7() printf("\033[A\033[A\033[A\033[A\033[A\033[A\033[A")
#define tm_mvDown7() printf("\033[B\033[B\033[B\033[B\033[B\033[B\033[B")
#define tm_mvRight7() printf("\033[C\033[C\033[C\033[C\033[C\033[C\033[C")
#define tm_mvLeft7() printf("\033[D\033[D\033[D\033[D\033[D\033[D\033[D")
//clear
#define tm_clear() printf("\033[2J")
//Font
#define tm_resetFont() printf("\033[0m")
#define tm_setBold() printf("\033[1m")
#define tm_setPale() printf("\033[2m")
#define tm_setIta() printf("\033[03")
#define tm_setUnder() printf("\033[4m")
#define tm_setBlink() printf("\033[5m")
#define tm_setQuickBlink() printf("\033[6m")
#define tm_setRevert() printf("\033[7m")
