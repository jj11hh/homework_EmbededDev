#include <time.h>
#include <stdio.h>
#include <stdint.h>

int main () {
    time_t epoch;
    struct tm datetime;

    time(&epoch);
    localtime_r(&epoch, &datetime);

    printf("time() = %jd\n", (intmax_t) epoch);
    printf("mktime(localtime(time())) = %jd\n",
        (intmax_t) mktime(&datetime)
    );

}
