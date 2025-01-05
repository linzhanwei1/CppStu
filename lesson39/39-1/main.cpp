#include <iostream>

using namespace std;

void func(int i) {
	cout << "func() : i" << i << endl;
}

int main(int argc, char* argv[]) {
	int a[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	int i = 0;
	int j = 0;

	while (i < 5)
		func(i),

		i++;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << a[i][j] << endl;
		}
	}

	(i, j) = 6;
	cout << "i = " << i << endl;	// 3
	cout << "j = " << j << endl;	// 6

	return 0;
}