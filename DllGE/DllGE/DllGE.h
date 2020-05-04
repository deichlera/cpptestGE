//DllGE.h - contains declarations of Vector and Matrix class operators and methods
#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

#ifdef DLLGE_EXPORTS
#define DLLGE_API extern "C" __declspec(dllexport)
#else
#define DLLGE_API extern "C" __declspec(dllimport)
#endif

DLLGE_API class Vector
{
public:

	Vector(std::vector<float> v);

	Vector& operator+=(const Vector& om);

	Vector operator+(const Vector& om) const;

	Vector& operator-=(const Vector& om);

	Vector operator-(const Vector& om) const;

	Vector& operator*=(float value);

	Vector& operator/=(float value);

	~Vector() {}

private:
	int row;
	std::vector<float> data;

	void resize(int n);

	void fill(std::vector<float> v);
};

DLLGE_API class Matrix
{
public:

	Matrix(std::vector<std::vector<float>> v);

	Matrix& operator+=(const Matrix& om);

	Matrix operator+(const Matrix& om) const;

	Matrix& operator-=(const Matrix& om);

	Matrix operator-(const Matrix& om) const;

	Matrix& operator*=(float value);

	Matrix& operator/=(float value);

	~Matrix() {}

private:
	int row, column;
	std::vector<std::vector<float>> data;

	void resize(int n, int m);

	void fill(std::vector<std::vector<float>> v);
};