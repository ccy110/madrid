/****************************************
技巧03：指向结构体变量的指针
****************************************/
#include <stdio.h>
#include <windows.h>
struct student   //自定义结构体
{
  int num;       //学生学号
  char name[20]; //学生姓名,数组字符串
  char sex;      //学生性别，字符
  int age;       //学生年龄
  float score;   //学生成绩
};

int main(int argc, char *argv[])
{
  //字符串用双引号，字符用单引号
  struct student student1 = {1001,"liming",'M',20,92.5};//定义结构体变量
  struct student *p;           //定义指针变量指向结构体类型
  
  p = &student1;
  
  printf ("number:%d\n", p->num);
  printf ("name:%s\n", p->name);
  printf ("sex:%c\n", p->sex);
  printf ("age:%d\n", p->age);
  printf ("score:%f\n", p->score);
  return 0;
}
