#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

class Test {
public:
	Test() {
		cout << "Test()";
		cout << endl;
	}
	~Test() {
		cout << "~Test()";
		cout << endl;
		//throw 2; // 不允许在析构函数中抛出异常 ① 内存泄露 ② 可能2此调用my_terminate
	}
};

void my_terminate() {
	cout << "void my_terminate()" << endl;
	//exit(1);
	abort();
}

int main(int argc, char* arv[]) {
	set_terminate(my_terminate);
	static Test t;
	
	throw 1;

	return 0;
}