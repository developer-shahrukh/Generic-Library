#include<stdio.h>
#include<tm_stack.h>
int main()
{
int x1,x2,x3,x4;
int *x;
bool succ;
Stack *stack;
stack=createStack(&succ);
if(succ) printf("Stack created\n");
else printf("Stack not created\n");
x1=10;
x2=20;
x3=30;
x4=40;

pushOnStack(stack,(void *)&x1,&succ);
if(succ) printf("%d pushed on stack\n",x1);
else printf("Not push on stack\n");

pushOnStack(stack,(void *)&x2,&succ);
if(succ) printf("%d pushed on stack\n",x2);
else printf("Not push on stack\n");

pushOnStack(stack,(void *)&x3,&succ);
if(succ) printf("%d pushed on stack\n",x3);
else printf("Not push on stack\n");

pushOnStack(stack,(void *)&x4,&succ);
if(succ) printf("%d pushed on stack\n",x4);
else printf("Not push on stack\n");

printf("Size of stack : %d\n",getSizeOfStack(stack));

if(isStackEmpty(stack)) printf("Stack is empty\n");
else printf("Stack not empty\n");

printf("Popped from stack\n");
while(!isStackEmpty(stack))
{
x=popFromStack(stack,&succ);
if(succ) printf("%d popped from stack\n",*x);
}
clearStack(stack);
printf("Stack clear\n");
printf("Size of stack : %d\n",getSizeOfStack(stack));

pushOnStack(stack,(void *)&x4,&succ);
if(succ) printf("%d pushed on stack\n",x4);
else printf("Not push on stack\n");

destroyStack(stack);
printf("destroye stack \n");
return 0;
}