#include "ring.h"
#include <stdlib.h>

Ring* create_ring(
    void (*sum)(void*, void*, void*),
    void (*scalr_mul)(void* k, void* a, void*),
    void (*subtraction)(void* a, void* b, void*),
    void (*get_opposite)(void* a, void* dst),
    void* one,
    void* zero) {

    Ring* ring = calloc(1, sizeof(Ring));
    ring->sum = sum;
    ring->subtraction = subtraction;
    ring->scalr_mul = scalr_mul;
    ring->one = one;
    ring->zero = zero;
    ring->get_opposite = get_opposite;

    return ring;
}
