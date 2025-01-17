#include <iostream>

using namespace std;

double divide(double a, double b) {
	const double delta = 0.000000000000001;
	double ret = 0;
	if (!((-delta < b) && (b < delta))) {
		ret = a / b;
	}
	else {
		throw 0;
	}
	return ret;
}

int main(int argc, char* argv[]) {
	try {
		double r = divide(1, 0);
	}
	catch (int e){
		cout << "e = " << e << endl;
	}
	catch (...) {
		cout << "..." << endl;
	}

	return 0;
}