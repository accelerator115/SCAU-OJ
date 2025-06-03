// 不考
#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

using namespace std;

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{   
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)   
{   
// 在栈S中插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)   
{   
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
     e=*--S.top;
	 return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{    
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
    e=*(S.top-1);
	return OK;
}

int StackLength(SqStack S) 
{   
// 返回栈S的元素个数
	int i;
    i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
	p = S.top;       
	if(S.top==S.base)printf("The Stack is Empty!");  
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)             
		{
			printf("%d ", *p);
			p--;               
		}
	}
	printf("\n");
	return OK;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int evaluateExpression(const char* expression) {
    SqStack operandStack, operatorStack;
    InitStack(operandStack);
    InitStack(operatorStack);

    int i = 0;
    while (expression[i] != '=' ) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            Push(operandStack, num);
        } else if (expression[i] == '(') {
            Push(operatorStack, expression[i]);
            i++;
        } else if (expression[i] == ')') {
            while (true)
             {
                SElemType op;
                GetTop(operatorStack,op);
                if(op == '(') break;
                int val2, val1;
                Pop(operandStack, val2);
                Pop(operandStack, val1);
                Pop(operatorStack, op);

                switch (op) {
                    case '+': Push(operandStack, val1 + val2); break;
                    case '-': Push(operandStack, val1 - val2); break;
                    case '*': Push(operandStack, val1 * val2); break;
                    case '/': Push(operandStack, val1 / val2); break;
                }
            }
            SElemType temp;
            Pop(operatorStack,temp);
            i++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (true) {
                if(StackLength(operatorStack) == 0) break;
                SElemType op;
                GetTop(operatorStack,op);
                if(op == '(') break;
                if (precedence(expression[i]) <= precedence(op)) {
                    int val2, val1;
                    Pop(operandStack, val2);
                    Pop(operandStack, val1);
                    Pop(operatorStack, op);

                    switch (op) {
                        case '+': Push(operandStack, val1 + val2); break;
                        case '-': Push(operandStack, val1 - val2); break;
                        case '*': Push(operandStack, val1 * val2); break;
                        case '/': Push(operandStack, val1 / val2); break;
                    }
                } else {
                    break;
                }
            }
            Push(operatorStack, expression[i]);
            i++;
        } else {
            i++;
        }
    }

    while (StackLength(operatorStack) != 0) {
        int val2, val1;
        SElemType op;
        Pop(operandStack, val2);
        Pop(operandStack, val1);
        Pop(operatorStack, op);

        switch (op) {
            case '+': Push(operandStack, val1 + val2); break;
            case '-': Push(operandStack, val1 - val2); break;
            case '*': Push(operandStack, val1 * val2); break;
            case '/': Push(operandStack, val1 / val2); break;
        }
    }

    SElemType result;
    Pop(operandStack, result);
    return result;
}

int main() {
    char expression[100];
    scanf("%s", expression);
    printf("%d\n", evaluateExpression(expression));
    return 0;
}

