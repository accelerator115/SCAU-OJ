#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T)
{ // 算法6.4
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            return ERROR;
        T->data = ch;            // 生成根结点
        CreateBiTree(T->lchild); // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree

void CountLeaf(BiTree T, int &d0, int &d1, int &d2)
{ // 统计二叉树T中各层结点数
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL) 
    {
        d0++;
    }
    else if(T->lchild != NULL && T->rchild !=NULL)
    {
        d2++;
    }
    else
    {
        d1++;
    }
    CountLeaf(T->lchild, d0, d1, d2);
    CountLeaf(T->rchild, d0, d1, d2);
} // CountLeaf

int main() // 主函数
{
    // 补充代码
    BiTree T;
    int d0 = 0, d1 = 0, d2 = 0;
    CreateBiTree(T);
    CountLeaf(T, d0, d1, d2);
    printf("%d\n%d\n%d\n", d2, d1, d0);
    return 0;
} // main
