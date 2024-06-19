#include<tm_array.h>
#include<stdio.h>
int main()
{
Array *array;
int num1,num2,num3;
int succ;
int i;
int *ptr;
array=createArray(&succ);
if(!succ)
{
printf("Unable to allocate array\n");
return 0;
}
num1=100;
num2=300;
num3=350;
setElementOfArray(array,2,(void *)&num1,&succ);
setElementOfArray(array,25,(void *)&num2,&succ);
setElementOfArray(array,1443,(void *)&num3,&succ);

for(i=0;i<getSizeOfArray(array);i++)
{
ptr=(int*)getElementOfArray(array,i);
if(ptr!=NULL) printf("%d-->%d\n",i,*ptr);
else printf("(%d--> )",i);
}
return 0;
}