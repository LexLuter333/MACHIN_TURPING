#include "../Headers/memoryUtils.h"

Block* head = NULL;  // Указатель на первый блок памяти
Block* last = NULL;  // Указатель на последний выделенный блок (для оптимизации)

void* my_malloc(size_t size) {
    Block* current;
    void* block_start;

    // Минимизация памяти: игнорируем запросы на 0 байт
    if (size <= 0) {
        return NULL;
    }

    // Ищем свободный блок, удовлетворяющий запросу
    current = head;
    while (current != NULL) {
        if (current->free && current->size >= size) {  // Подходящий блок найден
            current->free = 0;  // Помечаем блок как занятый
            return (void*)(current + 1);  // Смещаем указатель за метаданные
        }
        current = current->next;
    }

    // Если блок не найден, выделяем новую память через sbrk
    block_start = sbrk(size + BLOCK_SIZE);  // Память метаданных + данные
    if (block_start == (void*)-1) {
        return NULL;  // Ошибка при выделении памяти
    }

    // Приводим память к типу Block и инициализируем
    current = block_start;
    current->size = size;
    current->free = 0;
    current->next = NULL;

    // Обновляем конец списка
    if (last != NULL) {
        last->next = current;
    }
    last = current;
    if (head == NULL) {
        head = current;
    }

    return (void*)(current + 1);  // Смещаем указатель за метаданные
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;  // Ничего не освобождать
    }

    // Получаем адрес структуры блока памяти
    Block* block = (Block*)ptr - 1;

    // Помечаем блок как свободный
    block->free = 1;

    // Оптимизация: высвобождать память обратно OS, если последний блок освобожден
    if (block->next == NULL) {  // Это последний блок
        if (head == block) {    // Если это единственный блок
            head = NULL;
            last = NULL;
        } else {
            Block* temp = head;
            while (temp->next != block) {
                temp = temp->next;
            }
            temp->next = NULL;
            last = temp;
        }
        brk(block);  // Сдвигаем брейк назад
    }
}