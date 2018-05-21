#ifndef EVENT_H
#define EVENT_H
typedef void* callback_t(void*)
typedef struct event_t
{
    char name[100];
    callback_t callback;
} event_t;
#endif
