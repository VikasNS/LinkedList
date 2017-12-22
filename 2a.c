#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
  
int binary_search(int arr[],int low,int high,int key)
{
  if(low>high) return -1;
  int mid=(low+high)/2;
  if(arr[mid]==key) return mid;
  else  if(arr[mid]>key) return binary_search(arr,low,mid-1,key);
  else return binary_search(arr,low+1,high,key);
}
  
void main()
{
 
 printf("Enter the array \n");
 int arr[10];
 for(int i=0;i<10;i++)
 {
   arr[i]=i*5;
 }
 for(int i=0;i<10;i++)
 {
   printf("%d \n",arr[i]);
 }
 printf("found at %d",binary_search(arr,0,9,25));
  
}
  
  
