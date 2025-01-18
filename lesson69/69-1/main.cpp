#include <iostream>

using namespace std;

#if 0
// 版本一 80分
class Test {
private:
	int m_value;
	mutable int m_count;
public:
	Test(int value = 0) {
		m_value = value;
		m_count = 0;
	}

	int getValue() const {
		m_count++;
		return m_value;
	}

	void setValue(int value) {
		m_count++;
		m_value = value;
	}

	int getCount() const {
		return m_count;
	}
};
#endif

// 版本二 100分
class Test {
private:
	int m_value;
	int* const m_count = nullptr;
public:
	Test(int value = 0) : m_count(new int(0)) {
		m_value = value;
	}

	int getValue() const {
		*m_count = *m_count + 1;
		return m_value;
	}

	void setValue(int value) {
		*m_count = *m_count + 1;
		m_value = value;
	}

	int getCount() const {
		return *m_count;
	}
};


int main(int argc, char* argv[]) {
	Test t;
	t.setValue(100);

	cout << "t.m_value = " << t.getValue() << endl;
	cout << "t.m_count = " << t.getCount() << endl;

	const Test ct(200);

	cout << "ct.m_value = " << ct.getValue() << endl;
	cout << "ct.m_count = " << ct.getCount() << endl;

	return 0;
}