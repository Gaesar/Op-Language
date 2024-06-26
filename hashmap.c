#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����ϣ��ڵ�
typedef struct HashMapNode {
    char *key;
    void *value;
    struct HashMapNode *next;
} HashMapNode;

// �����ϣ��
typedef struct HashMap {
    HashMapNode **buckets;
    int capacity;
    int size;
} HashMap;

// ��ϣ����
unsigned int hashFunction(const char *key, int capacity) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

// ������ϣ��
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

// �����ֵ�Ե���ϣ��
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

// ��ȡֵ
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

// ��ӡ��ϣ��
void printHashMap(HashMap *map) {
    for (int i = 0; i < map->capacity; i++) {
        HashMapNode *current = map->buckets[i];
        while (current!= NULL) {
            printf("Key: %s, Value: %d\n", current->key, current->value);
            current = current->next;
        }
    }
}

// �ͷŹ�ϣ���ڴ�
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
