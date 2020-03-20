/****************************************
技巧13：猴子吃桃
****************************************/
#include <stdio.h>
#include <windows.h>
int main(int argc, char *argv[])
{
  int day,x1,x2;
  day=9;
  x2=1;
  while(day>0)
    {
      x1=(x2+1)*2;
      x2=x1;
      printf("day: %d\n", day);
      day--;
    }
  printf ("the total is %d\n",x1);
  return 0;
}