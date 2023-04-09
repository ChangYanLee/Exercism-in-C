#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define ASCII_a			97
#define ASCII_z			122

#define alphabetNumber	26
bool is_pangram(const char *sentence);



int main()
{
	printf("Ans : %d\n",is_pangram("abcdefghijklmnopqrstuvwxyz"));
	system("pause");
	return 0; 
}
bool is_pangram(const char *sentence)
{
	if(!sentence)
		return false;
	bool alphabetArray[alphabetNumber];
	memset(alphabetArray,false,alphabetNumber);
	char* index = (char* )sentence; 
	while(*index != '\0')
	{
		
		if(isalpha(*index))
		{
			alphabetArray[(tolower(*index) - ASCII_a)] = true;
			printf("%d:%d",(tolower(*index) - ASCII_a),alphabetArray[alphabetNumber - (tolower(*index) - ASCII_a)]);
			printf("%c\n",*index);
		}		

		index++;
	}
	int index1 = 0;
	for(;index1 < alphabetNumber;index1++)
	{
		if(!alphabetArray[index1])
			return false;
	}
	return true;
}
