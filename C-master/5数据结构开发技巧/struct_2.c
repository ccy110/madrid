/****************************************
技巧02：找最高分
****************************************/
#include <stdio.h>
struct student
{
  int num;
  char name[20];
  float score;
};
int main(int argc, char *argv[])
{
  int i,m;
  float maxscore;
  struct student stu[5]=
  {
    {101,"liming",89},
    {102,"zhanghong",95},
    {103,"lili",89},
    {104,"weichen",85},
    {105,"yangfan",75}
  };
  m=0;
  maxscore=stu[0].score;
  for (i=1; i<5; i++)
    {
      if (stu[i].score>maxscore)
	{
	  maxscore=stu[i].score;
	  m=i;
	}
    }
  printf ("the maxmum score is :%5.1f\n",maxscore);
  printf ("the student number is:%d\n",stu[m].num);
  printf ("the student name is:%s\n",stu[m].name);
  return 0;
}
