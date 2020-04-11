#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    int err = stat(argv[1], &st);
    if ( err == -1 ) 
        return -1;

    if (S_ISDIR(st.st_mode)) 
        printf("Directory\n");
    else if (S_ISREG(st.st_mode))
        printf("Normal File\n");

    return 0;
}
