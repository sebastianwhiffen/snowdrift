#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_QUEUE_SIZE 256
#define QUEUE_MASK (MAX_QUEUE_SIZE - 1)

typedef struct {
    void (*evPtr)();
} event_t;

static event_t event_queue[MAX_QUEUE_SIZE];
static int event_head = 0;
static int event_tail = 0;

int Com_Init() {

    memset(&event_queue[0], 0, MAX_QUEUE_SIZE * sizeof(event_t));

    return 0;
}

// void Com_Init_Event_Queue() {
//     memset(&event_queue[0], 0, MAX_QUEUE_SIZE * sizeof(event_t));
//     event_head = 0;
//     event_tail = 0;
// }

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

int Com_Frame() {

    Consume_Queue();

    usleep(16000);

    return 0;
}
