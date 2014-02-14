#include <stdio.h>
#include "public.h"

void test_opaque() {
    opaque_container_t *opaque = init_counter_o();
    increment_counter_o(opaque);
    tag_counter_o(opaque, "opaque");
    fprintf(stderr, "Opaque counter: %lu\n", read_counter_o(opaque));
}

void test_public() {
    public_data_t *pub = init_counter_c();
    ++pub->counter;
    tag_counter_c(pub, "public");
    fprintf(stderr, "Public counter: %lu\n", pub->counter);
}

int main(int argc, char** argv) {
    test_opaque();
    test_public();
}
