#include <stdio.h>
#include <limits.h>

int main() {
	printf("Char:\n");
	printf("\tNumber of bits: %d\n", CHAR_BIT); // 1
	printf("\tSigned minimum: %d\n", SCHAR_MIN); // 2
	printf("\tSigned maximum: %d\n", SCHAR_MAX); // 3
	printf("\tUnsigned max: %d\n", UCHAR_MAX); // 4

	printf("Short:\n");
	printf("\tSigned minimum: %d\n", SHRT_MIN);
	printf("\tSigned maximum: %d\n", SHRT_MAX);
	printf("\tUnsigned max: %d\n", USHRT_MAX);

	printf("Int:\n");
	printf("\tSigned minimum: %d\n", INT_MIN);
	printf("\tSigned maximum: %d\n", INT_MAX);
	printf("\tUnsigned max: %u\n", UINT_MAX); // 5

	printf("Long:\n");
	printf("\tSigned minimum: %ld\n", LONG_MIN); // 6
	printf("\tSigned maximum: %ld\n", LONG_MAX);
	printf("\tUnsigned max: %lu\n", ULONG_MAX); // 7

	printf("Long long:\n");
	printf("\tSigned minimum: %lld\n", LLONG_MIN); // 8
	printf("\tSigned maximum: %lld\n", LLONG_MAX);
	printf("\tUnsigned max: %llu\n", ULLONG_MAX); // 9

	return 0;
}

// 1. The char type is the only one that seems to havethe "BIT" defined
// constant.
// 2. Signed char minimum
// 3. Signed char maximum
// 4. Unsigned char maximum; zero is minimum
// 5. Unsigned integer max uses the %u placeholder
// 6. Long integers require the %ld placeholder
// 7. Unsigned long require the %lu placeholder
// 8. Double-longs require %lld
// 9. The double-unsigned long placeholder is %llu