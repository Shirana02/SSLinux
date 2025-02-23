#include <string.h>
#include <stdlib.h>

typedef struct _text{
	unsigned int len;
	unsigned int limit;
	char *body;
} text;

char *text_Make(unsigned int len, unsigned int limit);
char *text_Delete(char *target);
char *text_Copy_rigid(char *src, char *dst);
char *text_Copy_flex(char *src, char *dst);
