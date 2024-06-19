#ifndef __$_TM_HEAP__H
#define __$_TM_HEAP__H 123
#include<tm_common.h>
#include<tm_array.h>
typedef struct __$_tm_heap
{
Array *array;
int (*comparator)(void *,void *);
int size;
}Heap;

Heap * createHeap(int (*comparator)(void *,void *),int *succ);
void addToHeap(Heap *heap,void *element,int *succ);
void  * removeFromHeap(Heap *heap,int *succ);
void * elementAtTopOfHeap(Heap *heap,int *succ);
int getSizeOfHeap(Heap *heap);
void destroyHeap(Heap *heap);
void *getElementFromHeap(Heap *heap,int index,int *success);
void updateElementInHeap(Heap *heap,int index,void *element,int *success);

#endif
