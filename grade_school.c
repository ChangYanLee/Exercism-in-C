#include "grade_school.h"



int main()
{
	roster_t NTUST;
	init_roster(&NTUST);
	add_student(&NTUST,"Blair",2);
	add_student(&NTUST,"James",2);
	add_student(&NTUST,"James",3); 
	add_student(&NTUST,"Paul",3);   
	show_roster(&NTUST);
	//sort_roster(&NTUST);
	//show_roster(&NTUST);
	 
	roster_t temp = get_grade(&NTUST,3);
	show_roster(&temp);
	system("pause");
	return 0;
}





void init_roster(roster_t* roster)
{
    roster->count = 0;
    int index;
	for(index = 0;index < MAX_STUDENTS;index++)
	{
		roster->students[index].grade = 0;
		roster->students[index].name[0] = '\0';
	}
}

bool add_student(roster_t* roster,const char* name,uint8_t grade)
{
	if(check_same_name(roster,name))
	{
		printf("Error,Student have same name!\n");
		return false;
	}
	roster->count += 1;
    roster->students[roster->count - 1].grade = grade;
	strcpy(roster->students[roster->count - 1].name,name);
	sort_roster(roster);
	return true;
}

void show_roster(roster_t* roster)
{
	
	printf("Roster count: %d\n",roster->count);
	if(roster->count == 0)
		return ;
	printf("Student roster ======\n");
	int index;
	for(index = 0;index < roster->count;index++)
	{
		printf("Student name : %s\n",roster->students[index].name);
		printf("Student grade : %d\n\n",roster->students[index].grade);
	}
}
bool check_same_name(roster_t* roster,const char* name)
{
	if(roster->count == 0)
		return false;
	if(!strcmp(roster->students[roster->count - 1].name,name))
		return true;
	else 
		return false;
}
roster_t get_grade(roster_t* roster,uint8_t desired_grade)
{
	roster_t grade_roster;
	init_roster(&grade_roster);
	size_t index;
	for(index = 0;index < roster->count;index++)
	{
		
		if(roster->students[index].grade == desired_grade)
		{
			grade_roster.students[grade_roster.count] = roster->students[index];
			grade_roster.count += 1;
		}	
	}
	return grade_roster;
}
void sort_roster(roster_t* roster)
{
	if(roster->count <= 1)
		return ;
	size_t index,index1;
	student_t temp;
	for(index = 0;index < roster->count - 1;index++)
		for(index1 = 0;index1 < roster->count - 1;index1++)
		{
			if(roster->students[index1].grade > roster->students[index1 + 1].grade)
			{
				temp = roster->students[index1 + 1];
				roster->students[index1 + 1] = roster->students[index1];
				roster->students[index1] = temp;
			}else if(roster->students[index1].grade == roster->students[index1 + 1].grade)
			{
				if(roster->students[index1].name[0] > roster->students[index1 + 1].name[0])
				{
					temp = roster->students[index1 + 1];
					roster->students[index1 + 1] = roster->students[index1];
					roster->students[index1] = temp;
				}
				
			}	
		}

}


