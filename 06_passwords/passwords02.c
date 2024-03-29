#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term {
	char filename[16];
	FILE *fp;
	int items;
	char **list_base;
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

char *add_word(struct term t) {
    int word;

	word = rand() % t.items;
	return( *(t.list_base+word) );
}

char *number(void) {
    static char n[2];

	n[0] = rand() % 10 + '0';
	n[1] = '\0';

	return(n);
}

char *symbol(void) {
    char sym[8] = "!@#$%*_-";
	static char s[2];

	s[0] = sym[rand() % 8];
	s[1] = '\0';

	return( s );
}

int main() {
    char password[32]; // 1

	struct term noun = {"noun.txt", NULL, 0, NULL}; // 2
    struct term verb = {"verb.txt", NULL, 0, NULL};
    struct term adjective = {"adjective.txt", NULL, 0, NULL};

    build_vocabulary(&noun);
    build_vocabulary(&verb);
    build_vocabulary(&adjective);

    srand( time(NULL) );

    password[0] = '\0'; // 3

    strcpy(password, add_word(noun));
    strcat(password, number());
    strcat(password, add_word(verb));
    strcat(password, symbol());
    strcat(password, add_word(adjective));

    printf("%s\n", password);

    return 0;
}

// 1. stolen from the first passwords code
// 2. stolen from madlib02.c
// 3. always cap a string you build!