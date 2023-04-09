#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ASCII_SPACE			32
#define ASCII_DASH			45
#define ASCII_UNDERSCORE	95
#define ASCII_MARK			34 
#define ASCII_A				65
#define ASCII_Z				90
#define ASCII_a				97
#define ASCII_z				122

char* abbreviate(const char* phrase);
int main()
{
	
	char* ans = abbreviate("Rolling On The Floor Laughing So Hard "
                  "That My Dogs Came Over And Licked Me");
	printf("%s\n",ans);
	
	system("pause");
	return 0;
}
char* abbreviate(const char* phrase)
{
	if(phrase == NULL || *phrase == '\0')
		return NULL;
		
	int length = strlen(phrase) + 1;
	int index = 0;
	
	char* acronym = malloc(length*sizeof(char));
	
	bool flag_space = false;
	
	int count = 0;
	acronym[count++] = phrase[index];
	for(index = 1;index < length;index++)
	{
		if(flag_space && 
			((ASCII_Z >= (int)phrase[index] && (int)phrase[index] >= ASCII_A ) 
			|| (ASCII_z >= (int)phrase[index] && (int)phrase[index] >= ASCII_a)))
		{
			if((int)phrase[index] >= ASCII_a)
				acronym[count++] = phrase[index] - (ASCII_a - ASCII_A);
			else
				acronym[count++] = phrase[index];
		}
		if((int)phrase[index] == ASCII_SPACE 
		|| (int)phrase[index] == ASCII_DASH 
		|| (int)phrase[index] == ASCII_UNDERSCORE
		|| (int)phrase[index] == ASCII_MARK)
			flag_space = true;
		else
			flag_space = false;
	}
	acronym[count] = '\0';
	

	return acronym;
}
