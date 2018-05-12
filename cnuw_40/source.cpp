#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int isTriangle(double a, double b, double c) {
	return a + b > c && a + c > b & b + c > a;
}
int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if (!isTriangle(a, b, c)) {
		printf("it is not a triangle");
	}
	else {
		double s = (a + b + c) / 2;
		double S = sqrt(s*(s - a)*(s - b)*(s - c));
		printf("area=%.2lf", S);
	}
	return 0;
}