#include <stdint.h>

#define BOARD_SIZE	8	//8x8 array
typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);


int main()
{
	position_t queen1,queen2;
	queen1.column = 2;
	queen1.row = 8;
	queen2.column = 0;
	queen2.row = 0;
	printf("%d",can_attack(queen1,queen2));
	system("pause");
	return 0;
	
}
attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
	if(queen_1.column >= BOARD_SIZE || queen_1.row >= BOARD_SIZE
		|| queen_2.column >= BOARD_SIZE || queen_2.row >= BOARD_SIZE
		|| ((queen_1.column == queen_2.column) && (queen_1.row == queen_2.row)))
		return INVALID_POSITION;
	if(queen_1.column == queen_2.column || queen_1.row == queen_2.row
		|| (abs(queen_2.column - queen_1.column)/abs(queen_2.row - queen_1.row)) == 1)
		return CAN_ATTACK;
	else 
		return CAN_NOT_ATTACK;
	
}
