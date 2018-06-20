#include <stdio.h>
double lfabs(double v) {
	return v < 0 ? -v : v;
}
// 1: a>b   2:a<b   0:a=b
int lfcmp(double a, double b) {
	if (lfabs(a - b) < 1e-6) return 0;
	return a > b ? 1 : 2;
}
double lfsqrt(double v) {
	v = lfabs(v);
	double l = 0, r = v, d;
	while (d = (l + r) / 2) {
		switch (lfcmp(d*d, v)) {
		case 0: return d;
		case 1:
			r = d, l = 0; break;
		default:
			l = d, r = v;
		}
	}
	return d;
}
int main() {
	while (true) {
		double v;
		scanf_s("%lf", &v);
		printf("%lf\n\n", lfsqrt(v));
	}
	return 0;
}
