#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H
#include<unistd.h>

void** alloc_matrix(int m, int n, size_t element_size);

void free_matrix(void **matrix, int m);

int* read_int_array(int file, int m);

/* source file, m, n - dimensions */
char** read_char_matrix(int, int, int);
int** read_int_matrix(int, int, int);

void write_char_matrix(int, int, int, char**);
void write_int_matrix(int, int, int, int**);

char** copy_char_matrix(char **, int, int);

#endif
