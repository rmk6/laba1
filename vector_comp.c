
#include "vector_comp.h"


typedef struct ComplexNum {
    double Re;
    double Im;
} ComplexNum;


void sum_complex(void *a, void *b, void *dst) {
    ComplexNum *pa = (ComplexNum *) a;
    ComplexNum *pb = (ComplexNum *) b;

    ((ComplexNum *) dst)->Re = (pa->Re + pb->Re);
    ((ComplexNum *) dst)->Im = (pa->Im + pb->Im);

}

void get_opposite_complex(void *a, void *dst) {
    ComplexNum *pa = (ComplexNum *) a;


    ((ComplexNum *) dst)->Re = (pa->Re * -1);
    ((ComplexNum *) dst)->Im = (pa->Im * -1);
}

void mult_complex(void *k, void *a, void *dst) {
    ComplexNum *pa = (ComplexNum *) a;
    ComplexNum *pk = (ComplexNum *) k;

    ((ComplexNum *) dst)->Re = (pa->Re * pk->Re) - (pa->Im * pk->Im);
    ((ComplexNum *) dst)->Im = (pa->Re * pk->Im) + (pa->Im * pk->Re);

}

void subtraction_complex(void *a, void *b, void *dst) {
    ComplexNum *pa = (ComplexNum *) a;
    ComplexNum *pb = (ComplexNum *) b;

    ((ComplexNum *) dst)->Re = (pa->Re - pb->Re);
    ((ComplexNum *) dst)->Im = (pa->Im - pb->Im);
}

void input_complex_vector(Vector *vector) {
    ComplexNum *data = calloc(get_n(vector), sizeof(ComplexNum *));
    for (int i = 0; i < get_n(vector); i++) {

            printf("Re vector[%d] = ", i);
            scanf("%lf", &data[i].Re);
            printf("Im vector[%d] = ", i);
            scanf("%lf", &data[i].Im);
    }
    set_pointer(vector, (void *) data);
}

void print_complex_vector(Vector *vector) {
    ComplexNum *data = (ComplexNum *) get_pointer(vector);
    for (int i = 0; i < get_n(vector); i++) {
        if (data[i].Im == 0)
            printf(" (%lf + 0i) ", data[i].Im);
        if (data[i].Im < 0)
            printf(" (%.2lf - i%.2lf) ", data[i].Re, data[i].Im);
        if (data[i].Im > 0)
            printf(" (%.2lf + i%.2lf) ", data[i].Re, data[i].Im);
        printf("\n");
    }
}

void print_complex(void *num) {
    ComplexNum* pa = (ComplexNum*)num;
    if (pa->Im == 0)
        printf(" (%lf + 0i) \n", pa->Im);
    if (pa->Im < 0)
        printf(" (%.2lf - i%.2lf) \n", pa->Re, pa->Im);
    if (pa->Im > 0)
        printf(" (%.2lf + i%.2lf) \n", pa->Re, pa->Im);
}

void *input_one_complex() {
    ComplexNum *res = calloc(1, sizeof(ComplexNum));
    scanf("Re %lf", &res->Re);
    scanf("Im %lf", &res->Im);
    return (void *) res;
}

int equals_complex(Vector *A, Vector *B) {
    int n1 = get_n(A);
    int n2 = get_n(B);
    int condition = 1;
    if (n1 == n2) {
        ComplexNum *pA = (ComplexNum *) get_pointer(A);
        ComplexNum *pB = (ComplexNum *) get_pointer(B);
        for (int i = 0; i < n1; i++) {
            if (pA[i].Re != pB[i].Re || pA[i].Im != pB[i].Im) {
                condition = 0;
            }
        }
    }
    return condition;
}

Vector *generate_complex_vector(int n) {
    ComplexNum *ONE = calloc(1, sizeof(ComplexNum));
    ComplexNum *ZERO = calloc(1, sizeof(ComplexNum));
    ONE->Re = 1.0f;
    ONE->Im = 0.0f;
    ZERO->Re = 0.0f;
    ZERO->Im = 0.0f;

    Ring *ring_info = create_ring(sum_complex, mult_complex, subtraction_complex, get_opposite_complex, ONE, ZERO);
    Vector_Info *vectorInfo = vector_info_init(print_complex_vector, input_complex_vector, print_complex,
        input_one_complex, equals_complex);
    Vector *new = generate_vector(n, sizeof(ComplexNum), ring_info, vectorInfo);
    return new;
}