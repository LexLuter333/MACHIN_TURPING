#include "../Headers/Structures.h"


void InitializeList(struct LinkedList* list) {
  list->tail = NULL;
  list->head = NULL;
};

int AppendNode(struct LinkedList* list, char symbol) {
    void *current_brk = sbrk(0);

    if (brk(current_brk + sizeof(struct Node)) == -1) {
        return FAIL_CODE;
    }
    struct Node *newNode = (struct Node*)current_brk;

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
