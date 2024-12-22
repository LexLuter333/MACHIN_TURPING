#include <stdio.h>
#include <unistd.h>
#include "../Headers/I_O_File.h"
#include "../Headers/Structures.h"


int main(int argc, char *argv[]) {
    if (!argv[1]) {
        // TODO
    }
    struct ReadResult t = ReadFile(argv[1]);
    struct LinkedList tape = ReadTape();
    // struct LinkedList resAlg = RunAlgo(0, &tape);
    // for (int i = 0; i < 90; ++i) {
    //     write(STDOUT_FILENO, t.TableTransition[i][i].newSymbol, 100);
    // }
    for (int i = 0; i < 90; ++i) {
        for (int j = 0; j < 90; ++j) {
            write(STDOUT_FILENO,&(t.TableTransition[i][j].direction),1);
        }
    }
    OutputList(&tape);
}
