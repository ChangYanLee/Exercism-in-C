#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define NO_FIND_GCD		-1 
#define NUMERATOR_ZERO	0
typedef struct
{
	int numerator;
	int denominator;
}rational_t;

rational_t add(rational_t value1,rational_t value2);
rational_t subtract(rational_t value1,rational_t value2);
rational_t multiply(rational_t value1,rational_t value2);
rational_t divide(rational_t value1,rational_t value2);
rational_t absolute(rational_t value1);
rational_t exp_rational(rational_t value1,int16_t power);
float exp_real(uint16_t realValue,rational_t value);
rational_t reduce(rational_t value);
int get_greatest_common_divisor(rational_t value);
void show_rational_numbers(rational_t value);
int main()
{
	rational_t r1 = {-1,2};
	rational_t r2 = {1,1};
	//rational_t result = exp_rational(r1,-3);
	//show_rational_numbers(result);
	printf("%f\n",exp_real(9,r1));
	system("pause");
	return 0;
}
rational_t add(rational_t value1,rational_t value2)
{
	rational_t result = {0,0};
	result.numerator = value1.numerator*value2.denominator 
		+ value1.denominator*value2.numerator;
	result.denominator = value1.denominator*value2.denominator;
	return  reduce(result);
}
rational_t subtract(rational_t value1,rational_t value2)
{
	rational_t result = {0,0};
	result.numerator = value1.numerator*value2.denominator 
		- value1.denominator*value2.numerator;
	result.denominator = value1.denominator*value2.denominator;
	return reduce(result);
}
rational_t multiply(rational_t value1,rational_t value2)
{
	rational_t result = {0,0};
	result.numerator = value1.numerator*value2.numerator;
	result.denominator = value1.denominator*value2.denominator;
	return reduce(result);
}
rational_t divide(rational_t value1,rational_t value2)
{
	rational_t result = {0,0};
	result.numerator = value1.numerator*value2.denominator;
	result.denominator = value1.denominator*value2.numerator;
	return reduce(result);
}
rational_t absolute(rational_t value1)
{
	rational_t result = {0,0};
	result.numerator = abs(value1.numerator);
	result.denominator = abs(value1.denominator);
	return reduce(result);
}
rational_t exp_rational(rational_t value1,int16_t power)
{
	rational_t result = {0,0};
	if(power > 0)
	{
		result.numerator = (int)pow(value1.numerator,power);
		result.denominator = (int)pow(value1.denominator,power);
	}else
	{
		result.numerator = (int)pow(value1.denominator,abs(power));
		result.denominator = (int)pow(value1.numerator,abs(power));
	}
	return reduce(result);
}
float exp_real(uint16_t realValue,rational_t value)
{
	return (float)pow(realValue,(double)value.numerator/value.denominator);
	
}
rational_t reduce(rational_t value)
{
	int gcd_result = get_greatest_common_divisor(value);
	if(gcd_result == NO_FIND_GCD)
	{
		if(value.denominator < 0)
		{
			value.denominator *= -1;
			value.numerator *= -1;
		}
		return value;
	}
	else if(gcd_result == NUMERATOR_ZERO)
	{
		value.denominator = 1;
		return value;
	}else
	{
		value.denominator /= gcd_result;
		if(value.denominator < 0)
		{
			value.numerator /= gcd_result;
			value.numerator *= -1;
			value.denominator = abs(value.denominator);
		}	
		else
			value.numerator /= gcd_result;	
		return value;
	}
}
int get_greatest_common_divisor(rational_t value)
{
	int divisor = 2;
	int min = 0;
	if(value.numerator == 0)
		return NUMERATOR_ZERO;
		
	if(abs(value.numerator) > abs(value.denominator))
		min = abs(value.denominator);
	else 
		min = abs(value.numerator);
	while(divisor <= min)
	{
		if(!(value.numerator % divisor) && !(value.denominator % divisor))	
			return divisor;
		else
			divisor++;	
	}
	return NO_FIND_GCD;	
}
void show_rational_numbers(rational_t value)
{
	printf("Num: %d\n",value.numerator);
	printf("Den: %d\n",value.denominator);
}

