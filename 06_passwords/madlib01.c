#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *add_noun(void) {
    const char *vocabulary[] = {
		"couch", "dog", "tree", "eyeball",
		"banana", "necklace", "house", "car",
		"computer", "mountain", "cup", "hair"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

const char *add_verb(void) {
    const char *vocabulary[] = {
		"run", "eat", "burp", "sneeze",
		"cut", "yodel", "cook", "slice"
	};
	int r;

	r = rand() % (sizeof(vocabulary)/sizeof(char *));
	return( vocabulary[r] );
}

const char *add_adjective(void) {
    const char *vocabulary[] = {
        "loud", "big", "soft", "crunchy",
		"smelly", "great", "blue", "tiny",
		"ripe", "hairy"
    };
    int r;

    r = rand() % (sizeof(vocabulary)/sizeof(char *));
    return (vocabulary[r]);
}

int main() {
    srand ( time(NULL) ); // 1

    printf("Will you please take the %s %s ", // 2
           add_adjective(),                   // 3
           add_noun()
          );                                  // 4
    printf("and %s the %s? \n",               // 5
           add_verb(),                        // 6
           add_noun()
          );                                  // 7
    
    return 0;
}

// 1. Seeds the randomizer
// 2. Outputs the first part of the sentence
// 3. Fills in the adjective blank
// 4. Fills in the noun blank
// 5. Outputs the last part of the sentence
// 6. Fills in the verb blank
// 7. Fills in another noun blank