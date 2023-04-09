
#include <string.h>
#include <stdbool.h>
#define MAX_WORDS                                                              \
   20   // at most MAX_WORDS can be found in the test input string
#define MAX_WORD_LENGTH 50   // no individual word can exceed this length

// results structure
typedef struct word_count_word {
   char text[MAX_WORD_LENGTH +
             1];   // allow for the string to be null-terminated
   int count;
} word_count_word_t;

#define EXCESSIVE_LENGTH_WORD -1
#define EXCESSIVE_NUMBER_OF_WORDS -2

// count_words - routine to classify the unique words and their frequency in a
// sentence inputs:
//    sentence =  a null-terminated string containing that is analyzed
//
// outputs:
//    words = allocated structure to record the words found and their frequency
//    uniqueWords - number of words in the words structure
//           returns a negative number if an error.
//           words will contain the results up to that point.
int count_words(const char *sentence, word_count_word_t *words);


int main()
{
	char* input_text = "Joe can't tell between 'large' and large.";
	word_count_word_t ans[MAX_WORDS];
	memset(ans,0,sizeof(ans));
	printf("%d\n",count_words(input_text,ans));
	system("pause");
	return 0;
	
}
int count_words(const char *sentence, word_count_word_t *words)
{
	//Clear words array
	memset(words,0,sizeof(word_count_word_t) * MAX_WORDS);
	
	char str[strlen(sentence)];
	strcpy(str,sentence);
	
	char* cptr = str;
	bool sameWord = false;
	int wordsCount = 0;
	int strLength = (int)strlen(str);
	 
	int index = 0;
	for(;index <= strLength;index++)
	{
		//convert to lower case
		str[index] = tolower(str[index]);
		if(!isalnum(str[index]) && str[index] != '\'')
		{
			str[index] = '\0';//Set the word end ,then the cpter pointer to thid word
			if(strlen(cptr) > MAX_WORD_LENGTH)
				return EXCESSIVE_LENGTH_WORD;	
			else if(strlen(cptr) == 0)//skip if successive non-alphanum 
			{
				cptr = str + index + 1;
				continue;
			}
			if(cptr[0] == '\'' && cptr[strlen(cptr) - 1] == '\'')
			{
				cptr[strlen(cptr) - 1] = '\0';
				cptr += 1;
			}
			//Check the word array if words already exists 
			int index1 = 0;
			for(; index1 < wordsCount;index1++)
			{
				if(!strcmp(words[index1].text,cptr))	
				{
					words[index1].count++;
					sameWord = true;
					break;
				}
			}
			if(!sameWord)//if index1 equal wordsCount,not fund same word
			{
				if(wordsCount >= MAX_WORDS)
					return  EXCESSIVE_NUMBER_OF_WORDS;
				strcpy(words[wordsCount].text,cptr);
				words[wordsCount].count = 1;
				wordsCount++;
				printf("word: %s\n",cptr);
				printf("count: %d\n",wordsCount);		
			}
			sameWord = false;		
			cptr = str + index + 1;	
		}			
	}
	return wordsCount;
}


