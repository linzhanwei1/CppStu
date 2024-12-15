#include <stdio.h>

namespace First {
	int i = 0;
}

namespace Second {
	int i = 1;
	namespace Internal {
		struct P {
			int x;
			int y;
		};
	}
}

int main(int argc, char* argv[]) {
	using namespace First;
	using Second::Internal::P;

	printf("Frist::i = %d\n", i);
	printf("Second::i = %d\n", Second::i);

	P p = { 2,3 };
	printf("p.x = %d\n", p.x);
	printf("p.y = %d\n", p.y);

	return 0;
}