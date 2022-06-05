
#ifndef AG1_VECTOR_H
#define AG1_VECTOR_H

#include <stdlib.h>
#include "ring.h"
#include <string.h>


typedef struct Vector Vector;
typedef struct Vector_Info Vector_Info;


Vector_Info* vector_info_init(
    void (*print)(Vector*),
    void (*input)(Vector*),
    void (*print_one)(void*),
    void* (*input_one)(),
    int equals(Vector* A, Vector* B)
) ;



struct Vector* generate_vector(int n, size_t size, Ring* ring_info, Vector_Info* vector_info);

void swap(void* p1, void* p2, size_t size);

int get_n(Vector* vector);

void* get_pointer(Vector* vector);

void set_pointer(Vector* vector, void* pointer);

int equals(Vector* A, Vector* B);

void print(Vector* vector);

void input(Vector* vector);

void print_one(Vector* vector, void* item);

void* input_one(Vector* vector);

void vector_mem(Vector* vector);

Vector* scalr_mult(Vector* A, Vector* B, int* erorr);

Vector* vector_sum(Vector* A, Vector* B, int* erorr);

#endif AG1_VECTOR_H
