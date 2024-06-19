#include<tm_dll.h>
#include<stdio.h>
int main()
{
bool success;
DoublyLinkedListForwardIterator itr;
int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,y,k;
int *x;
DoublyLinkedList *list1,*list2;
list1=createDoublyLinkedList(&success);
list2=createDoublyLinkedList(&success);
printf("List created\n");
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
i7=10;
i8=9;
i9=25;
i10=15;
addToDoublyLinkedList(list2,(void *)&i1,&success);
addToDoublyLinkedList(list2,(void *)&i2,&success);
addToDoublyLinkedList(list2,(void *)&i3,&success);
addToDoublyLinkedList(list2,(void *)&i4,&success);
addToDoublyLinkedList(list2,(void *)&i5,&success);

printf("Size of List 1 : %d\n",getSizeOfDoublyLinkedList(list2));
printf("Size of List 1 : %d\n",getSizeOfDoublyLinkedList(list1));

printf("****************\n");
for(y=0;y<getSizeOfDoublyLinkedList(list2);y++)
{
x=(int *)getFromDoublyLinkedList(list2,y,&success);
printf("%d\n",*x);
}


insertIntoDoublyLinkedList(list2,(void *)&i6,0,&success);
insertIntoDoublyLinkedList(list2,(void *)&i7,5,&success);

printf("*******************\n");
printf("Size list2 : %d\n",getSizeOfDoublyLinkedList(list2));
for(y=0;y<getSizeOfDoublyLinkedList(list2);y++)
{
x=(int *)getFromDoublyLinkedList(list2,y,&success);
printf("%d\n",*x);
}
printf("*******************\n");

insertIntoDoublyLinkedList(list2,(void *)&i8,3,&success);
insertIntoDoublyLinkedList(list2,(void *)&i9,8,&success);
printf("*******************\n");
printf("Size list2 : %d\n",getSizeOfDoublyLinkedList(list2));
for(y=0;y<getSizeOfDoublyLinkedList(list2);y++)
{
x=(int *)getFromDoublyLinkedList(list2,y,&success);
printf("%d\n",*x);
}
printf("*******************\n");

insertIntoDoublyLinkedList(list2,(void *)&i10,7,&success);
printf("*******************\n");
printf("Size list2 : %d\n",getSizeOfDoublyLinkedList(list2));
for(y=0;y<getSizeOfDoublyLinkedList(list2);y++)
{
x=(int *)getFromDoublyLinkedList(list2,y,&success);
printf("%d\n",*x);
}
printf("*******************\n");


/*
appendToDoublyLinkedList(list1,list2,&success);
if(success) printf("Append to list1 to list 2\n");
else printf("Unable to appand \n");

for(y=0;y<getSizeOfDoublyLinkedList(list2);y++)
{
x=(int *)getFromDoublyLinkedList(list2,y,&success);
printf("%d\n",*x);
}

printf("After Iterating\n");
itr=getDoublyLinkedListForwardIterator(list1,&success);
if(success)
{
while(hasNextInDoublyLinkedList(&itr))
{
x=(int *)getNextElementFromDoublyLinkedList(&itr,&success);
if(success) printf("%d\n",*x);
}
}
*/
clearDoublyLinkedList(list1);
printf("List clearing\n");
destroyDoublyLinkedList(list1);
printf("Destroyed doubly linked list\n");
return 0;
}