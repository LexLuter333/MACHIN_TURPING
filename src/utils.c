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

char* int_to_string(int number){
  char buffer[20];
  int length = 0;
  if (number < 0){
      buffer[length++] = '-';
      number = number * -1;
  }
  int tmp = number;
  do{
    buffer[length++] = '0' + tmp % 10 ;
    tmp /= 10;
  } while(tmp > 0);

  return buffer;
}

int chars_to_int(char* chars){
    int i = 0;
    int result = 0;
    while (chars[i]) {
      result += chars[i] - '0';
      result *= 10;
    }
    if (chars[0] == '-') return result * -1;
    return result;
}