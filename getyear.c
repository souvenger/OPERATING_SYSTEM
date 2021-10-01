
/* ----------------------------------------------------------------- */
/* PROGRAM fork_2.c                                                 */
/*    This program creates two child processes displaying some line.*/
/*    the child and the paprent process is identified from the return value of fork()*/
/*     fork()  retrurn 0 to child and pid of child to parent process  
/* ----------------------------------------------------------------- */
#include "types.h"
#include "stat.h"
#include "user.h"
//#include "stat.h"
int main(void)
{
    printf(1, "Note: Unix V6 was released in year %d\n", getyear());
    exit();
}