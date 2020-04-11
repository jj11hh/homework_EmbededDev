#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    printf("errno = %d, str = %s\n", errno, strerror(errno));
        //判断文件是否存在，然后决定是否打开文件，同时看错误提示
    (void)fp; //Avoid Warning

    int err = access(argv[1], 0);
    printf("errno = %d, str = %s\n", errno, strerror(errno));

    if (err == 0) {             //打开文件操作
        //...
    } else {                    //创建文件操作
        //...
    }
}
