#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    char dir[1024] = {0};

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s FILENAME\n", argv[0]);
        return 255;
    }

    if (readlink("/proc/self/exe", dir, 1024) < 0)
    {
        perror(argv[0]);
        return -1;
    }

    size_t i;
    for (i = strnlen(dir, 1024); i >= 0 && dir[i] != '/'; --i);

    dir[i] = '\0';

    char filename[1024];
    snprintf(filename, 1024, "%s/%s", dir, argv[1]);

    int fd = open(filename, O_RDONLY);
    int count = 0;
    while (count = read(fd, filename, 1024))
    {
        // Don't be surprised, we just use 'filename' as a buffer
        write(STDOUT_FILENO, filename, count);
    }

    close(fd);

    return 0;

}
