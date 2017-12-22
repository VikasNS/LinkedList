#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
  
float calc(float op2,char oper,float op1)
{
  switch(oper)
  {
    case '+':return (op1+op2);
    case '-':return (op1-op2);
    case '*':return (op1*op2);
    case '/': if(op2==0)
              {
                printf("Division by zero error");
                exit(0);
              }else return (op1/op2);
    case '^':return powf(op1,op2);
    default:printf("Invalid");
            exit(0);
              
  }
}

typedef struct Stack
  {
    int top;
    float operators[10];
  }Stack;

void push(Stack *s,float ele)
{
  s->operators[++(s->top)]=ele;
}
float pop(Stack *s)
{
  return s->operators[(s->top)--];
}


void main()
{
 Stack s;
 s.top=-1;
 char inp[10];
 printf("Enter the postfix exp");
 scanf("%s",inp);
 int i=0;
 while(inp[i]!='\0')
 {
   if(isdigit(inp[i])) push(&s,(inp[i]-'0'));
   else
   {
     float op2=pop(&s);
     float op1=pop(&s);
     push(&s,calc(op2,inp[i],op1));
   }
   i++;
 }
  printf("%f",pop(&s));
}
  
  
