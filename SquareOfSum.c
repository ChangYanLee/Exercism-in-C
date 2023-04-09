#include <stdio.h>


unsigned int sum_of_squares(unsigned int n);
unsigned int square_of_sum(unsigned int n);
unsigned int difference_of_squares(unsigned int n);
int main()
{
	
	printf("Sum of squares: %d\n",sum_of_squares(5));
	printf("Squares of sum: %d\n",square_of_sum(5));
	printf("Difference of sequares: %d\n",difference_of_squares(5));
	
	
	return 0;
}

unsigned int sum_of_squares(unsigned int n) {
  return (n * (n + 1) * (2 * n + 1)) / 6;
}
unsigned int square_of_sum(unsigned int n) {
  unsigned int sum = (n * (n + 1)) / 2;
  return sum * sum;
}
unsigned int difference_of_squares(unsigned int n) {
  return square_of_sum(n) - sum_of_squares(n);
}

