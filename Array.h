#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<cstdarg>
using namespace std;
class Array
{
	friend ostream& operator << (ostream& out, Array& arr);
	friend istream& operator >> (istream& in, Array& arr);
	int* data;
	int capacity;
	bool isValidIndex(int index) const;
	static void myMemMove(void* src, void* dest, int byteCount);
	void input();
	void printArray() const;
public:
	Array(int count=0, ...);
	Array(const Array& ref);
	Array(Array&& ref);
	Array operator = (const Array& ref);
	Array operator = (Array && ref);
	int& operator [] (int index);
	const int& operator [] (int index) const;
	int getCapacity() const;
	void reSize(int newSize);
	~Array();
};
ostream & operator << (ostream& out, Array& arr);
istream& operator >> (istream& in, Array& arr);
#endif