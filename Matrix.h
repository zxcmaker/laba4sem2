#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;

template <class T>
class Matrix
{
	int line;
	int column;
	Vector<T>** matrix;

public:
	Matrix();
	Matrix(int _line, int _column);
	Matrix(const Matrix& _Matrix);
	~Matrix();

	void a(Matrix param)
	{
		cout << param[0][0];
	};
	Matrix<T> operator+(const Matrix<T>& param);
	Matrix<T> operator-(const Matrix<T>& param);
	Matrix<T> operator*(const Matrix<T>& param);
	Matrix<T>& operator = (const Matrix<T>& param);
	bool operator ==(const Matrix<T>& param);
	bool operator !=(const Matrix<T>& param);
	const bool operator ==(const Matrix<T>& param) const;
	const bool operator !=(const Matrix<T>& param) const;
	Vector<T>& operator [](const int n);
	const Vector<T>& operator [](const int n) const;

	template <class T>
	friend ostream& operator<<(ostream& os, const Matrix<T>& mat);
	template <class T>
	friend istream& operator>>(istream& in, Matrix<T>& mat);

};

	template<class T>
	Matrix<T>::Matrix()
	{
		line = 0;
		column = 0;
	}

	template<class T>
	Matrix<T>::Matrix(int _line, int _column)
	{
		if (_line < 0 || _column < 0)
		{
			throw "size < 0 or column < 0";
		}
		else
		{
			line = _line;
			column = _column;
			matrix = new Vector<T>*[_column];
			for (int i = 0; i < _column; i++)
				matrix[i] = new Vector<T>(_line);
		}
	}

	template<class T>
	Matrix<T>::Matrix(const Matrix& _Matrix)
	{
		line = _Matrix.line;
		column = _Matrix.column;
		matrix = new Vector<T>*[column];
		for (int i = 0; i < column; i++)
		{
			matrix[i] = new Vector<T>(line);
		}
	}

	template<class T>
	Matrix<T>::~Matrix()
	{
		if (line != 0 || column != 0)
			delete[] matrix;
	}

	template<class T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& param)
	{
		if (line == param.line && column == param.column)
		{
			Matrix<T> mat(line, column);
			for (int i = 0; i < column; i++)
					mat[i] = *(matrix[i]) + param[i];
			return mat;
		}
		else
		{
			throw "error size";
		}
	}

	template<class T>
	Matrix<T> Matrix<T>::operator-(const Matrix<T>& param)
	{

		if (line == param.line && column == param.column)
		{
			Matrix<T> mat(line, column);
			for (int i = 0; i < column; i++)
				mat[i] = *(matrix[i]) - param[i];
			return mat;
		}
		else
		{
			throw "error size";
		}
	}



	template<class T>
	Matrix<T> Matrix<T>::operator*(const Matrix<T>& param)
	{

		if (line == param.column || column == param.line)
		{
			Matrix<T> mat(param.column, line);
			for (int i = 0; i < param.column; i++)
			{ 
				for (int j = 0; j < line; j++)
				{
					for (int m = 0; m < column; m++)
					{
						mat[i][j] += (*this)[m][j] * param[i][m];
					}
				}
			}
			return mat;
		}
		else
		{
			throw "error";
		}
	}

	template<class T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T>& param)
	{
		if (this != &param)
		{
			delete[] matrix;
			column = param.column;
			matrix = new Vector<T>*[column];
			for (int n = 0; n < column; n++)
				matrix[n] = param.matrix[n];
		}
		return *this;
	}

	template<class T>
	bool Matrix<T>::operator==(const Matrix<T>& param)
	{
		bool equal = false;

		if (column = param.column)
			equal = true;
		for (int i = 0; i < column; i++)
		{
			if (matrix[i] != param.matrix[i])
			{
				equal = false;
				break;
			}
		}
		return equal;
	}

	template<class T>
	bool Matrix<T>::operator!=(const Matrix<T>& param)
	{
		return !(this == param);
	}

	template<class T>
	const bool Matrix<T>::operator==(const Matrix<T>& param) const
	{
		bool equal = false;

		if (column = param.column)
			equal = true;
		for (int i = 0; i < column; i++)
		{
			if (matrix[i] != param.matrix[i])
			{
				equal = false;
				break;
			}
		}
		return equal;
	}

	template<class T>
	const bool Matrix<T>::operator!=(const Matrix<T>& param) const
	{
		return !(this == param);
	}

	template<class T>
	Vector<T>& Matrix<T>::operator[](const int n)
	{
		if (column < n || n < 0)
			throw "error";
		else
			return *matrix[n];
	}

	template<class T>
	const Vector<T>& Matrix<T>::operator[](const int n) const
	{
		if (column < n || n < 0)
			throw "error";
		else
			return *matrix[n];
	}

	template<class T>
	ostream& operator<<(ostream& os, const Matrix<T>& mat)
	{
		for (int i = 0; i < mat.column; i++)
		{
			for (int j = 0; j < mat.line; j++)
			{
				os << mat[i][j] << " ";
			}
			os << endl;
		}
		os << endl;
		return os;
	}

	template<class T>
	istream& operator>>(istream& in, Matrix<T>& mat)
	{
		for (int i = 0; i < mat.column; i++)
		{
			in >> mat[i];
		}
		return in;
	}
