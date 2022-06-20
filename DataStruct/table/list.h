#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <malloc.h>

#pragma region
/*
typedef struct linkednode //结点类型
{
    int data;         //值域
    struct linkednode *next; //链域
} snode, *ptr;        //结点类型名snode，指针类型名ptr

ptr head;
ptr p;
ptr q;
struct linkednode *he; //类型struct linkednode*与类型ptr等价，都是指向snode的指针类型
// 编译预处理命令：
#include <malloc.h>
//通过调用文件中的malloc.h中的动态存储分配函数
//malloc产生结点（动态结点）
//free回收结点
//1、malloc()的典型用法：
p=(ptr)malloc(sizeof(snode));
//2、new的用法：使用new分配
q=new snode;

//结点的引用
p->data //访问结点的值域等价于
(*p).data;
p->next; //访问结点的链域等价于
(*p).next;


//废结点的回收：
free(p);
//释放后，变量p->不复存在，对p->的操作将变成“无意义”
delete q;
q=nullptr;


//插在表头
p->next=head;
head=p;

//插在表中
p->next=q->next;
q->next=p;


//删除表头结点
q=head;
head=head->next;
free(q);

//删除表中的结点
p=q->next;
q->next=p->next;
free(p);

 */
#pragma endregion
//表头插入
/*
步骤1：构造一个空链表;
步骤2：读入第一个元素值;
步骤3：当读入的元素值不是结束标志时，循环执行步骤4-7;
步骤4：创建一个新结点;
步骤5：将读入的元素值存入新结点的值域;
步骤6：将新结点插入到链表的表头处;
步骤7：读入下一个元素值，转步骤3;
步骤8：如构造完毕，返回首指针。
 */
int End_elm = 0;
typedef struct linkednode //结点类型
{
    int data;                //值域
    struct linkednode *next; //链域
} snode, *ptr;               //结点类型名snode，指针类型名ptr

ptr createlinkedA()
{
    ptr head, p;
    int x;
    head = NULL;         //表头指针置空
    scanf("%d\n", &x);   //读入一个新的元素值
    while (x != End_elm) //判断是否为结束的标志
    {
        p = (ptr)malloc(sizeof(snode)); //申请一个存储结点
        p->data = x;                    //将元素存入申请结点的值域
        p->next = head;                 //插在表头处，p的链域指向head指向的结点
        head = p;                       //表头指向新结点，head指向p指向的结点
        scanf("%d\n", &x);              //输入下一个元素
    }

    return (head); //返回表头指针
}

//表尾插入
/*
步骤1：构造一个空链表;
步骤2：读入第一个元素值;
步骤3：当读入的元素值不是结束标志时，循环执行步骤4-7;
步骤4：创建一个新结点;
步骤5：将读入的元素值存入新结点的值域;
步骤6：将新结点插入到链表的表尾处;
步骤7：读入下一个元素值，转步骤3;
步骤8：如构造完毕，返回首指针。
 */
ptr createlinkedB()
{
    ptr head, p, last;
    head = NULL;
    int x;
    scanf("%d\n", &x);
    while (x != End_elm)
    {
        p = (ptr)malloc(sizeof(snode));
        p->data = x;
        if (head == NULL)
        {
            p->next = head;
            head = p;
            last = p;
            // p->next=NULL;
        }
        else
        {
            last->next = p;
            p->next = NULL;
            last = p;
        }

        scanf("%d\n", &x);
    }

    return (head);
}

ptr createlinkedBY()
{
    ptr head, p, last;
    head = last = (ptr)malloc(sizeof(snode));
    last->next = NULL;
    int x;
    scanf("%d\n", &x);
    while (x != End_elm)
    {
        p = (ptr)malloc(sizeof(snode));
        p->data = x;
        last->next = p;
        p->next = NULL;
        last = p;
        scanf("%d\n", &x);
    }
    p = head;
    head = head->next;
    free(p);
    return (head);
}

