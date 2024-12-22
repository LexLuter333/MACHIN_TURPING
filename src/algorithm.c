#include "../Headers/Alg_Tyring.h"
#include "../Headers/ErrorHandler.h"

struct LinkedList RunAlgo(int idInitialState, struct LinkedList* lenta, int finalState, struct TableElem **table){

    struct Node* currentCell = lenta->head;
    int step = 0;
    int currentState = idInitialState;
    

    
    while(currentState != finalState){
        step++;

        if (step >= 100000){
            printError(-1); // TODO
        }

        struct TableElem elem = GetElem(currentCell->current, currentState, table);
        
        currentCell->current = elem.newSymbol;

        if (elem.direction == '>' ) {
            if (currentCell->next == NULL) {
              printError(-1); // TODO
            }
            currentCell = currentCell->next;
        }


        if (elem.direction == '<') {
            if (currentCell->prev == NULL) {
                printError(-1); // TODO
              }
            currentCell = currentCell->prev;
        }
        currentState = elem.idState;
    
    }

    return *lenta;

}

