#include <iostream>

using namespace std;

class Memory {
public:
	Memory() {
		cout << "Memory()" << endl;
	}
	~Memory() {
		cout << "~Memory()" << endl;
	}
};

class Disk {
public:
	Disk() {
		cout << "Disk()" << endl;
	}
	~Disk() {
		cout << "~Disk()" << endl;
	}
};

class Cpu {
public:
	Cpu() {
		cout << "Cpu()" << endl;
	}
	~Cpu() {
		cout << "~Cpu()" << endl;
	}
};

class MainBoard {
public:
	MainBoard() {
		cout << "MainBoard()" << endl;
	}
	~MainBoard() {
		cout << "~MainBoard()" << endl;
	}
};

class Computer {
private:
	Memory mMem;
	Disk mDisk;
	Cpu mCpu;
	MainBoard mMainBoard;
public:
	Computer() {
		cout << "Computer()" << endl;
	}
	void power() {
		cout << "power()" << endl;
	}
	void reset() {
		cout << "reset()" << endl;
	}
	~Computer() {
		cout << "~Computer()" << endl;
	}
};


int main(int argc, char* argv[]) {
	Computer c;

	return 0;
}