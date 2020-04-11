#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char filename[256];
    int fd;
    int i;
    if (argc < 2){
        printf("Filename Required:> ");
        fgets(filename, 256, stdin);
        filename[strlen(filename) - 1] = '\0'; //remove the '\n'
        if ((fd = creat(filename, 0644)) < 0){
            perror("creat");
            return -1;
        }
        else {
            close(fd);
        }
    }

    for (i = 1; i < argc; ++ i){
        if ((fd = creat(argv[i], 0644)) < 0){
            perror("creat");
            return -1;
        }
        else {
            close(fd);
        }
    }

    return 0;
}
