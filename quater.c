#include <stdio.h>
#include <stdlib.h>
//#include "hashmap.c"
#define MAX_SIZE 100

typedef struct Quater {
	char* operation;
	void* num1;
	void* num2;
	void* num3;
}Quater;

Quater* createQuater(const char* operation, void* num1, void* num2, void* num3) {
	Quater* quater = (Quater* )malloc(sizeof(Quater));
	quater->operation = strdup(operation);
	quater->num1 = num1;
	quater->num2 = num2;
	quater->num3 = num3;
	return quater;
}

typedef struct {
    Quater* items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// 检查队列是否已满
int isFullQueue(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// 检查队列是否为空
int isEmptyQueue(Queue* queue) {
    return queue->front == -1;
}

void clearQueue(Queue* queue) {
	queue->front = -1;
    queue->rear = -1;
} 

// 入队操作
void enqueue(Queue* queue, Quater* item) {
    if (isFullQueue(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmptyQueue(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
}

// 出队操作
Quater* dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue Underflow!\n");
        return NULL;
    }
    Quater* item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

// 获取队首元素
Quater* front(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    return queue->items[queue->front];
}

int getSizeQueue(Queue* queue) {
	return queue->rear - queue->front + 1;
}

void printQuater(Quater* quater) {
	printf("%s ", quater->operation);
	void* num1 = quater->num1;
	char* s = (char*)num1;
	printf("%s ", s);
	void* num2 = quater->num2;
	char* s2 = (char*)num2;
	printf("%s ", s2);
	void* num3 = quater->num3;
	char* s3 = (char*)num3;
	printf("%s\n", s3);
}

