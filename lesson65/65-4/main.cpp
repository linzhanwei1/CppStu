#include <iostream>

#include "Array.h"

using namespace std;

int main(int argc, char* argv[]) {
	Array<double, 5> ad;

	try {
		for (int i = 0; i < ad.length(); i++) {
			ad[i] = i * 1.2;
		}

		for (int i = 0; i < ad.length(); i++) {
			cout << ad[i] << endl;
		}
	}
	catch (...) {
		cout << "Exception" << endl;
	}

	return 0;
}