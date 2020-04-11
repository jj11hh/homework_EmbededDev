#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int fd = open("/tmp/test.txt", O_CREAT|O_WRONLY, 0644);
    if (fd < 0)
        return -1;

    write(fd, "abcdef", 6);
    close(fd);
    return 0;
}
