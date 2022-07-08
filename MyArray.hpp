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
	//�вι���
	MyArray(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->ptr = new T[capacity];
	}

	//���
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

	//=����
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

	//[]����
	T& operator[](int i)
	{
		return this->ptr[i];
	}

	//��ȡcapacity
	int getCapacity()
	{
		return this->capacity;
	}

	//��ȡsize
	int getSize()
	{
		return this->size;
	}

	//��ӡarr
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

	//�����Ԫ��
	void push(const T& t)
	{
		if (this->size == this->capacity)
		{
			return;
		}
		this->ptr[this->size] = t;
		this->size++;
		
	}

	//ɾ��ĩβԪ��
	T pop()
	{
		//Ҫ��this->size�жϵ�
		this->size--;
		return this->ptr[this->size];
	}


	//����
	~MyArray()
	{
		if (this->ptr != NULL)
		{
			delete[] this->ptr;
			this->ptr = NULL;
		}
	}
};

