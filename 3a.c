#include<stdio.h>

int toh(int n,char from,int via,int to)
{
  if(n>0)
  {
    toh(n-1,from,to,via);
    printf("%d from %c to %c \n",n,from,to);
    toh(n-1,via,from,to);
  }
}

void main()
{
 toh(3,'A','B','C');
}
  
  
