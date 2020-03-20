/****************************************
技巧03:回文素数
****************************************/
#include <stdio.h>
int ss(int i)
{
    int j;
    if(i<=1)
      return 0;
    if(i==2)
      return 1;
    for (j=2; j<i; j++)
      {
        if(i%j==0)
  	return 0;
        else if(i!=j+1)
  	continue;
        else
  	return 1;
      }
}
int main(int argc, char *argv[])
{
  int i;
  for (i=10; i<1000; i++)
    if(ss(i)==1)         //判断是否是素数
      if (i/100==0)      //判断是否是两位数
      {
        if (i/10==i%10)  //判断十位和个位是否相同
        printf ("%5d \n",i);
      }else if(i/100==i%10)    //判断百位和个位是否相同
        printf ("%5d \n",i);
        return 0;
}