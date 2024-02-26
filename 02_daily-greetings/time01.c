#include <stdio.h>
#include <time.h> // 1

int main() {
    time_t now; // 2

    time(&now); // 3

    printf("The computer thinks it's %lld\n", now);
    printf("%s", ctime(&now)); // 4

    return 0;
}

// 1. The time.h header file is required
// 2. time_t is a type for storing time values.
// 3. time() returns the current time of the system as a time_t value. (&now => using the "address of" operator to get the address of the variable "now" so we can store the current time in it)
// 4. ctime() converts the time_t value to a string representation of the time.