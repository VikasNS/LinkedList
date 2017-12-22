#include<stdio.h>

int gcd(int m,int n)
{
  if(m==n) return m;
  else if(m>n) return gcd(m-n,n);
  else return gcd(m,n-m);
}

void main()
{
 printf("%d",gcd(3,6));
}
  
  
