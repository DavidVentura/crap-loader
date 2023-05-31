#include "interface.h"

int plus_seven(uint8_t in) {
	return in + 7;
}
void __attribute__((section (".guest_init"))) guest_init() {
	guest_entrypoints.plus_seven = plus_seven;
}
