#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { FALSE, TRUE };

struct string {
	char *value;
	int length;
};

int string_create(struct string *s, char *v) {
	if ( s==NULL ) // 1
		return FALSE;

	s->length = strlen(v); // 2

	s->value = malloc( sizeof(char) * s->length +1 ); // 3
	if( s->value==NULL )
		return FALSE;

	strcpy(s->value,v); // 4

	return TRUE; // 5
}

// 1. Confirms that a string is available; if not, return FALSE
// 2. Assigns the string's length
// 3. Allocates storage for the string
// 4. Copies the original string to newly allocated storage
// 5. Returns TRUE if all operations are successful


void string_destroy(struct string *s) {
	free(s->value); // 6
	s->value = NULL; // 7
	s->length = 0; // 8
}

// 6. Free string storage memory
// 7. Assigns the pointer to NULL, which can be used later to test for a valid
// string's structure
// 8. Resets the string's length to 0


int main() {
	struct string str1;

	string_create(&str1,"I am not a string object");

	printf("The string '%s' is %d characters long\n",
			str1.value,
			str1.length
		  );

	string_destroy(&str1);

	return 0;
}