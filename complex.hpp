#include<iostream>
class Complex {
	private:
		double _real;
		double _imag;
	public:
	Complex();
	Complex(double real, double imag);
	Complex(double real);
	Complex(const Complex &_complex);
	~Complex();
	void set(double real, double imag);
	double real() const;
	double imag() const;
	void print();

	Complex add(Complex c);
	Complex sub(Complex c);
	Complex mult(Complex c);
	Complex div(Complex c);
	Complex con();
	
	double magnitude();
	double phase();

	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);

	friend std::ostream& operator<<(std::ostream &out, const Complex &c);
	friend std::istream& operator>>(std::istream &in, Complex &c);
};
