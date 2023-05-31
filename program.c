#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int myplusone(uint8_t in) {
	return in + 1;
}

int main() {
	typedef void (*func_t)(void);

	int pagesize = getpagesize();
	void *code = aligned_alloc(pagesize, 40);
	host_entrypoints.plus_one = myplusone;

	printf("guest_entry is at %p\n", &guest_entrypoints);
	printf("guest_entry.plus_seven is at %p\n", &guest_entrypoints.plus_seven);

	FILE *f = fopen("blob_init", "rb");
	fread(code, 30, 1, f);
	mprotect(code, pagesize,PROT_EXEC);
	((func_t)code)();
	printf("guest_entry.plus_seven is at %p\n", &guest_entrypoints.plus_seven);
}
