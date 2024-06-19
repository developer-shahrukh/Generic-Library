#ifndef __$_TM_DLL__C
#define __$_TM_DLL__C 123
#include<tm_dll.h>
#include<tm_common.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool * success)
{
DoublyLinkedList *doublyLinkedList;
if(success) *success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void destroyDoublyLinkedList(DoublyLinkedList * doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
int getSizeOfDoublyLinkedList(DoublyLinkedList * doublyLinkedList)
{
if(doublyLinkedList==NULL) return 0;
return doublyLinkedList->size;
}
void clearDoublyLinkedList(DoublyLinkedList * doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
while(doublyLinkedList->start)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}
void addToDoublyLinkedList(DoublyLinkedList * doublyLinkedList,void * ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success) *success=true;
}
void insertIntoDoublyLinkedList(DoublyLinkedList * doublyLinkedList,void * ptr,int index,bool * success)
{
int x;
DoublyLinkedListNode *p1,*node;
if(success) *success=false;
if(index<0 || index>doublyLinkedList->size) return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
return;
}
x=0;
p1=doublyLinkedList->start;
while(x<index)
{
p1=p1->next;
x++;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(p1==NULL)
{
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
}
if(p1==doublyLinkedList->start)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start->previous=node;
doublyLinkedList->start=node;
}
node->next=p1;
node->previous=p1->previous;
p1->previous->next=node;
p1->previous=node;
doublyLinkedList->size++;
if(success) *success=true;
}
void * removeFromDoublyLinkedList(DoublyLinkedList * doublyLinkedList,int index,bool *success)
{
void *ptr;
int x;
DoublyLinkedListNode *p1;
if(success) *success=false;
if(index<0 || index>=doublyLinkedList->size) return NULL;
x=0;
p1=doublyLinkedList->start;
while(x<index)
{
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(p1==doublyLinkedList->start && p1==doublyLinkedList->end)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}else if(p1==doublyLinkedList->start)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
}else if(p1==doublyLinkedList->end)
{
doublyLinkedList->end=doublyLinkedList->end->previous;
doublyLinkedList->end->next=NULL;
}
else
{
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
}
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
void appendToDoublyLinkedList(DoublyLinkedList * targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,bool *success)
{
bool done;
DoublyLinkedListNode *s,*e,*t,*node;
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=targetDoublyLinkedList->start;
while(t)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
node->previous=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s)
{
s=node;
s=s->next;
free(node);
}
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
}
void * getFromDoublyLinkedList(DoublyLinkedList * doublyLinkedList,int index,bool * success)
{
DoublyLinkedListNode *node;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
x=0;
node=doublyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success) *success=true;
return node->ptr;
}
DoublyLinkedListForwardIterator getDoublyLinkedListForwardIterator(DoublyLinkedList * doublyLinkedList,bool * success)
{
DoublyLinkedListForwardIterator doublyLinkedListForwardIterator;
doublyLinkedListForwardIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListForwardIterator;
if(doublyLinkedList->start==NULL)
{
if(success) *success=true;
return doublyLinkedListForwardIterator;
}
if(success) *success=true;
doublyLinkedListForwardIterator.node=doublyLinkedList->start;
return doublyLinkedListForwardIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListForwardIterator * doublyLinkedListForwardIterator)
{
if(doublyLinkedListForwardIterator==NULL) return false;
if(doublyLinkedListForwardIterator->node==NULL) return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator,bool * success)
{
void *ptr;
ptr=NULL;
if(success) *success=false;
if(doublyLinkedListForwardIterator==NULL || doublyLinkedListForwardIterator->node==NULL) return ptr;
ptr=doublyLinkedListForwardIterator->node;
doublyLinkedListForwardIterator->node=doublyLinkedListForwardIterator->node->next;
if(success) *success=true;
return ptr;
}
/*
DoublyLinkedListReverseIterator reverseGetDoublyLinkedListIterator(DoublyLinkedList * doublyLinkedList,bool * success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListReverseIterator;
if(doublyLinkedList->end==NULL)
{
if(success) *success=true;
return doublyLinkedListReverseIterator;
}
if(success) *success=true;
doublyLinkedListReverseIterator.node=doublyLinkedListReverseIterator->next;
return doublyLinkedListReverseIterator;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator * doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node->end==NULL) return false;
return true;
}
void * getPreviousInElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool * success)
{
void *ptr;
ptr=NULL;
if(success) *success=false;
if(doublyLinkedListReverseIterator==NULL || doublyLinkedListReverseIterator->node==NULL) return ptr;
ptr=doublyLinkedListReverseIterator->node;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
if(success) *success=true;
return ptr;
}
*/
#endif