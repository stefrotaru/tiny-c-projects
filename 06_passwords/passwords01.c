#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *add_word(void) {
    char *vocabulary[] = {
		"Orange", "Grape", "Apple", "Banana",
		"coffee", "tea", "juice", "beverage",
		"happY", "grumpY", "bashfuL", "sleepY"
	};
	int r;

	r = rand() % 12;
	return( vocabulary[r] );
}

char *number(void) {
    static char n[2]; // 1

	n[0] = rand() % 10 + '0'; // 2
	n[1] = '\0'; // 3

	return(n);
}

char *symbol(void) {
    char sym[8] = "!@#$%*_-";
	static char s[2]; // 1

	s[0] = sym[rand() % 8]; // 4
	s[1] = '\0'; // 3

	return( s );
}

int main() {
    char password[32]; // 5

	srand( (unsigned)time(NULL) );

	password[0] = '\0'; // 6

	strcpy(password, add_word()); // 7
	strcat(password, number()); // 8
	strcat(password, add_word()); // 9
	strcat(password, symbol()); // 10
	strcat(password, add_word()); // 11

	printf("%s\n", password);

	return(0);
}

// 1. The static array's contents are retained when the function terminates.
// 2. Generates a random char, 0 through 9, storing it as the first element of
// array n[].
// 3. Caps the string with a null char.
// 4. Plucks a random char from the sym[] array and sets it as the first element
// of array n[].

// 5. Storage where the password is built.
// 6. Initializes the string so that the strcpy() func doesn't puke xD.
// 7. Copies the first word generated into the password[] array.
// 8. Appends a number to the password[] array.
// 9. Appends the second word to the password[] array.
// 10. Appends a symbol to the password[] array.
// 11. Appends the third word to the password[] array.