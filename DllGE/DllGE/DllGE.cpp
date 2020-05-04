//DllGE.cpp - defines the exported functions for the DLL.
#include "pch.h"
#include "DllGE.h"

Vector::Vector(std::vector<float> v)
{
	resize(v.size());
	this->fill(v);
}

Vector& Vector::operator+=(const Vector& om)
{
	for (int i = 0; i < row; ++i)
		data[i] += om.data[i];
	return *this;
}

Vector Vector::operator+(const Vector& om) const
{
	Vector result = *this;
	return result += om;
}

Vector& Vector::operator-=(const Vector& om)
{
	for (int i = 0; i < row; ++i)
		data[i] -= om.data[i];
	return *this;
}

Vector Vector::operator-(const Vector& om) const
{
	Vector result = *this;
	return result -= om;
}

Vector& Vector::operator*=(float value)
{
	for (int i = 0; i < row; ++i)
		data[i] *= value;
	return *this;
}

Vector& Vector::operator/=(float value)
{
	for (int i = 0; i < row; ++i)
		data[i] /= value;
	return *this;
}


void Vector::resize(int n)
{
	row = n;
	data.resize(row);
}

void Vector::fill(std::vector<float> v)
{
	for (int i = 0; i < row; ++i)
		data[i] = v[i];
}

Matrix::Matrix(std::vector<std::vector<float>> v)
{
	resize(v.size(), v[0].size());
	this->fill(v);
}

Matrix& Matrix::operator+=(const Matrix& om)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			data[i][j] += om.data[i][j];
	return *this;
}

Matrix Matrix::operator+(const Matrix& om) const
{
	Matrix result = *this;
	return result += om;
}

Matrix& Matrix::operator-=(const Matrix& om)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			data[i][j] -= om.data[i][j];
	return *this;
}

Matrix Matrix::operator-(const Matrix& om) const
{
	Matrix result = *this;
	return result -= om;
}

Matrix& Matrix::operator*=(float value)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			data[i][j] *= value;
	return *this;
}

Matrix& Matrix::operator/=(float value)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			data[i][j] /= value;
	return *this;
}

void Matrix::resize(int n, int m)
{
	row = n;
	column = m;
	data.resize(row);
	for (std::vector<float>& d : data)
		d.resize(column);
}

void Matrix::fill(std::vector<std::vector<float>> v)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			data[i][j] = v[i][j];
}