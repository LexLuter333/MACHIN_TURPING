#include <stdio.h>
#include <unistd.h>
#include "../Headers/I_O_File.h"
#include "../Headers/Structures.h"
#include "../Headers/memoryUtils.h"
#include "../Headers/Alg_Tyring.h"

int main(int argc, char *argv[]) {
    printf("done\n");

    if (!argv[1]) {
        // TODO
        printf("nothing\n");
    }
    struct ReadResult *t_read_result = my_malloc(sizeof(struct ReadResult));
    *t_read_result = ReadFile(argv[1]);
    struct LinkedList tape = ReadTape();

    struct LinkedList resAlg = RunAlgo(
        t_read_result->TableTransition[0][0].idState,
        &tape,
        t_read_result->TableTransition[t_read_result->countState-1][t_read_result->countState-1].idState,
        t_read_result->TableTransition);

    OutputList(&resAlg);

    my_free(t_read_result);
}
