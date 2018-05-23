#include <event.h>
#include <queue.h>
#include <stdlib.h>
#include <pointerutilities.h>
#include <pthread.h>
#include <semaphore.h>


//create and destroy individual events
event_t* create_event(callback_t* callback)
{
       event_t *new_event = malloc(sizeof(event_t));
       return new_event;
}

void destroy_event(event_t *e)
{
    safe_free(&e);
}

//create and destroy individual event instances (id with params)
event_instance_t* create_event_instance(int event_id, void *params)
{
    event_instance_t *ei = malloc(sizeof(event_instance_t));
    ei -> event_id = event_id;
    ei -> parameters = params;
    return ei;
}

void destroy_event_instance(event_instance_t *ei)
{
    safe_free(&(ei->parameters));
    safe_free(&ei);
}
//create and destroy event list
void destroy_event_list(event_list_t *el)
{
    int i;
    for(i = 0; i < el -> size; i++)
    {
        destroy_event(el->list[i]);
    }
    safe_free(&(el -> list));
    safe_free(&el);
}
event_list_t* create_event_list(int size)
{
    event_list_t *l = malloc(sizeof(event_list_t));
    l -> list = malloc(size);
    l -> size = size;
    return l;
}

void add_event(event_list_t *el, int event_id, callback_t *callback)
{
    if(el == NULL || el -> list == NULL)
    {
        return;
    }
    el ->list[event_id] = create_event(callback);
}

void call_event(event_list_t *el, int event_id, void *parameters)
{
    if(el == NULL || event_id >= el -> size)
    {
        return;
    }
    el-> list[event_id]-> callback(parameters);
}

void trigger_event(int event_id, void *parameters)
{
    event_instance_t *ei = create_event_instance(event_id,parameters);
    pthread_lock_mutex(&queue_mutex);
    add_to_queue(events_queue,ei);
    sem_post(&queue_semaphore);
    pthread_unlock_mutex(&queue_mutex);
}

void* event_loop(event_list_t *el)
{
    event_instance_t *next_ei;
    while(!quit_event_loop_flag)
    {
        sem_wait(&queue_semaphore);
        pthread_lock_mutex(&queue_mutex);
        next_ei = get_next(events_queue);
        pop_queue(events_queue);
        pthread_unlock_mutex(&queue_mutex);
        call_event(el, next_ei -> event_id, next_ei -> parameters);
        destroy_event_instance(next_ei);
    }
}