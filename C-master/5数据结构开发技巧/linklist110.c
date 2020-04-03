/****************************************
技巧07：创建双向链表
****************************************/

/****************************************
单链表　实地想一下不包含头节点的缺点
单链表反转


链表中环的检测 一快一慢是否相遇
----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------
一种O（n）的办法就是（搞两个指针，一个每次递增一步，一个每次递增两步，如果有环的话两者必然重合，反之亦然）：
关于这个解法最形象的比喻就是在操场当中跑步，速度快的会把速度慢的扣圈

可以证明，p2追赶上p1的时候，p1一定还没有走完一遍环路，p2也不会跨越p1多圈才追上,一圈之内一定追上

我们可以从p2和p1的位置差距来证明，p2一定会赶上p1但是不会跳过p1的

因为p2每次走2步，而p1走一步，所以他们之间的差距是一步一步的缩小，4，3，2，1，0 到0的时候就重合了

根据这个方式，可以证明，p2每次走三步以上，并不总能加快检测的速度，反而有可能判别不出有环

既然能够判断出是否是有环路，那改如何找到这个环路的入口呢？

解法如下： 当p2按照每次2步，p1每次一步的方式走，发现p2和p1重合，确定了单向链表有环路了

接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当p1和p2再次相遇的时候，就是环路的入口了。

这点可以证明的：

在p2和p1第一次相遇的时候，假定p1走了n步骤，环路的入口是在p步的时候经过的，那么有

p1走的路径： p+c ＝ n；         c为p1和p2相交点，距离环路入口的距离

p2走的路径： p+c+k*L = 2*n；   L为环路的周长，k是整数

显然，如果从p+c点开始，p1再走n步骤的话，还可以回到p+c这个点

同时p2从头开始走的话，经过n步，也会达到p+c这点

显然在这个步骤当中p1和p2只有前p步骤走的路径不同，所以当p1和p2再次重合的时候，必然是在链表的环路入口点上。
-----------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------


1、如何判断一个链表是不是这类链表？
2、如果链表为存在环，如果找到环的入口点？扩展：判断两个单链表是否相交，如果相交，给出相交的第一个点。 
http://blog.chinaunix.net/uid-20235103-id-1970885.html 环的问题

求链表中间节点　设置一个快指针，一个慢指针，并且快指针的步长为慢指针的两倍，当快指针到达结尾时，慢指针一定在中间。
删除链表倒数第n个节点   也是快慢指针的问题


两个有序链表的合并

循环链表???????????????????????????尾节点指向头节点
约瑟夫问题

双向链表
双向循环链表

延伸之散列表散列冲突链表的解决办法
延伸之跳表的实现(redis有序集合)原理：建索引、二分查找


emacs的剪切为C-w；复制为M-w
成员运算符（.）和指向结构体成员的运算符（->）两者都是用来引用结构体变量
成员的，但是他们的应用环境是完全不同的。
成员运算符（.）用在一般结构体变量中，表示结构体变量的成员。
指向结构体成员运算符（->）与指向结构体变量的指针连用，表示指向结构体变量
指针的成员。
strut student
{
  int num;
  char name[10];
};
struct student stu; 
struct *s=&stu;
其中，stu.num s->num是正确的引用方法，但是stu->num和s.num是不允许。
其实，s->num就相当于（*s）.num。

头指针:链表里有“头指针”变量,它存放一个地址,该地址指向一个元素.
链表里的每个元素称为“节点”.
head是头指针,而不是头结点 它只占用4字节大小空间(如果是32位)
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
typedef struct node
{
    int data;
    struct node * next;   
}Node, *linklist;

//单链表的打印
void show(linklist head){
    int i;
    linklist ahead = head;
    for(i = 0; ahead != NULL; i++, ahead = ahead->next){
        printf("node(%d)->%d \n", i, ahead->data);
    }
}

linklist create(linklist head, int num){
    //创建头节点
    head = (linklist)malloc(sizeof(Node));
    head->data = num;
    head->next = NULL;

    int i;
    //一个向前的节点指针
    linklist ahead = head;
    linklist p;
    for(i = 1; i<=num; i++, ahead = ahead->next){
        p = (linklist)malloc(sizeof(Node));
        p->data = i*10;
        ahead->next = p;
        p->next = NULL;
    }
    show(head);
    return head;
}

//指针两两反转
linklist reverse1(linklist head){

    linklist p = head->next;
    linklist q = head->next->next;
    linklist r = q;
    head->next->next = NULL;
    while(1)
    {
        r = q->next;
        if(r == NULL){
            q->next = p;
            p = q;
            break;
        }
        q->next = p;
        p = q;
        q = r;
    }
    head->next = p;
    show(head);
    return head;
}
linklist reverse21(linklist pre, linklist cur, linklist after){
    cur->next = pre;
    if(after == NULL){
        return cur;
    }
    reverse21(cur, after, after->next);
}


//指针递归反转
linklist reverse2(linklist head){
    //前中后
    linklist pre = NULL;
    linklist cur = head->next;
    linklist after = head->next->next;
    cur =  reverse21(pre, cur, after);
    head->next = cur;

    show(head);
    return cur;
}

void searchentrypoint(linklist head, linklist meet){
    //从头节点开始？从首元节点开始？
    linklist p = head;
    while(1){
        p = p->next;
        meet = meet->next;
        if((p->data == meet->data) && (p->next == meet->next)){
            printf("p->data:%d p->next:%p\n", p->data, p->next);
            break;
        }
    }
}

void checkcircle(linklist head){
    //移动两个节点
    linklist fast = head;
    //移动一个节点
    linklist slow = head;
    while(1){
        fast = fast->next;
        if(fast == NULL){
            printf("%d\n", 0);
            break;
        }
        fast = fast->next;
        if(fast == NULL){
            printf("%d\n", 0);
            break;
        }
        slow = slow->next;
        if(slow->next == fast->next){
            printf("slow->data:%d\n", slow->data);
            printf("fast->data:%d\n", fast->data);
            printf("slow->next:%p\n", slow->next);
            printf("fast->next:%p\n", fast->next);
            printf("%d\n", 1);
            searchentrypoint(head, slow->next);
            break;
        }
    }

    // while  ( fast  &&  fast -> next ) 
    // {
    //     slow  =  slow -> next;
    //     fast  =  fast -> next -> next;
    //     if  ( slow  ==  fast )  break ;
    // }

    // return   ! (fast  ==  NULL  ||  fast -> next  ==  NULL);

    // 入口点
    //     slist * slow  =  head,  * fast  =  head;

    // while  ( fast  &&  fast -> next ) 
    // {
    //     slow  =  slow -> next;
    //     fast  =  fast -> next -> next;
    //     if  ( slow  ==  fast )  break ;
    // }

    // if  (fast  ==  NULL  ||  fast -> next  ==  NULL)
    //     return  NULL;

    // slow  =  head;
    // while  (slow  !=  fast)
    // {
    //      slow  =  slow -> next;
    //      fast  =  fast -> next;
    // }

    // return  slow;

}

int main(){

    //创建7节点的链表
    linklist head;
    int NodeNum = 7;
    head = create(head, NodeNum);
    //指针两两反转
    head = reverse1(head);
    // //递归反转
    head = reverse2(head);

    checkcircle(head);

    // int n = 3;
    // delnode(node, n);
    // //在创建一个有序链表并将其与之合并
    // combine(head);

    // searchmidnode(head);

    return 0;
}






// 链表中环的检测 一快一慢是否相遇
// bool IsExitsLoop(slist * head)
// {
//     slist * slow = head ,  * fast = head;

//     while  ( fast  &&  fast -> next ) 
//     {
//         slow  =  slow -> next;
//         fast  =  fast -> next -> next;
//         if  ( slow  ==  fast )  break ;
//     }

//     return   ! (fast  ==  NULL  ||  fast -> next  ==  NULL);
// }


// 两个有序链表的合并
// typedef struct List
// {
//     int a;
//     struct List *next;
// }list;


// void newList(list *l)
// {
//     //初始化头节点
//     l->next = NULL;
// }
// void setList(list * l)
// {
//     //建立链表
//     int i = 1;
//     int j;
//     while (i)
//     {
//         scanf_s("%d", &j);
//         if (j == -1)
//         {
//             i = 0;
//         }
//         else
//         {
//             list *l1 = (list *)malloc(sizeof(list));//为新的结点分派内存
//             l1->a = j;//储存数据
//             /*
//             将最后结点的next区域指向新结点
//             将新结点的next区域指向设置为空
//             */
//             l->next = l1;
//             l1->next = NULL;
//             l = l->next;
//         }
//     }
// }
// void printfList(list *l)
// {
//     printf("该链表内容为：\n");
//     while (l->next)
//     {
//         printf("%d\t", l->next->a);
//         l = l->next;
//     }
//     printf("\n");
// }
// list *add(list *LA, list *LB)
// {
//     //记录两个链表的头结点
//     list *la=LA;
//     list *l = LA;
//     list *lb = LB;
//     //移动指针
//     LA = LA->next;
//     LB = LB->next;
//     la->next = NULL;
    
