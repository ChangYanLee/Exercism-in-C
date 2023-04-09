#include <stdbool.h>
#include <stdlib.h>
//eggs (1)
//peanuts (2)
//shellfish (4)
//strawberries (8)
//tomatoes (16)
//chocolate (32)
//pollen (64)
//cats (128)
typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,
} allergen_t;

typedef struct {
   int count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

bool is_allergic_to(allergen_t allergen,const int score);
allergen_list_t get_allergens(const int socre);
void show_allergen(allergen_list_t* list);
int main()
{
	printf("%d\n",is_allergic_to(ALLERGEN_STRAWBERRIES,20));
	//printf("%d\n",(1 << ALLERGEN_STRAWBERRIES));
	allergen_list_t list;
	list = get_allergens(255);
	show_allergen(&list);
	system("pause");
	return 0;
}
bool is_allergic_to(allergen_t allergen,const int score)
{
	return ((1 << allergen) & score);	
}

allergen_list_t get_allergens(const int socre)
{
	allergen_list_t list;
	list.count = 0;
	memset(list.allergens,false,ALLERGEN_COUNT*sizeof(bool));
	int index = 0;
	int check_bit = 1;
	for(index = 0;index < ALLERGEN_COUNT;index++,check_bit <<= 1)
	{
		list.allergens[index] = (socre & check_bit);
		if(list.allergens[index])
			list.count++;
	}
	return list;
}
void show_allergen(allergen_list_t* list)
{
	printf("Allergen count: %d\n",list->count);
	int index = 0;
	for(index = 0;index < ALLERGEN_COUNT;index++)
	{
		switch(index)
		{
			case ALLERGEN_EGGS:
				printf("Allergen Egg: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_PEANUTS:
				printf("Allergen Peanuts: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_SHELLFISH:
				printf("Allergen Shellfish: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_STRAWBERRIES:
				printf("Allergen Strawberries: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_TOMATOES:
				printf("Allergen Tomatoes: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_CHOCOLATE:
				printf("Allergen Chocolate: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_POLLEN:
				printf("Allergen Pollen: %d\n",list->allergens[index]);
				break;
			case ALLERGEN_CATS:
				printf("Allergen Cats: %d\n",list->allergens[index]);
				break;
				
			default:
				break;					

		}
	}
}
