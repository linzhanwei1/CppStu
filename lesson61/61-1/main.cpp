#include <iostream>

using namespace std;

class Test {
private:
	string m_name;
public:
	Test(const char* name) {
		cout << "Hello, " << name << "." << endl;
		m_name = name;
	}
	void print() {
		cout << "I'm " << m_name << "." << endl;
	}
	~Test() {
		cout << "Goodbye, " << m_name << "." << endl;
	}
};

int main(int argc, char* argv[]) {
	auto_ptr<Test> pt(new Test("lucy"));
	pt->print();
	cout << endl;
	auto_ptr<Test> pt1(pt);
	cout << "pt = " << pt.get() << endl;
	cout << "pt1 = " << pt1.get() << endl;
	pt1->print();

	return 0;
}