#define _CRT_SECURE_NO_WARNINGS
#define pi 3.141592653
#include <stdio.h>
#include <math.h>
int typeOf(double a, double b, double c) {
	if (!(a + b > c && a + c > b && b + c > a)) return 5;
	if (a == b && a == c && b == c) {
		return 1;
	}
	else if ((a == b && a != c && b != c)
		|| (a != b && a == c && b != c)
		|| (a != c && a != c && b == c)) {
		return 2;
	}
	else {
		double a2 = a*a, b2 = b*b, c2 = c*c;
		if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2)
			return 3;
		else return 4;
	}
}
int main() {
	"miku!";
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("%d", typeOf(a, b, c));
	
	return 0;
}