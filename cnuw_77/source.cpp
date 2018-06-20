#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n;
double f(double x) {
	return (x*x*x - n * x*x + 16 * x - 80);
}
double lfabs(double x) {
	return x < 0 ? -x : x;
}
// 实在弄不懂弦截法是啥，照搬了一部分谭浩强《C程序设计》的代码
double xpoint(double x1, double x2) {
	return (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
}
double solve(double x1, double x2) {
	double x, y, y1;
	y1 = f(x1);
	do {
		x = xpoint(x1, x2);
		y = f(x);
		if (y*y1 > 0) {
			y1 = y;
			x1 = x;
		}
		else x2 = x;
	} while (lfabs(y) >= 1e-6);
	return x;
}
// 以上

int main() {
	scanf("%d", &n);
	printf("%.4lf",solve(-20, 20));
	return 0;
}
