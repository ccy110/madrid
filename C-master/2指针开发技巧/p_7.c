/****************************************
技巧06：使用指针查找数列中最大值/最小值
****************************************/
#include <stdio.h>
void max_min(int a[],int n,int *max,int *min)
{
  int *p;
  
  *max = *min = *a;

  for(p=a+1; p<a+n; p++)
    {  
      if(*p>*max)
        *max=*p;
      else if(*p<*min)
        *min=*p;
    } 
  return 0;
}


int main(int argc, char *argv[])
{
  int a[10];
  int max,min;
  printf ("input 10 integer numbers you want to operate:\n");
  for(int i=0; i<10; i++)
    scanf("%d",&a[i]);
  max_min(a,10,&max,&min);
  printf ("the maximun number is:%d\n",max);
  printf ("the maxinun number is:%d\n",min);
  return 0;
}