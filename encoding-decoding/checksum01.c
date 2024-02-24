#include <stdio.h>

int main() {
    int hexbytes[] = { // 1
        0x41, 0x42, 0x43, 0x44, 0x45,
        0x46, 0x47, 0x48, 0x49, 0x4A
    };
    int x, checksum;

    checksum = 0; // 2
    for ( x = 0; x < 10; x++ ) {
        checksum += hexbytes[x]; // 3
        printf("%02X ", hexbytes[x]);
    }
    printf("\nChecksum = %02X\n", checksum % 0x100); // 4

    return 0;
}

// 1. Just a random assortment of hex values; 10 total
// 2. Initializes the checksum variable here
// 3. Accumulates the totals
// 4. Outputs the checksum, but limited to a char-size value