#include <stdio.h>
#include <ctype.h>

int main() {
    const char *nato[] = {
        "Alpha", "Bravo", "Charlie", "Delta", "Echo",
        "Foxtrot", "Golf", "Hotel", "India", "Juliett",
        "Kilo", "Lima", "Mike", "November", "Oscar",
        "Papa", "Quebec", "Romeo", "Sierra", "Tango",
        "Uniform", "Victor", "Whiskey", "Xray", "Yankee",
        "Zulu"
    };
    char ch;

    while ( (ch=getchar()) != EOF ) {
        if ( isalpha(ch) )
            printf("%s ", nato[toupper(ch)-'A']); // 1
        
        if ( ch == '\n' ) // 2
            putchar(ch);
    }
    putchar('\n');

    return 0;
}

// 1. Translates a character into an offset within the nato[] array
// 2. Outputs a newline when encountered to keep the output clean

// It's important to know that any nonalphabetic characters (aside from new line)
// are ignored by this filter. Ignoring input in a filter is legitimate; a filter
// need not generate one-to-one output based on input.

// Filters operate on character I/O, but this limitation doesn't restrict a filter
// from affecting words, sentences, or other chunks of text. The key is to store
// input as soon as it arrives. Once the propper text chunks are assembled, such as
// a word or a sentence, the filter can process it. Check word_filter.c