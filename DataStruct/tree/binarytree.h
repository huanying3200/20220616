#ifndef _TREE_H
#define _TREE_H
//双链法存储二叉树，找儿子易，找父亲难;
//完全二叉树的顺序存储法：直接定位父与子;

typedef int element_type;

typedef struct Bnode
{
    element_type data;
    struct Bnode* *Lson, *Rson;
    
}Bnode,*Bptr;   //二叉树结点
Bptr root;

typedef struct Btree
{
    char* name;
    Bptr root;
}BTREE; //二叉树

#endif