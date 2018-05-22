#include <event.h>
#include <queue.h>
#include <stdlib.h>
#include <pointerutilities.h>

event_t* create_event(callback_t* callback)
{
       event_t *new_event = malloc(sizeof(event_t));
       return new_event;
}

void destroy_event(event_t *e)
{
    safe_free(&e);
}

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