#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

Status ListInsert_L(LinkList &L, int i, ElemType e) {
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

LinkList CreateList(int n, int arr[]) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        ListInsert_L(L, i + 1, arr[i]);
    }
    return L;
}

void PrintList(LinkList L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkList MergeLists(LinkList A, LinkList B) {
    LinkList C = (LinkList)malloc(sizeof(LNode));
    C->next = NULL;
    LinkList pa = A->next, pb = B->next, pc = C;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }
    pc->next = pa ? pa : pb;
    return C;
}

int main() {
    int nA, nB;
    scanf("%d", &nA);
    int arrA[nA];
    for (int i = 0; i < nA; ++i) {
        scanf("%d", &arrA[i]);
    }
    scanf("%d", &nB);
    int arrB[nB];
    for (int i = 0; i < nB; ++i) {
        scanf("%d", &arrB[i]);
    }

    LinkList A = CreateList(nA, arrA);
    LinkList B = CreateList(nB, arrB);

    printf("List A:");
    PrintList(A);
    printf("List B:");
    PrintList(B);

    LinkList C = MergeLists(A, B);
    printf("List C:");
    PrintList(C);

    return 0;
}