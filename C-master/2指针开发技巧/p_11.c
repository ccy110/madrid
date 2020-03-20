/****************************************
技巧11：用指向函数的指针比较大小
一个函数在编译时被分配一个入口地址，这个地址就称为
函数的指针。所以可以使用指针变量指向一个函数，然后
通过该指针变量调用这个函数。 

others:在函数调用中，只有通过地址，才能做数据的双向传递。

int *p[n];
int (*p)[n];
还有一种情况是声明函数：
int *p();
int (*p)();
这些分别表示什么意思呢？

表面上看这些问题，好像是指针，但是，如何来正确判断这几个定义，需要我们首先有运算符优先级的概念。

在c语言中，[]和()的优先级比星号（星号的名字叫做“指针运算符”）要高，所以，在这几个声明中，先看[]和()。
同时，这两个括号的运算符的结合顺序，是从左到右的。因此，int *p[n]，实际上相当与int *(p[n])，也就是(int *)(p[n])。

让我们来逐步分析：
(int *)(p[n])首先是一个数组（比如，把int *换为int，就是“元素是整形数据的数组”。那么，换为int*，就是“元素是指向整形数据的指针的数组”）。

再看另一个：
int (*p)[n]改变了自然的运算符的优先级，相当于(int)((*p)[n])。一有指针就头疼，我们把指针先替换掉，就是int a[n]，是一个n维数组，数组首地址（也就是数组名）是a。
那么，int (*p)[n]也是一个n维数组，但是这个数组的首地址是*p，也就是说，p指向的内容，是一个数组的首地址。
那么，p就是指向一个数组的指针，这个数组中的元素都是int。实际上，p相当于是一个二维指针。

同样的道理，可以分析 int *p();和int (*p)();

注意，这里我们对于星号赋予了不同的含义。阐述如下：
int a;
int *p=&a;//定义指向a的指针p
*p = 10;

这里，第二行中的星号表示“定义了一个指向int型数据的指针，为什么呢？因为实际上，* 相当于 (int *)，定义了一个指向int型数据的指针。
第三行的星号，表示p所指向的数据，因为星号前面并没有诸如int void char等表示类型的东西。

换句话说，如果星号前面有表示类型的int，void等数据，我们认为，这里的星号的意义，是“定义了一个指针”
如果星号前面没有表示类型的东西，那么我们认为，这里的星号的意义，是”该指针所指向的数据“。

那么，让我们回头看看int *p[n]和int (*p)[n]。
由于我们刚刚把优先级分析过，那么前者相当于(int *)(p[n])，后者相当于 int ((*p)[n])
根据刚才我们的关于星号的结论，前者表示定义了一个长度为n的数组(p[n])，每个元素都是指向int数据的指针(int *)。
后者表示，定义了一个int a[n]。这里大家都明白，然后把a换成*p，于是意思就是，p是一个指针，其指向的内容(也就是*p)是一个数组的首地址(就是a)


技巧11：用指向函数的指针比较大小
一个函数在编译时被分配一个入口地址，这个地址就称为
函数的指针。所以可以使用指针变量指向一个函数，然后
通过该指针变量调用这个函数。 
****************************************/
#include <stdio.h>
#include <windows.h>
min(int a,int b)
{
  if(a<b)
    return a;
  else 
    return b;
}
int main(int argc, char *argv[])
{
  int (*pmin) ();     //定义指向该函数的指针变量 pmin

  int a,b,m;
  pmin = min;  //函数指针变量赋值，只用给出函数名即可

  printf ("please input two integer numbers:\n");
  scanf("%d%d",&a,&b);
  
  m = (*pmin)(a,b);
  printf ("min=%d\n",m);

  Sleep(10000);
  return 0;
}


// int (*p) (); 吧，简单的理解，这就可以理解为调用函数，其中（*p）这个整体可以看作是函数名称，p代表函数的入口地址

// int main()
// {
//     int num;
//     int choice;
//     int res;
//     int *p = NULL;

//     int change(int a,int (*p)(int a));
//     int two(int a);
//     int eight(int a);
//     //int sixteen(int a); 

//     printf("Enter an integer:");
//     scanf("%d",&num);
//     printf("Bin output press 1\
//             Octal output press 2\
//             Hex output press 3\
//             Please enter your choice:\n");
//     scanf("%d",&choice);

//     if(choice == 1)
//     {
//         printf("Bin:");
//         change(num, two);
//     }
//     if(choice == 2)
//     {
//         printf("Octal:");
//         change(num, eight);
//     }
//     if(choice == 3)
//     {
//         printf("Hex:");
//         printf("%X",num);
//         //change(num, sixteen);
//     }

//     printf("\n");
//     return 0;
// }

// int change(int a,int (*p)(int a))
// {
//     int res;
//     res = (*p)(a);
//     printf("%d\n",res);
// }

// int two(int a)
// {
//     int i,res=0,k=1;
//     while( a )
//     {
//         i = a % 2;
//         res = k*i + res;
//         k = k*10;
//         a = a /2;
//     }
//     return res;
// }

// int eight(int a)
// {
//     int i,res=0,k=1;
//     while( a )
//     {
//         i = a % 8;
//         res = k*i + res;
//         k = k*10;
//         a =  a / 8;
//     }
//     return res;
// }
