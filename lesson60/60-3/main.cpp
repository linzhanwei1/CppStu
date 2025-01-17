#include <iostream>
#include "intArray.h"

using namespace std;

int main(int argc, char* argv[]) {
	HeapArray<int> *a = HeapArray<int>::NewInstance(5);

	if (a != nullptr) {
		HeapArray<int>& array = a->self();
		cout << "a.length = " << a->length() << endl;
		array[0] = 1;

		for (int i = 0; i < a->length(); i++) {
			array[i] = i + 1;
		}

		for (int i = 0; i < a->length(); i++) {
			cout << array[i] << endl;
		}
	}



	delete a;
	a = nullptr;

	return 0;
}