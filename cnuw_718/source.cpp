#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool fits(double a, double b, double x, double y, double r) {
	double x_a = x - a;
	double y_b = y - b;
	return (x_a * x_a + y_b * y_b) <= (r * r);
}
int main() {
	double circles[4][2] = { {2,2},{-2,2},{-2,-2},{2,-2} };
	double x, y;
	scanf("(%lf,%lf)", &x, &y);
	int tall = 0;
	for (int i = 0; i < 4; i++) {
		double a = circles[i][0],
			b = circles[i][1];
		if (fits(a, b, x, y, 1)) {
			tall = 10;
			break;
		}
	}
	printf("%d", tall);
	return 0;
}
