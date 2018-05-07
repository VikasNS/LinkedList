#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct node
{
  struct node * left;
  struct node * right;
  int info;
};
typedef  struct node * Nodeptr;

Nodeptr getNode()
{
  return (Nodeptr)malloc(sizeof(Nodeptr));
}
/*Evaluating an Expression Tree */
float oper(float op1,char op,float op2)
{
  switch(op)
  {
    case '+': return op1+op2;
    break;
    case '-': return op1-op2;
    break;
    case '*': return op1*op2;
    break;
    case '^': return pow(op1,op2);
    break;
    case '/': return op1/op2;
    break;
    default : printf("Invalid operand");
    }
}

float evalExpTree(Nodeptr tree)
{
  if(isdigit(tree->info)) return (float)((tree->info)-'0');
  else
  {
    float op2=evalExpTree(tree->right);
    float op1=evalExpTree(tree->left);
    return oper(op1,tree->info,op2);
  }
}
/*Evaluating an Expression Tree */


/*Creating an Expression Tree*/

//Operand stack//
typedef struct operandStack
{
  int top;
  Nodeptr operands[100];
}operandStack;

void push(operandStack *opS,Nodeptr node)
{
  opS->operands[++(opS->top)]=node;
}

Nodeptr pop(operandStack *opS)
{
  return opS->operands[(opS->top)--];
}

int count(operandStack *opS)
{
  return (opS->top)+1;
}
//Operand stack//

Nodeptr createEvalTree(char postfix[10])
{
  operandStack opS;
  opS.top=-1;
  int i=0;
  
  while(postfix[i]!='\0')
  {
    Nodeptr newnode=getNode();
    newnode->info=postfix[i];
    
    if(isdigit(postfix[i])) 
    {
      newnode->right=NULL;
      newnode->left=NULL;
      push(&opS,newnode);
      
    }else
    {
      newnode->right=pop(&opS);
      newnode->left=pop(&opS);
      push(&opS,newnode);
      printf("poped %d \n",newnode->right->info);
      printf("poped %d \n",newnode->left->info);
      
    }
    i++;
  }
  return pop(&opS);
}



/*Creating an Expression Tree*/

void inPostTrav(Nodeptr root)
{
    if(root==NULL) return;
    else
    {
        inPostTrav(root->left);
        inPostTrav(root->right);
        printf("%c ",root->info);
    }
}

void main()
{
  char postfix[10];
  printf("Enter the post fix expression");
  scanf("%s",postfix);
  Nodeptr root=createEvalTree(postfix);
  printf("%f",evalExpTree(root));
}
