#include <stdio.h>
#include <time.h>

int main() {
    time_t now;

    time(&now);

    printf("The computer thinks it's %lld\n", now);
    printf("%s", ctime(&now));

    return 0;
}

// time_t is a type for storing time values.
// time() returns the current time of the system as a time_t value. (&now => using the "address of" operator to get the address of the variable "now" so we can store the current time in it)
// ctime() converts the time_t value to a string representation of the time.