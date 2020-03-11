#include <stdio.h>
#include<math.h>
struct _complex {
	double real;
	double imag;
};

typedef struct _complex Complex;

void print_complex(Complex c);

Complex complex_add(Complex c1, Complex c2);
Complex complex_sub(Complex c1, Complex c2);
Complex complex_mult(Complex c1, Complex c2);
Complex complex_div(Complex c1, Complex c2);

Complex complex_conj(Complex c);

double magnitude(Complex c);
double phase(Complex c);

// adding handling fuctinos
void function1(Complex (*f1)(Complex, Complex), Complex c1, Complex c2);
void function2(double (*f2)(Complex), Complex c);
