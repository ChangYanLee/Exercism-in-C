#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define RESULT_ARRAY_LEN (1000)
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);
void show_array(uint32_t *primes,size_t length);
int main()
{
	static uint32_t result_array[RESULT_ARRAY_LEN];
	
	printf("Count: %d\n",sieve(1000,result_array,RESULT_ARRAY_LEN));
	//show_array(result_array,RESULT_ARRAY_LEN);
	system("pause");
	return 0;
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
	bool primes_array[max_primes];
	memset(primes_array,true,max_primes);
	
	uint32_t index = 0;
	uint32_t index1 = 0;
	for(index = 2;index <= limit;index++)
	{
		
		if(primes_array[index - 2])
		{
		//	printf("index: %d\n",index);
			index1 = index*index;
			while(index1 <= limit)
			{
				//printf("index1: %d\n",index1);
				primes_array[index1-2] = false;
				index1 += index;
				
			}
		}
	}
//	printf(" %d\n",primes_array[9]);
	uint32_t primes_count = 0;
	for(index = 2;index <= limit;index++)
	{
		if(primes_array[index - 2])
		{
			*(primes + primes_count) = index;
			primes_count++;
		}	
	}
	return max_primes < limit ? max_primes : primes_count;
	
}

void show_array(uint32_t *primes,size_t length)
{
	int index = 0;
	for(index = 0;index < length;index++)
		if(*(primes + index) != 0)
			printf("%d\n",*(primes + index));
}
