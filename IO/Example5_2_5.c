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

    if (st.st_mode & S_IFDIR) 
        printf("Directory\n");
    else if (st.st_mode & S_IFREG)
        printf("Normal File\n");

    return 0;
}
