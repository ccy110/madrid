/****************************************
技巧04：特殊的完全平方数
****************************************/
// 100到999中至少有两位相等的完全平方数
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j;
  int hun,ten,data;
  printf ("the result is:\n");
  for (i=100; i<=999; i++)
    {
		j=10;
		
		while(j*j <= i)
		
		{
			if (i==j*j)
			{
				hun=i/100;
				
				ten=i%100/10;

				data=i%10;
				
				if(hun==ten || hun==data || ten==data)
					printf ("%5d \n",i);
			}
			j++;
		}
    }
  return 0;
}