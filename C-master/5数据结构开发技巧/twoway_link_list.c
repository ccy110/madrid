#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>


typedef struct node
{
	char name[100]; //学生名字
	struct node *front;
	struct node *next;
}stu;


stu * create(int num){
	stu * head;
	head = (stu *)malloc(sizeof(stu));

	
}

int main(){

	int num;
	printf("create node num:%d\n", num);
	scanf("%d", &num);

	stu * head;
	head = create(num);	

	printf("\n");

	char name[100];
	printf("pls find and del name :%s\n");
	scanf("%s", &name);

	stu *sp;
	sp = search(head, name);
	del(sp);

	printf("\n");
}