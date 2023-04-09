
#include "memory_check.h"


#define LIST_TAIL	NULL
typedef int ll_data_t;

typedef struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
}list_node_t;

typedef struct list {
   struct list_node *first, *last;
}list_t;


// constructs a new (empty) list
list_t *list_create(void);

// counts the items on a list
size_t list_count(const list_t *list);

// inserts item at back of a list
void list_push(list_t *list, ll_data_t item_data);

// removes item from back of a list
ll_data_t list_pop(list_t *list);

// inserts item at front of a list
void list_unshift(list_t *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(list_t *list);

// deletes a node that holds the matching data
void list_delete(list_t *list, ll_data_t data);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(list_t *list);

void show_list(list_t *list);

int main()
{
	list_t *my_list;
	my_list =  list_create(); 
	show_mem_stat();
	list_push(my_list,2);
	list_push(my_list,3);
	list_push(my_list,4);
	list_push(my_list,6);
	show_list(my_list);
	printf("Pop: %d\n",list_pop(my_list));
	show_list(my_list);
	list_unshift(my_list,9);
	show_list(my_list);
	printf("Pop: %d\n",list_shift(my_list));
	show_list(my_list);
	list_delete(my_list,4);
	show_list(my_list);
	list_destroy(my_list);
	show_mem_stat();
	system("pause");
	return 0;
	
}
list_t *list_create(void)
{
	list_t* new_list = malloc(sizeof(list_t));
	new_list->first = LIST_TAIL;
	new_list->last = LIST_TAIL;
	return new_list;
}
size_t list_count(const list_t *list)
{
	size_t count = 0;
	list_node_t* counter_ptr = list->first;
	while(counter_ptr != LIST_TAIL)
	{
		counter_ptr = counter_ptr->next;
		count++;
	}
	return count;
}
void list_push(list_t *list, ll_data_t item_data)
{
	list_node_t* new_node = malloc(sizeof(list_node_t));
	new_node->data = item_data;
	if(list->first == LIST_TAIL)
	{
		list->first = new_node;
		list->last = new_node; 
		new_node->prev = NULL;	
	}else
	{
		list->last->next = new_node;
		new_node->prev = list->last;
		list->last = new_node;
	}
	new_node->next = LIST_TAIL;
	
}
void show_list(list_t *list)
{
	size_t index = 1;
	list_node_t *show_node_ptr = list->first;
	printf("Count: %d\n",list_count(list));
	while(show_node_ptr != list->last->next)
	{
		printf("%d: %d\n",index++,show_node_ptr->data);
		show_node_ptr = show_node_ptr->next;
	}
	
}
ll_data_t list_pop(list_t *list)
{
	if(list->first == LIST_TAIL)
		return 0;
	ll_data_t data = list->last->data;
	list->last = list->last->prev;
	free(list->last->next);
	if(list->last == LIST_TAIL)
		list->first = LIST_TAIL;
	else 
		list->last->next = LIST_TAIL;
	return data;
}
void list_unshift(list_t *list, ll_data_t item_data)
{
	list_node_t* new_node = malloc(sizeof(list_node_t));
	new_node->data = item_data;
	if(list->first == LIST_TAIL)
	{
		list->first = new_node;
		list->last = new_node; 
		new_node->next = LIST_TAIL;	
	}else
	{
		new_node->next = list->first;
		list->first->prev = new_node;
		list->first = new_node;
	}
}
ll_data_t list_shift(list_t *list)
{
	if(list->first == LIST_TAIL)
		return 0;
	ll_data_t data = list->first->data;
	list_node_t* temp_ptr = list->first;
	list->first = list->first->next;
	if(list->first == LIST_TAIL)
		list->last = LIST_TAIL;
	else 
		list->first->prev = LIST_TAIL; 
	free(temp_ptr);
	return data;
}
void list_delete(list_t *list, ll_data_t data)
{
	list_node_t* search_ptr = list->first;
	while(search_ptr != LIST_TAIL)
	{
		if(search_ptr->data == data)
		{
			if(search_ptr == list->first)//at header
			{
				list->first = list->first->next;
			}else if(search_ptr == list->last)//at tail 
			{
				list->last = list->last->prev;
				list->last->next = LIST_TAIL;
			}else
			{
				search_ptr->prev->next = search_ptr->next;
				search_ptr->next->prev = search_ptr->prev;
			}
			free(search_ptr);
			break;	
		}
		search_ptr = search_ptr->next;
	}
}
void list_destroy(list_t *list)
{
	list_node_t* index_ptr = list->first;
	while(index_ptr != LIST_TAIL)
	{
		list_node_t* destory_ptr = index_ptr;
		free(destory_ptr);
		index_ptr = index_ptr->next;
	}
	
	free(list);
}

