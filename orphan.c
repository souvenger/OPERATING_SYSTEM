/* ----------------------------------------------------------------- */
/* 	PROGRAM orphan_process.c                                                 */
/*  This program runs two processes, a parent and a child.  */
/*	The parent process terminates before the child making it an orphan process   */
/*	The init process becomes the parent of the orphan process */
/* ----------------------------------------------------------------- */

//*another way is by checking the ps command by make parent sleep 2 sec and child 10sec//
#include <sys/wait.h> /* contains prototype for wait */
#include <stdlib.h>
#include <unistd.h> /* contains fork prototype */
#include <stdio.h>
int main()
{
    int pid;
    printf("I'am the original process with PID %d and PPID %d.\n",
           getpid(), getppid());
    pid = fork(); /* Duplicate. Child and parent continue from here */
    if (pid != 0) /* pid is non-zero,so I must be the parent*/
    {
        // sleep(2);
        printf("I'am the parent with PID %d and PPID %d.\n",
               getpid(), getppid());
        printf("My child's PID is %d\n", pid);
    }
    else /* pid is zero, so I must be the child */
    {
        sleep(10); /* make sure that the parent terminates first */
        printf("I'm the child with PID %d and PPID %d.\n",
               getpid(), getppid());
    }
    printf("PID %d terminates.\n", getpid());
}