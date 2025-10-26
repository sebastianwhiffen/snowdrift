#include "../common/common.c"
#include <stdio.h>
#include <unistd.h>

void hello() { printf("hello from event \n"); }

int main() {

  void (*fn)(void) = hello;

  for (int i = 0; i < 5; i++) {
    Push_Queue(fn);
  }

  for (int i = 0; i < 5; i++) {
    Consume_Queue();
  }

  // usleep(16000);
  return 0;
}
