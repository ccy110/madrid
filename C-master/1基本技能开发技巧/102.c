/******************************
技巧：02
N进制转换为十进制
****************************************/
 
#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
  long t1; 
  int i;
  int n;
  int t;
  int t3; 
  char a[100];
  
  printf ("please input a number string:\n");
  
  gets(a);      //输入N进制数存到数组a中

  strupr(a);    //将a中的小写字母转换成大写字母
  
  printf ("t3=======:%s\n", a);

  t3 = strlen(a);

  printf ("t3=======:%d\n", t3);
  
  t1 = 0;
  printf ("please input n(2or8or16):\n");


  scanf("%d",&n);

  for (i = 0; i < t3; i++)
  {

    printf ("a[i]======================%d:\n", a[i]); 

    if ( (a[i] -'0' >= n && a[i] < 'A') || (a[i] -'A' + 10 >= n) ) //判断输入的数据和进制数是否相等
    {
      printf ("data error!!");
      Sleep(5000);
      exit(0);        //退出程序
    }

    if (a[i] >= '0'&&a[i] <= '9')    //判断是否为数字
	    t = a[i]-'0';

    else if(n >= 11 && (a[i]>='A' && a[i]<='A'+n-10))  //判断是否为字母o
	    t = a[i]-'A'+10;

    t1 = t1 * n + t;      //求出最终转换成十进制的值
  }

    printf ("the decimal is %ld\n",t1);
    Sleep(5000);
    return 0;
}