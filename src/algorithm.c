#include "Alg_Tyring.h"
#include "Structures.h"
#include "memoryUtils.h"
#include "ErrorHandler.h"
#include <unistd.h>

void RunAlgo(int idInitialState, struct LinkedList* lenta, int finalState, struct TableElem **table){

    struct Node* currentCell = lenta->head;
    int step = 0;
    int currentState = idInitialState;
    

    
    while(currentState != finalState){
        step++;

        if (step >= 100000){
            printError(); // TODO
        }

        struct TableElem elem = GetElem(currentCell->current, currentState, table);
        
        currentCell->current = elem.newSymbol;

        if (elem.direction == '>' ) {
            if (currCell->next == NULL) {
              printError(); // TODO
            }
            currentCell = currentCell->next;
        }


        if (elem.direction == '<') {
            if (currCell->prev == NULL) {
                printError(); // TODO
              }
            currentCell = currentCell->prev;
        }
        int currentState = elem.idState;
    
    }

}

