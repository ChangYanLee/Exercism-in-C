#include "stdbool.h"
bool is_armstrong_number(int candidate);
int main()
{
	int input;
	printf("Input a number: ");
	scanf("%d",&input);
	if(is_armstrong_number(input))
		printf("The number is a armstrong number!");
	else
		printf("The number is not a armstrong number!");
	return 0;
}
bool is_armstrong_number(int candidate)
{
    
	int temp = candidate;
	int ans = candidate;
	int sum = 0;
	int count = 0;
	int div = 1;
	int power = 1;
	int division = 0;
	int i;
	for(i = 1;temp != 0;i++)
	{
		temp /= 10;
		count++;
		div *= 10; 
	}
	div /= 10;
	while(candidate != 0)
	{
		division = candidate/div;
		printf("%d\n",division);
		for(i = 0;i < count;i++)
			power *=division;
		sum += power;
		power = 1;
		candidate %= div;
		div /= 10;
	}
	printf("%d\n",sum);

    return (sum == ans);
}

//Other ans
//    if (candidate < 10)
//        return true;
//    int digit_count = log10(candidate) + 1;
//    int num = candidate;
//    int pow_total = 0;
//    while (num > 0)
//    {
//        int pow_temp = num % 10;
//        int pow_temp_total = 1;
//        for (int i = 0; i < digit_count; i++)
//            pow_temp_total *= pow_temp;
//        pow_total += pow_temp_total;
//        num /= 10;
//    }
//    return candidate == pow_total;
