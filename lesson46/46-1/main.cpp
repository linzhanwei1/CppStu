#include <iostream>
#include <string>

using namespace std;

class Object {
private:
	string ms;
public:
	//Object() {
	//	cout << "Object() : " << endl;
	//}
	Object(string s) {
		cout << "Object(string s) : " << s << endl;
		ms = s;
	}
	~Object() {
		cout << "~Object()" << ms << endl;
	}
};

class Parent : public Object {
private:
	string ms;
public:
	Parent() : Object("Default") {
		cout << "Parent()" << endl;
		ms = "Default";
	}
	Parent(string s): Object(s) {
		cout << "Parent(string s) : " << s << endl;
		ms = s;
	}
	~Parent() {
		cout << "~Parent()" << ms << endl;
	}
};

class Child : public Parent {
private:
	Object mO1;
	Object mO2;
	string ms;
public:
	Child() :Parent(),mO1("Default 1"),mO2("Default 2") {
		cout << "Child()" << endl;
		ms = "Default";
	}
	Child(string s) : Parent(s), mO1(s + "1"), mO2{s + "2"} {
		cout << "Child(string s) : "<< s << endl;
		ms = s;
	}
	~Child() {
		cout << "~Child()" << ms << endl;
	}
};

int main(int argc, char* argv[]) {
	//Child c;
	Child cc("cc");
	cout << endl;

	return 0;
}