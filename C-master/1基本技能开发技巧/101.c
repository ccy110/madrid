/**************************************************
技巧：01
十进制数转化为十六进制
****************************************/


// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//   int i;
//   printf ("please input decimalism number:\n");
//   scanf("%d",&i);
//   printf ("the hex number is %x\n",i);
//   return 0;
// }




/****************************************
技巧03：IP地址形式输出
****************************************/
  /*
#include <stdio.h>
 int bin_dec(int x,int n)     //将而进制转换成十进制
 {
   if(n==0)
     return 1;
   return x*bin_dec(x,n-1);
 }
int main(int argc, char *argv[])
{
  int i;
  int ip[4]={0};
  char a[33];
  printf ("please input binary number:\n");
  scanf("%s",a);
  for (i=0; i<8; i++)
    {
      if (a[i]=='1')
{
  ip[0]+=bin_dec(2,7-i);
 }
    }
  for (i=8; i<16; i++)
    {
      if (a[i]=='1')
{
  ip[1]+=bin_dec(2,15-i);
 }
    }
  for (i=16; i<24; i++)
    {
      if (a[i]=='1')
	{
	  ip[2]+=bin_dec(2,23-i);
	}
    }
  for (i=24; i<32; i++)
    {
      if (a[i]=='1')
	{
	  ip[3]+=bin_dec(2,31-i);
	}
      if (a[i]=='\0')
	{
	  break;
	}
    }
printf ("ip:");
printf ("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
  return 0;
}
  */
/****************************************
技巧04：数字由小到大排序 三次交换
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int a,b,c,t;
  printf ("please input a,b,c:\n");
  scanf("%d%d%d",&a,&b,&c);
  if (a>b)
    {
      t=a;
      a=b;
      b=t;
    }
  if (a>c)
    {
      t=a;
      a=c;
      c=t;
    }
  if (b>c)
    {
      t=b;
      b=c;
      c=t;
    }
  printf ("the order of the number is:\n");
  printf ("%d  %d  %d\n",a,b,c);
  return 0;
}
*/
/****************************************
技巧05：阶梯问题
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i;
  for (i=100; i<1000; i++)
    {
      if(i%2==1&&i%3==2&&i%5==4&&i%6==5&&i%7==0)
	printf ("the number of the stairs is %d\n",i);
    }
  return 0;
}
 */
/****************************************
技巧06:判断闰年
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int year;
  printf ("please input the year:\n");
  scanf("%d",&year);
  if((year%4==0&&year%100!=0)||year%400==0)
    printf ("%d is a leap year\n",year);
  else
    printf ("%d is not a leap year\n",year);
  return 0;
}
  */
/****************************************
技巧07：对调数问题
****************************************/
   /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int x,y,z,x1,y1,z1,i,k,n,j=0;
  while(1)
    {
      printf ("please input an integer\n");
      scanf("%d",&n);
      if (n<=10||n>=100)
{
  printf ("data error\n");
  continue;
 }
      else if (n%10==0)
{
  printf ("data error\n");
  continue;
 }
      else
	{
	  x=n/10;
	  y=n%10;
	  z=10*y+x;
	  break;
	}
    }
  for (i=11; i<100; i++)
    {
      if (i%10==0)
	continue;   //结束本次循环
      else
	{
	  x1=i/10;
	  y1=i%10;
	  z1=10*y1+1;
	  //判断是否满足等式条件
	  if (n+i==z+z1&&n!=z1)
{
  printf ("%d+%d=%d+%d\n",n,i,z,z1);
  j++;
 }
	  else
	    continue;
	}
    }
if(j==0)
  printf ("inexistince\n");
  return 0;
}
   */
/****************************************
技巧08：评定成绩等级
****************************************/
    /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int score;
  printf ("please enter score(score<=10):");
  scanf("%d",&score);
  if (score==100)
    {
      score =90;
    }
  score = score/10;
  switch(score)
    {
    case 9:
      printf ("the grade is A\n");
      break;
    case 8:
      printf ("the grade is B\n");
      break;
    case 7:
      printf ("the grade is C\n");
      break;
    case 6:
      printf ("the grade is D\n");
      break;
    default:
      printf ("the grade is E\n");
    }
  return 0;
}
*/
/****************************************
技巧09:打印乘法口决表
****************************************/
     /*
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
     */
/****************************************
技巧10:打印杨辉三角
****************************************/
      /*
#include <stdio.h>
int main(int argc, char *argv[])
     {
       int i,j,a[11][11];
       for (i=1; i<11; i++)
	 {
	   a[i][i]=1;
	   a[i][1]=1;
	 }
       for (i=3; i<11; i++)
	 {
	   for (j=2; j<=i-1; j++)
	     {
	       a[i][j]=a[i-1][j-1]+a[i-1][j];
	     }
	 }
       for (i=1; i<11; i++)
	 {
	   for (j=1; j<=i; j++)
	       printf ("%4d\t",a[i][j]);
	   printf ("\n");
	 }
       return 0;
     }
      */

