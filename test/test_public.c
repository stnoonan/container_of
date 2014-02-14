#include <stdio.h>
#include <stdlib.h>
#include "public_public.h"

void test_public(int iterations) {
    public_data_t *pub = init_counter_c();
    for (int ii=0; ii<iterations; ++ii) {
        ++pub->counter;
    }
    tag_counter_c(pub, "public");
    fprintf(stderr, "Public counter: %"PRIu64"\n", pub->counter);
}

int main(int argc, char** argv) {
    test_public(atol(argv[1]));
}
