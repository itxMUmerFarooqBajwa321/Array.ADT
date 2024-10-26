#include "Array.h"
bool Array::isValidIndex(int index) const
{
	if (index < capacity && index >= 0)
	{
		return true;
	}
	return false;
}
void Array::input()
{
	for (int i = 0; i < capacity; i++)
	{
		cin >> data[i];
	}
}
Array::Array(int count, ...):capacity(0),data(nullptr)
{
	if (count <= 0)
		return;
	capacity = count;
	data = new int [capacity];
	va_list myList;
	va_start(myList, count);
	int arg;
	for (int i = 0; i < count; i++)
	{
		arg = va_arg(myList, int);
		data[i] = arg;
	}
	va_end(myList);
}
Array::Array(const Array& ref) : Array(0)
{
	if (this == &ref)
	{
		return;
	}
	if (!ref.data)
	{
		exit(0);
	}
	// this->~Array();  // no need of this coz object is already at valid and null/reset state due to Array() ie default ctor
	capacity = ref.capacity;
	this->reSize(capacity);
	/*int i = 0;
	while (i < capacity)
	{
		data[i]=ref.data[i];
		i++;
	}*/
	myMemMove(ref.data, data, sizeof(int) * capacity);
}
Array::Array(Array&& ref)
{
	if (this == &ref)
	{
		return;
	}
	if (!ref.data)
	{
		exit(0);
	}
	this->~Array();
	capacity = ref.capacity;
	data = ref.data;    // transfer of memory resource ie. array to pointer of calling obj.
	ref.data = nullptr;    // break the connection of array with old obj.
	ref.capacity = 0;
}
Array Array::operator = (const Array& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		exit(0);
	}
	// this->~Array();  // no need of this coz object is already at valid and null/reset state due to Array() ie default ctor
	capacity = ref.capacity;
	this->reSize(capacity);
	/*int i = 0;
	while (i < capacity)
	{
		data[i]=ref.data[i];
		i++;
	}*/
	myMemMove(ref.data, data, sizeof(int) * capacity);
	return *this;
}
Array Array::operator = (Array&& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		exit(0);
	}
	this->~Array();
	capacity = ref.capacity;
	data = ref.data;    // transfer of memory resource ie. array to pointer of calling obj.
	ref.data = nullptr;    // break the connection of array with old obj.
	ref.capacity = 0;
	return *this;
}
void Array::myMemMove(void* src, void* dest, int byteCount)
{
	const char* s = (const char*)src;
	char* d = (char*)dest;
	for (int i = byteCount - 1; i >= 0; i--)
	{
		d[i] = s[i];
	}
}
int& Array::operator [] (int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
const int& Array::operator [] (int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}

int Array::getCapacity() const
{
	return capacity;
}
void Array::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~Array();
		return;
	}
	int *temp = new int[newSize];
	int i = 0;
	int smallerSize = (newSize < capacity) ? newSize : capacity;
	if (data)     // means if there was any data in calling obj then transfer it to new array otherwise skip it.
	{
		while (i < smallerSize)
		{
			temp[i] = data[i];
			i++;
		}
	}
	this->~Array();
	capacity = newSize;
	data = temp;
}
void Array::printArray() const
{
	if (!data || !capacity)
	{
		return;
	}
	for (int i = 0; i < capacity; i++)
	{
		cout << data[i] << ' ';
	}
}
Array::~Array()
{
	delete[] data;
	data = nullptr;
	capacity = 0;
}
ostream & operator << (ostream& out, Array& arr)
{
	arr.printArray();    // OR u can implement whole logic of printArray () here by making it friend of class.
	return out;
}
istream & operator >> (istream & in, Array & arr)
{
	arr.input();
	return in;
}
