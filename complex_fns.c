#include <stdio.h>
#include<math.h>
#include "my_complex.h"

double magnitude(Complex c) {
	return sqrt((c.real * c.real) + (c.imag * c.imag));
}

double phase(Complex c) {
	double ph = atan(c.imag / c.real);
	ph = ph * (180 / M_PI);
	return (ph < 0) ? -ph : ph;
}

void print_complex(Complex c) {
		if(c.imag  < 0) {
			printf("%.3lf - %.3lf\n", c.real, -c.imag);
		}
		else {
			printf("%.3lf + %.3lf\n", c.real, c.imag);
		}
}

Complex complex_conj(Complex c) {
	c.imag *= -1;
	return c;
}

Complex complex_add(Complex c1, Complex c2) {
	Complex c = {c1.real + c2.real, c1.imag + c2.imag};
	return c;
}

Complex complex_sub(Complex c1, Complex c2) {
	Complex c = {c1.real - c2.real, c1.imag - c2.imag};
	return c;
}

Complex complex_mult(Complex c1, Complex c2) {
	Complex c = {(c1.real * c2.real) + (c1.imag * c2.imag * -1), (c1.imag * c2.real) + (c1.real * c2.imag)};
	return c;
}

Complex complex_div(Complex c1, Complex c2) {
	double denom = magnitude(c2) * magnitude(c2);
	if(denom == 0) {
		printf("Can't divide by zero\n");
	}
	else if(denom != 0) {
	Complex c = complex_mult(c1, complex_conj(c2));
	c.real /= denom;
	c.imag /= denom;
	return c;
	}
}
//void function1_complex(Complex a(), Complex b, Complex c) {
void function1(Complex (*f1)(Complex, Complex), Complex c1, Complex c2) {
	Complex r = f1(c1, c2);
	print_complex(r);
}
void function2(double (*f2)(Complex), Complex c) {
	double r = f2(c);
	printf("%f\n", r);
}
