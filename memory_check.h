//#ifndef MEMORY_CHECK_H
//#define MEMORY_CHECK_H

#include <malloc.h>
#include <stddef.h>
typedef struct _mem_node_t
{
  void * mem_pointer;
  char * file_name;
  char * function;
  int line;
  int size;
  int flag;

} mem_node_t ;

#define MAX_MEM_PTRS 1024
mem_node_t mem_node[MAX_MEM_PTRS];

void *add_mem_node(int size, char * file_name, int line, char * function);
void del_mem_node(void * mem_pointer);
void show_mem_stat(void);
