/****************************************
技巧11：一数三平方
****************************************/
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
  long i,n,n1,n2,n3,n4,count=0;
  printf ("the result is:\n");
 
  for (i=100000; i<=999999; i++)
	{
		n=(long)sqrt(i);
		if (i==n*n)
		{
			n1=i/1000;
			n2=i%1000;

			n3=(long)sqrt(n1);
			n4=(long)sqrt(n2);
			
			if (n1==n3*n3&&n2==n4*n4)
			{
				count++;
				printf ("%ld\n",i);
			}
		}
	}
  printf ("total is : %ld\n",count);
  return 0;
}