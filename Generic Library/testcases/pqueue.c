#include<stdio.h>
#include<tm_pqueue.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int x1,x2,x3,x4,x5;
int *ptr;
int succ;
PQueue *pQueue;
pQueue=createPQueue(myComparator,&succ);
if(!succ)
{
printf("Low of memory\n");
return 0;
}
x1=100;
x2=30;
x3=50;
x4=20;
x5=29;

addToPQueue(pQueue,&x1,&succ);
addToPQueue(pQueue,&x2,&succ);
addToPQueue(pQueue,&x3,&succ);
addToPQueue(pQueue,&x4,&succ);
addToPQueue(pQueue,&x5,&succ);

while(getSizeOfPQueue(pQueue)>0)
{
ptr=(int *)removeFromPQueue(pQueue,&succ);
printf("%d\n",*ptr);
}
// destroyPQueue(pQueue);
return 0;
}