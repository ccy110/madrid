/****************************************
技巧05：用指针实现逆序存放数组元素值
****************************************/
#include <stdio.h>
#include <windows.h>
inverte(int *x,int n)
{

  int *i; 
  int *p; 
  int *j;

  int temp; 
  int m = (n-1)/2;

  printf("m:=======%d \n", m);
  
  i = x;
  j = x+n-1;
  p = x+m;

  for (i=x; i<=p; i++,j--)
    {
      temp=*i;
      *i=*j;
      *j=temp;
    }
  return 0;
}

int main(int argc, char *argv[])
{
  int i;
  int a[10] = {1,2,3,4,5,6,7,8,9,0};

  printf ("the elements of original array:\n");

  for(i=0;i<10;i++)
    printf ("%d ",a[i]);
  printf ("\n");

  inverte(a,10);

  printf ("the elements has been inverted:\n");

  for(i=0;i<10;i++)
    printf ("%d ",a[i]);

  printf ("\n");

  Sleep(10000);
  return 0;
}