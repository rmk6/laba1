# CMakeList.txt: проект CMake для CMakeProject1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.20)

# Добавьте источник в исполняемый файл этого проекта.

add_executable(CMakeProject1 main.c vector.h vector.c vector_int.h vector_int.c ring.h ring.c vector_double.c vector_double.h vector_comp.h vector_comp.c tests.h tests.c filereader.c filereader.h exeptions.h exeptions.c)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.