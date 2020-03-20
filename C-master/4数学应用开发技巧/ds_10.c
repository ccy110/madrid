/****************************************
技巧10：神奇的数字6174
****************************************/
#include <stdio.h>
#include <windows.h>
 //自定义函数，实现求最大4位数与最小数的差
int difference(int a[])
{
  int t,i,j,sum,sum1,sum2;
  for(i=0;i<3;i++)
    for(j=i+1;j<4;j++)
      if(a[i]<a[j])
      	{
      	  t=a[i];
      	  a[i]=a[j];
      	  a[j]=t;
      	}

  sum1=a[0]*1000+a[1]*100+a[2]*10+a[3];
  sum2=a[3]*1000+a[2]*100+a[1]*10+a[0];
  sum=sum1-sum2;
  printf ("%5d=%5d-%5d\n",sum,sum1,sum2);
  return sum;
}

int main(int argc, char *argv[])
{
  int n,a[4];
  printf ("please input a number:\n");
  scanf("%d",&n);

  while(n != 6174)
    {
      a[0]=n/1000;
      a[1]=n/100%10;
      a[2]=n/10%10;
      a[3]=n%10;
      n = difference(a);
    }

  Sleep(10000);
  return 0;
}
  