#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t now;
    struct tm *clock;
    char time_string[64]; // 1 

    time(&now);
    clock = localtime(&now); // 2

    strftime(time_string, sizeof(time_string), "Today is %A, %B %d, %Y\nIt is %H:%M:%S\n", clock);
    // %A writes full day name, e.g. Monday (locale dependent)
    // %B writes full month name, e.g. October (locale dependent)
    // %d writes day of the month, e.g. 01 to 31
    // %Y writes year, e.g. 1970
    // %H writes hour in 24-hour format, e.g. 00 to 23
    // %M writes minute, e.g. 00 to 59
    // %S writes second, e.g. 00 to 59

    printf("Greetings");
    if ( argc > 1 )
        printf(", %s", argv[1]);
    printf("!\n%s", time_string);

    return 0;   
}

// 1. Storage for the string filled by the strftime() function
// 2. You must fill a localtime() tm structure to make the strftime() function work
// doc: https://devdocs.io/c/chrono/strftime