/****************************************
技巧12：统计各种字符个数
****************************************/
#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
  char c;
  int letter=0, digit=0, space=0, other=0;
  printf ("please input some characters\n");

  //当输入的不是回车时执行while循环体
  while((c=getchar())!='\n')
  {
    printf("other: %d\n", other);
    printf("%c\n", c);
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')
      letter++;
    else if(c>='0'&&c<='9')
      digit++;
    else if(c==' ')
      space++;
    else
      other++;
  }
  printf ("letter=%d,digit=%d,space=%d,other=%d\n",letter,digit,space,other);

  Sleep(10000);
  return 0;
}