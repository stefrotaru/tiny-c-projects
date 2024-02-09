#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t now;
    struct tm *clock;
    int hour;

    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour; // 1

    if ( hour > 0 && hour < 6) {
        printf("Are you still up? ");

        if ( argc > 1 ) {
            printf("Go to sleep, %s!", argv[1]);
        }

        return 0;
    }

    printf("Good ");
    if ( hour < 12 )        // 2
        printf("morning");
    else if ( hour < 17)    // 3
        printf("afternoon");
    else                    // 4
        printf("evening");
    
    if ( argc > 1 ) {      // 5
        printf(", %s!", argv[1]);
    }

    putchar('\n');

    return 0;
}

// 1. This statement is a convenience to avoid using clock->tm_hour over and over.
// 2. Before noon, say "Good morning".
// 3. From noon to 5 PM, say "Good afternoon".
// 4. Otherwise, it's evening.
// 5. Check for and output the first command-line argument if it exists.