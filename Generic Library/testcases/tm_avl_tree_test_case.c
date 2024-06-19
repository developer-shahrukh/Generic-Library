#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preIterator;
AVLTreePostOrderIterator postOrderIterator;
char more;
int *x;
int num,ch;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree, low on memory\n");
return 0;
}
while(1)
{
printf("1. insert in AVL tree\n");
printf("2. in order traversal \n");
printf("3. Remove\n");
printf("4. Search\n");
printf("5. Pre order traversal\n");
printf("6. Get height of tree\n");
printf("7. Post Order traversal\n");
printf("8. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number to be inserted in tree : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success) printf("Address of item that contains %d inserted in tree\n",*x);
else printf("Unable to insert in tree\n");
}
if(ch==2)
{
printf("In Order Iteration starts\n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==3)
{
printf("Enter a number to delete : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&success);
if(success) printf("%d deleted\n",*x);
else printf("%d Not found in AVL tree\n",num);
}
if(ch==4)
{
printf("Enter a number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d Found\n",*x);
else printf("%d Not found in AVL tree\n",num);
}
if(ch==5)
{
printf("Pre Order Iteration starts\n");
preIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{
while(hasNextPreOrderElementInAVLTree(&preIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==6)
{
//printf("Height of tree is %d\n",getHeightOfAVLTree(tree));
}

if(ch==7)
{
printf("Post Order Iteration starts\n");
postOrderIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==8) break;
}
destroyAVLTree(tree);
return 0;
}