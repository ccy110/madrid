/****************************************
技巧05：求1000以内的玩数
****************************************/
#include <stdio.h>
main()
{
  int i,j,sum=0;
  for (i=1; i<1000; i++)
  {
    sum=0;
    for(j=1;j<i;j++)
      if(i%j==0)
        sum+=j;
    if(sum==i)
      printf ("%4d \n",i);
  }
  return 0;
}

