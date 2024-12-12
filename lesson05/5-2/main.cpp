#include <stdio.h>

struct TRef {
	char& r;
};

int main(int argc, char* argv[]) {
	char c = 'c';
	char& rc = c;
	TRef ref = { c };

	printf("sizeof(char&) = %d\n", sizeof(char&));	// 1	sizeof(char)
	printf("sizeof(rc) = %d\n", sizeof(rc));		// 1	sizeof(c)
		
	printf("sizeof(TRef) = %d\n", sizeof(TRef));	// 4	指针常量
	printf("sizeof(ref.r) = %d\n", sizeof(ref.r));	// 1	sizeof(c)

	return 0;
}