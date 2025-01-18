#include <iostream>

using namespace std;

class Test {
private:

	int m_value;
public:
	Test() {
		m_value = 0;
	}
	~Test() {}
	void* operator new (unsigned int size) {
		void* ret = NULL;
		cout << "operator new: " << size << endl;

		return malloc(size);
	}

	void operator delete (void* p) {
		cout << "operator delete: " << p << endl;
		free(p);
	}
	void* operator new[] (unsigned int size) {
		void* ret = NULL;
		cout << "operator new[]: " << size << endl;

		return malloc(size);
	}

	void operator delete[] (void* p) {
		cout << "operator delete[]: " << p << endl;
		free(p);
	}

};


int main(int argc, char* argv[]) {
	Test* pt = nullptr;

	pt = new Test;

	delete pt;

	// new/delete new[]/delete[] 不能交叉使用
	pt = new Test[5];
	delete[] pt;

	return 0;
}