#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Array
{
private:
	int Size;
	T* Data;

public:
	Array() 
	{
		Size = 0;
		Data = 0;
	}

	//array1 = array2;
	void operator=(Array& other)
	{
		Size = other.Size;

		if (Data != 0)
		{
			delete Data;
		}

		Data = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			Data[i] = other.Data[i];
		}
	}

	friend ostream& operator<<(ostream& stream, Array<T>& arr)
	{
		stream << "Size = " << arr.Size << endl;
		for (int i = 0; i < arr.Size; i++)
		{
			stream << arr.Data[i] << " ";
		}

		return stream;
	}

	friend istream& operator>>(istream& stream, Array<T>& arr)
	{
		//cin >> arr;

		T* oldData = arr.Data;
		int oldSize = arr.Size;

		int newSize;
		cout << "Enter array size: ";
		cin >> newSize;

		T* newData = new T[newSize];
		for (int i = 0; i < oldSize; i++)
		{
			if (i < newSize)
			{
				newData[i] = oldData[i];
			}
		}

		delete oldData;

		arr.Size = newSize;
		arr.Data = newData;

		for (int i = 0; i < newSize; i++)
		{
			T obj;
			cin >> obj;

			arr.Data[i] = obj;
		}

		return stream;
	}

	bool operator==(Array<T>& other)
	{
		if (Size != other.Size)
		{
			return false;
		}

		for (int i = 0; i < Size; i++)
		{
			if (Data[i] != other.Data[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(Array<T>& other)
	{
		//eltare2a elsay3a
		//return !(*this == other);

		//eltare2a eltnya b2a
		if (Size != other.Size)
		{
			return true;
		}

		for (int i = 0; i < Size; i++)
		{
			if (Data[i] != other.Data[i])
			{
				return true;
			}
		}

		return false;
	}
};