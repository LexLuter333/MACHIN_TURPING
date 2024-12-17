#include <Structures.h>


struct TableElem GetElem(char currSymbol, int idState, struct TableElem **table ){
  return table[currSymbol][idState];
  }