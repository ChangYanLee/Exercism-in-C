#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

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



uint16_t color_code(resistor_band_t resistor[2]);

int main()
{
	
	printf("%d\n",color_code((resistor_band_t[]){ BLUE, GREY }));
	system("pause");
	return 0;
	
}
uint16_t color_code(resistor_band_t resistor[2])
{
	return resistor[0] * 10 + resistor[1]; 
	
}
