#include <iostream>

using namespace std;

class People {
private:
	string mName;
	int mAge;
public:
	People(string name, int age) {
		mName = name;
		mAge = age;
	}
	void print() {
		cout << "Name = " << mName << ", "
			<< "Age  = " << mAge << endl;
	}
};

class Teacher : public People {
public:
	Teacher(string name, int age) :People(name, age) { }
};

class Student : public People {
public:
	Student(string name, int age) :People(name, age) { }
};

class Dockor : public Teacher, public Student {
public:
	Dockor(string name, int age) : Teacher(name+"-1", age+1), Student(name+"-2", age+2) { }
};

int main(int argc, char* argv[]) {
	Dockor d("Delphi", 33);
	d.Teacher::print();
	d.Student::print();

	return 0;
}