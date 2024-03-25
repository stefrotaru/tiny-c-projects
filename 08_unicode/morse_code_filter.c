#include <stdio.h>
#include <ctype.h>

void toMorse(char c) {
	const char *morse_alpha[] = { // 1
		".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..",
		"--", "-.", "---", ".--.", "--.-", ".-.",
		"...", "-", "..-", "...-", ".--", "-..-",
		"-.--", "--.."
	};
	const char *morse_digit[] = { // 1
		"-----", ".----", "..---", "...--", "....-",
		".....", "-....", "--...", "---..", "----."
	};

	if ( isalpha(c) ) { // 2
		c = toupper(c); // 3
		printf("%s ",morse_alpha[c-'A']); // 4
	}
	else if ( isdigit(c) ) { // 5
		printf("%s ",morse_digit[c-'0']); // 6
	}
	else if ( c==' ' || c=='\n' ) { // 7
		putchar('\n');
	}
	else // 8
		return;
}

int main() {
    int ch;

    while ( (ch=getchar()) != EOF ) {
        toMorse(ch);
    }

    return 0;
}

// 1. Arrays declared as const char to keep the code from otherwise messing with
// them; this type of construction dislikes being manipulated
// 2. Pulls out alphabetic characters
// 3. Converts to uppercase; Morse is case-insensitive
// 4. Subtracts the character from 'A' to obtain the proper array element offset
// 5. Checks for digits 0 through 9
// 6. Subtracts the digit from '0' to obtain the proper array element offset
// 7. For spaces and new lines, output a newline
// 8. Ignores non-Morse characters; no output is generated