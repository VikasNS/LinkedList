#include<stdio.h>

typedef struct Queue
{
  int front;
  int rear;
  int arr[10];
}queue;

int is_full(queue *q)
{
  return (((q->rear)+1)%10==q->front);
}
int is_empty(queue *q)
{
  return (q->front==q->rear);
}

void insert(queue *q,int info)
{
  if(is_full(q)) printf("FULL");
  else 
  {
    q->rear=((q->rear)+1)%10;
    q->arr[q->rear]=info;
  }
}

void remov(queue *q)
{
  q->front=((q->front)+1)%10;
  printf("%d was deleted \n",q->arr[q->front]);
  
}

void display(queue q)
{
  int i=q.front;
  do
  {
    i=(i+1)%10;
    printf("%d ",q.arr[i]);
    
  }while(i!=q.rear);
  
}
void main()
{
  queue q;
  q.front=0;
  q.rear=0;
  insert(&q,10);
  insert(&q,20);
  insert(&q,30);
  insert(&q,40);
  insert(&q,10);
  insert(&q,20);
  insert(&q,30);
  insert(&q,40);
  insert(&q,10);
  insert(&q,10);
  
  printf("%d %d \n",q.front,q.rear);
  display(q);
  
}
