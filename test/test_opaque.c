#include <stdio.h>
#include <stdlib.h>
#include "opaque_public.h"

void test_opaque(int iterations) {
    opaque_container_t *opaque = init_counter_o();
    for (uint ii=0; ii < iterations; ++ii) {
        increment_counter_o(opaque);
    }
    tag_counter_o(opaque, "opaque");
    fprintf(stderr, "Opaque counter: %"PRIu64"\n", read_counter_o(opaque));
}

int main(int argc, char** argv) {
    test_opaque(atol(argv[1]));
}
