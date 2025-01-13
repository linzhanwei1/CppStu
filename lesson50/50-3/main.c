#include "demo.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	Demo* d = DemoCreate(1, 2);		// Demo* d = new Demo(1, 2);

	printf("d.mi = %d\n", DemoGetI(d));	// d->getI();
	printf("d.mj = %d\n", DemoGetI(d));	// d->getJ();
	printf("Add(3) = %d\n", DemoAdd(d, 3));	// d->add(3);

	DemoFree(d);		// ~~

	return 0;
}