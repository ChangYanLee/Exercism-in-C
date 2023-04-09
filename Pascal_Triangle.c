
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
void free_triangle(uint8_t **triangle, size_t rows);
uint8_t **create_triangle(size_t rows);

void show_array(uint8_t **array, size_t rows);
int main()
{
	size_t length = 3;
	uint8_t **array;
	
	array = create_triangle(length);
	show_array(array,length);
	free_triangle(array,length);
	system("pause");
	return 0;
} 

uint8_t **create_triangle(size_t rows)
{
	if(rows == 0)
	{
		uint8_t **triangle = calloc(1, sizeof(uint8_t *));
        triangle[0] = calloc(1, sizeof(uint8_t));
        return triangle;
	}
	 
	uint8_t **triangle_array = (uint8_t**)malloc(rows * sizeof(uint8_t*));
	
	size_t index_row = 0;
	size_t index_column = 0;
	for(index_row = 0;index_row < rows;index_row++)
	{
		*(triangle_array + index_row) = malloc(sizeof(char) * rows);
		for(index_column = 0;index_column < rows;index_column++)
		{
			if(index_column == 0)
			{
				*(*(triangle_array + index_row) + index_column) = 1;
			}else if((!index_row) && index_column)
			{
				*(*(triangle_array + index_row) + index_column) = 0;	
			}else
				*(*(triangle_array + index_row) + index_column) = *(*(triangle_array + index_row - 1) + index_column - 1)
					+ *(*(triangle_array + index_row - 1) + index_column);
		}
	}
	return triangle_array;
}
void free_triangle(uint8_t **triangle, size_t rows)
{
	size_t index = 0;
	for(index = 0;index < rows;index++)
	{
		free(*(triangle + index));
	}
	free(triangle);
}

void show_array(uint8_t **array, size_t rows)
{
	size_t index_row = 0;
	size_t index_column = 0;
	for(index_row = 0;index_row < rows;index_row++)
	{
		for(index_column = 0;index_column < rows;index_column++)
			printf("%d",array[index_row][index_column]);	
		printf("\n");
	}	
}	

