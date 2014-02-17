#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opaque_public.h"
#include "opaque_private.h"

void increment_counter_o(opaque_container_t *container) {
    ++container->public_counter;
}

uint64_t read_counter_o(opaque_container_t *container) {
    return container->public_counter;
}

opaque_container_t * init_counter_o() {
    opaque_container_t *container = calloc(1, sizeof(opaque_container_t));
    return container;
}

bool tag_counter_o(opaque_container_t * container, char *tag) {
    size_t new_tag_len = strnlen(tag, MAX_TAG_LEN);
    char *new_tag = calloc(1, new_tag_len);
    if (NULL == new_tag) {
        return false;
    }
    strncpy(new_tag, tag, new_tag_len);
    if (container->private_tag) {
        free(container->private_tag);
    }
    container->private_tag = new_tag;
    return true;
}
