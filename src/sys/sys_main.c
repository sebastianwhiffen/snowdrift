#include "../common/common.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void hello() { printf("hello from event \n"); }

int main() {

    Com_Init();

    void (*fn)(void) = hello;

    while (1) {
        Com_Frame();
    }

    return 0;
}
