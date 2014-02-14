#define MAX_TAG_LEN 1024

struct opaque_container {
    uint64_t private_counter;
    char * private_tag;
    uint64_t public_counter;
};
