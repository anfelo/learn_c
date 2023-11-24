#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList {
    int length;
    Node *head;
    Node *tail;

} LinkedList;

Node* createNode(int item) {
    Node *newNode = (Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = item;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void append(LinkedList *list, int item) {
    Node *node = createNode(item);

    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}

void prepend(LinkedList *list, int item) {
    Node *node = createNode(item);

    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }

    node->next = list->head;
    list->head = node;
}

void freeList(LinkedList *list) {
    Node *current = list->head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(list);
}

void printList(LinkedList *list) {
    Node *current = list->head;
    Node *nextNode;

    while (current != NULL) {
      nextNode = current->next;
      printf("%d -> ", current->value);
      current = nextNode;
    }

    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    LinkedList *list = createList();

    append(list, 777);
    append(list, 420);
    append(list, 69);
    prepend(list, 99);

    printList(list);

    freeList(list);

    return 0;
}
