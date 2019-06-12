#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    return c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag();
}

bool operator!= (const Complex& c1, const Complex& c2) { return !(c1 == c2); }

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
	os << setprecision(5) << c.real << showpos << c.imag << 'i';
	return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	is >> c.real >> c.imag;
	return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::operator bool() const {
	return real || imag;
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	Complex temp(*this);
	real++;
	return temp;
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex Complex::operator--(int dummy) {
	Complex temp(*this);
	real--;
	return temp;
}


Complex operator+(const Complex& c1, const Complex& c2) {
	Complex result(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
	return result;
}

double Complex::get_real() const { return real; }

double Complex::get_imag() const { return imag; }

Complex& Complex::operator*(const int i) {
	real *= i;
	imag *= i;
	return *this;
}

Complex& Complex::operator-=(const Complex& c) {
	real -= c.real;
	imag -= c.imag;
	return *this;
}

