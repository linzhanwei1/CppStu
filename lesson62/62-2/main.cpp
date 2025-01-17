#include <iostream>

#include "Singleton.h"

using namespace std;

class SObject {
private:
	friend class Singleton<SObject>;
	SObject(const SObject&);
	SObject operator=(const SObject&);
	SObject() {}
public:
	void print() {
		cout << "this = " << this << endl;
	}
};

int main(int argc, char* argv[]) {
	SObject* s = Singleton<SObject>::GetInstance();
	SObject* s1 = Singleton<SObject>::GetInstance();
	SObject* s2 = Singleton<SObject>::GetInstance();

	s->print();
	s1->print();
	s2->print();


	return 0;
}