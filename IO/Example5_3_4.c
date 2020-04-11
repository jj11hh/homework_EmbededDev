#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd;
    int err = access(argv[1], 0);
    printf("err=%d,errstr=%s\n", errno, strerror(errno));
    if (err == 0) {
        fd = open(argv[1], O_RDWR | O_SYNC, 0666);
    } else {
        fd = creat(argv[1], 0666);
    }
    if (fd == -1) {
        fprintf(stderr, "open or creat err \n");
        perror(argv[0]);
        return 0;
    }
}
