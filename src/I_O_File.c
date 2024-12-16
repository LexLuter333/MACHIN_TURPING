#include <unistd.h>
#include <fcntl.h>
#include "../Headers/I_O_File.h"

struct LinkedList ReadTape() {
    char ch;
    ssize_t bytes_read;
    void *current_brk = sbrk(0);

    if (brk(current_brk + sizeof(struct Node)) == -1) {
        return; //Вызвать димину функцию и передать код ошибки
    }
    struct LinkedList *list = (struct LinkedList *) current_brk;


    while ((bytes_read = read(STDIN_FILENO, &ch, 1)) > 0) {
        if (ch == '\n') {
            break;
        }
        if (ch != '_') {
            AppendNode(list, ch);
        }
    }

    return *list;
}

struct ReadResult ReadFile(char* filePath) {
    struct ReadResult result;


    int flow = open(filePath,O_RDONLY);
    if (flow == -1) {
        return; //вызвать димину поебень с ошибками
    }

    ssize_t bytes_read;
    char curr_symb;

    //TODO
    // Буфер, в него записываем строчку и бегаем по ней, сделать массив для хранения состояний

    int cntStates = 0;
    while ((bytes_read = read(flow,curr_symb, 1)) > 0 && curr_symb != '\n') {
        cntStates = cntStates*10 + (curr_symb - '0');
    }
    while ((bytes_read = read(flow,curr_symb, 1)) > 0 && curr_symb != '(');

    while ((bytes_read = read(flow,curr_symb, 1)) > 0) {

    }
}


int main(int argc, char *argv[]) {
    int len_arg = 0;
    while (argv[1][len_arg] != '\0') {
        len_arg++;
    } // Возможно надо будет убрать


    char *filePath = argv[1];
    write(STDOUT_FILENO,argv[1],len_arg);


    // struct LinkedList list = ReadTape();
    // write(STDOUT_FILENO,&(argv[1]), 100);
}
