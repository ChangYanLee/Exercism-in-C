#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
typedef  struct
{
	uint8_t column;
	uint8_t row;	
} saddle_point_t;

typedef struct
{
	size_t count;
	saddle_point_t points[];
}saddle_points_t;


saddle_points_t* saddle_points(const int row,const int column,uint8_t array[row][column]);
void free_saddle_points(saddle_points_t* ptr_points);
void show_saddle_points(saddle_points_t* ptr_points);
void show_input_array(const int row,const int column,uint8_t array[row][column]);
static bool row_greater(uint8_t value, size_t irow, size_t row, size_t column, uint8_t matrix[row][column]);
static bool column_less(uint8_t value, size_t icolumn, size_t row, size_t column, uint8_t matrix[row][column]);


int main()
{
	int row = 3;
	int column = 3;
	uint8_t matrix[3][3] = { {9, 8, 7 }, {5, 3, 2 }, {6, 6, 7 } };
//	uint8_t matrix[2][3] = { {3, 1, 3}, {3, 2, 4} };
//	uint8_t matrix[1][4] = { {2, 5, 3, 5}};

//uint8_t matrix[4][1] = { {2},{1},{4},{1}};
	//show_input_array(column,row,matrix);
	saddle_points_t* arrPoints;
	arrPoints = saddle_points(row,column,matrix);
	show_saddle_points(arrPoints);
	free_saddle_points(arrPoints);
	system("pause");
	return 0;
}

saddle_points_t* saddle_points(const int row,const int column,uint8_t array[row][column])
{
	saddle_points_t *points = malloc(sizeof(saddle_points_t) + 
                                     row * column * sizeof(saddle_point_t));
    points->count = 0;
    size_t irow,icolumn;
	for (irow = 0; irow < row; ++irow)
    {
        for (icolumn = 0; icolumn < column; ++icolumn)
        {
            if (!row_greater(array[irow][icolumn], irow, row, column, array))
            {
                continue;
            }
            if (!column_less(array[irow][icolumn], icolumn, row, column, array))
            {
                continue;
            }
            points->points[points->count] = (saddle_point_t){irow+1, icolumn+1};
            ++points->count;
        }
    }
    return points;
}

//	saddle_point_t points_temp[row*column];
//	
//	bool is_min_row[row][column];
//	bool is_max_column[row][column];
//	
//	uint8_t index_column = 0;
//	uint8_t index_row = 0;
//	uint8_t min_row = 0;
//	//Check is min row
//	//printf("Row min: \n");
//	for(index_column = 0;index_column < column;index_column++)
//	{
//		//Find min row value
//		index_row = 0;
//		min_row = array[index_row][index_column];
//		for(index_row = 1;index_row < row;index_row++)
//		{
//			if(array[index_row][index_column] < min_row)
//			{
//				min_row = array[index_row][index_column];
//			}
//		}
//		//printf("min:%d",min_row);
//		//Check min 
//		for(index_row = 0;index_row < row;index_row++)
//		{
//			if(array[index_row][index_column] == min_row)
//				is_min_row[index_row][index_column] = true;
//			else
//				is_min_row[index_row][index_column] = false;
//			//printf("%d",array[index_row][index_column]);
//			//printf("%d",is_min_row[index_row][index_column]);
//		}
//	//	printf("\n");
//	}
//	uint8_t max_column = 0;
//	//printf("Column max: \n");
//	for(index_row = 0;index_row < row;index_row++)
//	{
//		//Find min row value
//		index_column = 0;
//		max_column = array[index_row][index_column];
//		for(index_column = 1;index_column < column;index_column++)
//		{
//			if(array[index_row][index_column] > max_column)
//			{
//				max_column = array[index_row][index_column];
//			}
//		}
//		//printf("Column max: %d\n",max_column);
//		//Check max 
//		
//		for(index_column = 0;index_column < column;index_column++)
//		{
//			if(array[index_row][index_column] == max_column)
//				is_max_column[index_row][index_column] = true;
//			else
//				is_max_column[index_row][index_column] = false;
//			//printf("%d",is_max_column[index_row][index_column]);
//		}
//		//printf("\n");
//	}
//	
//	
//	size_t saddle_count = 0;
//	//Check saddle point 
//	for(index_row = 0;index_row < row;index_row++)
//	{
//		for(index_column = 0;index_column < column;index_column++)
//		{
//			printf("%d",is_max_column[index_row][index_column]);
//			printf("%d",is_min_row[index_row][index_column]);
//			if(is_max_column[index_row][index_column] && is_min_row[index_row][index_column])
//			{
//				
//				points_temp[saddle_count].row = (index_row + 1);
//				points_temp[saddle_count].column = (index_column + 1);	
//				saddle_count += 1;
//			}	
//		}
//		printf("\n");
//	}
//	
//	saddle_points_t* new_points = malloc(sizeof(saddle_points_t) 
//		+ (saddle_count)*sizeof(saddle_point_t));
//	if(!new_points)
//		return NULL;
//	memcpy(new_points->points,points_temp,(saddle_count)*sizeof(saddle_point_t));
//	new_points->count = saddle_count;
//	return new_points;

static bool column_less(uint8_t value, size_t icolumn, size_t row, size_t column, uint8_t matrix[row][column])
{
    bool ret = true;
    size_t i;
    for (i = 0; i < row; ++i)
    {
        if (value > matrix[i][icolumn])
        {
            ret = false;
            break;
        }
    }
    return ret;
}
static bool row_greater(uint8_t value, size_t irow, size_t row, size_t column, uint8_t matrix[row][column])
{
    bool ret = true;
    size_t j;
    for (j = 0; j < column; ++j)
    {
        if (value < matrix[irow][j])
        {
            ret = false;
            break;
        }
    }
    return ret;
}
void free_saddle_points(saddle_points_t* ptr_points)
{
	free(ptr_points);
}
void show_saddle_points(saddle_points_t* ptr_points)
{
	printf("Count: %d\n",ptr_points->count);
	size_t count = 0;
	for(count = 0;count < ptr_points->count;count++)
	{
		printf("row: %d\t",ptr_points->points[count].row);
		printf("column: %d\t\n",ptr_points->points[count].column);
	}
}
void show_input_array(const int row,const int column,uint8_t array[row][column])
{
	int index_row = 0;
	int index_col = 0;
	for(index_row = 0;index_row < row;index_row++)
	{
		for(index_col = 0;index_col < column;index_col++)
			printf("%d\t",array[index_row][index_col]);
		printf("\n");
	}	
}
