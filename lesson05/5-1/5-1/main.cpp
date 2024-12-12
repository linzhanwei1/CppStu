#include <stdio.h>

void Example() {
	printf("Example:\n");

	int a = 4;
	const int& b = a;
	int* p = (int*)&b;

	//b = 5;
	*p = 5;

	printf("a = %d\n", a);		// 4
	printf("b = %d\n", b);		// 5
}

void Demo() {
	printf("Demo:\n");

	const int& c = 1;
	int* p = (int*)&c;
	//c = 5;
	*p = 5;
	printf("c = %d\n", c);		// 5
}

int main(int argc, char* argv[]) {
	Example();

	printf("\n");

	Demo();

	return 0;
}