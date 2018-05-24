#include <queue.h>
#include <pointerutilities.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int quit_flag = 0;
    queue_t* intq = create_queue();
    char operation[6];
    int *temp = malloc(sizeof(int));
    FILE *fp = fopen("testqueue.txt","r");
    if(fp == NULL)
    {
        printf("Cannot find the file\n");
        return 0;
    }
    do
    {
        fscanf(fp,"%s %d\n",operation,temp);
        printf("\nPerforming %s %d",operation,*temp);
        if(strcmp("push",operation) == 0)
        {
            add_to_queue(intq,temp);
        }
        else if(strcmp("pop",operation) == 0)
        {
            temp = get_next(intq);
            pop_queue(intq);
            printf("\tValue popped: %d",*temp);
        }
        else
        {
            printf("\tQuitting");
            quit_flag = 1;
        }
    }while(!quit_flag && !feof(fp));
    safe_free(&temp);
    fclose(fp);
    fp = NULL;
    destroy_queue(intq);
    return 0;   
}