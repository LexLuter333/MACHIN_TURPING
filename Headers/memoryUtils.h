#include <unistd.h>

typedef struct Block {
    size_t size;           // Размер выделенного блока памяти
    int free;              // Флаг: свободен ли блок (1 = да, 0 = нет)
    struct Block* next;    // Указатель на следующий блок
} Block;

#define BLOCK_SIZE sizeof(Block)

void* my_malloc(size_t size);

void my_free(void* ptr);