#include "Structures.h"


struct TableElem GetElem(char currSymbol, int idState, struct TableElem table[MAX_ASCII][MAX_STATES] );

struct LinkedList RunAlgo(int idInitialState, struct LinkedList *lenta, int finalState, struct TableElem table[MAX_ASCII][MAX_STATES]);
