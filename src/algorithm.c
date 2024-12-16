#include "Alg_Tyring.h"
#include "Structures.h"
#include "memoryUtils.h"


void RunAlgo(int idInitialState, LinkedList lenta, int finalState, TableElem table){

    Node currentCell = lenta->head;
    int step = 0;
    int currentState = idInitialState;
    

    
    while(currentState != finalState){
        step++;

        if (step <= 100000){
            return 0;
        }

        TableElem elem = GetElem(startLenta->current, currentState, table);
        
        currentCell.current = elem.newSymbol;

        if (elem.direction == 1) {
            currenCell = currenCell.next;
        }

        if (elem.direction == -1) {
            currenCell = currenCell.prev;
        }

        int currentState = elem.idState;
    
    }

}

