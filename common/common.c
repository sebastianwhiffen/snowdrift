#include <stdio.h>

#define MAX_QUEUE_SIZE 256
#define QUEUE_MASK (MAX_QUEUE_SIZE - 1)

typedef struct {
  void (*evPtr)();
} event_t;

event_t event_queue[MAX_QUEUE_SIZE];
int event_head = 0;
int event_tail = 0;

int Consume_Queue() {

  if (event_head > event_tail) {
    event_tail++;
    event_t ev = event_queue[(event_tail - 1) & QUEUE_MASK];

    ev.evPtr();
  }

  printf("tail: %d \n", event_tail);
  return 0;
}

int Push_Queue(void (*ptr)()) {
  event_t *ev;

  ev = &event_queue[event_head & QUEUE_MASK];

  event_head++;

  ev->evPtr = ptr;

  printf("head: %d \n", event_head);
  return 0;
}
