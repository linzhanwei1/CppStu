#include <iostream>

using namespace std;

class Test {
public:
	Test() {
		cout << "Test()" << endl;
	}
	~Test() { cout << "~Test()" << endl; }
};

int main(int argc, char* argv[]) {
	Test* pn = new Test;	// Test()
	Test* pm = (Test*)malloc(sizeof(Test));

	delete pn;
	free(pm);	// 不调用析构函数

	return 0;
}