#ifndef __$_TM_PQUEUE__H
#define __$_TM_PQUEUE__H 123
#include<tm_heap.h>
#include<tm_common.h>
typedef struct __$_tm_pQueue
{
Heap *heap;
}PQueue;

PQueue * createPQueue(int (*predicate)(void *,void *),bool *success);
void addToPQueue(PQueue *pQueue,void *ptr,bool *success);
void * removeFromPQueue(PQueue *pQueue,bool *success);
void * elementAtFrontOfPQueue(PQueue *pQueue,bool *success);
int getSizeOfPQueue(PQueue *pQueue);
int isPQueueEmpty(PQueue *pQueue);
void clearPQueue(PQueue *pQueue);
void destroyPQueue(PQueue *pQueue);
void *getElementFromPQueue(PQueue *pQueue,int index,int *success);
void updateElementInPQueue(PQueue *pQueue,int index,void *element,int *success);
#endif