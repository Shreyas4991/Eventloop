#include <queue.h>
#include <pointerutilities.h>
#include <stdlib.h>

queue_node_t *create_queue_node(void *data)
{
    queue_node_t *new_node;
    new_node = malloc(sizeof(queue_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void destroy_queue_node(queue_node_t *node)
{
    safe_free(&(node -> data)); 
    safe_free(&node);
}

queue_t* create_queue()
{
    queue_t *q;
    q = malloc(sizeof(queue_t));
    q -> rear = q -> front = NULL;
    return q;
}

void destroy_queue(queue_t *q)
{
    queue_node_t *to_be_deleted, *traverse = q -> front;
    while(traverse != NULL)
    {
        to_be_deleted = traverse;
        traverse = traverse -> next;
        destroy_queue_node(to_be_deleted);
    }
    safe_free(&q);
}

int is_queue_empty(queue_t *q)
{
    if( q -> front == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
void add_to_queue(queue_t *q, void *data)
{
    queue_node_t *node = create_queue_node(data);
    if( q -> rear != NULL)
    {
        q -> rear -> next = node;
    }
    else
    {
        q -> front = node; //if the queue is empty then set front as well
    }
    q -> rear = node;
}
void* get_next(queue_t *q)
{
    void *data = NULL;
    if (q -> front != NULL)
    {
        data = q -> front -> data;
    }
    return data;
}

void pop_queue(queue_t *q)
{
    queue_node_t *next_node;
    if(q -> front != NULL)
    {
        next_node = q -> front;
        q -> front = q -> front -> next;
        destroy_queue_node(next_node);
        if (q -> front == NULL)
        {
            q -> rear = NULL; //signals empty queue, important for is_queue_empty to work
        }
    }
}