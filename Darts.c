#include <stdlib.h>
#include <stdint.h> 
#include <stddef.h>
#define CIRCLE_RADIUS	10


typedef struct{
	float x;
	float y;
}coordinate_t;

enum Darts_Points_t
{
	OUTSIDE_TARGET = 0,
	OUTER_TARGET = 1,
	MIDDLE_TARGET = 5,
	INNER_TARGET = 10, 
};

uint8_t score(coordinate_t _dart_Position);

int main()
{
	coordinate_t dart;
	dart.x = -0.1;
	dart.y = -0.1;
	printf("Score: %d\n",score(dart));
	system("pause");
	return 0;
}
uint8_t score(coordinate_t _dart_position)
{
	float distance = sqrt(_dart_position.x*_dart_position.x 
		+ _dart_position.y*_dart_position.y);
	if(distance > CIRCLE_RADIUS)
		return OUTSIDE_TARGET;
	else if(INNER_TARGET >= distance && distance >= MIDDLE_TARGET)
		return OUTER_TARGET;
	else if(MIDDLE_TARGET >= distance && distance >= OUTER_TARGET)
		return MIDDLE_TARGET;
	else if(OUTER_TARGET >= distance && distance >= OUTSIDE_TARGET)
		return INNER_TARGET;
}
