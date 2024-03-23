#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term {
    char filename[16]; // 1
    FILE *fp; // 2
    int items; // 3
    char **list_base; // 4
};

void build_vocabulary(struct term *t) {
    char buffer[BSIZE];
	char *r,*entry;

	t->fp = fopen(t->filename,"r");
	if( t->fp==NULL )
	{
		fprintf(stderr,"Unable to open file %s\n",t->filename);
		exit(1);
	}

	t->list_base = malloc(sizeof(char *) * 100);
	if( t->list_base==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	t->items = 0;
	while( !feof(t->fp) )
	{
		r = fgets(buffer,BSIZE,t->fp);
		if( r==NULL )
			break;
		entry = malloc(sizeof(char) * strlen(buffer)+1);
		if( entry==NULL )
		{
			fprintf(stderr,"Unable to allocate memory\n");
			exit(1);
		}

		strcpy(entry,buffer);
		r = entry;
		while(*r)
		{
			if( *r=='\n' )
			{
				*r = '\0';
				break;
			}
			r++;
		}

		*(t->list_base+t->items) = entry;
		t->items++;
		if( t->items%100==0 )
		{
			t->list_base = realloc(t->list_base,sizeof(char *)*(t->items+100));
			if( t->list_base==NULL )
			{
				fprintf(stderr,"Unable to reallocate memory\n");
				exit(1);
			}
		}
	}
	fclose(t->fp);
}

char *add_word(struct term t) { // 5
    int word;

    word = rand() % t.items; // 6
    return( *(t.list_base + word) ); // 7
}

int main() {
    struct term noun = {"noun.txt", NULL, 0, NULL}; // 8
    struct term verb = {"verb.txt", NULL, 0, NULL};
    struct term adjective = {"adjective.txt", NULL, 0, NULL};

    build_vocabulary(&noun); // 9
    build_vocabulary(&verb);
    build_vocabulary(&adjective);

    srand( time(NULL) );

    printf("Will you please take the %s %s ",
           add_word(adjective), // 10
           add_word(noun)
          );
    printf("and %s the %s? \n",
           add_word(verb),
           add_word(noun)
          );

    return 0;
}

// 1. A string representing the filename to open
// 2. A FILE pointer referencing the open file listed in the filename member
// 3. The total number of words extracted from the file
// 4. A block of memory containing pointers referencing each word in the file

// The build_vocabulary() function performs these tasks:
//   - Open the t -> filename member, saving the FILE pointer in variable t -> fp
// upon success
//   - Allocate storage for the t -> list_base member, which eventually references
// all strings read from the file
//   - A while loop read each string (word) from the file, allocating memory for
// the string and storing the address in the t -> list_base member

// 5. The function returns a char pointer, a string
// 6. Generates a random value ranging from zero to the number of items
// 7. References a random word stored at t.list_base, and returns its address

// 8. Structuers are declared and defined, savind lotsa code;
// 9. The build_vocabulary() function reads words from a file and creates a list
// in memory with each word indexed. This information is saved in the term 
// structure specific to each word type.
// 10. The add_word() function reads well in English, making the code understandable