//     while (LA!=NULL&&LB!=NULL)
//     {
//         /*
//         将两个结点的数据进行比较，数据较小的结点接在头结点后面，
//         */
//         if (LA->a < LB->a)
//         {
//             la->next = LA;
//             la = LA;
//             LA = LA->next;
//         }
//         else
//         {
//             la->next = LB;
//             la = LB;
//             LB = LB->next;
//         }
//     }

//     //若其中一个链表的结点已经全接在新表中则将另一个链表的剩余结点接在新表的后面
//     if (LA)
//     {
//         la->next = LA;
//     }
//     if(LB)
//     {
//         la->next = LB;
//     }
//     free(lb);
//     return l;
// }
// int main()
// {
//     //为结点分配内存
//     list *LA = (list *)malloc(sizeof(list));
//     list *LB = (list *)malloc(sizeof(list));
//     //初始化结点
//     newList(LA);
//     newList(LB);

//     //建立链表
//     setList(LA);
//     setList(LB);
//     //输出链表的内容
//     printf("LA的数据:\n");
//     printfList(LA);
//     printf("LB的数据:\n");

//     printfList(LB);

//     list *LC = add(LA, LB);
    
//     //输出合并后的新表
//     printfList(LC);
//     system("pause");
//     return 0;
// }




// 约瑟夫问题
// 有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。
// 就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。

