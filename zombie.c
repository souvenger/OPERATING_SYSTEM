/* ----------------------------------------------------------------- */
/* 	PROGRAM zombie_process.c                                                 */
/*  This program runs two processes, a parent and a child.  */
/*	The child process terminates before the paprent and the parent is unaware of the status of the child   */
/*	The child process becomes a zombie */
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <sys/wait.h> /* contains prototype for wait */
#include <stdlib.h>
#include <unistd.h> /* contains fork prototype */
#include <stdio.h>
// int main()
// {
//     int pid;
//     pid = fork(); /* Duplicate. Child and parent continue from here */
//     if (pid != 0) /* pid is non-zero, so I must be the parent */
//     {
//         while (1)       /* Never terminate and never execute a wait ( ) */
//             sleep(100); /* stop executing for 100 seconds */
//     }
//     else /* pid is zero, so I must be the child */
//     {
//         printf(("I an the child process\n"));
//         exit(42); /* exit with any number */
//     }
// }
/* if wait is used in place of sleep then it 
sends a signal to the parent process that child is terminated 
and it will remove its entry from system */
int main()
{
    int pid;
    pid = fork();
    if (pid != 0)
    {
        //wait(NULL);
        sleep(3);
        printf("I am the parent process with PID %d", getpid());
    }
    else
    {
        printf("I am the child process with PID %d", getpid());
    }
}