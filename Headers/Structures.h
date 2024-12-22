#pragma once
#define CHECKER_H
#define MAX_ASCII  95
#define MAX_STATES  256
#define MAX_LEN 100
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
    char direction;
};

//struct TableElem TableTransition[MAX_ASCII][MAX_STATES];

struct ReadResult {
    struct TableElem TableTransition[MAX_ASCII][MAX_STATES];
    int countState;
};

void InitializeList(struct LinkedList* list);

int AppendNode(struct LinkedList* list, char symbol);

