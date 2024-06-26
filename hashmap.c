#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义哈希表节点
typedef struct HashMapNode {
    char *key;
    void *value;
    struct HashMapNode *next;
} HashMapNode;

// 定义哈希表
typedef struct HashMap {
    HashMapNode **buckets;
    int capacity;
    int size;
} HashMap;

// 哈希函数
unsigned int hashFunction(const char *key, int capacity) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

// 创建哈希表
const HashMap *createHashMap(int capacity) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    if (map == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    map->buckets = (HashMapNode **)calloc(capacity, sizeof(HashMapNode *));
    if (map->buckets == NULL) {
        printf("Memory allocation failed!\n");
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;

    return map;
}

// 插入键值对到哈希表
void insert(HashMap *map, const char *key, void *value) {
    unsigned int index = hashFunction(key, map->capacity);
    HashMapNode *newNode = (HashMapNode *)malloc(sizeof(HashMapNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;

    if (map->buckets[index] == NULL) {
        map->buckets[index] = newNode;
    } else {
        HashMapNode *current = map->buckets[index];
        if(strcmp(current->key, key) == 0) {
			current->value = value;
		}
		else {
			int f = 1;
			while (current->next != NULL) {
            	current = current->next;
        		if(strcmp(current->key, key) == 0) {
					current->value = value;
					f = 0;
					break;
				}    	
        	}
        	if (f) current->next = newNode;
		}
    }

    map->size++;
}

// 获取值
void *get(HashMap *map, const char *key) {
    unsigned int index = hashFunction(key, map->capacity);

    HashMapNode *current = map->buckets[index];
    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

// 打印哈希表
void printHashMap(HashMap *map) {
    for (int i = 0; i < map->capacity; i++) {
        HashMapNode *current = map->buckets[i];
        while (current!= NULL) {
            printf("Key: %s, Value: %d\n", current->key, current->value);
            current = current->next;
        }
    }
}

// 释放哈希表内存
void destroyHashMap(HashMap *map) {
    for (int i = 0; i < map->capacity; i++) {
        HashMapNode *current = map->buckets[i];
        while (current!= NULL) {
            HashMapNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}