//单链表输出
void outlinkedA(ptr p) // p指向头
{
    printf("单链表各结点的值：\n");
    while (p != NULL)
    {
        printf("%5d", p->data); //输出结点的值
        p = p->next;            //滑动指针
    }
    printf("\n输出完成！");
}

//单链表查找
ptr searchA(ptr p, int x) // p是起始指针
{
    while (p != NULL)
    {
        if (p->data == x) //找到X，返回p
            return p;
        p = p->next; //暂时没找到，继续先后查找
    }

    return NULL; //没有查找到，返回空指针
}

//查找表尾设置监督元
ptr search(ptr p, ptr last, int x)
{
    last->data = x; //设置监督元
    while (p->data != x)
    {
        p = p->next;
    }

    if (p != last)
        return p; //查找成功

    return NULL; //查找不成功
}

//加头循环链表
int deleteEle(ptr h, int x)
{
    ptr f, p;
    f = h;
    h->data = x;
    p = h->next;
    while (p->data != x)
    {
        f = p;
        p = p->next;
    }

    if (h == p)
        return 0;

    f->next = p->next;
    free(p);
    return 1;
}

typedef int element_type;
element_type MAX;
//加头有序循环链表
ptr linkedBC()
{
    ptr head, f, l, p;
    element_type x;
    head = new snode;
    head->data = MAX;
    head->next = head;

    f = head;
    l = head->next;

    scanf("%d", &x);

    while (x != End_elm)
    {
        while (x > l->data)
        {
            f = l;
            l = l->next;
        }

        p = new snode;
        p->data = x;
        f->next = p;
        p->next = l;
        scanf("%d",&x);
    }

    return head;
}

//缺省多项式合并
typedef struct element
{
    int ceof;
    int exp;

} ele;

typedef struct _linkednode
{
    ele data;
    struct _linkednode *next;

} _snode, *_ptr;

_ptr merge(_ptr P, _ptr Q)
{
    _ptr _p, head, beforeP;
    head = P;
    beforeP = head;

    while (P->data.exp != Q->data.exp)
    {
        if ((P->data.ceof + Q->data.ceof) != 0)
        {
            P->data.ceof += Q->data.ceof;
            beforeP = P;
            P = P->next;
            Q = Q->next;
            break;
        }
        else
        {
            _p = P;
            P = P->next;
            head = P;
            beforeP = head;
            free(_p);
            Q = Q->next;
        }
    }

    if ((P->data.exp > Q->data.exp) && (head->data.exp == P->data.exp)) // Q数据域中多项式指数小于P数据域中多项式指数,表头插入
    {
        _p = (_ptr)malloc(sizeof(_snode));
        _p->data = Q->data;
        _p->next = head;
        head = _p;
        Q = Q->next;
        beforeP = head;
    }

    while (P != NULL && Q != NULL)
    {
        if (P->data.exp == Q->data.exp)
        {
            if ((P->data.ceof + Q->data.ceof) != 0)
            {
                P->data.ceof += Q->data.ceof;
                beforeP = P;
                P = P->next;
                Q = Q->next;
            }
            else
            {
                _p = P;
                P = P->next;
                free(_p);
            }
        }
        else if (P->data.exp < Q->data.exp)
        {
            if (Q->data.exp < P->next->data.exp)
            {
                _p = (_ptr)malloc(sizeof(_snode));
                _p->data = Q->data;
                _p->next = P->next;
                P = _p;
                P = P->next;
                Q = Q->next;
            }
            else
            {
                P = P->next;
            }
        }
        else // Q值域中多项式指数小于P中的多项式指数
        {
            _p = (_ptr)malloc(sizeof(_snode));
            _p->data = Q->data;
            _p->next = P;
            beforeP->next = _p;
            Q = Q->next;
        }
    }

    while (Q != NULL)
    {
        _p = (_ptr)malloc(sizeof(_snode));
        _p->data = Q->data;
        P->next = _p;
        P = P->next;
        Q = Q->next;
    }
    return head;
}

#endif