// 循环链表实现约瑟夫问题

// typedef struct NODE{
//     struct NODE *next;
//     int data;
// }Node,*Linklist;

// void Print_Linklist(Linklist L)
// {
//     Linklist head = L;
//     printf("List: ");
//     while(L->next != head)
//     {
//         printf("%d ",L->data);
//         L = L->next;
//     }
//     printf("%d ",L->data);
//     printf("\n");
// }

// int main()
// {
//     int i;
//     Linklist L;
//     Linklist head;
//     Linklist Out;

//     L = (Node*)malloc(sizeof(Node));
//     head = L;
//     L->data = 1;
//     L->next = head;
    

//     for(i=2;i<=41;i++)
//     {
//         L->next=(Node*)malloc(sizeof(Node));
//         L->next->data = i;
//         L->next->next = head;
//         L = L->next;
//     }


//     Print_Linklist(head);
    
//     L = head;
    
//     while(L != L->next)
//     {
//          for(i=1;i<2;i++)
//          {
//              L = L->next;
//          }
//          Out = L->next;
//          printf("%2d号 ----> 自杀！\n",Out->data);
//          L ->next = Out->next;
//          L = L->next;
//          free(Out);
//     }
//     printf("幸存者是：%d",L->data);
//     return 0;
// }
// typedef struct node
// {
//     int data;
//     struct node * next;
// }Node, *linklist;


// int yuesefu(int m, int n);

// linklist create(linklist head, int x){
//     //头节点
//     head = malloc(sizeof(Node));
//     head->next = NULL;
//     head->data = 1000;
//     linklist ahead = head;
//     for(int i = 0; i < x-1; i++, ahead = ahead->next){
//         linklist p = malloc(sizeof(Node));
//         p->data = (i+1)*10;
//         ahead->next = p;
//     }
//     ahead = head;
//     return head;
// }

// void show(linklist head, int x){
//     linklist p = head;
//     for(int i = 0; i < x; i++, p = p->next){
//         printf("%p %d\n", p->next, p->data);
//     }

// }

// int main(){
//     int x;//总数
//     int y;//出局
//     printf("please input x y\n");
//     while(scanf("%d %d", &x, &y) != EOF){
//         printf("last out data:%d\n", yuesefu(x, y));
//     }    
// }

// int yuesefu(int x, int y){
//     linklist head;
//     head = create(head, x);
//     show(head, x);
    
//     //约瑟夫start
//     linklist ahead = head;
//     linklist out;
//     // 输出最后一个
//     while(x != 1){
//          for(int i = 1; i < y - 1; i++)
//          {
//              ahead = ahead->next;
//          }

//          out = ahead->next;
//          printf("%2d ----> out \n", out->data);
         
//          ahead ->next = out->next;
//          ahead = ahead->next;
//          free(out);
//          x--;
//     }
//     printf("ahead->data:%d\n", ahead->data);
//     return ahead->data;
// }
























// typedef struct node {
//     unsigned int number;
//     struct node * next;
// }* pt, node;

// void creat(pt * c, int a);

// int yue(int m, int n);

// void show(pt head, int x){
//     pt p = head->next;
//     for(int i = 0; i < x; i++, p = p->next){
//         printf("%d\n", p->number);
//     }

// }

// int main ()
// {
//     int m, n;
//     while(scanf("%d %d", &m, &n) != EOF)
//     {
//         printf("last out data:%d\n", yue(m, n%m));
//     }
// }

// void creat (pt * c, int a)
// {
//     pt current, prev;
//     * c = (pt) malloc (sizeof(node));
//     prev = * c;
//     for(int i = 1; a--; i++)
//     {
//         current = (pt) malloc (sizeof(node));
//         current->number = i;
//         prev->next = current;
//         prev = current ;
//     }
//     current->next = (*c)->next;
// }

// int yue(int m,int n)
// {
//     pt head, current, prev; 
//     creat(&head,m);
//     show(head, m);
//     current = head->next;
//     for (int i = 1; i < m; i++)
//     {
//         for (int j = 0; j < n - 1; j++)
//         {
//             current = current->next;
//         }
//         prev = current->next;
//         current->number = current->next->number;
//         current->next = current->next->next;
//         printf("deldata:%d ", prev->number);
//         free(prev);
//     }
//     return current->number;
// }


//单链表反转

// void Reverse(List *L){
//     //分别是当前节点，直接前驱节点，直接后继节点
//     LNode *current, *pre, *pnext;
//     //初始化
//     current  = L -> next;
//     pre = NULL;
//     while(current != NULL){
 
//         //保留后继节点
//         pnext = current -> next;
//         //新的后继指向前驱实现反转
//         current -> next = pre;
 
//         //将当前节点向后移动
//         pre = current;
//         current = pnext;
//     }
//     return;
// }

// 单链表反转方法
// 1 ，两两对换
// 2， 放入数组，倒置数组
// 3， 递归实现    
// typedef struct node
// {
//     int data;
//     struct node * pnext;
// }Node, *pnode;

