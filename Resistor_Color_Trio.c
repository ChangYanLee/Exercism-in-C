#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

#define OHMS		1
#define KILOOHMS	1000

typedef enum Color
{
	BLACK = 0,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE
}resistor_band_t; 

typedef struct
{
	uint16_t value;
	uint16_t unit;
}resistor_value_t;

resistor_value_t color_code(resistor_band_t resistor[3]);

int main()
{
	color_code((resistor_band_t[]){ ORANGE, ORANGE, BLACK });
	
	
	
	system("pause");
	return 0;
}
resistor_value_t color_code(resistor_band_t resistor[3])
{
	resistor_value_t result;
	double resistor_value = (resistor[0]*10 + resistor[1])*pow(10,resistor[2]);
	printf("value 1: %f\n",(int)resistor_value);
	if((int)resistor_value / 1000)
	{
		result.value = resistor_value / 1000;
		result.unit = KILOOHMS;
	}else
	{
		result.value = resistor_value;
		result.unit = OHMS;
	}
	printf("value: %d\n",result.value);
	printf("unit: %d\n",result.unit);
	return result;
}

