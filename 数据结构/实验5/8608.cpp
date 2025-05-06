#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    int data;                // 节点数据
    struct BiTNode *lchild;  // 左子节点指针
    struct BiTNode *rchild;  // 右子节点指针
} BiTNode, *BiTree;

// 插入新节点
int InsertBST(BiTree *T, int key) {
    if (!(*T)) {
        // 如果当前节点为空，创建新节点
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!(*T)) return 0; // 内存分配失败
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return 1;  // 插入成功
    } else if (key == (*T)->data) {
        return 0;  // 关键字已存在，不需插入
    } else if (key < (*T)->data) {
        // 插入左子树
        return InsertBST(&((*T)->lchild), key);
    } else {
        // 插入右子树
        return InsertBST(&((*T)->rchild), key);
    }
}

// 创建二叉排序树
void CreateBST(BiTree *T, int data[], int n) {
    *T = NULL; // 初始化为空树
    for (int i = 0; i < n; i++) {
        InsertBST(T, data[i]);
    }
}

// 前序遍历
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%d ", T->data);     // 先访问根节点
        PreOrderTraverse(T->lchild); // 再遍历左子树
        PreOrderTraverse(T->rchild); // 最后遍历右子树
    }
}

// 中序遍历
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild); // 先遍历左子树
        printf("%d ", T->data);     // 再访问根节点
        InOrderTraverse(T->rchild); // 最后遍历右子树
    }
}

// 后序遍历
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild); // 先遍历左子树
        PostOrderTraverse(T->rchild); // 再遍历右子树
        printf("%d ", T->data);      // 最后访问根节点
    }
}

// 中序遍历的非递归算法
void InOrderTraverse_NonRecursive(BiTree T) {
    BiTree stack[100]; // 创建栈
    int top = -1;      // 栈顶指针
    BiTree p = T;      // 当前节点

    while (p || top != -1) {
        if (p) {
            // 如果当前节点非空，入栈并遍历左子树
            stack[++top] = p;
            p = p->lchild;
        } else {
            // 如果当前节点为空，出栈并访问节点，然后遍历右子树
            p = stack[top--];
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// 层次遍历
void LevelOrderTraverse(BiTree T) {
    if (!T) return;

    BiTree queue[100]; // 创建队列
    int front = 0, rear = 0; // 队头和队尾指针

    queue[rear++] = T; // 根节点入队

    while (front < rear) {
        BiTree node = queue[front++]; // 出队
        printf("%d ", node->data);    // 访问节点

        // 将左右子节点入队
        if (node->lchild) queue[rear++] = node->lchild;
        if (node->rchild) queue[rear++] = node->rchild;
    }
}

// 查找指定关键字
int SearchBST(BiTree T, int key) {
    if (!T) {
        return 0; // 未找到
    } else if (key == T->data) {
        return 1; // 找到了
    } else if (key < T->data) {
        return SearchBST(T->lchild, key); // 在左子树中查找
    } else {
        return SearchBST(T->rchild, key); // 在右子树中查找
    }
}

// 交换左右子树
void SwapTree(BiTree T) {
    if (T) {
        // 交换当前节点的左右子树
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;

        // 递归交换左右子树的左右子树
        SwapTree(T->lchild);
        SwapTree(T->rchild);
    }
}

// 计算树的深度
int TreeDepth(BiTree T) {
    if (!T) {
        return 0;
    } else {
        int leftDepth = TreeDepth(T->lchild);
        int rightDepth = TreeDepth(T->rchild);
        return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
    }
}

// 计算叶子节点数
int LeafCount(BiTree T) {
    if (!T) {
        return 0;
    } else if (!T->lchild && !T->rchild) {
        return 1; // 如果是叶子节点，返回1
    } else {
        return LeafCount(T->lchild) + LeafCount(T->rchild); // 递归计算左右子树的叶子节点数
    }
}

int main() {
    BiTree T = NULL;
    int n, search_key1, search_key2, insert_key;

    // 输入节点个数
    scanf("%d", &n);

    // 输入n个整数，构建二叉排序树
    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    CreateBST(&T, data, n);

    // 输入两个待查找的关键字和一个待插入的关键字
    scanf("%d", &search_key1);
    scanf("%d", &search_key2);
    scanf("%d", &insert_key);

    // 输出树的先序、中序、后序遍历序列
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");

    // 输出查找结果
    printf("%d\n", SearchBST(T, search_key1));
    printf("%d\n", SearchBST(T, search_key2));

    // 插入新节点，并输出插入后的遍历序列
    InsertBST(&T, insert_key);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");

    // 中序遍历的非递归算法
    InOrderTraverse_NonRecursive(T);
    printf("\n");

    // 层次遍历
    LevelOrderTraverse(T);
    printf("\n");

    // 第一次交换左右子树，并输出遍历序列
    SwapTree(T);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");

    // 第二次交换左右子树，恢复原状，并输出遍历序列
    SwapTree(T);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");

    // 输出树的深度和叶子节点数
    printf("%d\n", TreeDepth(T));
    printf("%d\n", LeafCount(T));

    // 释放内存
    free(data);

    return 0;
}