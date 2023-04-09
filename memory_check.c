//#include <malloc.h>
//
//typedef struct _mem_node_t
//{
//  void * mem_pointer;
//  char * file_name;
//  char * function;
//  int line;
//  int size;
//  int flag;
//
//} mem_node_t ;
//
//#define MAX_MEM_PTRS 1024
//mem_node_t mem_node[MAX_MEM_PTRS];
#include "memory_check.h"


void *add_mem_node(int size,
                   char * file_name,
                   int line,
                   char * function)
{

  int i = 0;
  int ret = -1;

  void *pointer = malloc(size);

  for(i = 0; i < MAX_MEM_PTRS; i++) {
      if(mem_node[i].flag == 0) {
        mem_node[i].flag = 1;
        mem_node[i].mem_pointer = pointer;
        mem_node[i].file_name = file_name;
        mem_node[i].function = function;
        mem_node[i].line = line;
        mem_node[i].size = size;
        ret = 0;
        break;
      }
  }
  return pointer;
}

void del_mem_node(void * mem_pointer)
{

  int i = 0;
  int ret = -1;

  for(i = 0; i < MAX_MEM_PTRS; i++) {
      if(mem_node[i].mem_pointer == mem_pointer) {
        mem_node[i].flag = 0;
        mem_node[i].mem_pointer = NULL;
        mem_node[i].file_name = 0;
        mem_node[i].function = 0;
        mem_node[i].line = 0;
        mem_node[i].size = 0;
        ret = 0;
        free(mem_pointer);
        break;
      }
  }
  return;
}
//Memory check function
void show_mem_stat(void)
{
  int i = 0;
  int ret = 0;

  for(i = 0; i < MAX_MEM_PTRS; i++) {
      if(mem_node[i].flag == 1) {
        printf("0x%p of %d bytes allocated"
               " from %s:%d in %s() is not freed\r\n",
               mem_node[i].mem_pointer,
               mem_node[i].size,
               mem_node[i].file_name,
               mem_node[i].line,
               mem_node[i].function);
        ret = 1;
      }
  }
  if(ret == 0) {
     printf("no memory leak detected! ");
  }
  return;
}

#undef malloc
#define malloc(size) add_mem_node(size, \
                                  __FILE__, \
                                  __LINE__, \
                                  (char*)__FUNCTION__)
#undef free
#define free(_p) del_mem_node(_p)
