#include<stdio.h>
#include<tm_queue.h>
int main()
{
int x1,x2,x3,x4;
int *x;
bool succ;
Queue *queue;
queue=createQueue(&succ);
if(succ) printf("Queue created\n");
else printf("Queue not created\n");
x1=10;
x2=20;
x3=30;
x4=40;

addToQueue(queue,(void *)&x1,&succ);
if(succ) printf("%d add to on queue\n",x1);
else printf("Not added to queue\n");


addToQueue(queue,(void *)&x2,&succ);
if(succ) printf("%d add to on queue\n",x2);
else printf("Not added to queue\n");

addToQueue(queue,(void *)&x3,&succ);
if(succ) printf("%d add to on queue\n",x3);
else printf("Not added to queue\n");

addToQueue(queue,(void *)&x4,&succ);
if(succ) printf("%d add to on queue\n",x4);
else printf("Not added to queue\n");


printf("Size of queue : %d\n",getSizeOfQueue(queue));

if(isQueueEmpty(queue)) printf("Queue is empty\n");
else printf("Queue not empty\n");

printf("Removed from queue\n");
while(!isQueueEmpty(queue))
{
x=removeFromQueue(queue,&succ);
if(succ) printf("%d Removed from queue\n",*x);
}
clearQueue(queue);
printf("Queue clear\n");
printf("Size of queue : %d\n",getSizeOfQueue(queue));


addToQueue(queue,(void *)&x1,&succ);
if(succ) printf("%d add to on queue\n",x1);
else printf("Not added to queue\n");

destroyQueue(queue);
printf("destroye queue \n");
return 0;
}