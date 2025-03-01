#include "term.h"
#include "cst.h"
#include "plist.h"
#include <stdio.h>
#define Cntl 96
#define Shift 32

#include <stdlib.h>

int main(void){
	plist *list = plist_make(sizeof(int));
	int i, j;
	for(i = 1; i < 10; i++){
		int res = plist_insert(list, list->len, &i, 4);
		for(j = 0; j < i; j++){
			printf("[%d]-", *(int*)plist_getItemBody(list, j));
		}
		printf("\n");
	}
	for(j = 0; j < list->len; j++){
		printf("[%d]-", *(int*)plist_getItemBody(list, j));
	}
	printf("\n");
	plist_destroy(list);
	return 0;
}
	
