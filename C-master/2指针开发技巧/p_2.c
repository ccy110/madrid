/****************************************
技巧02:使用指针实现数据交换
****************************************/
#include <stdio.h>
swap(int *p1,int *p2)
{
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}
int main(int argc, char *argv[])
{
  int a,b;
  int *pointer1,*pointer2;
  printf ("please input two swap numbers:\n");
  scanf("%d%d",&a,&b);
  pointer1=&a;
  pointer2=&b;
  swap(pointer1,pointer2);
  printf ("the result is :%d,%d\n",a,b);
  return 0;
}