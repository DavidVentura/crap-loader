#include <stdint.h>
typedef int (*plus_oner_t)(uint8_t);

typedef struct host_entrypoint_s {
	plus_oner_t plus_one;
} host_entrypoint_t;

typedef struct guest_entrypoint_s {
	plus_oner_t plus_seven;
} guest_entrypoint_t;

host_entrypoint_t __attribute__((section (".host_functionality"))) host_entrypoints;
guest_entrypoint_t __attribute__((section (".guest_functionality"))) guest_entrypoints;
