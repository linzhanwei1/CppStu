#pragma once

class Complex {
private:
	double a;
	double b;
public:
	Complex(double a=0.0, double b=0.0);
	double getA();
	double getB();
	double getModulus();

	Complex operator + (const Complex& c);
	Complex operator - (const Complex& c);
	Complex operator * (const Complex& c);
	Complex operator / (const Complex& c);

	bool operator == (const Complex& c);
	bool operator != (const Complex& c);

	Complex& operator = (const Complex& c);
};