// pnode CreateNode()
// {

//     pnode phead=(pnode)malloc(sizeof(Node));
//     //判断是否申请空间成功
//     if(phead==NULL)
//     {
//         printf("fail to allocate memory");
//         return NULL;
//     }
//     phead->pnext=NULL;
    
//     int n;
//     pnode ph=phead;
    
//     for(int i=0; i<5; i++)
//     {

//         pnode p=(pnode)malloc(sizeof(Node));
//         if(p==NULL)
//         {
//             printf("fail to allocate memory");
//             return NULL;
//         }
//         p->data=(i+2)*19;

//         phead->pnext=p;
//         p->pnext=NULL;
//         phead=phead->pnext;

//     }
//     return ph;
// }

// int list(pnode head)
// {
//     int count=0;
//     printf("遍历结果：\n");
//     while(head->pnext!=NULL)
//     {
//         printf("%d\t",head->pnext->data);
//         head=head->pnext;
//         count++;
//     }
//     printf("链表长度为：%d\n",count);
//     return count;
// }

// pnode reverse2(pnode head)//两两节点之间不断交换
// {
//      if(head == NULL || head->pnext == NULL) 
//         return head; //加上头节点少于两个节点没有反转的必要。
//     pnode p;
//     pnode q;

//     p = head->pnext;
//     q = head->pnext->pnext;
    
//     p->pnext = NULL; //旧的头指针是新的尾指针，next需要指向NULL
    
//     pnode tmp = q;
//     while(1)
//     {

//         tmp = q->pnext;
//         q->pnext = p;
//         //前两个都反转了所以反转之前 需要一个临时tmp保存下一个 要不都反转了 找不到了
//         p = q;
//         q = tmp;
//         if(tmp == NULL){
//             head->pnext = p;
//             return head;      
//         }
//     }   
// }

    

// void reverse1(pnode head,int count)//把链表的节点值放在数组中，倒置数组
// {
//     int a[5]= {0};

//     for(int i=0; i<count,head->pnext!=NULL; i++)
//     {
//         a[i]=head->pnext->data;
//         head=head->pnext;
//     }

//     for(int j=0,i=count-1; j<count; j++,i--)
//         printf("%d\t",a[i]);

// }


// // 类似尾递归类似上面的两两相倒
// pnode reverse3(pnode pre,pnode cur,pnode t)//递归实现链表倒置
// {
//     cur -> pnext = pre;
//     if(t == NULL)
//         return cur; //返回无头节点的指针，遍历的时候注意
//     reverse3(cur,t,t->pnext);
// }

// int main()
// {
//      pnode p=CreateNode();
//      pnode p3=CreateNode();

//      int n=list(p);
     
//      // printf("反转之后1：\n");
//      // reverse1(p, n);
//      // printf("\n");
//      // printf("反转之后的：\n");
//      // pnode p1=reverse2(p);
     
//      // list(p1);
//      p3 -> pnext = reverse3(NULL, p3 -> pnext,p3->pnext->pnext);
//      printf("3反转之后：\n");
//      list(p3);
//      // free(p);
//      // free(p1);
//      // free(p3);

//      // Sleep(10000);
//      return 0;
// }

// 这里注意： head ->next = pre; 以及 pre = head->next，前者把head->next 指向 pre，而后者是把head->next指向的节点赋值给pre。
// 如果原来head->next 指向 pnext节点，前者则是head重新指向pre，与pnext节点断开，后者把pnext值赋值给pre，head与pnext并没有断开。

// //双向循环链表
// typedef struct node{
//     struct node * pre;
//     int data;
//     struct node * next;    
// }Node, *linklist;


// linklist create(linklist h){
//     h = (linklist)malloc(sizeof(Node));
//     h->pre=h->next=NULL;

//     int num;
//     printf("please input create num\n", num);
//     scanf("%d", &num);

//     //向前指针
//     // linklist ahead = h;
//     while(num--){
//         linklist p;
//         p = (linklist)malloc(sizeof(Node));
        
//         //尾插法 
//         // p->data = num;
//         // ahead->next=p;
//         // p->pre = ahead;

//         // p->next=h;
//         // h->pre=p;

//         //头插法
//         p->data = num;

//         if(h->next == NULL){
//             p->next = h;
//             h->pre = p;

//             p->pre = h;
//             h->next = p;
//         }else{
//             h->next->pre = p;
//             p->next=h->next;
//             h->next=p;
//             p->pre=h; 
//         }


//         // ahead = p;
//     }

//     return h;
// }

// void show(linklist h){
//     linklist backward = h->pre;
//     while(backward != h){
//         printf("data:%d\n", backward->data);
//         backward = backward->pre;
//     }

// }

// int main(){
//     linklist h;
//     h = create(h);
//     show(h);
//     Sleep(10000);
//     return 0;
// }



// // 双向循环链表
// typedef struct tagNode
// {
//     struct tagNode *pre;
//     int data;
//     struct tagNode *next;
// }Node,*LinkList;

// void InitList(LinkList *L)
// {
//     *L=(LinkList)malloc(sizeof(Node));
//     (*L)->next=(*L)->pre=*L;

