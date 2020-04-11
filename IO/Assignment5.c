#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int fd = open("/tmp/test.txt", O_RDONLY);
    if (fd < 0)
        return -1;

    char buf[1024];
    char len = 0;
    while ((len = read(fd, buf, 1024))){
        write(STDOUT_FILENO, buf, len);    
    }
    return 0;
}
