#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char* items[MAX_SIZE];
    int top;
} StringStack;

// 创建一个空的字符串栈
StringStack* createStringStack() {
    StringStack* stack = (StringStack*)malloc(sizeof(StringStack));
    stack->top = -1;
    return stack;
}

// 检查栈是否已满
int isFullStringStack(StringStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 检查栈是否为空
int isEmptyStringStack(StringStack* stack) {
    return stack->top == -1;
}

// 入栈操作
void pushStringStack(StringStack* stack, char* item) {
    if (isFullStringStack(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = (char*)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(stack->items[stack->top], item);
}

// 出栈操作
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

// 获取栈顶元素但不出栈
char* peekStringStack(StringStack* stack) {
    if (isFullStringStack(stack)) {
        printf("Stack is empty!\n");
        return NULL;
    }
    return stack->items[stack->top];
}

// 打印栈的内容
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

// 释放栈的内存
void freeStringStack(StringStack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        free(stack->items[i]);
    }
    free(stack);
}

