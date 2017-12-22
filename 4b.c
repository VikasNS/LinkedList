#include<stdio.h>
#include<stdlib.h>
#define null 0
struct Node{
  int info;
  struct Node * next;
  
};
typedef struct Node * Nodeptr;
Nodeptr getNode()
{return (Nodeptr) malloc(sizeof(Nodeptr));}
void display(Nodeptr list)
{
  if(list==null) printf("LL is empty");
  else
  {
    Nodeptr curr=list;
    while(curr!=null)
   {
    printf("%d",curr->info);
  if(curr->next!=null) printf("->");curr=curr->next;
    
  }
    
  }
  
}
void insert_end(Nodeptr *list,int info)
{
  Nodeptr newnode=getNode();
  newnode->info=info;
  newnode->next=null;
  if(*list==null) *list=newnode;
  else 
  {
    Nodeptr curr=*list;
    while(curr->next!=null) curr=curr->next;
    curr->next=newnode;
  }
}

void delete_begining(Nodeptr *list)
{
  if(*list==null) printf("null");
  else
  {
    *list=(*list)->next;
  }
}

void main()
{
  Nodeptr n=null;
  insert_end(&n,1);
  insert_end(&n,2);
  insert_end(&n,3);
  display(n);
  printf("\n");
  delete_begining(&n);
  delete_begining(&n);
  display(n);
  
}

