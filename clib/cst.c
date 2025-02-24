#include "cst.h"

cst *cst_make(int len){
	if(len < 0) return NULL;
	cst *ret = (cst *)malloc(sizeof(int) + len + 1);
	if(ret == NULL) return NULL;
	ret->len = len;
	cst_access(ret,len) = '\0';
	return ret;
}
cst *cst_sizeup(cst *target){
	cst *newcst = cst_make(target->len * 2);
	if(newcst == NULL) return target;
	memcpy(cst_getptr(newcst,0), cst_getptr(target,0), target->len);
	free(target);
	return newcst;
}
