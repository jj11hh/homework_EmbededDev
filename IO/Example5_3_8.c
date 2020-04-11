#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

static int comp(const void * a, const void * b){
    return *(const char *)a - *(const char *)b;    
}

int main (int argc, char *argv[]) {
    if (argc != 2){
        fprintf(stderr, "usage: %s: FILE\n", argv[0]);
        fprintf(stderr, "Sort the whole file\n");
        return 1;
    }    

    int fd = open(argv[1], O_RDWR);
    if (fd < 0){
        perror("open");
        return -1;
    }

    struct stat st;
    if (fstat(fd, &st)){
        perror("fstat");
        close(fd);
        return -1;
    }
    
    size_t size = st.st_size;
    char *buf = (char *)malloc(size);
    size = read(fd, buf, size);

    qsort(buf, size, sizeof(char), &comp);
    lseek(fd, 0, SEEK_SET);
    write(fd, buf, size);

    close(fd);

    return 0;
}
