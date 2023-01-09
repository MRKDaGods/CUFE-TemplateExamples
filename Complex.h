#pragma once

#include <iostream>

using namespace std;

class Complex;

class test {
private:
	int age;

	//b5ly complex yshof elprivates bt3ty
	friend class Complex;
};

class Complex
{
private:
	int Real;
	int Imaginary;

public:
	Complex(int r = 0, int i = 0)
	{
		Real = r;
		Imaginary = i;
	}

	//c1 = c1 + c2, +(c1, c2)
	//c3 = c1 + c2
	Complex operator+(Complex& other)
	{
		return Complex(Real + other.Real, Imaginary + other.Imaginary);
	}

	//c1 / c2
	Complex operator/(Complex& other)
	{
		return Complex(Real / other.Real, Imaginary / other.Imaginary);
	}

	void operator+=(Complex& other)
	{
		Real += other.Real;
		Imaginary += other.Imaginary;
	}

	Complex& operator++(int)
	{
		Complex c = *this;
		
		Real++;

		return c;
	}

	Complex& operator++()
	{
		Real++;
		return *this;
	}

	bool operator==(Complex& other)
	{
		return Real == other.Real && Imaginary == other.Imaginary;
	}

	friend ostream& operator<<(ostream& stream, Complex& other)
	{
		stream << other.Real << ", " << other.Imaginary << endl;
		return stream;
	}
};

//gowa ay class <CLASS>
// friend <SOMETHING>
//SOMETHING (method aw class) di btshof elprivates bt3t CLASS