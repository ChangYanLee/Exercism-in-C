
#include <stdlib.h>
#define PHONE_NUMBER_LENGTH	10
#define ASCII_ZERO		48
#define ASCII_ONE		49
#define ASCII_NINE		57
#define ERROR_NUMBER	"0000000000"

	 
char *phone_number_clean(const char *input);

int main()
{
	printf("%s\n",phone_number_clean("(223) 456-7890"));
	show_mem_stat();
	system("pause");
	return 0;
}
char *phone_number_clean(const char *input)
{
	char *phone_number = calloc((PHONE_NUMBER_LENGTH + 1),sizeof(char*));
    int number_count = 0;
	int index = 0;
    while(input[index] != 0)
	{
		if(number_count < 1 && input[index] == '1')
		{
			index++;
			continue;
		}	
		if((int)input[index] >= ASCII_ZERO && ASCII_NINE >= (int)input[index])
		{
			phone_number[number_count++] = input[index];
			printf("%c\n",input[index]);
		}
		index++;
	}
	phone_number[PHONE_NUMBER_LENGTH + 1] = '\0';
	if((int)phone_number[3] <= ASCII_ONE||(int)phone_number[0] <= ASCII_ONE || number_count != PHONE_NUMBER_LENGTH)
		strcpy(phone_number,ERROR_NUMBER);
		
    return phone_number;
	
}
