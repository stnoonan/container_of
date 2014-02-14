#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "public_public.h"
#include "public_private.h"

public_data_t* init_counter_c() {
    private_container_t *container = calloc(1, sizeof(private_container_t));
    return &container->public_data;
}

bool tag_counter_c(public_data_t *pub, char *tag) {
#if 0
    private_container_t * container = container_of(
            pub, private_container_t, public_data);
#endif
    private_container_t * container = (private_container_t *) (
            (char *)pub - offsetof(private_container_t, public_data));

    size_t new_tag_len = strnlen(tag, MAX_TAG_LEN);
    char *new_tag = calloc(1, new_tag_len);
    if (NULL == new_tag) {
        return false;
    }
    strncpy(new_tag, tag, new_tag_len);
    if (NULL != container->private_tag) {
        free(container->private_tag);
    }
    container->private_tag = new_tag;
    return true;
}
