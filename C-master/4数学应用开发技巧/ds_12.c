/****************************************
技巧12:求等差数列
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,number,n;
  for(number=1;number<4;number++)
	for(n=1;n<4;n++)
		if ((4*number+6*n==26) && number*(number+n)*(number+2*n)*(number+3*n)==880)
			{
				printf ("the result is:\n");
				for (j=1; j<=20; j++)
				{
					printf ("%3d",number);
					number+=n;
					if(j%5==0)
						printf ("\n");
				}
			}
  return 0;
}