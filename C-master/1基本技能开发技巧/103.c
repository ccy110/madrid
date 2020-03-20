#include <stdio.h>
#include <windows.h>

 int bin_dec(int x,int n)     //将二进制转换成十进制
 {
   if(n == 0)
     return 1;
   return x*bin_dec(x,n-1);
 }


int main(int argc, char *argv[])
{
  int i;
  
  int ip[4] = {0};
  
  char a[33];
  
  printf ("please input binary number:\n");

  scanf("%s", a);

  for (i = 0; i < 8; i++)
  {
    if (a[i]=='1')
    {
      ip[0] += bin_dec(2,7-i);
    }
  }

  for (i=8; i<16; i++)
  {
    if (a[i]=='1')
    {
      ip[1] += bin_dec(2,15-i);
    }
  }

  for (i=16; i<24; i++)
  {
    if (a[i]=='1')
    {
      ip[2] += bin_dec(2,23-i);
    }
  }

  for (i=24; i<32; i++)
  {
    if (a[i]=='1')
    {
      ip[3] += bin_dec(2,31-i);
    }
    if (a[i]=='\0')
    {
      break;
    }
  }

  printf ("ip:");
  printf ("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);

  Sleep(5000);
  
  return 0;
}