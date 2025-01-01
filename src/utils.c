#include "../Headers/Structures.h"
#include "../Headers/memoryUtils.h"

void InitializeList(struct LinkedList* list) {
  list->tail = NULL;
  list->head = NULL;
};

int AppendNode(struct LinkedList* list, char symbol) {

    struct Node *newNode = (struct Node*)my_malloc(sizeof(struct Node));

    if (list->tail == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = list->tail->next;
    }

    newNode->current = symbol;
    newNode->next = NULL;

    return SUCCESS_CODE;
}
