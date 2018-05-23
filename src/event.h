#ifndef EVENT_H
#define EVENT_H

#include <queue.h>
#include <pthread.h>
#include <semaphore.h> 
//globals
extern queue_t *events_queue;
extern pthread_mutex_t queue_mutex;
extern sem_t queue_semaphore;
extern int quit_event_loop_flag = 0;
//globals

typedef void (*callback_t)(void*);

typedef struct event_t
{
    callback_t callback;

} event_t;

typedef struct
{
    int event_id;
    void *parameters;
} event_instance_t;

typedef struct
{
    int size;
    event_t **list; //pointer to dynamic array 
                    // of event_t pointers

} event_list_t;

event_t* create_event(callback_t*);
void destroy_event(event_t *e);

event_instance_t* create_event_instance(int event_id, void *parameters);
void destroy_event_instance(event_instance_t *ei);

event_list_t* create_event_list(int size);
void destroy_event_list(event_list_t *el);

void add_event(event_list_t *list, int event_id, callback_t *callback);
void call_event(event_list_t *elist, int event_id, void *parameters);
void trigger_event(int event_id, void *parameters);
void* event_loop(event_list_t *el);
#endif
