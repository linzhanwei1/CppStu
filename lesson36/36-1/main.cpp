#include <iostream>

using namespace std;

class Test {
private:
	int* m_pointer;
public:
	Test() {
		m_pointer = nullptr;
	}
	Test(int i) {
		m_pointer = new int(i);
	}
	Test(const Test& obj) {
		if (this != &obj) {
			m_pointer = new int(*obj.m_pointer);
		}
	}
	Test& operator = (const Test& obj) {
		if (this != &obj) {
			delete m_pointer;
			m_pointer = new int(*obj.m_pointer);
		}
		return *this;
	}
	void print() {
		cout << "m_pointer = " << hex << m_pointer << endl;
	}
	~Test() {
		delete m_pointer;
		m_pointer = nullptr;
	}
};

int main(int argc, char* argv[]) {
	Test t1 = 1;
	Test t2;

	t2 = t1;

	t1.print();
	t2.print();


	return 0;
}