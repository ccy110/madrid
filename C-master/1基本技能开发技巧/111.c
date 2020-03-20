/****************************************
技巧11：特殊等式 xyz+yzz=532
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int x,y,z,i;
  for (x=1; x<10; x++)
      for (y=1; y<10; y++)
	  for (z=0; z<10; z++)
	    {
	      i=100*x+10*y+z+100*y+10*z+z;
	      if(i==532)
				printf ("x=%d,y=%d,z=%d\n",x,y,z);
	    }
  return 0;
}