// passing parameters to pthread create function
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
void *thread_function(void *arg)
{
    int sum = 0;
    int n = atoi(arg);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    pthread_exit("Done"); // Thread returns "Done"
}
int i, n, j;
int main()
{
    char *m = "5";
    pthread_t a_thread; //thread declaration
    void *result;
    pthread_create(&a_thread, NULL, thread_function, m); //thread is created
    pthread_join(a_thread, &result);
    printf("Thread joined\n");
    for (j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }
    printf("thread returned %s\n", (char *)result);
}