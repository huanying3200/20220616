#ifndef _TREE_H
#define _TREE_H

//树的基本概念：空树、树枝、树叶、儿子、父亲、兄弟、祖先、子孙
//            结点的度(结点子树的个数)、树的元数（树中最大度数）、结点的层数（自上而下，根为第1层，叶子为高层）、结点的高度（从下往上，最高叶子为高为1,根为最大高）、根到叶的路径、树高、有序树、位置树、K正则树、森林

//满二叉树（高为k，结点数=2的k次幂-1的二叉树）
//完全二叉树：满二叉树，从上到下，从做到右，依次取n个结点所构成的二叉树。

//双链法存储二叉树，找儿子易，找父亲难;
//完全二叉树的顺序存储法：直接定位父与子;

typedef int element_type;

typedef struct Bnode
{
    element_type data;
    struct Bnode **Lson, *Rson;

} Bnode, *Bptr; //二叉树结点
Bptr root;

typedef struct Btree
{
    char *name;
    Bptr root;
} BTREE; //二叉树

//普通树转换成二叉树方法：顺次链接结点的左儿子和其他儿子，去掉除左儿子和结点的其他结点连线，顺时针旋转45度。根没有右儿子
//森林转换成二叉树：需要添加虚根，转换方法和普通树转换方法相同，根有右儿子。
//二叉树转换成普通树的方法：左子树为左儿子，右子树为兄弟

//二叉树遍历
//先根遍历DLR   DLR结点序列
//中根遍历LDR   LDR结点序列
//后根遍历LRD

//双链表结构
typedef int element_type;
typedef struct Bnode
{
    element_type data;
    struct Bnode *Lson, *Rson;
} Bnode, *Bptr;
Bptr root;
//先序遍历DLR递归函数
void visit(Bptr p);
void preorder(Bptr p)
{
    if (!p)
        return;

    visit(p);
    preorder(p->Lson);
    preorder(p->Rson);
}

//减少空调用
void preorderA(Bptr p)
{
    visit(p);
    if (p->Lson)
        preorderA(p->Lson);
    if (p->Rson)
        preorderA(p->Rson);
}
void main()
{
    if (root)
        preorderA(root);
}

//中序遍历
void inorder(Bptr p)
{
    if (p->Lson)
        inorder(p->Lson);
    visit(p);
    if (p->Rson)
        inorder(p->Rson);
}

//计算层数,先序遍历
typedef struct BnodeL
{
    int data;
    int Layer;
    struct BnodeL *Lson, *Rson;
} BnodeL, *BLptr;

// level(root,1)
void level(BLptr p, int i)
{
    if (!p)
        return;
    p->Layer = i;
    level(p->Lson, i + 1);
    level(p->Rson, i + 1);
}

//计算高度，后续遍历
typedef struct BHnode
{
    int data;
    int height;
    struct BHnode *Lson, *Rson;
} BHnode, *BHptr;
int hegiht(BHptr p)
{
    int i, j;
    if (!p)
        return 0;

    i = hegiht(p->Lson);
    j = hegiht(p->Rson);
    p->height = (i > j) ? i + 1 : j + 1;
    return (p->height);
}

//先(后)序序列和中序序列唯一确定二叉树，构造二叉树
Bptr buildtree(int a[], int b[], int i, int j, int s, int t)
{
    int k;
    Bptr P;
    P = new Bptr();
    if (i > j)
        return P = NULL;
    P->data = a[i];

    k = s;
    while ((k <= t) && (b[k] != a[i]))
    {
        k++;
    }
    if (k > t)
        exit(ERROR);
    P->Lson = buildtree(a, b, i + 1, i + k - s, s, k - 1);
    P->Rson = buildtree(a, b, i + k - s + 1, j, k + 1, t);
    return P;
}

//扩充先(后)序序列构造二叉树
Bptr pre_create()
{
    Bptr P;
    int x;
    scanf("%d", &x);
    if (x == ZERO)
        return NULL;

    P = new Bptr();
    P->data = x;
    P->Lson = pre_create();
    P->Rson = pre_create();
    return P;
}

//检索树(某种有序特征)，左小右大的特征
//递归查找
Bptr find(Bptr p, int x)
{
    if (!p)
        return NULL;

    if (x < p->data)
    {
        find(p->Lson, x);
    }
    else if (x > p->data)
    {
        find(p->Rson, x);
    }
    else
    {
        return p;
    }
}
//递归查找
Bptr search(Bptr p, int x)
{

    while (p)
    {
        if (x < p->data)
        {
            p = p->Lson;
        }
        else if (x > p->data)
        {
            p = p->Rson;
        }
        else
        {
            return p;
        }
    }

    return NULL;
}
//递归创建检索树
Bptr insert(element x, Bptr p)
{
    if (!p)
    {
        p = new Bptr();
        p->data = x;
        p->Lson = p->Rson = NULL;
        return p;
    }

    if (x > p->data)
        insert(x, p->Rson);
    else
        insert(x, p->Lson);
}

Bptr create()
{
    Bptr root;
    root = NULL;
    int x;
    scanf("%d", &x);
    while (x != ZERO)
    {
        insert(x, root);
        scanf("%d", &x);
    }
    return root;
}
//非递归构造
void insert_(element_type x, Bptr p)
{
    Bptr q;
    while (p)
    {
        q = p;
        if (x >= p->data)
            p = p->Rson;
        else
            p = p->Lson;
    }

    p = new Bptr;
    p->data = x;
    p->Lson = p->Rson = NULL;
    if (x >= q->data)
        q->Rson = p;
    else
        q->Lson = p;
}
Bptr create_()
{
    Bptr root;
    root = NULL;
    int x;
    scanf("%d", &x);
    if (x != ZERO)
    {
        root->data = x;
        root->Lson = root->Rson = NULL;
    }
    else
        return NULL;

    scanf("%d", &x);
    while (x != ZERO)
    {
        insert_(x, root);
        scanf("%d", &x);
    }
    return root;
}

//删除
int delete (Bptr p, element_type x)
{
    Bptr f, q, r, s;
    while ((!p) && (x != p->data))
    {
        f = p;
        if (x > p->data)
            p = p->Rson;
        else
            p = p->Lson;
    }
    if (!p)
        return -1;
    if (!p->Lson)
    {
        if (p->Rson)
        {
            if (p == f->Lson)
            {
                f->Lson = p->Rson;
                delete p;
            }
            else
            {
                f->Rson = p->Rson;
                delete p;
            }
        }
        else
            delete p;
    }
    else if (!p->Rson /* condition */)
    {
        if (p == f->Lson)
        {
            f->Lson = p->Lson delete p;
        }
        else
        {
            f->Rson = p->Lson delete p;
        }
    }
    else
    {
        s = p->Lson;
        if (s->Rson == NULL)
        {
            p->data = s->data;
            p->Lson = s->Lson;
            delete s;
        }
        else
        {
            r = s->Rson;
            while(r->Rson)
            {
                s=r;
                r=r->Rson;
            }
            p->data=r->data;
            s->Rson=r->Lson;
            delete r;
        }
    }
    return 1;
}

#endif