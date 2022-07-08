#pragma
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
private:
	int capacity;
	int size;
	T* ptr;
public:
	//有参构造
	MyArray(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->ptr = new T[capacity];
	}

	//深拷贝
	MyArray(const MyArray& arr)
	{
		if (this->ptr != NULL)
		{
			delete[] this->ptr;
			this->ptr = NULL;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->ptr = new T[arr.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->ptr[i] = arr.ptr[i];
		}

	}

	//=重载
	MyArray& operator=(const MyArray& arr)
	{
		if (this->ptr != NULL)
		{
			delete[] this->ptr;
			this->ptr = NULL;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->ptr = new T[arr.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->ptr[i] = arr.ptr[i];
		}

		return *this;
	}

	//[]重载
	T& operator[](int i)
	{
		return this->ptr[i];
	}

	//获取capacity
	int getCapacity()
	{
		return this->capacity;
	}

	//获取size
	int getSize()
	{
		return this->size;
	}

	//打印arr
	void printAll()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->ptr[i] <<"\t";
			if (!((i+1) % 5))
			{
				cout << endl;
			}
		}
		cout << endl;
	}

	//添加新元素
	void push(const T& t)
	{
		if (this->size == this->capacity)
		{
			return;
		}
		this->ptr[this->size] = t;
		this->size++;
		
	}

	//删除末尾元素
	T pop()
	{
		//要做this->size判断的
		this->size--;
		return this->ptr[this->size];
	}


	//析构
	~MyArray()
	{
		if (this->ptr != NULL)
		{
			delete[] this->ptr;
			this->ptr = NULL;
		}
	}
};

