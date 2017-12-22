#include<stdio.h>

typedef struct Queue
{
  int front;
  int rear;
  int arr[10];
}queue;

int is_full(queue *q)
{
  return (q->rear==9);
}
int is_empty(queue *q)
{
  return (q->front>q->rear);
}

void insert(queue *q,int info)
{
  if(is_full(q)) printf("FULL");
  else q->arr[++(q->rear)]=info;
}

void remov(queue *q)
{
  printf("%d was deleted",q->arr[(q->front)++]);
  if(is_empty(q))
  {
    q->rear=-1;
    q->front=0;
  }
}

void display(queue q)
{
  for(int i=q.front;i<=q.rear;i++)
  {
    printf("%d ",(q.arr)[i]);
  }
}
void main()
{
  queue q;
  q.front=0;
  q.rear=-1;
  insert(&q,10);
  insert(&q,20);
  insert(&q,30);
  display(q);
  remov(&q);
  
  display(q);
}
