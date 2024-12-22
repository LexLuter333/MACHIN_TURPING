#ifndef MEMORYUTILS_H
#define MEMORYUTILS_H
#include <unistd.h>

typedef struct Block {
    unsigned int size;
    int free;
    struct Block *next;
} Block;

#define BLOCK_SIZE sizeof(Block)
void* base = NULL;


void *appendMem(int size){};


#endif
