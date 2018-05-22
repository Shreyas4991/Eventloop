#ifndef EVENT_H
#define EVENT_H

#include <queue.h>

typedef queue_t event_queue_t;

typedef void (*callback_t)(void*);

typedef struct event_t
{
    callback_t callback;

} event_t;

typedef struct
{
    int size;
    event_t **list; //pointer to dynamic array 
                    // of event_t pointers

} event_list_t;

event_t* create_event(callback_t*);
void destroy_event(event_t *e);
event_list_t* create_event_list(int size);
void destroy_event_list(event_list_t *el);

void add_event(event_list_t *list, int event_id, callback_t *callback);
void call_event(event_list_t *elist, int event_id, void *parameters);
void trigger_event(event_queue_t* eq,int event_id);

#endif
