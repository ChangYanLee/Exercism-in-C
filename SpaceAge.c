#include <stdint.h>

#define SECONDS_OF_YEAR	31557600

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
   TOTAL,
} planet_t;

float orbital_period_per_earth[TOTAL] = {
	0.2408467,
	0.61519726,
	1.0,
	1.8808158,
	11.862615,
	29.447498,
	84.016846,
	164.79132
};

float age(planet_t planet, int64_t seconds);


int main()
{
	
	printf("%.2f\n",age(MERCURY, 2134835688));
	
	
	system("pause");
	return 0;
}
float age(planet_t planet, int64_t seconds)
{
	if((NEPTUNE >= planet) && (planet >= MERCURY))
		return seconds / orbital_period_per_earth[planet] / SECONDS_OF_YEAR;
	else
		return -1.0;		
}
