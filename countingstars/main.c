
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "file_functions.h"

int count_stars(char**, int, int);
void colour_star(char**, int, int, int, int);
void write_result(int, int, int);

int main(int argc, char*argv[])
{
    int m = 0, n = 0, i = 0;
    char **sky = NULL;
    int *dimensions = NULL;


    while((dimensions = read_int_array(0,2)) != NULL)
    {
        m = dimensions[0];
        n = dimensions[1];
        sky = read_char_matrix(0, m, n);
        int stars = count_stars(sky, m, n);
        i++;
        write_result(1, i, stars);
        free_matrix((void**)sky, m);
        free(dimensions);
        dimensions = NULL;
    }
    return 0;
}

int count_stars(char** matrix, int m, int n)
{
    int stars = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (matrix[i][j] == '#')
                continue;
            if (matrix[i][j] == '-')
            {
                stars++;
                colour_star(matrix, m, n, i, j);
            }
        }
    }
    return stars;
}

void colour_star(char** matrix, int m, int n, int i, int j)
{
    /* Check if stars are outside sky bounds */
    if (i >= m || j >= n || i < 0 || j < 0)
        return;
    if (matrix[i][j] == '#')
        return;
    
    /* Mark star point visited */
    matrix[i][j]='#';

    colour_star(matrix, m, n, i, j+1);
    colour_star(matrix, m, n, i+1, j);
    colour_star(matrix, m, n, i, j-1);  
    colour_star(matrix, m, n, i-1, j);
}

void write_result(int fd, int i, int stars)
{
    char result[20];
    snprintf(result, 20, "Case %d: %d\n", i, stars);
    write(fd, result, strlen(result));
}
