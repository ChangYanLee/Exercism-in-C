#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h> 

#define ARRAY_LENGTH(A)	(sizeof(A) / sizeof(A[0]))
#define ERROR_BUFFER_FULL	0
#define ERROR_BUFFER_EMPTY	1
typedef uint16_t buffer_value_t;

typedef struct {
	buffer_value_t *buffer;
	size_t size;
	size_t write_index;
	size_t read_index;
	bool is_full;
}circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
uint16_t write(circular_buffer_t* cir_buffer, buffer_value_t value);
uint16_t overwrite(circular_buffer_t* cir_buffer, buffer_value_t value);
uint16_t read(circular_buffer_t* cir_buffer, buffer_value_t* read_value);
void clear_buffer(circular_buffer_t* cir_buffer);
void delete_buffer(circular_buffer_t* cir_buffer);
void show_buffer(circular_buffer_t* cir_buffer);
bool is_buffer_empty(circular_buffer_t* cir_buffer);
bool is_buffer_full(circular_buffer_t* cir_buffer);
int main()
{
	circular_buffer_t *cir_buffer = new_circular_buffer(4);
	write(cir_buffer,2);
	write(cir_buffer,3);
	write(cir_buffer,1);
	write(cir_buffer,7);
	
	show_buffer(cir_buffer);
	
	buffer_value_t read_value = 0;
	read(cir_buffer,&read_value);
	printf("r:%d\n",read_value);
	write(cir_buffer,4);
	show_buffer(cir_buffer);
	read(cir_buffer,&read_value);
	printf("r:%d\n",read_value);
	write(cir_buffer,9);
	show_buffer(cir_buffer);
	clear_buffer(cir_buffer);
	write(cir_buffer,1);
	write(cir_buffer,2);
	write(cir_buffer,3);
	write(cir_buffer,4);
	show_buffer(cir_buffer);
	delete_buffer(cir_buffer);
	system("pause");
	return 0;
}

circular_buffer_t *new_circular_buffer(size_t capacity)
{
	circular_buffer_t *new_buffer = malloc(sizeof(circular_buffer_t));
	if(new_buffer == NULL)
		printf("Error");
	new_buffer->buffer = malloc(capacity*sizeof(buffer_value_t));
	new_buffer->size = capacity - 1;
	new_buffer->write_index = 0;
	new_buffer->read_index = 0;
	new_buffer->is_full = false;
	return new_buffer;
	 
}

uint16_t write(circular_buffer_t* cir_buffer, buffer_value_t value)
{
	if(cir_buffer->is_full)
		return -1;
	
	cir_buffer->buffer[cir_buffer->write_index] = value;
	cir_buffer->write_index = (cir_buffer->write_index == cir_buffer->size) ? 0:cir_buffer->write_index + 1;
	cir_buffer->is_full = is_buffer_full(cir_buffer);
	//printf("W:%d\n",cir_buffer->write_index);
	return 0;
}
uint16_t overwrite(circular_buffer_t* cir_buffer, buffer_value_t value)
{
	cir_buffer->buffer[cir_buffer->write_index] = value;
	cir_buffer->write_index = (cir_buffer->write_index == cir_buffer->size) ? 0:cir_buffer->write_index + 1;
	return 0;
}
uint16_t read(circular_buffer_t* cir_buffer, buffer_value_t* read_value)
{
	if(is_buffer_empty(cir_buffer))
		return ERROR_BUFFER_EMPTY;
	
	*read_value = cir_buffer->buffer[cir_buffer->read_index];
	cir_buffer->read_index = (cir_buffer->read_index == cir_buffer->size) ? 0:cir_buffer->read_index + 1;
	cir_buffer->is_full = false;
	//printf("r:%d\n",read_value);
	return 0;
}
void clear_buffer(circular_buffer_t* cir_buffer)
{
	cir_buffer->is_full = false;
	cir_buffer->read_index = 0;
	cir_buffer->write_index = 0;
}
void delete_buffer(circular_buffer_t* cir_buffer)
{
	free(cir_buffer->buffer);
	free(cir_buffer);
}
void show_buffer(circular_buffer_t* cir_buffer)
{
	int index;
	for(index = 0;index <= cir_buffer->size;index++)
		printf("%d\n",cir_buffer->buffer[index]);
}
bool is_buffer_empty(circular_buffer_t* cir_buffer)
{
	if(cir_buffer->write_index == cir_buffer->read_index && !cir_buffer->is_full)
		return true;
	else
		return false;
}
bool is_buffer_full(circular_buffer_t* cir_buffer)
{
	if(cir_buffer->write_index == cir_buffer->read_index)
		return true;
	else
		return false;
}
