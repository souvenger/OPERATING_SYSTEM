
/* ----------------------------------------------------------------- */
/* PROGRAM fork_2.c                                                 */
/*    This program creates two child processes displaying some line.*/
/*    the child and the paprent process is identified from the return value of fork()*/
/*     fork()  retrurn 0 to child and pid of child to parent process  
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <unistd.h>   /* contains fork prototype */
#include <sys/wait.h> /* contains prototype for wait */
#include <stdlib.h>
int main(void)
{
    int pid;
    int status;
    printf("Hello IIITA!\n");
    printf("I am the parent process and pid is : %d .\n", getpid());
    printf("We are before fork\n");
    pid = fork();
    if (pid == 0)
        printf("I am the child process and pid is :%d.\n", getpid());
    else
    {
        wait(&status); //wait for child to finish
        printf("I am the parent process and pid is: %d .\n", getpid());
    }
    //printf("Here we are after fork and a new child has been created\n");
}