  #include<stdio.h>
  #include<stdlib.h>
  #include<ctype.h>
  
  typedef struct Stack
  {
    int top;
    char operators[10];
  }Stack;

int priority(char op)
{
  if(op=='^') return 5;
  else if(op=='(') return 2;
  else if(op=='+' || op=='-') return 3;
  else if(op=='*' || op=='/') return 4;
  
}

void push(Stack *s,char ele)
{
  s->operators[++(s->top)]=ele;
}
char pop(Stack *s)
{
  return s->operators[(s->top)--];
}
int should_pop(int in_stack,int new_ele)
{
  if(new_ele=='^') return 0;
  return in_stack>=new_ele;
}

int is_empty(Stack s)
{
  return (s.top==-1);
}
void main()
{
  Stack op;
  op.top=-1;
  char output[10];
  char input[10];
  int i=0;
  int o=0;
  printf("Enter the infix expression \n");
  scanf("%s",input);
  char symb;
  while(input[i]!='\0')
  {
    if(isdigit(input[i])) output[o++]=input[i];
    else
    {
      if(input[i]=='(') push(&op,input[i]);
      else if(input[i]==')')
      {
        if(is_empty(op))
        {
          printf("helo");
          printf("Invalid expression 59");
          exit(0);
        }
        symb=pop(&op);
        while(symb!='(')
        {
          output[o++]=symb;
          if(is_empty(op))
           {
              printf("Invalid expression 69");
              printf("helo");
              exit(0);
            }
          symb=pop(&op);
        }
       
      }
      else
      {
        while((should_pop(priority(op.operators[op.top]),priority(input[i]))) && !is_empty(op))
        {
          output[o++]=pop(&op);
        }
        push(&op,input[i]);
      }
    }
  i++;
  }
  
  while(!is_empty(op))
  {
    output[o++]=pop(&op);
  }
  output[o]='\0';
  printf("%s",output);
    
  }
