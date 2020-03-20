/****************************************
技巧16：灯塔数量（利用了穷举法）
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int n=1,m,sum,i;
  while(1)
  {
    m=n;
    sum=0;
    for (i=1; i<8; i++)
    {
      m=m*2;
      sum+=m;
    }
    sum+=n;
    if (sum==765)
    {
      printf ("the first floor has %d\n",n);
      printf ("the eight floor has %d\n",m);
      break;
    }
    n++;
  }
  return 0;
}