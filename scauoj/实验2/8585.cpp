#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, ElemType e) {
    if (S.top == MAXSIZE - 1) return false;
    S.data[++S.top] = e;
    return true;
}

bool Pop(SqStack &S, ElemType &e) {
    if (S.top == -1) return false;
    e = S.data[S.top--];
    return true;
}

void DecimalToOctal(int decimal) {
    SqStack S;
    InitStack(S);
    while (decimal != 0) {
        Push(S, decimal % 8);
        decimal /= 8;
    }
    while (!StackEmpty(S)) {
        int e;
        Pop(S, e);
        printf("%d", e);
    }
    printf("\n");
}

int main() {
    int decimal;
    scanf("%d", &decimal);
    DecimalToOctal(decimal);
    return 0;
}