#include<stdio.h>
#include<stdlib.h>
#define null 0
struct node 
{
  int info;
  struct node * next;
  
};
typedef struct node * Nodeptr;

Nodeptr getNode()
{
  return (Nodeptr)malloc(sizeof(Nodeptr));
}

void display(Nodeptr list)
{
  if(list==null) printf("Empty list");
  else
  {
    Nodeptr curr=list;
    while(curr!=null) 
    {
      printf("%d",curr->info);
      if(curr->next!=null) printf("->");
      curr=curr->next;
    }
    
  }
}

void insert_front(Nodeptr *list,int info)
{
  
  Nodeptr newnode=getNode();
  newnode->info=info;
  newnode->next=*list;
  *list=newnode;
}

void delete_nth(Nodeptr *list,int n)
{
  if(*list!=null)
  {
    Nodeptr curr=*list;
    Nodeptr prev=null;
    int i=1;
    while(curr!=null)
    {
      if(i==n)
      {
        if(prev==null) *list=curr->next;
        else  prev->next=curr->next;
        free(curr);
        break;
      }
      prev=curr;
      curr=curr->next;
      i++;
    }
  }
}

void insert_nth(Nodeptr *list,int info,int n)
{
  int i=1;
  Nodeptr newnode=getNode();
  newnode->info=info;
  Nodeptr curr=*list;
  Nodeptr prev=null;
  int done=1;
  while(curr!=null)
  {
      
      if(i==n)
      {
        if(prev==null) *list=newnode;
        else prev->next=newnode;
        newnode->next=curr;
        done=0;
        break;
        
      }
      prev=curr;
      curr=curr->next;
  i++;  
  }
  
  if(done)
  {
    if(i==n)
      {
       newnode->next=null;
       prev->next=newnode;
      }
  }
}

int main(void) {
  Nodeptr n=getNode();
  n->info=30;
  for(int i=9;i>0;i--)
  {
    insert_front(&n,i*3);
    
  }
  // 
  // Nodeptr n2=getNode();
  // n2->info=12;
  // n->next=n2;
  // n2->next=null;
  display(n);
  printf("\n");
  delete_nth(&n,11);
  display(n);
}
