#include <stdio.h>

int main() {
    int i;

    for (i = 0; i <= 255; i++) {
        printf("%d %o %x %c\n", i, i, i, i);
    }    

    return 0;
}

// prints a looong ascii table