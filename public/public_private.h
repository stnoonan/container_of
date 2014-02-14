#ifndef container_of
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})
#endif

#define MAX_TAG_LEN 1024

typedef struct {
    uint64_t private_counter;
    char * private_tag;
    public_data_t public_data;
} private_container_t;
