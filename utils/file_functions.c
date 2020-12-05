#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void** alloc_matrix(int m, int n, size_t element_size)
{
    void **matrix = malloc(m * sizeof(void*));
    for(int i=0; i<m; i++)
    {
        matrix[i] = malloc(n * element_size);
    }
    return matrix;
}

void free_matrix(void **matrix, int m)
{
    for(int i=0; i<m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
}

int* read_int_array(int file, int m)
{
    int i = 0;
    char *mstr;
    char line[100];
    int *array = (int*) malloc(m * sizeof(int));

    do {
        if (read(file, &line[i], sizeof(char)) == 0)
        {
            return NULL;
        }
    } while (line[i++] != '\n' && i < 100);

    mstr = strtok(line, " \n");
    i=0;
    while (i < m)
    {
        array[i] = atoi(mstr);
        mstr = strtok(NULL, " \n");
        i++;
    }
    return array;
}

/* source file, m, n - dimensions */
char** read_char_matrix(int file, int m, int n)
{
    char **matrix = (char**) alloc_matrix(m, n, sizeof(char));
    char c;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            read(file, &matrix[i][j], sizeof(char));
        }

        read(file, &c, sizeof(char));
    }
    return matrix;
}

/* source file, m, n - dimensions */
int** read_int_matrix(int file, int m, int n)
{
    int **matrix = (int**) alloc_matrix(m, n, sizeof(int));
    char c, d;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            read(file, &d, sizeof(char));
            matrix[i][j]=d-'0';
        }

        read(file, &c, sizeof(char));
    }
    return matrix;
}

void write_char_matrix(int file, int m, int n, char** matrix)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            write(file, &matrix[i][j], sizeof(char));
        }

        write(file, "\n", sizeof(char));
    }
}

void write_int_matrix(int file, int m, int n, int** matrix)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            write(file, &matrix[i][j], sizeof(char));
        }

        write(file, "\n", sizeof(char));
    }
}

char** copy_char_matrix(char **matrix, int m, int n)
{
    char **copy = (char**)alloc_matrix(m, n, sizeof(char));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            copy[i][j] = matrix[i][j];
        }
    }
    return copy;
}
