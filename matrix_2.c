#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define n 1000
#define nthreads 4
int a[n][n], b[n][n], c[n][n];
void *worker(void *arg)
{
    int *p = (int *)arg;
    for (int i = *p; i < *p + n / nthreads; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
int main()
{
    pthread_t tid[nthreads];
    int rows[nthreads];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }
    //thread creation
    for (int i = 0; i < nthreads; i++)
    {
        rows[i] = i * (n / nthreads);
        pthread_create(&tid[i], NULL, worker, &rows[i]);
    }
    for (int i = 0; i < nthreads; i++)
    {
        pthread_join(tid[i], NULL);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

/*2 threads
real    0m10.056s
user    0m5.953s
sys     0m0.281s

1000 threads
real    0m8.622s
user    0m11.766s
sys     0m0.359s

4 threads
real    0m9.068s
user    0m7.469s
sys     0m0.234s

sequential
real    0m12.438s
user    0m5.563s
sys     0m0.188s*/