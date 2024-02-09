#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *clock; // 1

    time(&now);
    clock = localtime(&now);
    printf("  Day of the year: %d\n", clock->tm_yday); // tm_yday ranges from 0 to 365
    printf("  Day of the week: %d\n", clock->tm_wday); // tm_wday ranges from 0 to 6
    printf("             Year: %d\n", clock->tm_year + 1900); // You must add 1900 to tm_year to get the current year
    printf("            Month: %d\n", clock->tm_mon + 1); // tm_month ranges from 0 to 11
    printf("              Day: %d\n", clock->tm_mday); // tm_mday ranges from 1 to 31
    printf("             Hour: %d\n", clock->tm_hour); // tm_hour ranges from 0 to 23
    printf("           Minute: %d\n", clock->tm_min); // tm_min ranges from 0 to 59
    printf("           Second: %d\n", clock->tm_sec); // tm_sec ranges from 0 to 59

    return 0;
}

// 1. Because localtime() returns a pointer, it's best to declare the structure as a pointer.
// doc: https://devdocs.io/c/chrono/tm 