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

struct ReadResult ReadFile(char *filePath) {
    struct ReadResult result;


    int flow = open(filePath,O_RDONLY);
    if (flow == -1) {
        return; //вызвать димину поебень с ошибками
    }

    ssize_t bytes_read;
    char curr_symb = '';

    //TODO
    // Буфер, в него записываем строчку и бегаем по ней, сделать массив для хранения состояний

    int cntStates = 0;
    while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != '\n') {
        cntStates = cntStates * 10 + (curr_symb - '0');
    }
    result.countState = cntStates;

    char statesArray[MAX_STATES][MAX_ASCII];
    int sts = 0;
    int symbInSts = 0;
    while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != '\n') {
        if (curr_symb == ' ') {
            statesArray[sts][symbInSts] = '\0';
            ++sts;
            symbInSts = 0;
        } else {
            statesArray[sts][symbInSts] = curr_symb;
            symbInSts++;
        }
    }


    int cntTransitions = 0;
    while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != '\n') {
        cntTransitions = cntTransitions * 10 + (curr_symb - '0');
    }

    for (int i = 0; i < cntTransitions; i++) {
        char currState[MAX_LEN];
        int idCurrState = -1;
        int ascii;
        char newState[MAX_LEN];
        int idNewState = -1;
        char newAscii;
        char direction;


        int statePointer = 0;
        while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != ' ') {
            //Считываем состояние
            if (curr_symb == '(' || curr_symb == ',' || curr_symb == ')' || curr_symb == '\n') continue;
            currState[statePointer] = curr_symb;
            statePointer++;
        }
        currState[statePointer] = '\0';
        statePointer++;

        for (int j = 0; j < cntStates; j++) {
            for (int i = 0; i < statePointer; i++) {
                if (statesArray[j][i] != currState[i])break;
                if (statesArray[j][i] == currState[i] == '\0') {
                    idCurrState = j;
                    break;
                }
            }
            if (idCurrState != -1) {
                break;
            }
        }


        while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != ')') {
            //Считываем символ
            ascii = curr_symb;
        }

        while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != '(') {
        };


        statePointer = 0;
        while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != ' ') {
            //Считываем состояние
            if (curr_symb == '(' || curr_symb == ',') continue;
            newState[statePointer] = curr_symb;
            statePointer++;
        }
        newState[statePointer] = '\0';
        statePointer++;

        for (int j = 0; j < cntStates; j++) {
            for (int i = 0; i < statePointer; i++) {
                if (statesArray[j][i] != newState[i])break;
                if (statesArray[j][i] == newState[i] == '\0') {
                    idNewState = j;
                    break;
                }
            }
            if (idNewState != -1) {
                break;
            }
        }

        while ((bytes_read = read(flow, curr_symb, 1)) > 0 && curr_symb != ' ') {
            //Считываем символ
            if (curr_symb == ',') { continue; }
            newAscii = curr_symb;
        }

        bytes_read = read(flow, curr_symb, 1);
        direction = curr_symb;


        result.TableTransition[ascii][idCurrState].direction = direction;
        result.TableTransition[ascii][idCurrState].newSymbol = newAscii;
        result.TableTransition[ascii][idCurrState].idState = idNewState;
    }

    return result;
}

void OutputList(struct LinkedList *tape) {
    struct Node *currNode = tape->head;
    while (currNode != NULL) {
        write(STDOUT_FILENO,&(currNode->current),1);
        currNode = currNode->next;
    }
}



int main(int argc, char *argv[]) {
    int len_arg = 0;
    while (argv[1][len_arg] != '\0') {
        len_arg++;
    } // Возможно надо будет убрать


    char *filePath = argv[1];
    write(STDOUT_FILENO, argv[1], len_arg);


    // struct LinkedList list = ReadTape();
    // write(STDOUT_FILENO,&(argv[1]), 100);
}
