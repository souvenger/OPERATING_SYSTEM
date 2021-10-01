#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 1000
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], d[MAX][MAX];
void *parallel(void *arg)
{
    int row = (int *)arg;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            d[row][i] += a[row][j] * b[j][i];
        }
    }
    pthread_exit(NULL);
}
void sequential()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }
    // pthread_t tid[MAX];
    // for (int i = 0; i < MAX; i++)
    // {
    //     int rc = pthread_create(&tid[i], NULL, parallel, (void *)i);
    //     if (rc)
    //     {
    //         printf("ERROR; return code from pthread_create() is %d\n", rc);
    //         exit(-1);
    //     }
    // }
    // for (int i = 0; i < MAX; i++)
    // {
    //     pthread_join(tid[i], NULL);
    // }
    // printf("\n");
    // for (int i = 0; i < MAX; i++)
    // {
    //     for (int j = 0; j < MAX; j++)
    //     {
    //         printf("%d ", d[i][j]);
    //     }
    //     printf("\n");
    // }
    sequential();
}