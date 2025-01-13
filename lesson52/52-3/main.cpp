#include <iostream>

using namespace std;

class Channel {	// interface
public:
	virtual bool open() = 0;
	virtual void close() = 0;
	virtual bool send(char* buf, int len) = 0;
	virtual int receive(char* buf, int len) = 0;
};

int main(int argc, char* argv[]) {


	return 0;
}