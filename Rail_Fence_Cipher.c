#include <stddef.h>
#include <string.h>
#include <stdlib.h>
typedef struct decodeString
{
	char* decodeStr;
	int strIndex;
}Decode_T;

char *encode(char *text, int rails);
char *decode(char *ciphertext, int rails);


int main()
{
	
	//encode("EXERCISES", 4);
	decode("133714114238148966225439541018335470986172518171757571896261", 6);
	system("pause");
	return 0;
}

char *encode(char *text, int rails)
{
	int length = (int)strlen(text) - 1;
	char *encodeStr = malloc((length + 1) * sizeof(char));
	int period = 2*(rails - 1);
	int interval = 0;
	int index = 0;
	int encodeIndex = 0;
	int row = 0;
	
	while(row < rails)
	{
		if(row == 0 || row == (rails - 1))
			interval = period;
		else 
			interval = 2*(rails - row - 1);
		index = row;
		while(index <= length)
		{
			printf("%d:%c\n",index,text[index]);
			encodeStr[encodeIndex] = text[index];
			encodeIndex++;
			index += interval;
			if(rails > 3 && row != 0 && row != ((rails - 1)))
				interval = (index % 3 == 1)? 4:2;	
		}
		row++;
	}
	encodeStr[encodeIndex] = '\0';
	printf("encode: %s\n",encodeStr);
	return encodeStr;
}

char *decode(char *ciphertext, int rails)
{
	int length = (int)strlen(ciphertext);
	printf("len:%d\n",length);
	int period = 2*(rails - 1);
	int interval = 0;
	int index = 0;
	Decode_T* decodeArray = (Decode_T*)malloc(rails * sizeof(Decode_T));
	for(;index < rails;index++)
	{
		decodeArray[index].decodeStr = (char*)malloc(length * sizeof(char));
		decodeArray[index].strIndex = 0;
	}	
	
	int row = 0;		
	int decodeIndex = 0;
	int cipherIndex = 0;
	int varInterval = 0;
	int count = 0; 
	while(row < rails)
	{
		if(row == 0 || row == (rails - 1))
			interval = period;
		else 
			interval = 2*(rails - row - 1);
		varInterval = interval;
		decodeIndex = 0;
		count = 0;
		index = row;
		while(index < length)
		{
			//printf("%d:%c\n",cipherIndex,ciphertext[index]);
			decodeArray[row].decodeStr[decodeIndex] = ciphertext[cipherIndex];
			decodeIndex++;
			cipherIndex++;
			printf("%d:%d\n",index,interval);
			index += interval;
			if(rails > 3  && row != 0 && row != (rails - 1))
				interval = (count % 2)? varInterval:period - varInterval;
			count++;
		}
		decodeArray[row].decodeStr[decodeIndex] = '\0';
		printf("%d : %s\n",row,decodeArray[row].decodeStr);	
		row++;
	}
	
	int railsPeriod = rails + (rails - 2);
	int rowIndex = 0;
	decodeIndex = 0;
	
	char *decodeStr = malloc((length + 1) * sizeof(char));
	while(decodeIndex < length)
	{
		row = 0;
		rowIndex = 0;
		while(row < railsPeriod)
		{
			if(decodeIndex == length)
				break;
			decodeStr[decodeIndex] = decodeArray[rowIndex].decodeStr[decodeArray[rowIndex].strIndex];	
			//printf("%d:%c\n",rowIndex,decodeStr[decodeIndex]);
			decodeArray[rowIndex].strIndex++;
			decodeIndex++;
			row++;
			if(row > rails - 1)
				rowIndex--;
			else
				rowIndex++;
		}
		
	}
	decodeStr[decodeIndex] = '\0';
	free(decodeArray);
	printf("Decode : %s\n",decodeStr);
	return decodeStr;
}
