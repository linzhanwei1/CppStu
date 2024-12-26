#pragma once
#include <stdio.h>

class Test {
private:
	int mi;
public:
	Test(int i) {
		mi = i;
		printf("Test(int i): %d\n", mi);
	}
	Test(const Test& obj) {
		mi = obj.mi;
		printf("Test(const Test& obj): %d\n", mi);
	}
};