#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define MAX_STR_LEN (5 + 1)   // "##:##\0"
typedef struct
{
	char text[MAX_STR_LEN];
}clock_t; 


clock_t clock_create(const int hour,const int minute);
clock_t clock_add(clock_t clock,const int minute_add);
clock_t clock_subtract(clock_t clock,const int minute_sub);
bool clock_is_equal(clock_t clock1,clock_t clock2);
void show_clock(clock_t* clock);
int main()
{
	clock_t clock;
	clock = clock_create(-2,-60);
	show_clock(&clock);
	system("pause");
	return 0;
}
clock_t clock_create(const int hour,const int minute)
{
	clock_t new_clock;
	int clock_hour,clock_mintue; 
	clock_hour = hour;
	clock_mintue = minute;
	clock_hour += clock_mintue / 60;
	clock_mintue %= 60;
	if (clock_mintue < 0) 
	{
    	clock_mintue += 60;
	    clock_hour -= 1;
	}
	clock_hour %= 24;
	if (clock_hour < 0) 
    	clock_hour += 24;

	sprintf(new_clock.text,"%02d:%02d",clock_hour,clock_mintue);
	return new_clock;
}
clock_t clock_add(clock_t clock,const int minute_add)
{
	int clock_hour,clock_minute;
	sscanf(clock.text,"%d:%d",&clock_hour,&clock_minute);
	return clock_create(clock_hour,(clock_minute + minute_add));
}
clock_t clock_subtract(clock_t clock,const int minute_sub)
{
	return clock_add(clock,-minute_sub);
}
bool clock_is_equal(clock_t clock1,clock_t clock2)
{
	return strcmp(clock1.text,clock2.text) == 0;
}
void show_clock(clock_t* clock)
{
	puts(clock->text);
}
