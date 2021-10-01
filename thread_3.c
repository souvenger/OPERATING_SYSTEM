#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *thread_function(void *arg);
int num[2] = {3, 5};
int sum;
void *result;

int main()
{
    pthread_t a_thread;                                            //thread declaration
    pthread_create(&a_thread, NULL, thread_function, (void *)num); //thread is created
    pthread_join(a_thread, &result);                               //process waits for thread to finish . Comment this line to see the difference
    printf("Inside Main process\n");
    printf("Sum is %d\n", *((int *)result));
}
void *thread_function(void *arg)
{ // the work to be done by the thread is defined in this function
    printf("Inside Thread\n");
    int *x = arg;
    int *sum = (int *)malloc(sizeof(int));
    *sum = x[0] + x[1];
    pthread_exit((void *)sum);
}