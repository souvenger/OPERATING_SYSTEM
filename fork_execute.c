#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
//The exec family of functions shall
//replace the current process image with a new process image.
int main()
{

    int pid;
    int status;

    pid = fork();
    if (pid > 0) // parent process waits for child to finish
    {
        printf("Parent process\n");
        //pid = wait(&status);
        sleep(3);
    }

    else // excute ls/ps or any command in child process
    {
        //printf("Child process\n");
        execlp("ls", "", NULL);
        exit(0);
    }
}
