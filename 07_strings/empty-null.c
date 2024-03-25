#include <stdio.h>
#include <string.h>

int main() {
    char a[5] = {'\0'}; // 1

    char b[5]; // 2

    if ( strcmp(a, b) == 0) // 3
        puts("Strings are the same");
    else
        puts("Strings are not the same");
    
    printf("Length : a=%lu b=%lu\n", strlen(a), strlen(b)); // 4
    printf("Storage: a=%zu b=%zu\n", sizeof(a), sizeof(b)); // 5
}

// 1. The empty string
// 2. The null string (Uninitialized)
// 3. If both string are identical
// 4. Size according to strlen()
// 5. Size according to sizeof