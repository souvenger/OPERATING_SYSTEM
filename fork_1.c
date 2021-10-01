
/* ----------------------------------------------------------------- */
/* PROGRAM fork_1.c                                                 */
/*    This program creates two child processes displaying some line.*/
/*    However, the child and the paprent process cannot be identified */
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <unistd.h> /* contains fork prototype */

int main(void)
{
    printf("Hello IIITA!\n");
    printf("We are before fork\n");
    fork();
    printf("Here we are after fork and a new child has been created\n");
    printf("Well!! Let me guess who am I? Child or Parent \n");
    printf("\t I am process %d.\n", getpid());
}