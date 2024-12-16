
struct Node {
    struct Node* next;
    char current;
    struct Node* prev;
};

struct LinkedList {
public:
    LinkedList() {
        tail = NULL;
        head = NULL;
    }

    Node *getTail() {
        return tail;
    }

    Node *getHead() {
        return head;
    }

    void append(char current) {
        Node *tmp = new Node;

        if (tail == NULL) {
            tmp->prev = NULL;
            head = tmp;
            tail = tmp;
        } else {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tail->next;
        }

        tmp->current = current;
        tmp->next = NULL;
        
        
    }

    bool isEmpty() {
        return head == nullptr;
    }

private:
    Node *tail;
    Node *head;
};


struct TableElem {
    char newSymbol;
    int idState;
    short direction;
};

struct TableElem TableTransition[MAX_ASCII][MAX_STATES];

struct ReadResult {
    struct TableElem TableTransition[MAX_ASCII][MAX_STATES];
    int countState;
}