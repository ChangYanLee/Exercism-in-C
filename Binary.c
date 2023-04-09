#include <stdlib.h>
#include <string.h>
#define INVALID -1

int convert(const char *input);

int main()
{
	printf("Dec: %d\n",convert("nope10"));
	
	system("pause");
	return 0;
}
int convert(const char *input)
{
	size_t index = 0;
	int sum = 0;
	while(*(input + index) != '\0')
	{
		if(*(input + index) != '1' && *(input + index) != '0')
			return INVALID;
		sum = sum << 1;
		if(*(input + index) == '1')
			sum += 1;
		index++;		
	}	
	return sum;
	
}

