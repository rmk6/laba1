
#ifndef AG1_RING_H
#define AG1_RING_H



typedef struct Ring {
    void (*sum)(void* a, void* b, void* dst);

    void (*scalr_mul)(void* k, void* a, void* dst);

    void (*subtraction)(void* a, void* b, void* dst);

    void (*get_opposite)(void* a, void* dst);

    void* one;
    void* zero;

} Ring;

Ring* create_ring(
    void (*sum)(void*, void*, void*),
    void (*scalr_mul)(void* k, void* a, void*),
    void (*subtraction)(void* a, void* b, void*),
    void (*get_opposite)(void* a, void* dst),
    void* one,
    void* zero);


#endif //AG1_RING_H
