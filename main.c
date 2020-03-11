#include <stdio.h>
#include<math.h>
#include "my_complex.h"

int main() {
	Complex a = {3, 4};
	Complex b = {5, 12};
	printf("complex a\n");
	print_complex(a);
	printf("complex b\n");
	print_complex(b);
	Complex (*fn1[4])(Complex, Complex);
	double (*fn2[2])(Complex);
	fn1[0] = complex_add;
	fn1[1] = complex_sub;
	fn1[2] = complex_mult;
	fn1[3] = complex_div;

	fn2[0] = magnitude;
	fn2[1] = phase;
	printf("add a and b\n subtract a from b\n multiply a and b\n divide b into a parts\n");
	for(int i=0; i<4; i++) {
		Complex c = fn1[i](b, a);
		print_complex(c);
	}
	printf("magnitude of a then b phase of a then b\n");
	for(int j=0; j<2; j++) {
		double c = fn2[j](a);
		double d = fn2[j](b);
		printf(" %f\n", c);
		printf(" %f\n", d);
	}
	return 0;
}
