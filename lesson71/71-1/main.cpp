#include <iostream>
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
	}
};


int main(int argc, char* argv[]) {
	static Test t;

	throw 1;

	return 0;
}