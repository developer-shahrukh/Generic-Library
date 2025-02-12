#ifndef __$_TM_SLL__C 
#define __$_TM_SLL__C 123
#include<tm_sll.h>
#include<tm_common.h>
#include<stdlib.h>
SinglyLinkedList * createSinglyLinkedList(bool *success)
{
SinglyLinkedList *singlyLinkedList;
if(success) *success=false;
singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(singlyLinkedList==NULL) return NULL;
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
if(success) *success=true;
return singlyLinkedList;
}
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return;
clearSinglyLinkedList(singlyLinkedList);
free(singlyLinkedList);
}
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return 0;
return singlyLinkedList->size;
}
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
SinglyLinkedListNode *node;
if(singlyLinkedList==NULL) return;
while(singlyLinkedList->start)
{
node=singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
free(node);
}
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
}
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success)
{
SinglyLinkedListNode *node;
if(singlyLinkedList==NULL) return;
if(success) *success=false;
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
if(singlyLinkedList->start==NULL)
{
singlyLinkedList->start=node;
singlyLinkedList->end=node;
}
else
{
singlyLinkedList->end->next=node;
singlyLinkedList->end=node;
}
if(success) *success=true;
singlyLinkedList->size++;
}
void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success)
{
int x;
SinglyLinkedListNode *p1,*p2;
SinglyLinkedListNode *node;
if(success) *success=false;
if(singlyLinkedList==NULL) return;
if(index<0 || index>singlyLinkedList->size) return;
if(index==singlyLinkedList->size)
{
addToSinglyLinkedList(singlyLinkedList,ptr,success);
return;
}
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
if(index==0)
{
node->next=singlyLinkedList->start;
singlyLinkedList->start=node;
singlyLinkedList->size++;
if(success) *success=true;
return;
}
x=0;
p1=singlyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next=p1;
p2->next=node;
singlyLinkedList->size++;
if(success) *success=true;
}
void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *succ)
{
void *ptr;
SinglyLinkedListNode *p1,*p2;
int x;
if(succ) *succ=false;
if(singlyLinkedList==NULL) return NULL;;
if(index<0 || index>=singlyLinkedList->size) return NULL;
x=0;
p1=singlyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(p1==singlyLinkedList->start && p1==singlyLinkedList->end)
{
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
}else if(singlyLinkedList->start==p1)
{
singlyLinkedList->start=singlyLinkedList->start->next;
}else if(singlyLinkedList->end==p1)
{
singlyLinkedList->end=p2;
singlyLinkedList->end->next=NULL;
}
else
{
p2->next=p1->next;
}
free(p1);
singlyLinkedList->size--;
if(succ) *succ=true;
return ptr;
}
void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList  *sourceSinglyLinkedList,bool *success)
{
SinglyLinkedListNode *s,*e,*t,*node;
bool done;
if(success) *success=false;
if(targetSinglyLinkedList==NULL) return;
if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceSinglyLinkedList->start;
while(t)
{
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) 
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
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
node=s;
s=s->next;
free(node);
}
return;
}
if(targetSinglyLinkedList->start==NULL)
{
targetSinglyLinkedList->start=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size=sourceSinglyLinkedList->size;
}
else
{
targetSinglyLinkedList->end->next=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;
}
if(success) *success=true;
}
void * getFromSinglyLinkedList(SinglyLinkedList * singlyLinkedList,int index,bool *success)
{
SinglyLinkedListNode *node;
int x;
if(success) *success=false;
if(singlyLinkedList==NULL) return NULL;
if(index<0 || index>=singlyLinkedList->size) return NULL;
x=0;
node=singlyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success) *success=true;
return node->ptr;
}
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success)
{
SinglyLinkedListIterator singlyLinkedListIterator;
singlyLinkedListIterator.node=NULL;
if(success) *success=false;
if(singlyLinkedList==NULL) return singlyLinkedListIterator;
if(singlyLinkedList->start==NULL)
{
if(success) *success=true;
return singlyLinkedListIterator;
}
if(success) *success=true;
singlyLinkedListIterator.node=singlyLinkedList->start;
return singlyLinkedListIterator;
}
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)
{
if(singlyLinkedListIterator==NULL) return false;
if(singlyLinkedListIterator->node==NULL) return false;
return true;
}
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success)
{
void *ptr;
ptr=NULL;
if(success) *success=false;
if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL) return ptr;
ptr=singlyLinkedListIterator->node->ptr;
singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}
#endif