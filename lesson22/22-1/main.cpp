#include <stdio.h>
#include "intArray.h"

int main(int argc, char* argv[]) {
	IntArray a(5);
	
	for (int i = 0; i < a.length(); ++i) {
		a.set(i, i + 1);
	}
	IntArray b = a;

	for (int i = 0; i < a.length(); ++i) {
		int value = -1;
		if (a.get(i, value)) {
			printf("a[%d] = %d\n", i, value);
		}
	}

	printf("\r\n");

	for (int i = 0; i < b.length(); ++i) {
		int value = -1;
		if (b.get(i, value)) {
			printf("b[%d] = %d\n", i, value);
		}
	}


	return 0;
}