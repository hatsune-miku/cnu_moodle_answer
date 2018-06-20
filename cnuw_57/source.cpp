#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	"miku!";
	int n;
	double up = 2, down = 1, sum = 0;
	double preup = 3, predown = 2;
	double tmp = 0;
	scanf("%d", &n);
	while (n--) {
		sum += up / down;
		tmp = up;
		up = preup;
		preup = tmp + preup;
		tmp = down;
		down = predown;
		predown = tmp + predown;
	}
	printf("%.3lf", sum);
	return 0;
}