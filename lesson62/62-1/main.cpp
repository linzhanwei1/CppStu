#include <iostream>

using namespace std;

class SObject {
private:
	static SObject* c_instance;
	SObject() {};						// 1.私有化构造函数
	SObject(const SObject&);			// 2.私有化拷贝构造
	SObject& operator=(const SObject&);	// 3.私有化赋值操作
										// 4.生命周期和系统一致的化，不需要析构
public:
	static SObject* GetInstance();
	void print() {
		cout << "this = " << this << endl;
	}
};

SObject* SObject::c_instance = nullptr;

SObject* SObject::GetInstance() {
	if (c_instance == nullptr) {
		c_instance = new SObject();
	}
	return c_instance;
}

int main(int argc, char* argv[]) {
	SObject* s = SObject::GetInstance();
	SObject* s1 = SObject::GetInstance();
	SObject* s2 = SObject::GetInstance();


	s->print();
	s1->print();
	s2->print();

	return 0;
}