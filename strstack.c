#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char* items[MAX_SIZE];
    int top;
} StringStack;

// ����һ���յ��ַ���ջ
StringStack* createStringStack() {
    StringStack* stack = (StringStack*)malloc(sizeof(StringStack));
    stack->top = -1;
    return stack;
}

// ���ջ�Ƿ�����
int isFullStringStack(StringStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// ���ջ�Ƿ�Ϊ��
int isEmptyStringStack(StringStack* stack) {
    return stack->top == -1;
}

// ��ջ����
void pushStringStack(StringStack* stack, char* item) {
    if (isFullStringStack(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = (char*)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(stack->items[stack->top], item);
}

// ��ջ����
char* popStringStack(StringStack* stack) {
    if (isFullStringStack(stack)) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    char* item = stack->items[stack->top];
    stack->items[stack->top] = NULL;
    stack->top--;
    return item;
}

// ��ȡջ��Ԫ�ص�����ջ
char* peekStringStack(StringStack* stack) {
    if (isFullStringStack(stack)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    return stack->items[stack->top];
}

// ��ӡջ������
void printStringStack(StringStack* stack) {
    if (isFullStringStack(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s ", stack->items[i]);
    }
    printf("\n");
}

// �ͷ�ջ���ڴ�
void freeStringStack(StringStack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        free(stack->items[i]);
    }
    free(stack);
}

