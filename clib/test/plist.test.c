#include "plist.h"
#include <stdio.h>

void test_showIntItems(plist *list){
	int i;
	printf("  len = %d; ", list->len);
	for(i = 0; i < list->len; i++){
		printf("%d-", *((int*)plist_getItemBody(list, i)));
	}
	printf("\n");
}
void test_showStrItems(plist *list){
	int i;
	printf("  len = %d; ", list->len);
	for(i = 0; i < list->len; i++){
		printf("%s-", (char*)plist_getItemBody(list, i));
	}
	printf("\n");
}

int main(void){
	plist *list;
	list = plist_make();

	printf("\ncase 1 : int ptr\n");
		int src[5] = {0, 1, 2, 3, 4};

		plist_insert(list, 100, (src + 0), 4);
		printf("? len = 1; 0\n");
		test_showIntItems(list);

		plist_insert(list, 0, (src + 1), 4);
		printf("? len = 2; 1-0\n");
		test_showIntItems(list);

		plist_insert(list, 100, (src + 2), 4);
		printf("? len = 3; 1-0-2\n");
		test_showIntItems(list);

		plist_insert(list, 3, (src + 3), 4);
		printf("? len = 4; 1-0-2-3\n");
		test_showIntItems(list);

		plist_insert(list, 3, (src + 4), 4);
		printf("? len = 5; 1-0-2-4-3\n");
		test_showIntItems(list);

		plist_remove(list, 0);
		printf("? len = 4; 0-2-4-3\n");
		test_showIntItems(list);

		plist_remove(list, 1);
		printf("? len = 3; 0-4-3\n");
		test_showIntItems(list);

		plist_remove(list, 2);
		printf("? len = 2; 0-4\n");
		test_showIntItems(list);

		plist_destroy(list);

	printf("\n\ncase 2 : char ptr\n");
		int i;
		char *str0 = malloc(5);
		char *str1 = malloc(2);
		char *str2 = malloc(3);
		char *str3 = malloc(2);
		char *str4 = malloc(5);
		for(i = 0; i < 4; i++){str0[i] = 'A'+i;} str0[i]='\0';
		for(i = 0; i < 1; i++){str1[i] = 'C'+i;} str1[i]='\0';
		for(i = 0; i < 2; i++){str2[i] = 'B'+i;} str2[i]='\0';
		for(i = 0; i < 1; i++){str3[i] = 'A'+i;} str3[i]='\0';
		for(i = 0; i < 4; i++){str4[i] = 'a'+i;} str4[i]='\0';

		list = plist_make();
		plistItem *item;

		plist_insert(list, 100, NULL, 0);
		item = plist_getItem(list, 0);
		item->body = str0;
		printf("? len = 1; ABCD-\n");
		test_showStrItems(list);

		plist_insert(list, 0, NULL, 0);
		item = plist_getItem(list, 0);
		item->body = str1;
		printf("? len = 2; C-ABCD-\n");
		test_showStrItems(list);
		
		plist_insert(list, 2, NULL, 0);
		item = plist_getItem(list, 2);
		item->body = str2;
		printf("? len = 3; C-ABCD-BC-\n");
		test_showStrItems(list);

		plist_insert(list, 2, NULL, 0);
		item = plist_getItem(list, 2);
		item->body = str3;
		printf("? len = 4; C-ABCD-A-BC-\n");
		test_showStrItems(list);
		
		plist_insert(list, 100, NULL, 0);
		item = plist_getItem(list, 4);
		item->body = str4;
		printf("? len = 5; C-ABCD-A-BC-abcd-\n");
		test_showStrItems(list);

		plist_remove(list, 1);
		printf("? len = 4; C-A-BC-abcd-\n");
		test_showStrItems(list);

		plist_remove(list, 3);
		printf("? len = 3; C-A-BC-\n");
		test_showStrItems(list);

		int ret;
		ret = plist_remove(list, 5);
		printf("? out of range --> return 0\n");
		if(ret == 0){
			printf("  yes! return 0.");
		}
	return 0;
}
