#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_functions.h"

void fill_path(int**, int*, int, int, int, int);
void fill_map(int**, int*);

int main(int argc, char* argv[])
{
	int *dim = read_int_array(0,2);
	int **map = read_int_matrix(0, dim[0], dim[1]);
	int *nr_querries = read_int_array(0,1);
	fill_map(map, dim);
	//write_int_matrix(1, dim[0], dim[1], map);
	for(int i = 0; i<*nr_querries; i++)
	{
		int *coord = read_int_array(0,4);
		coord[0]--;
		coord[1]--;
		coord[2]--;
		coord[3]--;
		if(map[coord[0]][coord[1]] == map[coord[2]][coord[3]])
		{
			if(map[coord[0]][coord[1]] %2)
				printf("decimal\n");
			else
				printf("binary\n");
		}
		else
		{
			printf("neither\n");
		}
		free(coord);
	}
	free_matrix((void**)map, dim[0]);
	free(dim);
	free(nr_querries);
	return 0;
}

void fill_map(int** map, int* dim)
{
	int odd = '2';
	int even = '3';
	for(int i = 0; i<dim[0]; i++)
	{
		for(int j = 0; j<dim[1]; j++)
		{
			//point already vizited
			if(map[i][j]!=0 && map[i][j]!=1)
				continue;

			if(map[i][j] == 0)
			{
				fill_path(map, dim, i, j, map[i][j], odd);
				odd+=2;
			}
			else
			{				
				fill_path(map, dim, i, j, map[i][j], even);
				even+=2;
			}
		}
	}
}

void fill_path(int **map, int *dim, int r1, int c1, int type, int color)

{
	if (r1 < 0 || r1 >= dim[0] || c1 < 0 || c1 >= dim[1])
		return ;

	if(map[r1][c1] != type)
		return ;

	map[r1][c1] = color;

	fill_path(map, dim, r1, c1+1, type, color);
	fill_path(map, dim, r1, c1-1, type, color);
	fill_path(map, dim, r1-1, c1, type, color);
	fill_path(map, dim, r1+1, c1, type, color);
}