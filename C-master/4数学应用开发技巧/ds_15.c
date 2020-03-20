/****************************************
技巧15：自然对数的底e的计算 e=1+1/1!+1/2!+1/3!+...
****************************************/
#include <stdio.h>
int main(int argc, char *argv[])
 {
   float e=1.0,n=1.0;
   int i=1;
   while(1/n > 1e-10)
     {
      printf("%.11f\n", 1e-10);
       e+=1/n;
       i++;
       n=i*n;
     }
   printf ("the value of e is %f\n",e);
   return 0;
 }
  