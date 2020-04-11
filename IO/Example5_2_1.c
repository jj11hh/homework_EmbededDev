#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (mkdir(argv[1], 0666))
    {
        fprintf(stderr, "-----A ERROR OCCURED-----\n");
        fprintf(stderr, "ERRNO = %d, %s\n", errno, strerror(errno));

        perror(argv[0]);

        return -1;
    }

    return 0;
}
