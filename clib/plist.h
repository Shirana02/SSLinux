#include <stdlib.h>
#include <string.h>

typedef struct _plistItem{
	struct _plistItem *next;
	void *body;
} plistItem;
typedef struct _plist{
	int len;
	plistItem *idx_0;
} plist;

plist *plist_make();
int  plist_insert(plist *list, int idx, void *dataPtr, int dataSize);
int  plist_remove(plist *list, int idx);
void *plist_getItemBody(plist *list, int idx);
int  plist_destroy(plist *list);
