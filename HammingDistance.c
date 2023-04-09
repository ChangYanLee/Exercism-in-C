#include <ctype.h>
#include <stdbool.h>


#define ERROR_LENGTH    -1

int compute(const char *lhs, const char *rhs);

int main()
{
	printf("%d",compute("ATA","AGTG"));
	
	return 0;
}

int compute(const char *lhs, const char *rhs)
{
    if(strlen(lhs) != strlen(rhs))
        return ERROR_LENGTH;
    int strLength = strlen(lhs);
    int index,hammingDistance = 0;
    for(index = 0;index < strLength;index++)
    {
        if(*lhs != *rhs)
            hammingDistance++;
        lhs++;
        rhs++;
    }
    return hammingDistance;
}
