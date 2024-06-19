#ifndef __$_TM_DLL__H
#define __$_TM_DLL__H 123
#include<tm_common.h>
typedef struct __$_tm_dll_node
{
void *ptr;
struct __$_tm_dll_node *next;
struct __$_tm_dll_node *previous;
}DoublyLinkedListNode;
typedef struct __$_tm_dll
{
struct __$_tm_dll_node *start;
struct __$_tm_dll_node *end;
int size;
}DoublyLinkedList;

typedef struct __$_tm_forward_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListForwardIterator;

typedef struct __$_tm_reverse_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListReverseIterator;

DoublyLinkedList * createDoublyLinkedList(bool * success);
void destroyDoublyLinkedList(DoublyLinkedList * doublyLinkedList);
int getSizeOfDoublyLinkedList(DoublyLinkedList * doublyLinkedList);

void clearDoublyLinkedList(DoublyLinkedList * doublyLinkedList);
void addToDoublyLinkedList(DoublyLinkedList * doublyLinkedList,void * ptr,bool * success);
void insertIntoDoublyLinkedList(DoublyLinkedList * doublyLinkedList,void * ptr,int index,bool * success);

void * removeFromDoublyLinkedList(DoublyLinkedList * doublyLinkedList,int index,bool *success);
void appendToDoublyLinkedList(DoublyLinkedList * targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,bool *success);
void * getFromDoublyLinkedList(DoublyLinkedList * doublyLinkedList,int index,bool * success);

DoublyLinkedListForwardIterator getDoublyLinkedListForwardIterator(DoublyLinkedList * doublyLinkedList,bool * success);
bool hasNextInDoublyLinkedList(DoublyLinkedListForwardIterator * doublyLinkedListForwardIterator);
void * getNextElementFromDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator,bool * success);

DoublyLinkedListReverseIterator reverseGetDoublyLinkedListIterator(DoublyLinkedListReverseIterator * doublyLinkedListReverseIterator,bool * success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator * doublyLinkedListReverseIterator);
void * getPreviousInElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool * success);

#endif