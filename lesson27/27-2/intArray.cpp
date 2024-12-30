#include "intArray.h"

IntArray::IntArray(int len) {
	m_length = len;
}

bool IntArray::construct() {
	m_pointer = new int[m_length];
	if (m_pointer) {
		// 初始化
		for (int i = 0; i < m_length; ++i) {
			m_pointer[i] = 0;
		}
		return true;
	}
	return false;
}

IntArray* IntArray::NewInstance(int len) {
	IntArray* ret = new IntArray(len);

	if (!(ret && ret->construct())) {
		delete ret;
		ret = nullptr;
	}
	return ret;
}

int IntArray::length() {
	return m_length;
}
bool IntArray::get(int index, int& value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		value = m_pointer[index];
	}
	return true;
}
bool IntArray::set(int index, int value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		m_pointer[index] = value;
	}
	return true;
}

void IntArray::free() {
	delete[] m_pointer;
	m_pointer = nullptr;
	m_length = 0;
}