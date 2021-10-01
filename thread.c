#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *thread_function(void *arg)
{
    // the work to be done by the thread is defined in this function
    printf("Inside Thread\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
}
int main()
{
    pthread_t a_thread; //thread declaration contain id of thread
    pthread_create(&a_thread, NULL, thread_function, NULL);
    //thread is created
    pthread_join(a_thread, NULL); //process waits for thread to finish . //Comment this line to see the difference
    printf("Inside Main Program\n");
    for (int j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }
}
