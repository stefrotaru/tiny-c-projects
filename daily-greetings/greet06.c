#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int moon_phase(int year, int month, int day) {
    int d,g,e;

    d = day;
    if (month == 2)
        d += 31;
    else if (month > 2)
        d += 59 + (month -3 ) * 30.6 + 0.5;
    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;
    if (e == 25 || e == 24)
        ++e;
    return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

int main(int argc, char *argv[]) {
    time_t now;
    struct tm *clock;
    char time_string[64];
	char *phase[8] = {
		"waxing crescent", "at first quarter",
		"waxing gibbous", "full", "waning gibbous",
		"at last quarter", "waning crescent", "new"
	};
    int mp, items, saying;
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    char **list_base;

    time(&now);
    clock = localtime(&now);

    strftime(time_string, sizeof(time_string), "Today is %A, %B %d, %Y\nIt is %H:%M:%S\n", clock);

    printf("Greetings");
    if ( argc > 1 )
        printf(", %s", argv[1]);
    printf("!\n%s", time_string);

    mp = moon_phase(clock->tm_year+1900,clock->tm_mon,clock->tm_mday);
	printf("The moon is %s\n",phase[mp]);

    fp = fopen(filename, "r");
    if ( fp == NULL) {
        fprintf(stderr, "unable to open file %s\n", filename);
        exit(1);
    }

    list_base = (char **)malloc(sizeof(char *) * 100);
    if ( list_base == NULL ) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    items = 0;
    while ( !feof(fp) ) {
        r = fgets(buffer, BSIZE, fp);
        if ( r == NULL )
            break;

        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if ( entry == NULL ) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer);
        *(list_base + items) = entry;
        items++;
    }

    if ( items % 100 == 0 ) {
        list_base = (char **)realloc(list_base, sizeof(char *) * (items + 100));

        if ( list_base == NULL ) {
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
        }
    }

    fclose(fp);

    srand( (unsigned)time(NULL) );
    saying = rand() % (items - 1);
    printf("%s", *(list_base + saying));

    return 0;   
}

// greet05.c with the moon pithy saying added