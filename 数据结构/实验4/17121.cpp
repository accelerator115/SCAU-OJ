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

int d0,d1,d2;

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
        T->data = ch;                 // 生成根结点
        CreateBiTree(T->lchild);       // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree

void Count(BiTree &T)
{
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
    Count(T->lchild);
    Count(T->rchild);    
}

int main() // 主函数
{
    // 补充代码
    BiTree T;
    CreateBiTree(T);
    Count(T);
    printf("%d\n%d\n%d\n", d2, d1, d0);
} // main