#include <time.h>
#include <stdio.h>

int main() {
    time_t epoch;
    time(&epoch);

    printf("%s", asctime(gmtime(&epoch)));
}
