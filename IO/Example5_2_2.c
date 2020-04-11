#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    char cwd[2048];

    getcwd(cwd, 2048);

    if ( errno ){
        perror(argv[0]);
        return -1;
    }

    write(STDOUT_FILENO, cwd, strnlen(cwd, 2048));
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}