// }

// void CreateLink(LinkList L, int n)
// {
//     LinkList p=L,q;
//     while(n--)
//     {
//         q=(LinkList)malloc(sizeof(Node));
//         scanf("%d",&q->data);
        
//         p->next=q;
//         q->pre=p;
        
//         q->next=L;//尾插法
//         L->pre=q;
//         p=q;
//     }
// }

// void TraverseList(LinkList L)
// {
//     LinkList p = L->pre;
//     while(p!=L)
//     {
//         printf("%d ",p->data);
//         p=p->pre;
//     }
// }

// int main()
// {
//     int n;
//     LinkList L;
//     InitList(&L);
 
//     scanf("%d",&n);
 
//     CreateLink(L,n);
//     TraverseList(L);

//     Sleep();
//     return 0;
// }


// 循环链表
// // 首先 static 的最主要功能是隐藏(对其他文件隐藏)，其次因为 static 变量存放在静态存储区(还有全局变量)，所以它具备持久性和默认值0。
// static int size=0;  

// typedef struct Node{      //定义一个链表的结点 
//     int data;
//     struct Node *next;
// }node, *linklist; 


// linklist head_creat(linklist l){  //头插法建立循环链表 
 
//     int num = 3;                   //插入的链表数量    
//     int a = 3;
//     while(num--)
//     {
//         linklist p;
//         p=(linklist)malloc(sizeof(node));
//         printf("please input data\n");
//         scanf("%d",&p->data);
//         p->next=l->next;
//         l->next=p;
//         size++;
//     }

//     linklist p=l;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     p->next=l;
//     return l;
// }


// void out_list(linklist h){    //显示链表结点值 
//     linklist p=h->next;
//     while(p!=h){
//         printf("node data:%d ",p->data);
//         p=p->next;
//     }
//     printf("size is %d\n",size);
// }
// linklist dele(linklist h){   //在链表中删除值为num的结点
//     int rmnum;
//     printf("please input delnum");
//     scanf("%d",&rmnum);
//     linklist p=h->next;
//     linklist q=h;
//     while(p!=h){
//         if(p->data==rmnum){
//             q->next=p->next;
//             p->next=NULL;
//             free(p);
//             size--;
//             break;
//          }
//          p=p->next;
//          q=q->next;
//     }
//     return h;

// }
// linklist inset(linklist l){  //插入结点 
//     printf("insert num"); 
//     int num;                   //插入的链表数量    
//     scanf("%d",&num);
//     while(num--){
//         linklist p;
//         p=(linklist)malloc(sizeof(node));
//         scanf("%d",&p->data);
//         p->next=l->next;
//         l->next=p;
//         size++;
//     }
//     return l; 
    
// }
// int main(){
//     linklist h;       //初始化头节点              
//     h=(node*)malloc(sizeof(node));
//     h->data=666; 
//     h->next=NULL;
//     char choose;
//     printf("ple input option:\nc------init\ni------insert\nd------delete\ns------show\nx------exit\n"); 
    
//     while(1){
//         scanf("%c",&choose);
//         switch(choose){
//             case 'c':
//                 h = head_creat(h);
//                 out_list(h);
//                 break;
//             case 'i':
//                 h = inset(h);
//                 out_list(h);
//                 break; 
//             case 'd':
//                 h = dele(h);
//                 out_list(h);
//                 break;
//             case 's':
//                 out_list(h);
//                 break;
//             case 'x':
//                 return 0;
//             default:
//                 printf("input error"); 
            
//         }
//     }
     
// }


// typedef struct node
// {
//     struct node * pre;
//     int data;
//     struct node * next;
// }Node, *Tlinkedlist;


// Tlinkedlist create(Tlinkedlist head){
//     //分配头节点
//     head = (Tlinkedlist)malloc(sizeof(Node));
//     head->pre = NULL;
//     head->next = NULL;

//     int i;
//     Tlinkedlist tmp;
//     for(i = 1, tmp = head; i<4; i++, tmp = tmp->next){
//         Tlinkedlist p;
//         p = (Tlinkedlist)malloc(sizeof(Node));

//         p->pre = tmp;
//         p->data = i;
//         p->next = NULL;

//         tmp->next= p;
//     }

//     return head;
// }

// Tlinkedlist insert(Tlinkedlist head, int position, int data){
//     Tlinkedlist tmp = head;
//     int i = 1;

//     while(i < position){
//         //找前驱节点
//         tmp = tmp->next;
//         i++;
//     }
//     Tlinkedlist p;
//     p = (Tlinkedlist)malloc(sizeof(Node));

//     p->data = data;
//     tmp->next->pre = p;
//     p->next = tmp->next;
//     tmp->next=p;
//     p->pre=tmp;

//     return head;
// }

// head del(Tlinkedlist head, int deldata){
//     Tlinkedlist tmp = head->next;
//     while(tmp){
//         if(tmp->data == deldata){
//             tmp->next->pre = tmp->pre;
//             tmp->pre->next = tmp->next;
//             free(tmp);
//             return head;
//         }
//         tmp=tmp->next;
//     }
// }



