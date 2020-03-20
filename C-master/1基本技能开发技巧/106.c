// 一个两位正整数；将个位与十位对调，得到另一个两位正整数，我们称这两个数互为对调数。
// 现给定一个两位正整数，问是否能找到另一个对调后不同的两位正整数，使得这两个正整数之和等于他们对调后的数之和？
// 例如：56 + 54 = 65 + 45
#include <stdio.h>
#include <windows.h>
int main(int argc, char *argv[])
{
	int x,y,z, x1,y1,z1, i,k,n,j=0;
	while(1)
	{			
	  printf ("please input an integer\n");


	  scanf("%d", &n);
	  
	  if (n<=10 || n>=100)
		{
			printf ("data error\n");
			// continue 语句和 break 语句的区别是，continue 语句只结束本次循环，而不是终止整个循环。
			// break 语句则是结束整个循环过程，不再判断执行循环的条件是否成立。
			// 而且，continue 只能在循环语句中使用，即只能在 for、while 和 do…while 中使用，除此之外 continue 不能在任何语句中使用。
			// continue 的用法十分简单，其作用为结束本次循环，即跳过循环体中下面尚未执行的语句，然后进行下一次是否执行循环的判定。
			continue;
		}
	  else
	    {
			x=n/10;
			y=n%10;
			z=10*y+x;
			// 不管是 for 循环，还是 while 循环，或者是 do…while 循环，都可以用 break 跳出来，
			// 但是 break 只能跳出一层循环。当有多层循环嵌套的时候，break只能跳出“包裹”它的最里面的那一层循环，无法一次跳出所有循环。
			// http://c.biancheng.net/view/182.html
			break; 
		}
	}


	for (i=11; i<100; i++)
	{
		if (i%10==0)
			continue;   //结束本次循环
		else
		{
			x1=i/10;
			y1=i%10;
			z1=10*y1 + x1;

			//判断是否满足等式条件
			while(i == 54)
			{
				printf("n: %d \n", n);
				printf("z:%d \n", z);

				printf("i:%d \n", i);
				printf("z1:%d \n", z1);

				break;
			}
			if (n+i==z+z1 && n != z1)
			{
				printf ("%d+%d=%d+%d\n",n,i,z,z1);
				j++;
			}
			else
				continue;
		}
	}

	if(j==0)
		printf ("inexistince\n");

	Sleep(10000);
	return 0;
}
