#ifndef __INT_ARRAY_H__
#define __INT_ARRAY_H__

class IntArray {
private:
	int m_length;
	int* m_pointer;
	IntArray(int len);
	bool construct();
public:
	static IntArray* NewInstance(int len);
	int length();
	bool get(int index, int& value);
	bool set(int index, int value);
	int& operator [] (int i);
	IntArray& self();
	~IntArray();
};


#endif /* __INT_ARRAY_H__ */
