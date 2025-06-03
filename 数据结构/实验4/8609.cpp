// 不考
#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;
typedef struct
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
void select(HuffmanTree &HT, int n, int &s1, int &s2)
{ // 在HT[1..n]中选择parent为0且weight最小的两个结点， 其序号分别为s1（最小）和s2（次小）。
    // 找最小的节点
    s1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (s1 == 0 || HT[i].weight < HT[s1].weight)
            {
                s1 = i;
            }
        }
    }

    // 找次小的节点
    s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && i != s1)
        {
            if (s2 == 0 || HT[i].weight < HT[s2].weight)
            {
                s2 = i;
            }
        }
    }
}
void createHuffmanTree(HuffmanTree &HT, int n)
{ // 构造哈夫曼树HT
    int i, m, s1, s2;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HT = new HTNode[m + 1]; // 0号单元未用
    for (i = 1; i <= m; i++)
    { // 初始化HT数组
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (i = 1; i <= n; i++)
        cin >> HT[i].weight;
    for (i = n + 1; i <= m; i++) // 建哈夫曼树
    {                            // 在HT[1..i-1]中选择parent为0且weight最小的两个结点， 其序号分别为s1(最小)和s2(次小)
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
void createHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{                           //--- 从叶子到根逆向求每个字符的哈夫曼编码 ---
    char *cd = new char[n]; // 分配求编码的工作空间
    cd[n - 1] = '\0';       // 编码结束符。
    int i, c, f, start;
    for (i = 1; i <= n; ++i)
    {
        start = n - 1;
        c = i, f = HT[i].parent;
        while (f) // 从叶子到根逆向求编码
        {
            --start;
            if (HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f, f = HT[f].parent;
        }
        HC[i] = new char[n - start]; // 为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);   // 从cd复制编码(串)到HC
    }
}
int main()
{
    int i, n;
    int *w;
    HuffmanTree HT;
    HuffmanCode HC;
    scanf("%d", &n);        // 权值个数
    HC = new char *[n + 1]; // 0空间未用
    createHuffmanTree(HT, n);
    createHuffmanCode(HT, HC, n);
    for (i = 1; i <= n; i++)
        printf("%s\n", HC[i]); // 输出哈夫曼编码
}
