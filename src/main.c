#include <event.h>
#include <pthread.h>
#include <semaphore.h>
#include <eventio.h>
#include <queue.h>


int main(int argc, char **argv)
{
    pthread_t event_loop_thread;
    sem_init(&queue_semaphore,0,0);
    pthread_mutex_init(&queue_mutex, NULL);
    event_list_t *el = register_events();
    events_queue = create_queue();
    //flag to determine the end of event_loop
    quit_event_loop_flag = 0; 
    //Add eventloop thread here.
    pthread_create(&event_loop_thread, NULL, event_loop, el);
    evmain(argc, argv);
    //Add evmain() here.
    //set quit_event_loop_flag to 1
    quit_event_loop_flag = 1;
    //call join on event loop thread
    pthread_join(&event_loop_thread, NULL);
    destroy_queue(events_queue);
    destroy_event_list(el);
    return 0;
}