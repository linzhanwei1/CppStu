#include <stdio.h>

#if 0
int main(int argc, char* argv[]) {
	bool b = 0;

	printf("b = %d\n", b);	// 0
	b++;
	printf("b = %d\n", b);	// 1
	b = b - 3;
	printf("b = %d\n", b);	// 1

	return 0;
}
#endif

#if 0
int main(int argc, char* argv[]) {
	bool b = false;
	int a = b;

	printf("sizeof(b) = %d\n", sizeof(b));	// 1
	printf("b = %d, a = %d\n", b, a);		// 0 0

	b = 3;
	a = b;
	printf("b = %d, a = %d\n", b, a);		// 1 1

	b = -5;
	a = b;
	printf("b = %d, a = %d\n", b, a);		// 1 1

	a = 10;
	b = a;
	printf("a = %d, b = %d\n", a, b);		// 10 1

	a = 0;
	b = a;
	printf("a = %d, b = %d\n", a, b);		// 0 0

	return 0;
}
#endif

int main(int argc, char* argv[]) {
	int a = 1;
	int b = 2;
	(a < b ? a : b) = 3;
	printf("a = %d, b = %d\n", a, b);

	return 0;
}