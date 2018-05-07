#include<stdio.h>
#define size 3
#define true 1
#define false 0
typedef int bool;
struct stack
{
int number[size];
int top;
};
typedef struct stack STACK;

void push(STACK *s,int newElement);
void pop(STACK *s,int *removedElement,bool *isremoved);
bool isStackEmpty(STACK *s);
bool isStackNotFull(STACK *s);
void display(STACK s);

void main()
{
STACK newStack;
newStack.top=-1;
int removedElement;
bool isremoved=false;
int element,choice;

do
{
printf("Please Enter 1 to PUSH 2 to POP 3 to Display the Stack and 4 to QUIT \n");
scanf("%d",&choice);
switch(choice)
{

case 1:
printf("Please enter the element to pushed into the stack \n");
scanf("%d",&element);
push(&newStack,element);
printf("%d was added successfully",element);
break;

case 2:
pop(&newStack,&removedElement,&isremoved);
if(isremoved)
printf("%d was removed \n",removedElement);
break;

case 3:
display(newStack);
break;
case 4:
break;
default:
printf("Invalid Input \n");

}

}while(choice!=4);

}

void push(STACK *s,int newElement)
{
if(isStackNotFull(s))
{

s->number[++(s->top)]=newElement;

}
else
{
printf("Stack is full \n");
}

}

void pop(STACK *s,int *removedElement,bool *isremoved)
{
if(isStackEmpty(s))
{
printf("Stack is Empty \n");
}else
{
*removedElement=s->number[(s->top)--];
*isremoved=true;

}

}

bool isStackEmpty(STACK *s)
{
if(s->top==-1)
{
return true;
}
else
{
return false;
}


}

bool isStackNotFull(STACK *s)
{
if(s->top==size-1)
{
return false;
}
else
return true;

}

void display(STACK s)
{
int j=0;
for(j=0;j<=s.top;j++)
{
printf("%d \n",s.number[j]);
}
}
