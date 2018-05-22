#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node_t
{   
    void *data;
    struct queue_node_t *next;
} queue_node_t;

typedef struct
{
    queue_node_t *front, *rear;
} queue_t;


queue_node_t* create_queue_node(void*);
void destroy_queue_node(queue_node_t*);

queue_t* create_queue();
void destroy_queue(queue_t*);

void add_to_queue(queue_t*, void*);
void* get_next(queue_t*);
void pop_queue(queue_t*);
#endif