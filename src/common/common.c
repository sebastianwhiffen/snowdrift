// #include <lua.h>
// #include <lualib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <SDL3/SDL.h>

#define MAX_QUEUE_SIZE 256
#define QUEUE_MASK (MAX_QUEUE_SIZE - 1)

typedef struct {
    void (*evPtr)();
} event_t;

static event_t event_queue[MAX_QUEUE_SIZE];
static int event_head = 0;
static int event_tail = 0;
// char buff[256];
// int lua_error;
// lua_State *L;

int Com_Init() {

    setvbuf(stdout, NULL, _IONBF, 0);
#ifdef DEDICATED
    printf("dedicated");
#else
    printf("server");
#endif

    memset(&event_queue[0], 0, MAX_QUEUE_SIZE * sizeof(event_t));

    // FILE *fptr;
    //
    // fptr = fopen("filename.txt", "r");
    //
    // L = lua_open();    /* opens Lua */
    // luaopen_base(L);   /* opens the basic library */
    // luaopen_table(L);  /* opens the table library */
    // luaopen_io(L);     /* opens the I/O library */
    // luaopen_string(L); /* opens the string lib. */
    // luaopen_math(L);   /* opens the math lib. */
    //
    // while (fgets(buff, sizeof(buff), fptr) != NULL) {
    //     lua_error = luaL_loadbuffer(L, buff, strlen(buff), "line") ||
    //             lua_pcall(L, 0, 0, 0);
    //     if (error) {
    //         fprintf(stderr, "%s", lua_tostring(L, -1));
    //         lua_pop(L, 1); /* pop error message from the stack */
    //     }
    // }
    //
    // lua_close(L);

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

    // printf("tail: %d \n", event_tail);
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

    // SDL_Event e;

    Consume_Queue();

    // while (SDL_PollEvent(&e)) {
    // }

    usleep(16000);

    return 0;
}
