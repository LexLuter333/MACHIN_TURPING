#define MAX_ASCII  95
#define MAX_STATES  256
#include <unistd.h>

#define SUCCESS_CODE  1
#define FAIL_CODE  111
struct Node {
    struct Node* next;
    char current;
    struct Node* prev;
};

struct LinkedList {
    struct Node *tail;
    struct Node *head;
};

struct TableElem {
    char newSymbol;
    int idState;
    short direction;
};

//struct TableElem TableTransition[MAX_ASCII][MAX_STATES];

struct ReadResult {
    struct TableElem TableTransition[MAX_ASCII][MAX_STATES];
    int countState;
};

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

