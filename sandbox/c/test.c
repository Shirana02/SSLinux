#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void){
	printf("read %d\n", PROT_READ);
	printf("writre %d\n", PROT_WRITE);
	printf("read writre %d\n", PROT_WRITE | PROT_READ);
	printf("share %d\n", MAP_SHARED);
	printf("private %d\n", MAP_PRIVATE);
	printf("anon %d\n", MAP_ANONYMOUS);
	printf("private & anon %d\n", MAP_ANONYMOUS | MAP_PRIVATE);
	printf("NULL %p\n", NULL);
	printf("sysconf %ld\n", sysconf(_SC_PAGE_SIZE));


	return 0;
}
