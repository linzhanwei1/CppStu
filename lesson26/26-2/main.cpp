#include <stdio.h>

class Demo {
public:
	int i;;
public:
	int getI();
	static void StaticFunc(const char* s);
	static void staticSetI(Demo& d, int v);
};

int Demo::getI() {
	return i;
}

void Demo::StaticFunc(const char* s) {
	printf("StaticFunc: %s\n", s);
}

void Demo::staticSetI(Demo& d, int v) {
	d.i = v;
}

int main(int argc, char* argv[]) {
	Demo::StaticFunc("man Begin...");

	Demo d;

	Demo::staticSetI(d, 10);

	printf("d.i = %d\n", d.getI());

	Demo::StaticFunc("man End...");

	return 0;
}