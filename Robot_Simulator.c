#include <stdlib.h>


typedef enum {
   DIRECTION_NORTH = 0,
   DIRECTION_DEFAULT = DIRECTION_NORTH,
   DIRECTION_EAST,
   DIRECTION_SOUTH,
   DIRECTION_WEST,
   DIRECTION_MAX
} robot_direction_t;
typedef enum {
   TURN_RIGHT = 0,
   TURN_LEFT
} Direction_t;
typedef struct {
   int x;
   int y;
} robot_position_t;

typedef struct {
   robot_direction_t direction;
   robot_position_t position;
} robot_status_t;

robot_status_t robot_create(robot_direction_t direction, int x, int y);
void robot_move(robot_status_t *robot, const char *commands);
robot_direction_t ChangeDirection(robot_direction_t robot_direction,Direction_t direction);
void move_forward(robot_status_t *robot);
void show_robot(robot_status_t *robot);
int main()
{
	robot_status_t robot;
	robot = robot_create(DIRECTION_NORTH,7,3);
	robot_move(&robot,"RAALAL");
	show_robot(&robot);
	
	
	system("pause");
	return 0;
}
robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_status_t new_robot;
	new_robot.direction = direction;
	new_robot.position.x = x;
	new_robot.position.y = y;
	
	return new_robot;
}
void robot_move(robot_status_t *robot, const char *commands)
{
	int command_length = 0;
	while(*(commands + command_length) != '\0')
	{
		//printf("a:%c",*(commands + command_length));
		if(*(commands + command_length) == 'R')
			robot->direction = ChangeDirection(robot->direction,TURN_RIGHT);
		else if(*(commands + command_length) == 'L')
			robot->direction = ChangeDirection(robot->direction,TURN_LEFT);
		else if(*(commands + command_length) == 'A')
			move_forward(robot);
		//printf("D: %d\n",robot->direction);
		command_length++;
	}	
}
robot_direction_t ChangeDirection(robot_direction_t robot_direction,Direction_t direction)
{
	robot_direction_t new_direction;
	if(direction == TURN_RIGHT)
	{
		robot_direction = (robot_direction == DIRECTION_WEST) ? DIRECTION_NORTH:++robot_direction;
		
	}else if(direction == TURN_LEFT)
	{
		robot_direction = (robot_direction == DIRECTION_NORTH) ? DIRECTION_WEST:--robot_direction;
	}
	
	return robot_direction;
}
void move_forward(robot_status_t *robot)
{
	switch(robot->direction)
	{
		case DIRECTION_NORTH:
			robot->position.y += 1;
			break;
		case DIRECTION_EAST:
			robot->position.x += 1;
			break;
		case DIRECTION_SOUTH:
			robot->position.y -= 1;
			break;
		case DIRECTION_WEST:
			robot->position.x -= 1;
			break;	
		default:
			break;	
	}
}
void show_robot(robot_status_t *robot)
{
	printf("X: %d\n",robot->position.x);
	printf("Y: %d\n",robot->position.y);
}
