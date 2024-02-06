#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t now;
    struct tm *clock;
    int hour;

    time (&now);
    clock = localtime(&now);
    hour = clock->tm_hour; // tm_hour ranges from 0 to 23

    if ( hour > 0 && hour < 6) { // 1 to 5am
        printf("Are you still up? ");

        if ( argc > 1 ) {
            // if there's an argument, I hope it's a name
            printf("Go to sleep, %s!", argv[1]);
        }

        return 0;
    }

    printf("Good ");
    if ( hour < 12 )
        printf("morning");
    else if ( hour < 17)
        printf("afternoon");
    else 
        printf("evening");
    
    if ( argc > 1 ) {
        // again, if there's an argument, I hope it's a name
        printf(", %s!", argv[1]);
    }

    putchar('\n');

    return 0;
}