#include <stdio.h>

int a = 1;
struct SV {
	int& x;
	int& y;
	int& z;
};

int main(int argc, char* argv[]) {
	int b = 2;
	int* pc = new int(3);
	SV sv = {a, b, *pc};
	int& array[] = { a, b, *pc };	// 数组的每个元素的地址是连续的。但实际值array[0]:全局静态存储区array[1]栈区array[2]堆区

	printf("&sv.x = %p\n", &sv.x);
	printf("&sv.y = %p\n", &sv.y);
	printf("&sv.z = %p\n", &sv.z);

	delete pc;
	pc = nullptr;
	return 0;
}