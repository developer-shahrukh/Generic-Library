#include<stdio.h>
#include<tm_heap.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (* leftInt)-(* rightInt);
}
int main()
{
int x1,x2,x3,x4,x5,x6,x7;
int *ptr;
int succ,i;
Heap *heap;
heap=createHeap(myComparator,&succ);
if(!succ)
{
printf("Low of memory\n");
return 0;
}
x1=10;
x2=-3;
x3=44;
x4=5;
x5=60;
x6=4;

addToHeap(heap,&x1,&succ);
addToHeap(heap,&x2,&succ);
addToHeap(heap,&x3,&succ);
addToHeap(heap,&x4,&succ);
addToHeap(heap,&x5,&succ);

for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementFromHeap(heap,i,&succ);
printf("%d\n",*ptr);
}
printf("Now Updating\n");
x7=-20;
updateElementInHeap(heap,7,(void *)&x7,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementFromHeap(heap,i,&succ);
printf("%d\n",*ptr);
}

destroyHeap(heap);
return 0;
}