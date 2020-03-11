#include<iostream>
#include<cmath>
#include"complex.hpp"
Complex::Complex() {
//	std::cout<<"made by default constructure"<<std::endl;
	_real = 0, _imag = 0;
}
Complex::Complex(double real, double imag) {
//	std::cout<<"made by parameteterized constructure"<<std::endl;
	_real = real;
	_imag = imag;
}	
Complex::Complex(double real) {
//	std::cout<<"made by parameteterized constructure"<<std::endl;
	_real = real, _imag = 0;
}
Complex::Complex(const Complex &_complex) {
//	std::cout<<"made by copy constructore"<<std::endl;
	_real = _complex._real;
	_imag = _complex._imag;
}
Complex::~Complex() {
//	std::cout<<"good bye"<<std::endl;
}
double Complex::real() const {
	return _real;
}
double Complex::imag() const {
	return _imag;
}
void Complex::print() {
	if(_imag>0){
		std::cout<<_real<<"+"<<_imag<<"j"<<std::endl;
	}
	else if(_imag<0) {
		std::cout<<_real<<"-"<<-_imag<<"j"<<std::endl;
	}
	else {
		std::cout<<_real<<std::endl;
	}
	return;
}
Complex Complex::add(Complex c) {
	Complex c1;
	c1._real = c._real + _real;
	c1._imag = c._imag + _imag;
	return c1;
}
Complex Complex::sub(Complex c) {
	Complex c1;
	c1._real = _real - c._real;
	c1._imag = _imag - c._imag;
	return c1;
}
Complex Complex::mult(Complex c) {
	Complex c1;
	c1._real = c._real * _real - c._imag * _imag;
	c1._imag = c._real * _imag + c._imag * _real;
	return c1;
}
Complex Complex::div(Complex c) {
	Complex c1;
	c1._real = (c._real * _real + c._imag * _imag) / (c._real * c._real + c._imag * c._imag);
	c1._imag = (c._real * _imag - c._imag * _real) / (c._real * c._real + c._imag * c._imag);
	return c1;
}
Complex Complex::con() {
	Complex c;
	c._real = _real;
	c._imag = -_imag;
	return c;
}
double Complex::magnitude() {
	double c;
	c = sqrt(_real * _real + _imag * _imag);
	return c;
}
double Complex::phase() {
	double p;
	p = atan(_imag / _real);
	p = p * 180 / 3.14159265359;
	return p;
}

Complex Complex::operator+(Complex c) {
	Complex c1;
	c1._real = c._real + _real;
	c1._imag = c._imag + _imag;
	return c1;
}
Complex Complex::operator-(Complex c) {
	Complex c1;
	c1._real = c._real - _real;
	c1._imag = c._imag - _imag;
	return c1;
}
Complex Complex::operator*(Complex c) {
	Complex c1;
	c1._real = c._real * _real - c._imag * _imag;
	c1._imag = c._real * _imag + c._imag * _real;
	return c1;


}
Complex Complex::operator/(Complex c) {
	Complex c1;
	c1._real = (c._real * _real + c._imag * _imag) / (c._real * c._real + c._imag * c._imag);
	c1._imag = (c._real * _imag - c._imag * _real) / (c._real * c._real + c._imag * c._imag);
	return c1;

}

std::ostream& operator<<(std::ostream &out, const Complex &c) {
	if(c._imag>0) {
		out<<c._real<<"+"<<c._imag<<"j"<<std::endl;
	}
	else if(c._imag<0) {
		out<<c._real<<"-"<<-c._imag<<"j"<<std::endl;
	}
	else {
		out<<c._real<<std::endl;
	}
	return out;
}
std::istream& operator>>(std::istream &in, Complex &c) {
	in>>c._real>>c._imag;
	return in;
}
