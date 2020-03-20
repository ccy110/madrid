/****************************************
技巧04:使用指针输出数组元素
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[10] = {1,1,1};
  int *p,i;
  // puts("please input ten integer:\n");
  // for(i=1; i<=10; i++)
  //   scanf("%d", &a[i]);

  // printf ("\n");

  for(p=&a; p<(a+10); p++)
    printf ("%d ", *p);
  return 0;
}