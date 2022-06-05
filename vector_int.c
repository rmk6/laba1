
#include "vector_int.h"


void sum_int(void *a, void *b, void *dst) {
    int *pa = (int *) a;
    int *pb = (int *) b;

    *(int *) dst = *pa + *pb;
} 

void get_opposite_int(void *a, void *dst) {
    int *pa = (int *) a;

    *(int *) dst = *pa * -1;
}

void mult_int(void *k, void *a, void *dst) {
    int *pk = (int *) k;
    int *pa = (int *) a;

    *(int *) dst = *pk * *pa;
} 

void subtraction_int(void *a, void *b, void *dst) {
    int *pa = (int *) a;
    int *pb = (int *) b;

    *(int *) dst = *pa - *pb;
} 

void input_int_vector (Vector *vector) {
    int *data = calloc(get_n(vector), sizeof(int ));
    for (int i = 0; i < get_n(vector); i++) {
        printf("vector[%d]= ", i);
        scanf("%d", &data[i]);
    }
    set_pointer(vector, (void *) data);
}

void print_int_vector(Vector *vector) {
    printf("\n");
    int *data = (int *) get_pointer(vector);
    for (int i = 0; i < get_n(vector); i++) {
        printf("%d ", data[i]);
        printf("\n");
    }
}

void print_int(void *num) {
    int *pa = (int *) num;
    printf("%d\n", *pa);
}

void *input_one_int() {
    int *res = calloc(1, sizeof(int));
    scanf("%d", res);
    return (void *) res;
}

int equals_int(Vector *A, Vector *B) {
    int n1 = get_n(A);
    int n2 = get_n(B);
    int condition = 1;

    if (n1 == n2) {
        int *pA = (int *) get_pointer(A);
        int *pB = (int *) get_pointer(B);
        for (int i = 0; i < n1; i++) {
            if (pA[i] != pB[i]) {
				condition = 0;
            }
        }
    }
    return condition;
}

Vector *generate_int_vector(int n) {
    int *ONE = calloc(1, sizeof(int));
    int *ZERO = calloc(1, sizeof(int));
    *ONE = 1;
    *ZERO = 0;
    Ring *ring_info = create_ring(sum_int, mult_int, subtraction_int, get_opposite_int, ONE, ZERO);
    Vector_Info *vectorInfo = vector_info_init(print_int_vector, input_int_vector, print_int, input_one_int,equals_int);
    Vector *new = generate_vector(n, sizeof(int), ring_info, vectorInfo);
    return new;
}
