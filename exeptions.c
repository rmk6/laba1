#include "exeptions.h"

void exception_handler(const int* erorr_code, const char* function) {
    if (*erorr_code != -1) {
        printf("===============================================\n");
        printf("An exception was thrown\n");
        printf("Function where was thrown: ");
        printf("%s\n", function);
        printf("error code =");
        printf("%d", *erorr_code);
        if (*erorr_code == 0) {
            printf("Null pointer error!\n");
        }
        else if (*erorr_code == 1) {
            printf("Incorrect sizes!\n");
        }
        printf("===============================================\n");
    }

}

