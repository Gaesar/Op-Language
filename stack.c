#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// 创建一个空栈
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// 检查栈是否已满
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 检查栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈操作
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// 获取栈顶元素
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

// 打印栈的内容
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int getSize(Stack* stack) {
	if (isEmpty(stack)) {
        return 0;
    }
    return stack->top + 1;
}
