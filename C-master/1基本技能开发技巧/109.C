/****************************************
技巧09:打印乘法口决表
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j;
  for (i=1; i<=9; i++)
	{
	  for (j=1; j<=i; j++)
		{
			printf ("%d*%d=%d p",i,j,i*j);
		}
	  printf ("\n");
	}
  return 0;
}
  