
#include "vector.h"
#include "ring.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct Vector {
    int n;
    size_t size_of_one;
    void *pointer;
    Ring *ring_info;
    Vector_Info *info;
} Vector;


typedef struct Vector_Info {
    void (*print)(Vector *vector);

    void (*input)(Vector *vector);

    void (*print_one)(void *num);

    void *(*input_one)();

    int (*equals)(Vector *A, Vector *B);
} Vector_Info;


Vector_Info *vector_info_init(
        void (*print)(Vector *),
        void (*input)(Vector *),
        void (*print_one)(void *),
        void *(*input_one)(),
        int equals(Vector *A, Vector *B)
) {
    Vector_Info *vector_info = calloc(1, sizeof(Vector_Info));
    vector_info->print = print;
    vector_info->input = input;
    vector_info->print_one = print_one;
    vector_info->input_one = input_one;
    vector_info->equals = equals;

    return vector_info;
}



struct Vector *generate_vector(int n, size_t size, Ring *ring_info, Vector_Info *vector_info) {
    Vector *vector = calloc(1, sizeof(Vector));;

    vector->n = n;
    vector->size_of_one = size;

    vector->ring_info = ring_info;
    vector->info = vector_info;


    return vector;
}


int get_n(Vector *vector) {
    return vector->n;
}

void *get_pointer(Vector *vector) {
    return vector->pointer;
}

void set_pointer(Vector *vector, void *pointer) {
    if (pointer) {
        vector->pointer = pointer;
    }

}

int equals(Vector *A, Vector *B) {
    return A->info->equals(A, B);
}

void print(Vector *vector) {
    vector->info->print(vector);

}

void input(Vector *vector) {
    vector->info->input(vector);
}

void print_one(Vector *vector, void *item) {
    vector->info->print_one(item);
}

void *input_one(Vector *vector) {
    return vector->info->input_one();
}

void vector_mem(Vector *vector) {
   vector->pointer = calloc(vector->n, sizeof(void *));
}

Vector *scalr_mult( Vector *A, Vector* B, int *erorr) {
    Vector *C = NULL;
    Vector* res = NULL;
    if (A->pointer && B->pointer) {
		if (A->n == B->n){
			
			C = generate_vector(A->n, A->size_of_one, A->ring_info, A->info);
            res = generate_vector(1, A->size_of_one, A->ring_info, A->info);
            vector_mem(C);
			vector_mem(res);
			size_t size = A->size_of_one;
			int n = A->n;

			for (int i = 0; i < n; i++) {
                void* mult_res = calloc(1, size);
                A->ring_info->scalr_mul((((char*)(A->pointer)) + i * size),
                    (((char*)(B->pointer)) + i * size), mult_res);

                C->ring_info->sum((((char*)(C->pointer )) + i * size), mult_res,
                    (((char*)(C->pointer )) + i * size));
                free(mult_res);

			}
            for (int i = 0; i < n; i++) {
                
                C->ring_info->sum((((char*)(C->pointer)) + i * size), res->pointer,
                    res->pointer);
            }
        }
        else {
            *erorr = 1;
        }
    } else {
        *erorr = 0;
    }
    return C;
}


Vector *vector_sum(Vector *A, Vector *B, int *erorr) {
    Vector *C = NULL;
    if (A->pointer && B->pointer) {
        if (A->n == B->n) {
            int n = get_n(A);
            size_t size = A->size_of_one;
            C = generate_vector(A->n, A->size_of_one, A->ring_info, A->info);
            vector_mem(C);
			
			for (int i = 0; i < n; i++) {
                
                A->ring_info->sum((((char*)(A->pointer)) + i * size),
                    (((char*)(B->pointer )) + i * size),
                    (((char*)(C->pointer )) + i * size));
			}
			

        } else {
            *erorr = 1;
        }
    } else {
        *erorr = 0;
    }
    return C;
}
