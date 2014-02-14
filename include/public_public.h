#include <inttypes.h>
#include <stdbool.h>

typedef struct {
    uint64_t counter;
} public_data_t;

public_data_t* init_counter_c();
bool tag_counter_c(public_data_t *, char *);
