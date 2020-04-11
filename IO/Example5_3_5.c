#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "usage: ", 7);
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, " FILE\n", 6);

        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    
    if (fd == -1)
    {
        write(STDERR_FILENO, "open: ", 6);
        write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
        write(STDERR_FILENO, "\n", 1);

        return -1;
    }

    char buffer[1024];
    size_t count;

    while ((count = read(STDIN_FILENO, buffer, 1024)))
    {
        write(fd, buffer, count);    
    }
    
    close(fd);

    return 0;
}
