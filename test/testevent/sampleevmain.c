#include <eventio.h>

#define EVENT_ONE 0
#define EVENT_TWO 1
#define EVENT_THREE 2

void callback_one(void *param)
{
    printf("\nCallback one\n");
}
void callback_two(void *param)
{
    printf("\nCallback two\n");
}
void callback_three(void *param)
{
    printf("\nCallback three\n");
}
event_list_t* register_events()
{
    int n_events = 3;
    event_list_t *el = create_event_list(3);
    add_event(el,EVENT_ONE,callback_one);
    add_event(el,EVENT_TWO,callback_two);
    add_event(el,EVENT_THREE, callback_three);
    return el;
}

int evmain(int argc, char **argv)
{
    printf("\nWelcome to events world");
    trigger_event(EVENT_ONE,NULL);
    printf("\nWe take eventing seriously here");
    trigger_event(EVENT_TWO, NULL);
    printf("\nWe're serious\n");
    trigger_event(EVENT_THREE,NULL);
    return 0;
}
