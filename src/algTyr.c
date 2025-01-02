#include "../Headers/Alg_Tyring.h"


struct TableElem GetElem(char currSymbol, int idState, struct TableElem table[MAX_ASCII][MAX_STATES]){
  return table[currSymbol][idState];
  }