#include "intArray.h"

IntArray::IntArray(int len) {
	m_pointer = new int[len];
	m_length = len;
	// 初始化
	for (int i = 0; i < len; ++i) {
		m_pointer[i] = 0;
	}

}

// 拷贝构造 深拷贝
IntArray::IntArray(const IntArray& obj) {
	m_pointer = new int[obj.m_length];
	m_length = obj.m_length;

	for (int i = 0; i < obj.m_length; ++i) {
		m_pointer[i] = obj.m_pointer[i];
	}
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


IntArray::~IntArray() {
	delete[] m_pointer;
	m_pointer = nullptr;
	m_length = 0;
}