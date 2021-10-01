#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{

  char *buff[50], fn[10];
  int fd, n, i;

  printf("Enter the filename\n");
  scanf("%s", fn);

  printf("\nEnter text");
  scanf("%s", buff);
  fgets(buff, 100, stdin);
  fd = open(fn, O_CREAT | O_WRONLY);

  n = write(fd, buff, strlen(buff));

  close(fd);
}
//
//"code-runner.executorMap": {
//  "cpp": "cd $dir && g++ --std=c++11  $fileName && ./a",
//},
//g++ --std=c++11