#ifndef __$_TM_QUEUE__H
#define __$_TM_QUEUE__H 123
#include<tm_sll.h>
#include<tm_common.h>
typedef struct __$_tm_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;

Queue * createQueue(bool *success);
void addToQueue(Queue *queue,void *ptr,bool *success);
void * removeFromQueue(Queue *queue,bool *success);
void * elementAtTopOfQueue(Queue *queue,bool *success);
int getSizeOfQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif