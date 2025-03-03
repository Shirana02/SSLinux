#include "term.h"
#include "cst.h"
#include "plist.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define Cntl 96
#define Shift 32


int main(void){
	cst *path = cst_make(PATH_MAX);
	getcwd(&(path->body), PATH_MAX);

	DIR *dir = opendir(&(path->body));
	struct dirent *dent;

	plist *dlist = plist_make();

	int i = 0;
	while(1){
		printf("%d %d\n", i, dlist->len); //test code
		dent = readdir(dir);
		if(dent == NULL) break;
		int len = strlen(dent->d_name);
		cst *dname = cst_make(len);
		memcpy(cst_getPtr(dname,0), dent->d_name, len);
		plist_insert(dlist, 65535, NULL, 0);
		cst *idx_i_body = plist_getItemBody(dlist, i);
		idx_i_body = dname;
		/*
		printf("getItemBody() = %p\n", plist_getItemBody(dlist, i));
		printf("idx_i_body = %p\n", idx_i_body);
		printf("dname = %p\n", idx_i_body);
		*/
		i++;
	}

	i = 1;
	cst *dirname = (cst *)plist_getItemBody(dlist,i);
	printf("%s\n", (char *)cst_getPtr(dirname, i));
		
	return 0;
}
	
