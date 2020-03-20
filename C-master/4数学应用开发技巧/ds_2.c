/****************************************
技巧02：可逆素数
****************************************/
#include <stdio.h>
#include <math.h>
 //自定义ss函数，作用是判断一个数是否为素数
// 可逆素数是将一个素数的各个位置的数字顺序倒置过来构成的反序数仍是素数。本例子是求1000到10000内的可逆素数。
int ss(int i)
{
  int j;
  if(i<=1)      //小于1的数不是素数
    return 0;
  if(i==2)      //2是素数
    return 1;
  for (j=2; j<i; j++)    //对大于2的数进行判断
  {
    if(i%j==0)
      return 0;
    // 如果没到最大数继续循环
    else if(i != j+1)
      continue;
    else
      return 1;
  }
}

int main(int argc, char *argv[])
{
  int i,n=0,n1,n2,n3,n4;

  for(i=1000;i<10000;i++)
    if (ss(i)==1)
    {
      n4=i%10;
      n3=(i%100)/10;
      n2=(i/100)%10;
      n1=i/1000;
      // 
      if(ss(1000*n4+100*n3+10*n2+n1)==1)
      {
        printf ("%d ",i);
        n++;
        if(n%10==0)
          printf ("\n");
      }
    }
  return 0;
}

