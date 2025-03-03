#include "cst.h"

cst *cst_make(int len){
	if(len < 0) return NULL;
	cst *ret = (cst *)malloc(sizeof(int) + len + 1);
	if(ret == NULL) return NULL;
	ret->len = len;
	cst_getValue(ret,len) = '\0';
	return ret;
}
cst *cst_sizeup(cst *target){
	cst *newcst = cst_make(target->len * 2);
	if(newcst == NULL) return target;
	memcpy(cst_getPtr(newcst,0), cst_getPtr(target,0), target->len);
	free(target);
	return newcst;
}
int cst_destroy(cst *target){
	free(target);
	return 1;
}
