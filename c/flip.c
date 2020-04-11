#include <stdio.h>

int main (int argc, char *argv[]){
    char buffer[1024]; // assuming a line will not excess 1024 bytes
    int stack = 0;
    char c;
    
    for (;;) { // infinity loop
        c = getchar(); // read a char into c
        if ( c == EOF ) {
            for (; stack > 0; stack --){
                putchar(buffer[stack - 1]);
            }    

            break;
        }

        else if ( c == '\n' ) {
            for (; stack > 0; stack --){
                putchar(buffer[stack - 1]);
            }    
            putchar('\n');
        }

        else {
            if (stack < 1024)
                buffer[stack ++] = c;
        }
    }

    return 0;
}
