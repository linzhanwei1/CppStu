#include <stdio.h>

void static_cast_demo() {
	int i = 0x12345;
	char c = 'c';
	int* pi = &i;
	char* pc = &c;

	c = static_cast<char>(i);
	//pc = static_cast<char*>(pi);		// 不可以
}

void const_cast_demo() {
	const int& j = 1;
	int& k = const_cast<int&>(j);

	const int x = 2;					// 产生一个常量
	int& y = const_cast<int&>(x);		// 为常量分配一块内存

	//int z = const_cast<int>(x);		// 不可以
	k = 5;
	printf("k = %d\n", k);				// 5
	printf("j = %d\n", j);				// 5

	y = 8;
	printf("x = %d\n", x);				// 2
	printf("y = %d\n", y);				// 8
	printf("&x = %d\n", &x);
	printf("&y = %d\n", &y);
}

void reinterpret_cast_demo() {
	int i = 0;
	char c = 'c';
	int* pi = &i;
	char* pc = &c;

	pc = reinterpret_cast<char*>(pi);
	pi = reinterpret_cast<int*>(pc);
	pi = reinterpret_cast<int*>(i);
	//c = reinterpret_cast<char>(i);		// 不可以
}

void dynamic_cast_demo() {
	int i = 0;
	int* pi = &i;
	//char* pc = dynamic_cast<char*>(pi);		// 不可以
}

int main(int argc, char* argv[]) {
	static_cast_demo();
	const_cast_demo();
	dynamic_cast_demo();

	return 0;
}