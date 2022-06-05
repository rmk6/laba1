
#ifndef MAIN_C_EXEPTIONS_H
#define MAIN_C_EXEPTIONS_H

#include <stdio.h>

enum Erorrs {
    NULL_POINTER,
    INCORRECT_SIZE
};

void exception_handler(const int*, const char* function);

#endif 
