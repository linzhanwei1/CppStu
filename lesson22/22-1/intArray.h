#ifndef __INT_ARRAY_H__
#define __INT_ARRAY_H__

class IntArray {
private:
	int m_length;
	int* m_pointer;
public:
	IntArray(int len);
	IntArray(const IntArray& obj);
	~IntArray();
	int length();
	bool get(int index, int& value);
	bool set(int index, int value);
};


#endif /* __INT_ARRAY_H__ */
