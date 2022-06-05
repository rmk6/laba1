#include <stdio.h>
#include <stdlib.h>
#include "vector_comp.h"
#include "vector_double.h"
#include "vector_int.h"
#include "tests.h"
#include "exeptions.h"

int data_type_selection() {
    int data_type = 0;
    printf("Please select the data type\n    1. integer\n    2. float\n    3. ccomplex \n    4. Work with current vectors\n    5. exit\n");
    scanf("%d", &data_type);
    return data_type;
}
int vector_operation() {
    int selection = 0;
    printf("Please select operation:\n    1. Vector sum\n    2. Vector scalar mult\n    3. tests\n    4. exit\n");
    scanf("%d: ", &selection);
    return selection;
}

Vector * set_vector_type(int data_type, int* size) {
    Vector* vector = NULL;
    if (data_type == 1) {
        vector = generate_int_vector(size[0]);
    }
    else if (data_type == 2) {
        vector = generate_float_vector(size[0]);
    }
    else if (data_type == 3) {
        vector = generate_complex_vector(size[0]);
    }
    return vector;
}

int* input_vector_size(char* title) {
    printf("Vector %s\n", title);

    int* arr = calloc(1, sizeof(int));
    printf("input n :");
    scanf("%d: ", &arr[0]);

    return arr;
}


void menu() {

    int data_type = 0;
    int operation = 0;
    int* error = calloc(1, sizeof(int));
    *error = -1;

    Vector* A = NULL;
    Vector* B = NULL;
    Vector* C = NULL;

    printf("laba 1\n");

    while (1) {
        data_type = data_type_selection();

        if (data_type == 5) {

            break;
        }
        operation = vector_operation();

        if (operation == 1) {
            if (data_type != 4) {
                A = set_vector_type(data_type, input_vector_size("A"));
                B = set_vector_type(data_type, input_vector_size("B"));
            }

            if (A != NULL && B != NULL) {
                if (data_type != 4) {
                    printf("Vector A\n");

                    input(A);
                }

                if (data_type != 4) {
                    printf("Vector B\n");
                    input(B);
                }

                printf("Vector A\n");
                print(A);

                printf("Vector B\n");
                print(B);

                printf("\n");
                printf("A + B =");

                C = vector_sum(A, B, error);
                exception_handler(error, "vector_sum");
                if (C != NULL)
                    print(C);
                else
                    printf("Error, result vector has NULL pointer!\n");

                printf("\n");
            }
            else
                printf("Error, result vector has NULL pointer!\n");
        }
        if (operation == 2) {
            if (data_type != 4) {
                A = set_vector_type(data_type, input_vector_size("A"));
                B = set_vector_type(data_type, input_vector_size("B"));
            }

            if (A != NULL && B != NULL) {


                if (data_type != 4) {
                    printf("Vector A\n");

                    input(A);
                }

                if (data_type != 4) {
                    printf("Vector B\n");
                    input(B);
                }
                printf("Vector A\n");
                print(A);

                printf("Vector B\n");
                print(B);
                C = scalr_mult(A, B, error);
                exception_handler(error, "vector_mult");

                printf("A x B =");
                if (C != NULL)
                    print(C);
                else
                    printf("Error, result vector has NULL pointer!\n");

                printf("\n");
            }
            else {
                printf("Error, result vector has NULL pointer!\n");
            }
        }

        if (operation == 3) {
            IntSumTest();
            vectorSumTest();
            vectorMultTest();

        }

    }
}

int main()
{

    menu();
    return 0;
}