// void show(Tlinkedlist head){
//     Tlinkedlist tmp;
//     int i;
//     for(i = 1, tmp = head -> next; tmp != NULL; i++, tmp = tmp->next){
//         printf("%d -> %d\n", i, tmp->data);
//     }
// }



// int main(){
//     Tlinkedlist head = NULL;
//     head = create(head);
//     show(head);

//     printf("insert......\n");
  
//     head = insert(head, 2, 789);
//     show(head);

//     printf("del......\n");
//     head = del(head, 789);  
//     show(head);

//     return 0;
// }


























































































// typedef struct line{
//     struct line * prior;
//     int data;
//     struct line * next;
// }line;

// line* initLine(line * head){
//     head=(line*)malloc(sizeof(line));

//     head->prior=NULL;
//     head->next=NULL;
//     head->data=1;
    
//     line * list=head;
      
//     for (int i=2; i<=3; i++) {
//         line * body=(line*)malloc(sizeof(line));
//         body->prior=NULL;
//         body->next=NULL;
//         body->data=i;
       
//         list->next=body;
//         body->prior=list;

//         list=list->next;
//     }
//     return head;
// }


// line * insertLine(line * head,int data,int add){
//     //新建数据域为data的结点
//     line * temp=(line*)malloc(sizeof(line));
//     temp->data=data;
//     temp->prior=NULL;
//     temp->next=NULL;

//     //插入到链表头，要特殊考虑
//     if (add==1) {
//         temp->next=head;
//         head->prior=temp;
//         head=temp;
//     }else{
//         line * body=head;
//         //找到要插入位置的前一个结点
//         for (int i=1; i<add-1; i++) {
//             body=body->next;
//         }
//         //判断条件为真，说明插入位置为链表尾
//         if (body->next==NULL) {
//             body->next=temp;
//             temp->prior=body;
//         }else{
//             body->next->prior=temp;
//             temp->next=body->next;
//             body->next=temp;
//             temp->prior=body;
//         }
//     }
//     return head;
// }
// line * delLine(line * head,int data){
//     line * temp=head;
//     //遍历链表
//     while (temp) {
//         //判断当前结点中数据域和data是否相等，若相等，摘除该结点
//         if (temp->data==data) {
//             temp->prior->next=temp->next;
//             temp->next->prior=temp->prior;
//             free(temp);
//             return head;
//         }
//         temp=temp->next;
//     }
//     printf("链表中无该数据元素");
//     return head;
// }
// //输出链表的功能函数
// void display(line * head){
//     line * temp=head;
//     while (temp) {
//         if (temp->next==NULL) {
//             printf("%d\n",temp->data);
//         }else{
//             printf("%d->",temp->data);
//         }
//         temp=temp->next;
//     }
// }

// int main() {
//     line * head;
//     head=initLine(head);
   
//     // head=insertLine(head, 4, 2);

//     display(head);
    
//     head=delLine(head, 1);
//     display(head);
   
//     return 0;
// }





















































// // 单链表的创建、展示、插入、删除

// // 节点
// typedef struct node
// {
//     int data;
//     struct node * next;
// }Node, *linkedlist;

// //创建一个带有头节点的链表
// linkedlist create(){
//     // 头指针指向头节点
//     linkedlist head;
//     head = (linkedlist)malloc(sizeof(Node));
//     head->next = NULL;

//     //需要尾插时需要定义临时的tail指针
//     linkedlist tail;
//     tail = head;

//     printf("pls input data\n");
//     int inputdata;
//     while(scanf("%d", &inputdata) != EOF){

//         linkedlist p;
//         p = (linkedlist)malloc(sizeof(Node));

//         //此时应注意是头插还是尾插
//         //尾插按顺序
//         p->data = inputdata;
//         tail->next = p;
//         tail = p;
//         tail->next = NULL;
//     }

//     return head;
// }

// linkedlist insert(linkedlist head, int positon, int data){
//     //插入的时候 找到前节点
//     linkedlist pre;
//     pre = head;
//     int i = 1;
//     while(i < positon){
//         pre = pre->next;
//         i++;
//     }
//     linkedlist p;
//     p = (linkedlist)malloc(sizeof(Node));

//     p->data = data;
//     p->next = pre->next;
//     pre->next = p;

//     return head;
// }

// linkedlist delete(linkedlist head, int deldata){
//     linkedlist p;
//     linkedlist pre;
//     //首元节点
//     p = head->next;
//     printf("deldata %d\n", deldata);
//     if(p->data == deldata){
//         head->next = p->next;
//     }else{
//         while(p->data != deldata)
//         {
//             pre = p;
//             p = p->next;
//         }
//         pre->next = p->next;
//     }
    
//     free(p);

//     return head;
// }   



// void show(linkedlist head){
//     int i;
//     linkedlist tmp;
//     for(i = 1, tmp = head->next;tmp != NULL;i++, tmp = tmp->next)
//         printf("%d -> %d\n", i, tmp->data);
// }


// int main(){

//     //头指针 
//     linkedlist head;
    
//     head = create();
//     show(head);
//     int position, data;
//     printf("pls input position and data\n");
//     scanf("%d %d", &position, &data);
//     head = insert(head, position, data);
//     show(head);

