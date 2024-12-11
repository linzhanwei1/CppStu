#include <stdio.h>

int main(int argc, char* argv[]) {
	int a = 4;
	int& b = a;

	b = 5;

	printf("a = %d\n", a);		// 5
	printf("b = %d\n", b);		// 5
	printf("&a = %p\n", &a);	// &a = 012FFA68
	printf("&b = %p\n", &b);	// &b = 012FFA68
}