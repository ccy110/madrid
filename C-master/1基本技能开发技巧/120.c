/****************************************
技巧19:彩球问题
****************************************/

#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,count;
  puts("the result is:\n");   //向屏幕上输出提示信息
  printf ("time  red ball  white ball  black ball\n");
  count = 1;
  for(i=0;i<=3;i++)
    for(j=0;j<=3;j++)
      if((8-i-j)<=6)
		printf ("%3d%7d%12d%12d\n", count++, i, j, 8-i-j);
  return 0;
}