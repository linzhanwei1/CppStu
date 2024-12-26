#include <stdio.h>

class Test {
private:
	int i;
	int j;
	int* p;
public:
	int getI() {
		return i;
	}
	int getJ() {
		return j;
	}
	int* getP() {
		return p;
	}

	Test(int v) {
		i = 1;
		j = 2;
		p = new int;

		*p = v;
	}

	// 拷贝构造函数 深拷贝
	Test(const Test& obj) {
		i = obj.i;
		j = obj.j;
		p = new int;
		*p = *obj.p;
	}

	void free() {
		delete p;
		p = nullptr;
	}
};

int main(int argc, char* argv[]) {
	Test t1(3);
	Test t2 = t1;

	printf("t1.i:%d, t1.j:%d t1.p = 0x%p *t1.p = %d\n", t1.getI(), t1.getJ(), t1.getP(), *(t1.getP()));
	printf("t2.i:%d, t2.j:%d t2.p = 0x%p *t2.p = %d\n", t2.getI(), t2.getJ(), t2.getP(), *(t2.getP()));

	t1.free();
	t2.free();
	return 0;
}