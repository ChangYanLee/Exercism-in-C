

#include <stdlib.h>
#define NO_SEARCH_TARGET	NULL

const int *binary_search(int value,const int *arr,size_t length);

int main()
{
	int arr[] = {1,2,3,4,8,12};
	
	size_t length = sizeof(arr)/sizeof(arr[0]);
	//printf("%d",length);
	//printf("%d\n",binary_search(3,arr,length));
	if(&arr[0] == binary_search(1,arr,length))
		printf("Find!\n");
	else
		printf("No find!\n");
	system("Pause");
	return 0;
}
const int *binary_search(int value,const int *arr,size_t length)
{
	if(length < 1)
		return NO_SEARCH_TARGET;
	//else if(length %2)
	int left = 0;
	int right = length - 1;
	int middle;
	while(right >= left)
	{
		middle = (right + left)/2;
		printf("Locate : %d\n",middle);
		if(arr[middle] > value)
		{
			right = middle - 1;
			
		}else if(arr[middle] < value)
		{
			left = middle + 1;
		}else
		{
			return &arr[middle];
		}	
	}
	return NO_SEARCH_TARGET;
}



