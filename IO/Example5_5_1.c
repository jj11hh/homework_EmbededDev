#include <time.h>
#include <stdio.h>
#include <stdint.h>

int main () {
    time_t sec = time((time_t *) NULL);
    printf("%jd\n", (intmax_t) sec);

    return 0;
}
