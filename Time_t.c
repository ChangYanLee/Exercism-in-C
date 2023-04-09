#include <time.h>
#include <stddef.h>





int main()
{

	time_t lt;

	lt =time(NULL);
	printf("The Calendar Time now is %d\n",lt);
	
	
	system("pause");
	return 0;
}