//     int deldata;
//     printf("delete data \n");
//     scanf("%d", &deldata);
//     head = delete(head, deldata);
//     show(head);    

//     Sleep(10000);
//     // show();
// }





























// #define OK 1
// #define ERR 0
// #define MAXSIZE 100
// typedef int ElemType;
 
// //定义
// typedef struct Node
// {
//     ElemType data;
//     struct Node *next;
// }Node,*LinkedList;
 
// //初始化
// LinkedList LinkedListInit()
// {
//     LinkedList L;
//     L = (LinkedList )malloc(sizeof(Node));
//     if (L==NULL)
//     {
//         printf("申请内存空间失败.");
//     }
//     L->next=NULL;
//     return L;
// }
 
// //单链表的建立1，头插入法建立单链表
// LinkedList LinkedListCreateHead()
// {
//     //申请头节点    
//     LinkedList Head;
//     Head = (LinkedList)malloc(sizeof(Node));
//     Head->next=NULL;

//     ElemType x;//x为链表数据域中的数据
//     while (scanf("%d",&x)!=EOF)
//     {
//         Node *P;
//         P=(Node *)malloc(sizeof(Node));
         
//         P->data=x;
 
//         P->next=Head->next;
         
//         Head->next=P;
     
//     }
//     return Head;
// }
 
// //单链表的建立2，尾插入法建立单链表
// LinkedList LinkedListCreateTail()
// {
//     //申请头节点
//     LinkedList Head;
//     Head = (LinkedList)malloc(sizeof(Node));
//     Head->next=NULL;
 
//     //定义Tail始终指向终端结点，开始时指向头结点
//     LinkedList Tail;
//     Tail=Head;
 
//     ElemType x;
//     while (scanf("%d",&x)!=EOF)
//     {
//         LinkedList p;
//         P = (LinkedList)malloc(sizeof(Node));//申请新的结点
         
//         P->data=x;
//         Tail->next=P;
//         Tail=P;
//     }
//     Tail->next=NULL;
//     return Head;
     
// }
// //单链表的插入，在链表的第i个位置插入x的元素
// LinkedList LinkedListInsert(LinkedList L,int i,ElemType x)
// {
//     Node *pre;
//     pre = L;
 
//     for (int temp=1; temp<i; temp++)
//         pre=pre->next;

//     Node *P = (Node *)malloc(sizeof(Node));
    
//     P->data = x;
    
//     P->next=pre->next;
    
//     pre->next=P;
//     return L;
 
// }
 
// //单链表的删除，在链表中删除值为x的元素
 
// LinkedList LinkedListDel(LinkedList L,ElemType x)
// {
//     Node *p;//需要删除的节点
//     Node *pre; //pre为删除节点的前驱结点

//     //指向首元节点
//     p=L->next;
     
//     while (p->data!=x)
//     {

//         pre=p;
//         p=p->next;
         
//     }

//     pre->next=p->next;
    
//     free(p);
//     return L;
     
// }
// //显示单链表数据
// void LinkedListShow(LinkedList L)
// {
//     LinkedList temp;
//     int i=0;
//     for(i=1,temp = L->next; temp != NULL; i++,temp = temp->next)
//         printf("(%d)->%d ",i,temp->data);
//     printf("\n");
// }

// int main()
// {
 
//     //键盘中输入EOF方法：press Ctrl+Z on a new line
//     LinkedList L;
//     //尾插法建表
//     printf("please input node data:\n");
//     L=LinkedListCreateTail();
//     printf("the linked list show:\n");
//     LinkedListShow(L);
 
//     int i;
//     ElemType x;
//     printf("please input what insert position and data:\n");
//     scanf("%d %d",&i,&x);
//     LinkedListInsert(L,i,x);
//     printf("the linked list show:\n");
//     LinkedListShow(L);
 
//     printf("please input delete data:");
//     scanf("%d",&x);
//     LinkedListDel(L,x);
//     printf("the linked list show:\n");
//     LinkedListShow(L);
     
//     return 0;
// }












// typedef struct node
// {
//   char name[20];    //存储数据
//   struct node *prior;
//   struct node *next;  //指针类型，其指向本结构体类型的数据
// }stud;             //双向链表的结构定义

// stud *create(int n)
// {
//   stud *p,*h,*s;   //声明结构体指针
//   int i;
  
//   h=(stud*)malloc(sizeof(stud));   //申请节点空间

//   h->name[0]='\0';  
//   h->prior=NULL;
//   h->next=NULL;
//   //第0个节点称为整个链表的头节点，它一般不存放具体数据，只是存放第一个
//   //节点的地址，也称为头指针
//   p=h;

//   for (i=0; i<n; i++)
//     {
//       s=(stud*)malloc(sizeof(stud));
//       p->next=s;                   //指定后继节点
//       printf ("input the %d student's name: \n",i+1);
//       scanf("%s",s->name);
//       s->prior=p;               //指定前驱节点
//       s->next=NULL;
//       p=s;
//     }
  
//   // 待商榷
//   p->next=NULL;
  
//   return (h);
// }

