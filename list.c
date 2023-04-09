#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef int list_element_t;

typedef struct {
   size_t length;
   list_element_t elements[];
} list_t;

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]);

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2);

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t));
bool filter_modulo(list_element_t element);
// returns the length of the list
size_t length_list(list_t *list);

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));
list_element_t map_increment(list_element_t element);
// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t));

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t));
list_element_t fold_multiply(list_element_t element,list_element_t accumulator);
list_element_t fold_add(list_element_t element,list_element_t accumulator);
list_element_t fold_divide(list_element_t element,list_element_t accumulator);
// reverse the elements of the list
list_t *reverse_list(list_t *list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list);

void show_list(list_t *list);

static list_t *list;
static list_t *list2;
static list_t *actual;

int main()
{
	list = new_list(4,(list_element_t[]){1,3,2,5});
	list2 = new_list(2,(list_element_t[]){4,5});
	actual = append_list(list,list2);
	//printf("L:%d\n",length_list(list));
	//actual = filter_list(list,filter_modulo);
	//actual = map_list(list,map_increment);
	//printf("foldl:%d\n",foldl_list(list,2,fold_add));
	//printf("foldr:%d\n",foldr_list(list,5,fold_divide));
	//actual = reverse_list(list);
	show_list(actual);
	delete_list(list);
	delete_list(list2);
	delete_list(actual);
	system("pause");
	return 0;
	
}
list_t *new_list(size_t length, list_element_t elements[])
{
	size_t elements_size = sizeof(list_element_t) * length;
	list_t *list = malloc(sizeof(list_t) + elements_size);
	if(!list)
		return NULL;
	list->length = length;
	size_t index;

	memcpy(list->elements, elements, elements_size);
	return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
	size_t list1_size = sizeof(list_element_t) * list1->length;
    size_t list2_size = sizeof(list_element_t) * list2->length;
    list_t *newList = malloc(sizeof(list_t) + list1_size + list2_size);
    newList->length = list1->length + list2->length;
    memcpy(newList->elements, list1->elements, list1_size);
    memcpy(newList->elements + list1->length, list2->elements, list2_size);
    return newList;
}
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))//use callback function
{
	list_element_t *filtered_List = (list_element_t *)malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);
    int j = 0;
    size_t i;
    for ( i = 0; i < list->length; i++)
    {
        if (filter(list->elements[i]))
        {
            filtered_List[j++] = list->elements[i];
        }
    }
    return new_list(j, filtered_List);
//	if(!list)
//		return NULL;
//	list_t *_list = new_list(list->length,NULL);
//	if(!_list)
//		return NULL;
//	_list->length = 0;
//	size_t index;
//	for(index = 0;index < list->length;index++)
//	{
//		if(filter(list->elements[index]))
//		{
//			_list->elements[_list->length] = list->elements[index]; 
//			_list->length += 1; 
//		}
//	}
//	return _list;
}
bool filter_modulo(list_element_t element)
{
	return (element % 2 == 1);
}
size_t length_list(list_t *list)
{
	return list->length;
}
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
//	if(!list)
//		return NULL;
//		
//	size_t index;
//	for(index = 0;index < list->length;index++)
//		list->elements[index] = map(list->elements[index]);
//	return list;
	list_element_t *mapped_List = (list_element_t *) malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);
    int j = 0;
    size_t i;
    for (i = 0; i < list->length; i++)
    {
        mapped_List[j++] = map(list->elements[i]);
    }
    return new_list(j, mapped_List);
}
list_element_t map_increment(list_element_t element)
{
	return element + 1;
}
list_element_t fold_multiply(list_element_t element,list_element_t accumulator)
{
	return element * accumulator;
}
list_element_t fold_add(list_element_t element,list_element_t accumulator)
{
	return element + accumulator;
}
list_element_t fold_divide(list_element_t element,list_element_t accumulator)
{
	return (accumulator == 0) ? 0:element / accumulator;
}
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
	if(!list)
		return initial;
	size_t index;
	list_element_t total = initial;
	for(index = 0;index < list->length;index++)
		total = foldl(list->elements[index],total);
	return total;

}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{

	if(!list)
		return initial;
	size_t index;
	list_element_t total = initial;
	for(index = 0;index < list->length;index++)
		total = foldr(list->elements[list->length - index - 1],total);
	return total;
}
list_t *reverse_list(list_t *list)
{
	if(!list)
		return NULL;
	if(list->length == 0)
		return list;
	list_element_t reverse_element[list->length];
	size_t index;
	for(index = 0;index < list->length;index++)
		reverse_element[index] = list->elements[list->length - index - 1];
	return new_list(list->length,reverse_element);	
}
void delete_list(list_t *list)
{
	free(list);
}
void show_list(list_t *list)
{
	if(list == NULL)
		return ;
	size_t index;
	printf("Items: %d\n",list->length);
	for(index = 0;index < list->length;index++)
		printf("%d\n",list->elements[index]);
	
}

