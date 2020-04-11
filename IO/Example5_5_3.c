#include <time.h>
#include <stdio.h>

int main () {
    char * weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char * months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
    };
    time_t epoch;
    struct tm datetime;

    time(&epoch);
    localtime_r(&epoch, &datetime);

    printf("%s, %02d %s, %04d, %02d:%02d:%02d\n",
        weekdays[datetime.tm_wday], datetime.tm_mday, 
        months[datetime.tm_mon], datetime.tm_year + 1900,
        datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
}
