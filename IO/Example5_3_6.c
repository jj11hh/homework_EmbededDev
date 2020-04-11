#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main (int argc, char *argv[])
{

    DIR * stack[128];   // Max Stack Depth = 128
    DIR ** sp = stack;  // Stack Pointer

    struct dirent *item;

    size_t base_len = 0;
    size_t path_len = 0;
    char path[2048] = {0};

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s DIRECTORY\n", argv[0]);
        return 1;
    }    

    strncpy(path, argv[1], 2048);
    path_len = strlen(path);
    base_len = path_len;

    *sp = opendir(path);
    if (*sp == NULL) {
        perror("opendir");
        return -1;
    }
    
    for(;;)
    {
        while ((item = readdir(*sp)))
        {
            size_t name_len = strlen(item->d_name);
            if (item->d_type == DT_DIR)
            {
                if (!strcmp(item->d_name, ".") || !strcmp(item->d_name, ".."))
                    continue;

                if (sp < stack + 128)
                {
                    sp ++;
                    if (path_len + name_len + 1 >= 2048)
                    {
                        fprintf(stderr, "error: path is too long\n");
                        return -1;
                    }

                    path[path_len ++] = '/';
                    strncpy(&path[path_len], item->d_name, 2048 - path_len);
                    path_len += name_len;

                    *sp = opendir(path);
                    if (*sp == NULL)
                    {
                        perror("opendir");
                        return -1;
                    }
                }
                else
                {
                    fprintf(stderr, "error: max depth exceed\n");
                    return -1;
                }
            }
            else
            {

                path[path_len ++] = '/';
                strncpy(&path[path_len], item->d_name, 2048 - path_len);
                path_len += name_len;

                printf("unlink: %s\n", path);
                if (unlink(path) == -1){
                    perror("unlink");
                    return -1;
                }

                while(path[path_len] != '/') path_len --;
                path[path_len] = '\0';
            }
        }

        if (path_len == base_len)
        {
            closedir(*sp);
            rmdir(argv[1]);
            break;
        }
        else
        {
            closedir(*sp);
            sp --;
            printf("rmdir: %s\n", path);
            rmdir(path);
            while(path[path_len] != '/') path_len --;
            path[path_len] = '\0';
        }
    }

    return 0;
}
