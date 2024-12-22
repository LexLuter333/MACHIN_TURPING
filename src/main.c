#include <unistd.h>
#include "../Headers/I_O_File.h"


int main(int argc, char* argv[]){
    if (!argv[1]){
        // TODO
    }
    struct ReadResult t = ReadFile(argv[1]);
    write(STDIN_FILENO, &t, 100);
}