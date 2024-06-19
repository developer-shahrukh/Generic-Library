#include<stdio.h>
#include<tm_sll.h>
int main()
{
bool success;
SinglyLinkedListIterator itr;
int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,y;
int *x;
SinglyLinkedList *list1,*list2;
list1=createSinglyLinkedList(&success);
list2=createSinglyLinkedList(&success);
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
addToSinglyLinkedList(list1,(void *)&i1,&success);
addToSinglyLinkedList(list1,(void *)&i2,&success);
addToSinglyLinkedList(list1,(void *)&i3,&success);
addToSinglyLinkedList(list2,(void *)&i4,&success);
addToSinglyLinkedList(list2,(void *)&i5,&success);

appendToSinglyLinkedList(list1,list2,&success);
if(success) printf("Append to list1 to list 2\n");
else printf("Unable to appand \n");

printf("Size Is : %d\n",getSizeOfSinglyLinkedList(list1));

for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
x=(int *)getFromSinglyLinkedList(list1,y,&success);
printf("%d\n",*x);
}
printf("After Iterating\n");

itr=getSinglyLinkedListIterator(list1,&success);
if(success)
{
while(hasNextInSinglyLinkedList(&itr))
{
x=(int *)getNextElementFromSinglyLinkedList(&itr,&success);
if(success) printf("%d\n",*x);
}
}
clearSinglyLinkedList(list1);
printf("List clearing\n");
destroySinglyLinkedList(list1);
printf("Destroyed singly linked list\n");
return 0;
}