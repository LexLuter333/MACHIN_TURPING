#include "ErrorHandler.h"
#include <unistd.h>

void printError(int errorCode) {
    char* message = "ERROR CODE: ";
    write(1, message, 12);

    char buffer[12];
    int length = 0;

    if (errorCode < 0) {
        buffer[length++] = '-';
        errorCode = -errorCode;
    }

    int temp = errorCode;
    do {
      buffer[length++] = '0' + temp % 10;
      temp /= 10;
    } while (temp > 0);

    for (int i = 0; i < length / 2; i++) {
      char t = buffer[i];
      buffer[i] = buffer[length - i - 1];
      buffer[length - i - 1] = t;
    }
    buffer[length] = '\n';
    length++;

    write(1, buffer, length);
    syscall(60, status);

    char* okMessage = "OK";
    write(1, okMessage, 2);
}
