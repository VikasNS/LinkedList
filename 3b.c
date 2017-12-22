#include<stdio.h>
#include<stdlib.h>
#define null 0
struct Node
{
  int info;
  struct Node * next;
};
typedef struct Node * Nodeptr;

Nodeptr getNode()
{
  return (Nodeptr) malloc(sizeof(Nodeptr));
}

void insert_begining(Nodeptr *list,int info)
{
  Nodeptr newnode=getNode();
  newnode->info=info;
  newnode->next=*list;
  *list=newnode;
}

void display(Nodeptr list)
{
  if(list==null) printf("LL is empty");
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

void delete_end(Nodeptr *list)
{
  if(*list==null) printf("LL is empty");
  else
  {
    Nodeptr prev=null;
    Nodeptr curr=*list;
    while(curr->next!=null)
    {
      prev=curr;
      curr=curr->next;
    }
    if(prev==null) *list=null;
    else prev->next=null;
  }
}
void main()
{
 Nodeptr n=null;
 insert_begining(&n,3);
 insert_begining(&n,2);
 insert_begining(&n,1);
 display(n);
 printf("\n");
 delete_end(&n);
 delete_end(&n);
 display(n);
}
  
  
