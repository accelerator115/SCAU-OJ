#include <malloc.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
    QElemType *base; // 初始化的动态分配存储空间
    int front;       // 头指针,若队列不空,指向队列头元素
    int rear;        // 尾指针,若队列不空,指向队列尾元素的下一个位置
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    // 构造一个空队列Q，该队列预定义大小为MAXQSIZE
    // 请补全代码
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    // 插入元素e为Q的新的队尾元素
    // 请补全代码
    SqQueue *p = &Q;
    if ((p->rear + 1) % MAXQSIZE == p->front)
        return ERROR;
    p->base[p->rear] = e;
    p->rear = (p->rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    // 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
    // 请补全代码
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
    // 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
    // 请补全代码
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue Q)
{
    // 返回Q的元素个数
    // 请补全代码
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status QueueTraverse(SqQueue Q)
{
    // 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
    int i;
    i = Q.front;
    if (Q.front == Q.rear)
        printf("The Queue is Empty!\n");
    else
    {
        printf("The Queue is: ");
        while (i != Q.rear)
        {
            printf("%d ", Q.base[i]);
            i = (i + 1) % MAXQSIZE;
        }
    }
    printf("\n");
    return OK;
}

int main()
{
    int a;
    SqQueue S;
    QElemType x, e;
    if (InitQueue(S)) // 判断顺序表是否创建成功，请填空
    {
        printf("A Queue Has Created.\n");
    }
    while (1)
    {
        printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            scanf("%d", &x);
            if (!EnQueue(S, x))
                printf("Enter Error!\n"); // 判断入队是否合法，请填空
            else
                printf("The Element %d is Successfully Entered!\n", x);
            break;
        case 2:
            if (!DeQueue(S, e))
                printf("Delete Error!\n"); // 判断出队是否合法，请填空
            else
                printf("The Element %d is Successfully Deleted!\n", e);
            break;
        case 3:
            if (!GetHead(S, e))
                printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
            else
                printf("The Head of the Queue is %d!\n", e);
            break;
        case 4:
            printf("The Length of the Queue is %d!\n", QueueLength(S)); // 请填空
            break;
        case 5:
            QueueTraverse(S); // 请填空
                break;
        case 0:
            return 1;
        }
    }
}