#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#define ASCII_SPACE    32
#define ASCII_HYPHEN   45
bool is_isogram(const char phrase[]);
int main()
{
	
	is_isogram("");
	return 0;
}
bool is_isogram(const char phrase[])
{
    
    if(phrase == NULL)
        return false;
    int arrayLength = strlen(phrase);
    if(arrayLength != 0)
    {
        int index,index1;
        char temp;
        for(index = 0;index < arrayLength - 1;index++)
        {
            if((int)phrase[index] == ASCII_HYPHEN 
               ||(int)phrase[index] == ASCII_SPACE)
                continue;
            else
                temp = phrase[index];
            for(index1 = index + 1;index1 < arrayLength;index1++)
            {
                 if(tolower(temp) == tolower(phrase[index1]))
                     return false;
            }
        }
        return true;
    }else
        return true;
}
