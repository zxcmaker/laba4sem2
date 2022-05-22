#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector
{
protected:
	int line;
	T* vector;
public:
	Vector();
	Vector(int _line);
	Vector(const Vector& _Vector);
	~Vector();

	Vector<T> operator+(const Vector<T>& param);
	Vector<T> operator-(const Vector<T>& param);
	T operator*(const Vector<T>& param);
	Vector<T>& operator = (const Vector<T>& param);
	bool operator ==(const Vector<T>& param);
	bool operator !=(const Vector<T>& param);
	const bool operator ==(const Vector<T>& param) const;
	const bool operator !=(const Vector<T>& param) const;
	T& operator [](const int n);
	const T operator [](const int n) const;

	template <class T>
	friend ostream& operator<<(ostream& os, const Vector<T>& vec);
	template <class T>
	friend istream& operator>>(istream& in, Vector<T>& vec);
};

template<class T>
Vector<T>::Vector()
{
		line = 0;
}

template<class T>
Vector<T>::Vector(int _line)
{
	if (line < 0) 
	{
		throw "size < 0";
	}
	else 
	{
		line = _line;
		vector = new T[line];
		for (int i = 0; i < line; i++)
			vector[i] = 0;
	}
}

template<class T>
Vector<T>::Vector(const Vector& _Vector)
{
	line = _Vector.line;
	vector = new T[line];
	for (int i = 0; i < line; i++)
	{
		vector[i] = _Vector.vector[i];
	}
}

template<class T>
Vector<T>::~Vector()
{
	if (line != 0)
		delete[] vector;
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& param)
{
		if (line == param.line) 
		{
			Vector<T> vec(line);
			for (int n = 0; n < line; n++)
				vec.vector[n] = param.vector[n] + vector[n];
			return vec;
		}
		else
		{
			throw "error size";
		}
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& param)
{
		if (line == param.line) 
		{
			Vector<T> vec(line);
			for (int n = 0; n < line; n++)
				vec.vector[n] = param.vector[n] - vector[n];
			return vec;
		}
		else
		{
			throw "error size";
		}
}

template<class T>
T Vector<T>::operator*(const Vector<T>& param)
{
		if (line == param.line)
		{
			T result = 0;
			for (int n = 0; n < line; n++)
				result += param.vector[n] * vector[n];
			return result;
		}
		else
		{
			throw "error size";
		}
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& param)
{
		if (this != &param) 
		{
			delete[] vector;
			line = param.line;
			vector = new T[line];
			for (int n = 0; n < line; n++)
				vector[n] = param.vector[n];
		}
		return *this;
}

template<class T>
bool Vector<T>::operator==(const Vector<T>& param)
{
		bool equal = false;

		if (line = param.line)
			equal = true;
		for (int i = 0; i < line; i++)
		{
			if (vector[i] != param.vector[i])
			{
				equal = false;
				break;
			}
		}
		return equal;
}

template<class T>
bool Vector<T>::operator!=(const Vector<T>& param)
{
	return !(this == param);
}

template<class T>
const bool Vector<T>::operator==(const Vector<T>& param) const
{
	bool equal = false;

	if (line = param.line)
		equal = true;
	for (int i = 0; i < line; i++)
	{
		if (vector[i] != param.vector[i])
		{
			equal = false;
			break;
		}
	}
	return equal;
}

template<class T>
const bool Vector<T>::operator!=(const Vector<T>& param) const 
{
	return !(this == param);
}

template<class T>
T& Vector<T>::operator[](const int n)
{
		if (line < n || n < 0)
			throw "error";
		else
			return vector[n];
}

template<class T>
const T Vector<T>::operator[](const int n) const
{
	if (line < n || n < 0)
		throw "error";
	else
		return vector[n];
}



template<class T>
ostream& operator<<(ostream& os, const Vector<T>& vec)
{
	for (int n = 0; n < vec.line; n++) 
	{
		os << "(" << vec[n] << ")\n";
	}
	os << endl;
	return os;
}

template<class T>
istream& operator>>(istream& in, Vector<T>& vec)
{
	for (int n = 0; n < vec.line; n++)
	{
		in >> vec[n];
	}
	return in;
}