// stud *search(stud *h,char *x)
// {
//   stud *p;
//   char *y;
//   p=h->next;
//   while(p)
//     {
//       y=p->name;
//       if(strcmp(y,x)==0)  //如果是要删除的节点，则返回地址
//         return (p);
//       else 
//         p=p->next;
//     }
//   printf ("cannot find data!\n");
// }

// void del(stud *p)
// {
//   p->next->prior=p->prior;    //p的下一个节点的前驱指针指向p的前驱节点
//   p->prior->next=p->next;     //p的前驱节点的后继指针指向p的后继节点
//   free(p);
// }

// int main(int argc, char *argv[])
// {
//   int number;             //定义变量
//   char sname[20];         //定义字符型数组
//   stud *head;
//   stud *sp;
//   puts("please input the size of the list:");
//   scanf("%d",&number);    //输入链表节点数
//   head = create(number);     //创建链表
  
//   sp = head->next;
  
//   printf ("now the double list is:\n");
//   while(sp)               //输出链表中数据
//     {
//       printf ("%s\n",&*(sp->name));   
//       sp=sp->next;
//     }
//   printf ("please input the name which you want to find:\n");
//   scanf("%s",sname);
//   sp=search(head,sname);      //查找指定节点
//   printf ("the name you want to find and delete is: %s\n",*&sp->name);
//   del(sp);                    //删除节点
//   sp=head->next;
//   printf ("now the double list is:\n");
//   while(sp)                   //输出当前链表中数据
//     {
//       printf ("%s ",&*(sp->name));
//       sp=sp->next;
//     }
//   printf ("\n");


//   Sleep(100000);
//   return 0;
// }


// /* 单链表的结构 */
// struct List{
//   int data;               //  数据域
//   struct List *next;      //  指针域 
// };

// /* 双向链表的结构 */
// typedef struct List{
//   int data;     //  数据域
//   struct List *next;    //  向后的指针
//   struct List *front;   //  向前的指针
// };

// typedef struct List* pElem;
// typedef struct List eElem;


// pElem CreatList(){

//   pElem head = (pElem)malloc( sizeof(eElem) );
//   assert( head != NULL );   //  包含于标准库<assert.h>
//   head->next = head->front = NULL;    //  初始化链表，指针置空
//   return head;
// }

// // 双向链表的插入 最主要的语句自然就是tmp->next = head->next

// void InsertElem( pElem head , int data ){
//   if( head == NULL ){
//     printf("The list is empty.\n");   //  头结点为空，则无法插入
//     return;
//   }
//   pElem tmpHead = head;   //  创建一个临时的头结点指针
//   if( tmpHead->next == NULL ){
//     /*  当双向链表只有一个头结点时 */    
//     pElem addition = (pElem)malloc( sizeof(eElem) );
//     assert( addition != NULL );
//     addition->data = data;    //  数据域赋值
//     addition->next = tmpHead->next;   //  后向指针连接
//     tmpHead->next = addition;
//     addition->front = tmpHead;      //  将插入结点的front 指向头结点
//   }
//   else{
//     /* 当双向链表不只一个头结点时 */
//     pElem addition = (pElem)malloc( sizeof(eElem) );
//     assert( addition != NULL );
//     addition->data = data;    //  数据域赋值
//     tmpHead->next->front = addition;    //  头结点的下一个结点的front 指针
//     addition->front = tmpHead;    //  插入的结点的front 指针指向头结点
//     addition->next = tmpHead->next;   //  插入结点的next 指针指向原本头指针的下一结点
//     tmpHead->next = addtion;    //  将头结点的next 指针指向插入结点
//   }
// }


// // 双向链表的遍历
// void IlluList( pElem head ){
//   printf("-------------------------------\n");
//   if( head == NULL ){
//     printf("The list is empty.\n");
//     return;
//   }
//   pElem tmpHead = head;
//   while( tmpHead->next != NULL ){
//     tmpHead = tmpHead->next;    //  头结点数据域为空，因此直接从头结点的下一结点开始遍历
//     printf("%d\n",tmpHead->data);
//   }
//   //  此时tmpHead 的地址在链表的最后一个结点处
//   while( tmpHead->front->front != NULL ){
//     printf("%d\n",tmpHead->data);   //  最后一个结点要输出
//     tmpHead = tmpHead->front;
//   }
//   printf("%d\n",tmpHead->data);
//   return;
// }


// // 删除一个节点
// void DeleteElem( pElem head , int data ){
//   if( head == NULL ){
//     printf(""The list is empty.\n);
//     return;
//   }
//   pElem tmpHead = head;
//   while( tmpHead->next != NULL ){
//     tmpHead = tmpHead->next;
//     if( tmpHead->data == data ){
//       tmpHead->front->next = tmpHead->next;   //  将被删结点的上一个结点的next 指针指向 被删结点的下一个结点
//       tmpHead->next->front = tmpHead->front;    //  将被删结点的下一个结点的 front 指针指向 被删结点的上一个结点
//       break;
//     }
//   }
//   free(tmpHead);    //  释放内存
// }


// // 销毁链表
// void DestroyList( pElem head ){
//   pElem tmp;
//   while( head->next != NULL ){
//     tmp = head;   //  指针不断后移
//     head = head->next;
//     free(tmp);
//   }
//   free(head);
// }
