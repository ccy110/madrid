/****************************************
技巧12：使用返回指针的函数查找最大值
****************************************/
#include <stdio.h>
#include <windows.h>

*FindMax(int *p, int n)  //定义指针函数
{
  int i, *max;

  max=p;
  
  for(i=0;i<n;i++)
    if(*(p+i)>*max)
      max=p+i;
  return max;
}

int main(int argc, char *argv[])
{
  int a[10], *max, i;

  printf ("please input ten integer:\n");
  for (i=0; i<10; i++)
    {
      scanf("%d",&a[i]);
    }


  max = FindMax(a, 10);
  
  printf ("the max number is: %d\n",*max);
  Sleep(10000);
  return 0;
}