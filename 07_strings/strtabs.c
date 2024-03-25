#include <stdio.h>

void strtabs(const char *s, int tab) {
    int column, x, spaces;

    column = 0; // 1
    while ( *s ) { // 2
        if ( *s == '\t' ) { // 3 
            spaces = tab - (column % tab); // 4
            for ( x = 0; x < spaces; x++ ) // 5
                putchar(' ');
            column += spaces; // 6
        }
        else { // 7
            putchar(*s);
            if ( *s == '\n' ) // 8
                column = 0;
            else
                column++;
        }
        s++;
    }
}

// calculate and diplay a tab
int main() {
    const char *text[3] = {
        "Hello\tHi\tHowdy\n",
        "\tLa\tLa\n",
        "Constantinople\tConstantinople\n"
    };
    int x, y;

    for ( y = 4; y < 32; y *= 2) { // 9
        printf("Tab width: %d\n", y);
        for ( x = 0; x < 3; x++ ) {
            strtabs(text[x], y);
        }
    }

    return 0;
}

// 1. The column variable tracks the current column position.
// 2. Loops through the string
// 3. Catches the tab character
// 4. Calculates the number of spaces to output line up at the next tab stop
// 5. Outputs the required spaces
// 6. Updates the column offset
// 7. Handles other characters here
// 8. If a newline is output, resets the column value
// 9. Nested loop to output the three sample strings at three different tab stops:
// 4, 8, and 16 spaces