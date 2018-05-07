/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define NULL 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{
    int info;
    struct node * right;
    struct node * left;
};
typedef struct node * nodeptr;

nodeptr getNode()
{
    return (nodeptr)malloc(sizeof(nodeptr));
}
nodeptr createRootNode(int info)
{
    nodeptr newnode=getNode();
    newnode->info=info;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

int isLeftThere(nodeptr node)
{
    return (node->left!=NULL);
}

int isRightThere(nodeptr node)
{
    return (node->right!=NULL);
}

void insertRight(nodeptr root,int info)
{
    if(isRightThere(root)) printf("right node allready exists");
    else 
    {
        nodeptr newnode=getNode();
        newnode->info=info;
        newnode->right=NULL;
        newnode->left=NULL;
        
        root->right=newnode;
    }
}

void prevTrav(nodeptr root)
{
    if(root==NULL) return;
    else
    {
        printf("%c ",root->info);
        prevTrav(root->left);
        prevTrav(root->right);
    }
}

void inOrderTrav(nodeptr root)
{
    if(root==NULL) return;
    else
    {
        prevTrav(root->left);
        printf("%c ",root->info);
        prevTrav(root->right);
    }
}

void inPostTrav(nodeptr root)
{
    if(root==NULL) return;
    else
    {
        inPostTrav(root->left);
        inPostTrav(root->right);
        printf("%c ",root->info);
    }
}

void checkDuplicateAndInsert(nodeptr root)
{
    int info;
    nodeptr prev=NULL;
    nodeptr curr=root;
    
    
    printf("Enter the element,or enter -1 to exit \n");
    scanf("%d",&info);
    printf("ok 98 \n");
    while(info!=-1)
    {
        prev=NULL;
        curr=root;
        printf("ok 101 \n");
        while(curr!=NULL && curr->info!=info  )   
        {
            printf("ok 104 \n");
            prev=curr;
            printf("ok 105 \n");
            if(curr->info>info) 
            {curr=curr->left;
            printf("ok 108 \n");}
            else curr=curr->right;
            printf("ok 110 \n");
            printf("prev is %d \n",prev->info);
            printf("Curr is %d \n",curr);
        }
        printf("ok 117 \n");
        if(1)
        {
            printf("ok 115 \n");
            nodeptr newnode=getNode();
            newnode->info=info;
            newnode->right=NULL;
            newnode->left=NULL;
            
            printf("ok 121 \n");
            if(prev->info<info) 
            {
                prev->left=newnode;
                printf("ok 125 \n");
            }
            else prev->right=newnode;
        }else printf("%d allready exists",info);
        
        printf("Enter the next element");
        scanf("%d",&info);
    }
}
void insertLeft(nodeptr root,int info)
{
    if(isLeftThere(root)) printf("left node allready exists");
    else 
    {
        nodeptr newnode=getNode();
        newnode->info=info;
        newnode->right=NULL;
        newnode->left=NULL;
        
        root->left=newnode;
    }
}

/*To create Evaluation Tree*/

//Operand stack//
typedef struct operandStack
{
  int top;
  nodeptr operands[100];
}operandStack;

void push(operandStack *opS,nodeptr node)
{
  opS->operands[++(opS->top)]=node;
}

nodeptr pop(operandStack *opS)
{
  return opS->operands[(opS->top)--];
}

int count(operandStack *opS)
{
  return (opS->top)+1;
}
//Operand stack//

//Eval Tree//
nodeptr createEvalTree(char postfix[10])
{
  operandStack opS;
  opS.top=-1;
  int i=0;
  
  while(postfix[i]!='\0')
  {
    nodeptr newnode=getNode();
    newnode->info=postfix[i];
    
    
    
    if(isdigit(postfix[i])) 
    {
      newnode->right=NULL;
      newnode->left=NULL;
      push(&opS,newnode);
      printf("pushed %d \n",newnode->info);
    }else
    {
      newnode->right=pop(&opS);
      newnode->left=pop(&opS);
      push(&opS,newnode);
      printf("poped %d \n",newnode->right->info);
      printf("poped %d \n",newnode->left->info);
      printf("pushed %c \n",newnode->info);
    }
    
    
    
    
    
    i++;
  }
  return pop(&opS);
}



//Eval Tree//









int main()
{
   printf("enter the postfix exp");
   char post[10];
   scanf("%s",post);
   nodeptr root=createEvalTree(post);
   prevTrav(root);
   
   
}



