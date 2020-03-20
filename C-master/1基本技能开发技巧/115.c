/****************************************
技巧15：求同学的平均身高
****************************************/
#include <stdio.h>
#include <windows.h>
float average(float array[], int n)
{
  int i;
  float aver,sum=0;
  for(i=0; i<n; i++)
    sum+=array[i];
  aver=sum/n;
  return(aver);
}
int main(int argc, char *argv[])
{
  float average(float array[],int n);
  
  float height[100];
  float aver;
  int i;
  int n;
  
  printf ("please input the number of students:\n");
  scanf("%d",&n);
  printf ("please input student's height:\n");

  for(i=0;i<n;i++)
    scanf("%f", &height[i]);

  printf ("\n");
  aver=average(height, n);
  printf ("average height is %6.2f\n",aver);

  Sleep(10000);
  return 0;
}