#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// ����һ����ջ
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// ���ջ�Ƿ�����
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// ���ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ��ջ����
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// ��ջ����
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// ��ȡջ��Ԫ��
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

// ��ӡջ������
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
