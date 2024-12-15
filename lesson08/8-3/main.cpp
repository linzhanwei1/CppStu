#include <stdio.h>

int add(int a, int b) {	// int(int, int)
	return a + b;
}

int add(int a, int b, int c) {	// int(int, int, int)
	return a + b + c;
}

int main(int argc, char* argv[]) {
	printf("%p\n", (int(*)(int, int))add(1, 2));
	printf("%p\n", (int(*)(int, int, int))add(1, 2, 3));

	return 0;
}