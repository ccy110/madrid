***************************************
// 技巧10：使用指针实现字符串的匹配
// 
***************************************
#include <stdio.h>
#include <string.h>
int match(char *B,char *A)
{
  int tmp,j,start=0;
  int lastB = strlen(B)-1;
  int lastA = strlen(A)-1;
  int endmatch = lastA;

  for (j=0; endmatch <= lastB; endmatch++, start++)
  {
    if(B[endmatch] == A[lastA])
      for(j=0, tmp = start; j < lastA && B[tmp]==A[j]; )
         tmp++, j++;

    if (j==lastA)
    {
      return (start+1);
    }
  }


  if (endmatch > lastB)
  {
    printf ("the string is not matchable!\n");
    return -1;
  }

}

int main(int argc, char *argv[])
{
  char s[] = "one world,one dream world";
  char t[] = "world";
  int p = match(s,t);
  if (p != -1)
    {
      printf ("Matchable!\n");
      printf ("the start position is %d\n",p);
    }
  printf ("\n");
  return 0;
}