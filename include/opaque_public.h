#include <inttypes.h>
#include <stdbool.h>

typedef struct opaque_container opaque_container_t;

void increment_counter_o(opaque_container_t *);
uint64_t read_counter_o(opaque_container_t *);
opaque_container_t* init_counter_o();
bool tag_counter_o(opaque_container_t *, char *);
