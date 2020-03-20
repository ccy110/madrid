/****************************************
技巧07：创建双向链表
****************************************/

/****************************************
单链表
双向链表
循环链表

单链表反转
链表中的检测
两个有序链表的合并
删除链表倒数第n个链表
求链表中间节点


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
    struct node * pre;
    int data;
    struct node * next;
}Node, *Tlinkedlist;


Tlinkedlist create(Tlinkedlist head){
    //分配头节点
    head = (Tlinkedlist)malloc(sizeof(Node));
    head->pre = NULL;
    head->next = NULL;

    int i;
    Tlinkedlist tmp;
    for(i = 1, tmp = head; i<4; i++, tmp = tmp->next){
        Tlinkedlist p;
        p = (Tlinkedlist)malloc(sizeof(Node));

        p->pre = tmp;
        p->data = i;
        p->next = NULL;

        tmp->next= p;
    }

    return head;
}

Tlinkedlist insert(Tlinkedlist head, int position, int data){
    Tlinkedlist tmp = head;
    int i = 1;

    while(i < position){
        //找前驱节点
        tmp = tmp->next;
        i++;
    }
    Tlinkedlist p;
    p = (Tlinkedlist)malloc(sizeof(Node));

    p->data = data;
    tmp->next->pre = p;
    p->next = tmp->next;
    tmp->next=p;
    p->pre=tmp;

    return head;
}

head del(Tlinkedlist head, int deldata){
    Tlinkedlist tmp = head;
    while(tmp){
        
    }
}



void show(Tlinkedlist head){
    Tlinkedlist tmp;
    int i;
    for(i = 1, tmp = head -> next; tmp != NULL; i++, tmp = tmp->next){
        printf("%d -> %d\n", i, tmp->data);
    }
}



int main(){
    Tlinkedlist head = NULL;
    head = create(head);
    show(head);

    printf("insert......\n");
  
    head = insert(head, 2, 789);
    show(head);

    printf("del......\n");
    head = del(head, 789);  
    show(head);

    return 0;
}


























































































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
