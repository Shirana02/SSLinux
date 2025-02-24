#include <stdlib.h>
#include <string.h>

#define cst_access(cstptr,idx) (*(&((*cstptr).body) + idx))
#define cst_getptr(cstptr,idx)   (&((*cstptr).body) + idx)
#define cst_isOOR(cstptr,idxVar) (cstptr->len <= idxVar)

typedef struct _cst{
	int len;
	char body;
} cst;

cst *cst_make(int len);
cst *cst_sizeup(cst *target);
