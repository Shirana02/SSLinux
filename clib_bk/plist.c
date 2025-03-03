#include "plist.h"

//private
plistItem *_getItem_idx(plist *list, int idx){
	plistItem *currentPtr = list->idx_0; //this is the item at index 0
	int i;
	for(i = 0; i < idx; i++){
		if(currentPtr->next == NULL){
			return NULL;
		}
		currentPtr = currentPtr->next;
	}
	return currentPtr;
}
int _bindItem(plist *list, plistItem *item, int idx){
	if(list->len == 0){
		list->idx_0 = item;
		list->len++;
		return 1;
	}
	if(idx <= 0){
		item->next = list->idx_0;
		list->idx_0 = item;
	}else if(0 < idx && idx < list->len){
		plistItem *prevItem = _getItem_idx(list, idx - 1);
		if(prevItem == NULL){
			return 0;
		}
		plistItem *nextItem = prevItem->next;
		item->next = nextItem;
		prevItem->next = item;
	}else{
		plistItem *prevItem = _getItem_idx(list, list->len - 1);
		plistItem *nextItem = NULL;
		item->next = nextItem;
		prevItem->next = item;
		return 0;
	}
	list->len++;
	return 1;
}
int _remove_thisPtr(plistItem *prevItem, plistItem *targetItem, plistItem *nextItem){
	free(targetItem);
	prevItem->next = nextItem;
	return 1;
}

	
//public
plist *plist_make(){
	plist * ret = malloc(sizeof(int) * 2 + sizeof(void *));
	if(ret == NULL) return NULL;
	ret->len = 0;
	return ret;
}
int  plist_insert(plist *list, int idx, void *dataPtr, int dataSize){
	if(dataSize < 0) return 0;
	int result;
	void *body;
	if(dataSize != 0 && dataPtr != NULL){
		 body = malloc(dataSize);
		if(body == NULL) return 0;
	}else{
		body = NULL;
	}
	plistItem *listItem;
	listItem = malloc(sizeof(plistItem));
	if(listItem == NULL){
		if(body != NULL){
			free(body);
		}
		return 0;
	}
	listItem->next = NULL;
	listItem->body = body;
	if(body != NULL){
		memcpy(body, dataPtr, dataSize);
	}
	
	result = _bindItem(list, listItem, idx);
	if(result == 0){
		if(dataPtr != NULL){
			free(body);
		}
		free(listItem);
		return 0;
	}
	return 1;
}

int plist_remove(plist *list, int idx){
	if(idx == 0){
		if(list->len == 0) return 0;
		plistItem *prevItem = list->idx_0;
		plistItem *targetItem = prevItem->next;
		plistItem *nextItem = targetItem->next;
		_remove_thisPtr(prevItem, targetItem, nextItem);
		list->len--;
	}else if(0 < idx){
		plistItem *prevItem = _getItem_idx(list, idx - 1);
		plistItem *targetItem = prevItem->next;
		plistItem *nextItem = targetItem->next;
		_remove_thisPtr(prevItem, targetItem, nextItem);
		list->len--;
	}else{
		return 0;
	}
}
void *plist_getItemBody(plist *list, int idx){
	if(list->len <= idx) return NULL;
	plistItem *target;
	target = _getItem_idx(list, idx);
	return target->body;
}

int plist_destroy(plist *list){
	int i;
	plistItem *prevItem = NULL;
	plistItem *currentItem = list->idx_0;
	for(i = 0; i < list->len; i++){
		prevItem = currentItem;
		currentItem = currentItem->next;
		if(prevItem->body == NULL) continue;
		free(prevItem->body);
	}
	free(list);
	return 1;
}
