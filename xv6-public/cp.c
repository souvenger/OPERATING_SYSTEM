#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char *argv[3])
{

    char str[512];

    int sz;

    int fd = open(argv[1], O_RDONLY);
    int fd1 = open(argv[2], O_CREATE | O_RDWR);

    while ((sz = read(fd, str, 512)) > 0) // if sz==0 loop ends file pointer reach to end
    {
        write(fd1, str, sz);
    }

    close(fd);
    close(fd1);
    exit();
}