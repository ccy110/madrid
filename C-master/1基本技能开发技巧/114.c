/****************************************
技巧14：删除字符串中连续字符
****************************************/
#include <stdio.h>
#include <windows.h>
char del(char s[],int pos,int len)   //自定义删除函数，这里采用覆盖方法
 {
   int i;
   for (i=pos+len-1; s[i]!='\0'; i++, pos++)

     s[pos-1] = s[i];   //用删除部分后的字符依次从删除部分开始覆盖

   // 别忘了字符串末尾
   s[pos-1] = '\0';

   return s;
 }

int main(int argc, char *argv[])
{
  char str[50];
  int position,length;
  printf ("please input string:\n");
  gets(str);   //使用gets函数获得字符串
  printf ("please input delete position:");
  scanf("%d", &position);

  printf ("please input delete length:");
  scanf("%d", &length);
  
  del(str,position,length);
  printf ("the final string:%s\n",str);
  
  Sleep(10000);
  return 0;
}