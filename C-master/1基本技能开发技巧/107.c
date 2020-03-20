/****************************************
技巧08：评定成绩等级
****************************************/
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

  switch(score)
    {
      case 9:
        printf("the grade is A \n");
        break;
      case 8:
        printf("the grade is B \n");
        break;
      case 7:
        printf("the grade is C \n");
        break;
      case 6:
        printf("the grade is D \n");
        break;
      default:
        printf("the grade is E \n");
    }


    
  return 0;
}