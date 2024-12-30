#include <stdio.h>

class Test {
private:
	int mi;
public:
	int mj;
	Test(int i);
	Test(const Test& t);
	int getMi() const;
};

Test::Test(int i) {
	mi = i;
}

Test::Test(const Test& t) {
	mi = t.getMi();
}

int Test::getMi() const {
	return mi;
}

int main() {
	const Test t(1);

	printf("t.getMi() = %d\n", t.getMi());

	return 0;
}