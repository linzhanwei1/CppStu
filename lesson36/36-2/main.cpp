#include <iostream>
#include "intArray.h"

using namespace std;

int main(int argc, char* argv[]) {
	IntArray *a = IntArray::NewInstance(5);
	IntArray *b = IntArray::NewInstance(10);

	if (a && b) {
		IntArray& array = a->self();
		IntArray& brray = b->self();

		cout << "a.length = " << array.length() << endl;
		cout << "b.length = " << brray.length() << endl;
		
		array = brray;

		cout << "a.length = " << array.length() << endl;
		cout << "b.length = " << brray.length() << endl;
	}

	delete b;
	b = nullptr;

	delete a;
	a = nullptr;

	return 0;
}