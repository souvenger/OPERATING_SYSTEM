
/* ----------------------------------------------------------------- */
/* 	PROGRAM fork_wait.c                                                 */
/*  This program runs two processes, a parent and a child.  */
/*	The use of wait system call guarantees the child process will print */
/* 	its message before the parent proces             */
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <sys/wait.h> /* contains prototype for wait */
#include <stdlib.h>
int main(void)
{
    int pid;
    int status;
    printf("Hello World!\n");
    pid = fork();
    if (pid == -1) /* check for error in fork */
    {
        perror("bad fork");
        exit(1);
    }
    if (pid == 0)
        printf("I am the child process.\n");
    else
    {
        wait(&status); /* parent waits for child to finish */
        printf("I am the parent process.\n");
    }
}