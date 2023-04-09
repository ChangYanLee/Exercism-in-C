#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>



typedef struct {
	uint16_t a;
	uint16_t b;
	uint16_t c;
}triplet_t;

typedef struct {
	size_t count;
	triplet_t triplets[];
}triplets_t;

triplets_t* triplets_with_sum(const uint16_t sum);
void free_triplets(triplets_t* new_triplets);
void show_triplets(triplets_t* new_triplets);
int main()
{
	triplets_t* new_triplets = NULL;
	new_triplets = triplets_with_sum(1001);
	
	show_triplets(new_triplets);
	
	free_triplets(new_triplets);
	system("pause");
	return 0;
}

triplets_t* triplets_with_sum(const uint16_t sum)
{
	triplets_t* new_triplets = malloc(sizeof(triplets_t) + 10*sizeof(triplet_t));
	if(!new_triplets)
		return NULL;
	new_triplets->count = 0;	 
	int index_a = 1;
	int index_b = 1;
	int temp = sum;
	for(index_a = 1;index_a <= temp;index_a++)
	{
		//printf("a = %d\n",index_a);
		for(index_b = index_a;index_b <= sum;index_b++)
		{
			//printf("b = %d\n",index_b);
			if(((sum - index_a - index_b) == sqrt(index_a*index_a + index_b*index_b)) )
			{
			 	new_triplets->triplets[new_triplets->count].a = index_a;
			 	new_triplets->triplets[new_triplets->count].b = index_b;
			 	new_triplets->triplets[new_triplets->count].c = (sum - index_a - index_b);
			 	new_triplets->count += 1; 
			 	//temp = index_b;
			}
		} 
	}
	
	return new_triplets;
	
}
void free_triplets(triplets_t* new_triplets)
{
	free(new_triplets->triplets);
	free(new_triplets);
}

void show_triplets(triplets_t* new_triplets)
{
	printf("Count: %d\n",new_triplets->count);
	size_t index = 0;
	for(index = 0;index < new_triplets->count;index++)
		printf("a = %d\nb = %d\nc = %d\n",new_triplets->triplets[index].a,
			new_triplets->triplets[index].b,new_triplets->triplets[index].c);
	
	
}

