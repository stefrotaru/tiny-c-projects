#include <stdio.h>
#include <string.h> // 1

int main() {
    struct str {
        char *string;
        unsigned long long (*length)(const char *); // 2
    };
    struct str str1; // 3
    char s[] = "Heresy";

    str1.string = s; // 4
    str1.length = &strlen; // 5

    printf("The string '%s' is %lu characters long\n", str1.string, str1.length(str1.string)); // 6

    return 0;
}

// 1. Must include the string.h header for the definition of strlen()
// 2. The function member of structure str
// 3. Variable str1 is created of the str structure type
// 4. The strin gmember is assigned
// 5. The function is assigned, no parantheses, and prefixed by the address-of operator.
// 6. The function is called in the printf() statement