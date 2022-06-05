
#include "vector_double.h"



void sum_float(void* a, void* b, void* dst) {
    double* pa = (double*)a;
    double* pb = (double*)b;

    *(double*)dst = *pa + *pb;
}

void get_opposite_float(void* a, void* dst) {
    double* pa = (double*)a;

    *(double*)dst = *pa * -1;
}

void mult_float(void* k, void* a, void* dst) {
    double* pk = (double*)k;
    double* pa = (double*)a;

    *(double*)dst = *pk * *pa;
}

void subtraction_float(void* a, void* b, void* dst) {
    double* pa = (double*)a;
    double* pb = (double*)b;

    *(double*)dst = *pa - *pb;
}

void input_float_vector(Vector* vector) {
    double* data = calloc(get_n(vector), sizeof(double));
    for (int i = 0; i < get_n(vector); i++) {
        printf("vector[%d]= ", i);
        scanf("%lf", &data[i]);
    }

    set_pointer(vector, (void*)data);
    //printf("%p\n", get_pointer(vector));
}

void print_float_vector(Vector* vector) {
    printf("\n");
    double* data = (double*)get_pointer(vector);
    for (int i = 0; i < get_n(vector); i++) {

        printf("%.2lf ", data[i]);
        printf("\n");
    }
}

void print_float(void* num) {
    double* pa = (double*)num;
    printf("%.2lf\n", *pa);
}
void* input_one_float() {
    double* res = calloc(1, sizeof(double));
    scanf("%lf", res);
    return (void*)res;
}

int equals_float(Vector* A, Vector* B) {

    int n1 = get_n(A);
    int n2 = get_n(B);

    int condition = 1;
    if (n1 == n2) {
        double* pA = (double*)get_pointer(A);
        double* pB = (double*)get_pointer(B);
        for (int i = 0; i < n1; i++) {

            if (pA[i] != pB[i]) {
            condition = 0;
                
            }
        }
    }
    return condition;
}
Vector* generate_float_vector(int n) {
    double* ONE = calloc(1, sizeof(double));
    double* ZERO = calloc(1, sizeof(double));
    *ONE = 1.0f;
    *ZERO = 0.0f;
    Ring* ring_info = create_ring(sum_float, mult_float, subtraction_float, get_opposite_float, ONE, ZERO);
    Vector_Info* vectorInfo = vector_info_init(print_float_vector, input_float_vector, print_float, input_one_float, equals_float);
    Vector* new = generate_vector(n, sizeof(double), ring_info, vectorInfo);
    return new;
}
