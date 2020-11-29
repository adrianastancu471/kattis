#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H
#include<unistd.h>

void** alloc_matrix(int m, int n, size_t element_size);

void free_matrix(void **matrix, int m);

int* read_int_array(int file, int m);

/* source file, m, n - dimensions */
char** read_char_matrix(int file, int m, int n);
#endif