#include <stdio.h>
#include "opaque_public.h"
#include "public_public.h"

void test_opaque() {
    opaque_container_t *opaque = init_counter_o();
    increment_counter_o(opaque);
    tag_counter_o(opaque, "opaque");
    fprintf(stderr, "Opaque counter: %"PRIu64"\n", read_counter_o(opaque));
}

void test_public() {
    public_data_t *pub = init_counter_c();
    ++pub->counter;
    tag_counter_c(pub, "public");
    fprintf(stderr, "Public counter: %"PRIu64"\n", pub->counter);
}

int main(int argc, char** argv) {
    test_opaque();
    test_public();
}
