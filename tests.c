#include "tests.h"
#include "filereader.h"

char *BASE_DIR = "C:/Users/Milana/Documents/CMakeProject1/CMakeProject1/";

void IntSumTest() {

    printf("SUM of integer test\n");
    char* file_name = "C:/Users/Milana/Documents/CMakeProject1/CMakeProject1/IntSum.txt";

    FILE *fp = fopen(file_name, "r");
    if (fp!=NULL) {

        char *string = freadline(fp);
        int *indexes = NULL;
        int *a = NULL;
        int *b = NULL;
        int *res = NULL;
  
        while (string) {

            if (string[0] == '(' && string[strlen(string) - 1] == ')') {
                string = remove_chars(string, 0); // first (
                string = remove_chars(string, (int) strlen(string) - 1); // second )
                int test_number = atoi(string);
                printf("Test %d\n", test_number);
            } else if (string[0] == 'a') {
                a = calloc(1, sizeof(int));
                string = cut_sting(string, 4);
                *a = atoi(string);

            } else if (string[0] == 'b') {
                b = calloc(1, sizeof(int));
                string = cut_sting(string, 4);
                *b = atoi(string);
            } else if (string[0] == 'r') {
                res = calloc(1, sizeof(int));
                string = cut_sting(string, 6);
                *res = atoi(string);
            }
            if (a && b && res) {

                if (*a + *b == *res) {
                    printf("OK\n");
                } else {
                    printf("ERROR\n");
                }
                a = NULL;
                b = NULL;
                res = NULL;
            }


            string = freadline(fp);
        }
        fclose(fp);-411.
    }
    else {
        printf("NULL");
    }
}
// ок
void vectorSumTest() {
    printf("SUM of integer Vector\n");
    char* file_name = "C:/Users/Milana/Documents/CMakeProject1/CMakeProject1/VectorSum.txt";
    FILE *fp = fopen(file_name, "r");
    int erorr = -1;0;
    if (fp) {

        char *string = freadline(fp);

        int *indexes = NULL;
        Vector *A = NULL;
        Vector *B = NULL;
        Vector *C = NULL;
        int isA = 0;
        int isB = 0;
        int isC = 0;
        int n1 = 0; 
        int n2 = 0;
        while (string) {

            if (string[0] == '(' && string[strlen(string) - 1] == ')') {
                string = remove_chars(string, 0);
                string = remove_chars(string, (int) strlen(string) - 1);
                int test_number = atoi(string);
                printf("Test %d\n", test_number);
            } else if (string[0] == 'n' && string[1] == '1') {
                string = cut_sting(string, 5);
                n1 = atoi(string);
            } else if (string[0] == 'n' && string[1] == '2') {
                string = cut_sting(string, 5);
                n2 = atoi(string);
            } else if (n1 != 0 && n1 != 0 ) {


                if (string[0] == 'A') {
                    A = generate_int_vector(n1);
                    vector_mem(A);
                    int *pA = (int *) get_pointer(A);
                    for (int i = 0; i < n1; i++) {
                        fscanf(fp, "%d", &pA[i]);                       
                    }
                    set_pointer(A, (void *) pA);
                    isA = 1;

                } else if (string[0] == 'B') {
                    B = generate_int_vector(n2);
                    vector_mem(B);
                    int *pB = (int *) get_pointer(B);
                    for (int i = 0; i < n2; i++) {
                        fscanf(fp, "%d", &pB[i]);
                    }
                    set_pointer(B, (void *) pB);
                    isB = 1;
					
                } else if (string[0] == 'R') {
                    C = generate_int_vector(n1);
                    vector_mem(C);
                    int *pR = (int *) get_pointer(C);
                    for (int i = 0; i < n2; i++) {
                        fscanf(fp, "%d", &pR[i]);
                    }
                    set_pointer(C, (void *) pR);
                    isC = 1;

                }
                if (isA && isB && isC) {


                    if (equals(vector_sum(A, B, &erorr), C) == 1) {
                        printf("OK\n");
                    } else {
                        printf("ERROR\n");
                    }

                    n1 = 0;
                    n2 = 0;
                    isA = 0;
                    isB = 0;
                    isC = 0;
                }

            }

            string = freadline(fp);
        }
    }

}
// ok

void vectorMultTest() {
    printf("MULT of integer Vectors\n");
    char *file_name = sumStrings(BASE_DIR, "VectorMult.txt");
    FILE *fp = fopen(file_name, "r");
    int erorr = -1;
    if (fp) {
        char *string = freadline(fp);

        int *indexes = NULL;
        Vector *A = NULL;
        Vector *B = NULL;
        Vector *C = NULL;
        int isA = 0;
        int isB = 0;
        int isC = 0;
        int n1 = 0;
        int n2 = 0;
        while (string) {

            if (string[0] == '(' && string[strlen(string) - 1] == ')') {
                string = remove_chars(string, 0);
                string = remove_chars(string, (int) strlen(string) - 1);
                int test_number = atoi(string);
                printf("Test %d\n", test_number);
            } else if (string[0] == 'n' && string[1] == '1') {
                string = cut_sting(string, 5);
                n1 = atoi(string);
            } else if (string[0] == 'n' && string[1] == '2') {
                string = cut_sting(string, 5);
                n2 = atoi(string);

            } else if (n1 != 0 && n2 != 0) {


                if (string[0] == 'A') {
                    A = generate_int_vector(n1);
                    vector_mem(A);

                    int *pA = (int *) get_pointer(A);
                    for (int i = 0; i < n1; i++) {
                        fscanf(fp, "%d", &pA[i]);
                    }
                    set_pointer(A, (void *) pA);
                    isA = 1;

                } else if (string[0] == 'B') {
                    B = generate_int_vector(n2);
                    vector_mem(B);
                    int *pB = (int *) get_pointer(B);
                    for (int i = 0; i < n2; i++) {
                            fscanf(fp, "%d", &pB[i]);
                    }
                    set_pointer(B, (void *) pB);
                    isB = 1;
					
                } else if (string[0] == 'R') {
                    C = generate_int_vector(n1);
                    vector_mem(C);

                    int *pR = (int *) get_pointer(C);
                    for (int i = 0; i < n1; i++) {
                            fscanf(fp, "%d", &pR[i]);
                    }
                    set_pointer(C, (void *) pR);
                    isC = 1;

                }
                if (isA && isB && isC) {


                    if (equals(scalr_mult(A, B, &erorr), C) == 1) {
                        printf("OK\n");
                    } else {
                        printf("ERROR\n");
                    }

                    n1 = 0;
                    n2 = 0;
                    isA = 0;
                    isB = 0;
                    isC = 0;
                }
            }

            string = freadline(fp);
        }
    }

}
// готово